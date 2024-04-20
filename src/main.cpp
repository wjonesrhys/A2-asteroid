#include <entity.hpp>
#include <entitymanager.hpp>

#include <fstream>
#include <memory>
#include <SFML/Graphics.hpp>

#include <imgui.h>
#include <imgui-SFML.h>

enum entityType {
    Window, 
    Font,
    Rectangle,
    Circle,
    Empty = -1
};

entityType hashit(std::string& entityType) {
    for (char &c : entityType) { 
        c = std::tolower(c); 
    } 
    if (entityType == "window") return Window;
    if (entityType == "font") return Font;
    if (entityType == "rectangle") return Rectangle;
    if (entityType == "circle") return Circle;
    return Empty;
}

void createWindow(std::ifstream& fin, sf::RenderWindow& renderWindow) {
    std::string iconLocation;
    int width, height;
    fin >> iconLocation >> height >> width;

    renderWindow.create(sf::VideoMode(height, width), "testing code", sf::Style::Default);
    renderWindow.setFramerateLimit(120);
    renderWindow.setVerticalSyncEnabled(true);
    renderWindow.setPosition(Vec2(1920/4, 1080/4));

    sf::Image icon;
    if (!icon.loadFromFile(iconLocation)) {
        std::cout << "icon didn't load" << std::endl;
    } else {
        renderWindow.setIcon(32,32,icon.getPixelsPtr());
        std::cout << "icon loaded" << std::endl;
    } 

    std::cout << "window loaded" << std::endl;
}

void createFontAndText(std::ifstream& fin, sf::Font& font, sf::Text& text) {
    std::string fontLocation;
    int size, r, g, b;
    fin >> fontLocation >> size >> r >> g >> b;
    
    font.loadFromFile(fontLocation);
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color(r,g,b));
}

void createRectangle(std::ifstream& fin, EntityManager& em) {
    std::string label;
    float pos_x, pos_y, speed_x, speed_y;
    int r, g, b;
    float width, height;
    fin >> label >> pos_x >> pos_y >> speed_x >> speed_y >> r >> g >> b >> width >> height;

    auto e = em.addEntity("rectangle");
    e->shape        = std::make_shared<CShape>(Vec2(pos_x, pos_y),sf::Color(r,g,b),Vec2(width,height));
    e->boundingBox  = std::make_shared<CBBox>(Vec2(width, height));
    e->transform    = std::make_shared<CTransform>(Vec2(pos_x,pos_y), Vec2(speed_x,speed_y));
    e->name         = std::make_shared<CName>(label);
}

void createCircle(std::ifstream& fin, EntityManager& em) {
    std::string label;
    float pos_x, pos_y, speed_x, speed_y;
    int r, g, b;
    float radius;
    fin >> label >> pos_x >> pos_y >> speed_x >> speed_y >> r >> g >> b >> radius;

    auto e = em.addEntity("circle");
    e->shape        = std::make_shared<CShape>(Vec2(pos_x, pos_y),sf::Color(r,g,b),radius);
    e->boundingBox  = std::make_shared<CBBox>(Vec2(radius*2));
    e->transform    = std::make_shared<CTransform>(Vec2(pos_x,pos_y), Vec2(speed_x,speed_y));
    e->name         = std::make_shared<CName>(label);
}

void checkWallCollision(EntityVec& entities, sf::RenderWindow& window) {
    Vec2 windowSize(window.getSize());
    for (auto& e : entities) {
        auto& bbox =  e->boundingBox;

        if (e->shape->shape->getPosition().x - bbox->halfWidth < 0) 
        {
            e->shape->shape->setPosition(Vec2(bbox->halfWidth, e->shape->shape->getPosition().y));
            e->transform->speed *= Vec2(-1,1);
            e->transform->prevPos = e->shape->shape->getPosition();
            e->transform->pos = e->shape->shape->getPosition();
        }

        if (e->shape->shape->getPosition().x + bbox->halfWidth > windowSize.m_x) 
        {   
            e->shape->shape->setPosition(Vec2(windowSize.m_x - bbox->halfWidth, e->shape->shape->getPosition().y));
            e->transform->speed *= Vec2(-1,1);
            e->transform->prevPos = e->shape->shape->getPosition();
            e->transform->pos = e->shape->shape->getPosition();
        }

        if (e->shape->shape->getPosition().y - bbox->halfHeight < 0) 
        {
            e->shape->shape->setPosition(Vec2(e->shape->shape->getPosition().x, bbox->halfHeight));
            e->transform->speed *= Vec2(1,-1);
            e->transform->prevPos = e->shape->shape->getPosition();
            e->transform->pos = e->shape->shape->getPosition();
        }

        if (e->shape->shape->getPosition().y + bbox->halfHeight > windowSize.m_y) 
        {
            e->shape->shape->setPosition(Vec2(e->shape->shape->getPosition().x, windowSize.m_y - bbox->halfHeight));
            e->transform->speed *= Vec2(1,-1);
            e->transform->prevPos = e->shape->shape->getPosition();
            e->transform->pos = e->shape->shape->getPosition();
        }
        
    }
}

Vec2 linearInterpolation(Vec2& start, Vec2& end, float alpha) {
    return (start * (1 - alpha) + end * alpha);
}

int main() 
{
    EntityManager entityManager;
    sf::RenderWindow renderWindow;
    sf::Font font;
    sf::Text text;
    bool showImGui = true;
    bool drawEntities = true;
    bool drawNames = true;

    std::string nextEntity;
    std::ifstream fin("resources/config.txt");
    if (fin) {
        while (fin >> nextEntity) {
            switch (hashit(nextEntity)) {
                case Window:
                    createWindow(fin, renderWindow);
                    break;
                case Font:
                    createFontAndText(fin, font, text);
                    break;
                case Rectangle:
                    createRectangle(fin, entityManager);
                    break;
                case Circle:
                    createCircle(fin, entityManager);
                    break;
                default:
                    break;
            }
        }
        std::cout << "Successfully Loaded Config!" << std::endl;
        // Close the file
        fin.close();
    } else {
        std::cout << "Unable to locate config file!" << std::endl;
        renderWindow.create(sf::VideoMode(800, 600), "testing code", sf::Style::Default);
    }

    sf::Time TIME_PER_FRAME = sf::seconds( 1.0f / 60.0f );
    sf::Clock clock;
    sf::Time accumulator;
    sf::Time frameTime;

    float alpha;

    if (!ImGui::SFML::Init(renderWindow)) 
    {
        std::cout << "not able to initialise imgui for sfml" << std::endl;
    } else {
        std::cout << "imgui initialised" << std::endl;
    }

    while(renderWindow.isOpen()) {
        auto entities = entityManager.getEntities();
        frameTime = clock.restart();
        accumulator += frameTime;

        if (showImGui) 
        {
            ImGui::SFML::Update(renderWindow, frameTime);
            ImGui::Begin("debug window");
            ImGui::Checkbox("draw entities", &drawEntities);
            ImGui::Checkbox("draw text", &drawNames);
            ImGui::End();
        }

        // events
        sf::Event event;
        while(renderWindow.pollEvent(event)) {
            if (showImGui) 
            {
                ImGui::SFML::ProcessEvent(renderWindow, event);
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    renderWindow.close();
                }

                if (event.key.code == sf::Keyboard::Num0) {
                    showImGui == true ? showImGui = false : showImGui = true;
                    if (entities.size() > 0) {
                        entities.at(0)->destroy();
                    }
                }

                if (event.key.code == sf::Keyboard::Num9) {
                    drawEntities == true ? drawEntities = false : drawEntities = true;
                }

                if (event.key.code == sf::Keyboard::Num8) {
                    drawNames == true ? drawNames = false : drawNames = true;
                }
            }
        }

        // update
        while (accumulator >= TIME_PER_FRAME) {
            for (auto& entity : entities) {
                entity->transform->prevPos = entity->transform->pos;
                entity->transform->pos += entity->transform->speed*TIME_PER_FRAME.asSeconds();
                entity->shape->shape->setPosition(entity->transform->pos);
            }
            accumulator -= TIME_PER_FRAME;
        }

        alpha = (accumulator/TIME_PER_FRAME);

        //interpolate on the alpha
        for (auto& entity : entities) {
            entity->shape->shape->setPosition(linearInterpolation(entity->transform->prevPos, entity->transform->pos, alpha));
        }

        std::vector<sf::Text> names;
        //set text and position
        for (auto& e : entities) {
            text.setString(e->name->name);
            auto bounds = text.getLocalBounds();
            text.setOrigin(Vec2(bounds.width/2, bounds.height));
            text.setPosition(e->shape->shape->getPosition());
            names.push_back(text);
        }

        //check for collisions
        checkWallCollision(entities, renderWindow);

        renderWindow.clear();

        for (auto& e : entities) 
        {
            if (drawEntities) 
            {
                renderWindow.draw(*e->shape->shape);
            }
        }

        for (auto& name : names) 
        {
            if (drawNames) 
            {
                renderWindow.draw(name);
            }
        }

        if (showImGui) 
        {
            ImGui::SFML::Render(renderWindow);
        }

        renderWindow.display();
        entityManager.update();
    }

    return 0;
}
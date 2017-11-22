#pragma once

#include <xyginext/ecs/Component.hpp>
#include <xyginext/ecs/System.hpp>
#include <xyginext/ecs/Director.hpp>

#include <random>

struct Snake
{
    Snake()
    {
        //pick two random body colours
        std::mt19937 randomEngine;
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        randomEngine.seed(static_cast<int>(seed));
        std::uniform_int_distribution<int> colourDistribution = std::uniform_int_distribution<int>(0, sf::Color::White.r);
    
        auto rnd = [&]
        {
            return colourDistribution(randomEngine);
        };
    
        m_toneOne = sf::Color(rnd(), rnd(), rnd());
        m_toneTwo = sf::Color(rnd(), rnd(), rnd());
    }
    float                     m_speed = 150.f;      //current speed
    float                     m_turnSpeed = 3.f;
    float                     m_direction;
    int                       m_maxLength = 50;
    float                     m_tailLength = 0.3f;
    sf::Color                 m_toneOne, m_toneTwo;
    std::deque<sf::Vector2f>  m_spine;
};

class SnakeRenderer : public xy::System, public sf::Drawable{
public:
    SnakeRenderer(xy::MessageBus&);
    
    void process(float dt) override;
    
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    
};

//class Snake : public sf::Drawable, public sf::Transformable
//{
//public:
//    Snake(sf::RenderWindow& window, World& world, Score& score, std::string headTexture);
//    ~Snake() = default;
//
//    //update the sssssnake
//    void update(float dt);
//
//    //respawn when killed
//    void respawn();
//
//    //check for collisions with mice
//    bool checkForCollision(sf::FloatRect rect);
//    void addToSize(int scoreToAdd);
//
//    //get current size - original size to be used as score
//    int getCurrentScore();
//
//    sf::View getView() const;
//
//    float getSpeed() const;
//    void setSpeed(float speed);
//
//private:
//
//    virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;
//
//    sf::VertexArray        m_snakeBody;
//    float                tailLength;        //the fraction of the snake to make the tail
//
//    float                m_direction;    //the current direction of the snake
//    float                m_speed;        //current speed
//    float                m_turnSpeed;    //the speed it can turn at
//
//    sf::RenderWindow*    m_window;
//    World*                m_world;
//    Score*                m_score;
//
//    std::deque<sf::Vector2f>    positionHistory;
//    std::size_t                    positionHistorySize;
//
//    const int snakeOrigSize = 50;
//    sf::Color                    toneOne;
//    sf::Color                    toneTwo;
//
//    sf::Texture                    m_headTexture;
//    sf::Sprite                    m_headSprite;
//
//    std::mt19937                             randomEngine;
//    std::uniform_int_distribution<int>       colourDistribution;    //for getting random colours!
//
//    sf::View                                m_view;
//    float                                    lifeSpan;
//
//    sf::Sound                                        m_eatSound;
//    sf::SoundBuffer                                    m_eatSoundBuffer;
//};
//

//
//  SnakingState.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef SnakingState_hpp
#define SnakingState_hpp

#include <xyginext/core/State.hpp>
#include <xyginext/ecs/Scene.hpp>

class SnakingState : public xy::State
{
public:
    SnakingState(xy::StateStack& ss, xy::State::Context& context);
    
    bool handleEvent(const sf::Event &evt) override;
    
    void handleMessage(const xy::Message &) override;
    
    bool update(float dt) override;
    
    void draw() override;
    
    xy::StateID stateID() const override;
    
private:
    xy::Scene m_scene;
};

#endif /* SnakingState_hpp */

//
//  PausedState.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef PausedState_hpp
#define PausedState_hpp

#include <xyginext/core/State.hpp>

class PausedState : public xy::State
{
public:
    PausedState(xy::StateStack& ss, xy::State::Context context) : xy::State(ss, context){};
    bool handleEvent(const sf::Event &evt) override;
    
    void handleMessage(const xy::Message &) override;
    
    bool update(float dt) override;
    
    void draw() override;
    
    xy::StateID stateID() const override;
    
};

#endif /* PausedState_hpp */

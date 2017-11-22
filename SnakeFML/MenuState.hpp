//
//  MenuState.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include <xyginext/core/State.hpp>

class MenuState : public xy::State
{
public:
    MenuState(xy::StateStack& ss, xy::State::Context context) : xy::State(ss, context){};
    bool handleEvent(const sf::Event &evt) override;
    
    void handleMessage(const xy::Message &) override;
    
    bool update(float dt) override;
    
    void draw() override;
    
    xy::StateID stateID() const override;
    
};
#endif /* MenuState_hpp */

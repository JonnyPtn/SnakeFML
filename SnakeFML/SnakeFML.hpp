//
//  SnakeFML.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef SnakeFML_h
#define SnakeFML_h

#include <xyginext/core/App.hpp>
#include <xyginext/core/StateStack.hpp>

class SnakeFML : public xy::App
{
public:
    SnakeFML();
    void handleEvent(const sf::Event &) override;
    
    void handleMessage(const xy::Message &) override;
    
    void registerStates() override;
    
    void updateApp(float dt) override;
    
    void draw() override;
    
private:
    xy::StateStack m_stateStack;
    
};

#endif /* SnakeFML_h */

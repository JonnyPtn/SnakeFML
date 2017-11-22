//
//  SnakeFML.cpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#include "SnakeFML.hpp"
#include "States.hpp"
#include "MenuState.hpp"
#include "SnakingState.hpp"
#include "PausedState.hpp"

SnakeFML::SnakeFML() :
xy::App(),
m_stateStack({*getRenderWindow(), *this})
{
    setWindowIcon("Assets/Images/icon.png");
    registerStates();
}

void SnakeFML::handleEvent(const sf::Event & ev) {
    m_stateStack.handleEvent(ev);
}

void SnakeFML::handleMessage(const xy::Message & msg) {
    m_stateStack.handleMessage(msg);
}

void SnakeFML::registerStates() { 
    m_stateStack.registerState<MenuState>(States::MENU);
    m_stateStack.registerState<SnakingState>(States::SNAKING);
    m_stateStack.registerState<PausedState>(States::PAUSED);
    
    m_stateStack.pushState(States::SNAKING);
}

void SnakeFML::updateApp(float dt) { 
    m_stateStack.update(dt);
}

void SnakeFML::draw() { 
    m_stateStack.draw();
}

//
//  MenuState.cpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#include "MenuState.hpp"
#include "States.hpp"

bool MenuState::handleEvent(const sf::Event &evt) {
}

void MenuState::handleMessage(const xy::Message &) {
}

bool MenuState::update(float dt) {
}

void MenuState::draw() {
}

xy::StateID MenuState::stateID() const {
    return States::MENU;
}

//
//  PausedState.cpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#include "PausedState.hpp"
#include "States.hpp"

bool PausedState::handleEvent(const sf::Event &evt) {
}

void PausedState::handleMessage(const xy::Message &) {
}

bool PausedState::update(float dt) {
}

void PausedState::draw() {
}

xy::StateID PausedState::stateID() const {
    return States::PAUSED;
}

//
//  SnakingState.cpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#include "SnakingState.hpp"
#include "States.hpp"
#include "Snake.hpp"
#include <xyginext/ecs/components/Transform.hpp>
#include <xyginext/ecs/components/Camera.hpp>
#include <xyginext/ecs/systems/CameraSystem.hpp>
#include "Grass.hpp"

SnakingState::SnakingState(xy::StateStack& ss, xy::State::Context& context) :
xy::State(ss, context),
m_scene(context.appInstance.getMessageBus())
{
    m_scene.addSystem<GrassRenderer>(context.appInstance.getMessageBus());
    m_scene.addSystem<SnakeRenderer>(context.appInstance.getMessageBus());
    m_scene.addSystem<xy::CameraSystem>(context.appInstance.getMessageBus());
    
    // Snake entity
    auto e = m_scene.createEntity();
    e.addComponent<Snake>();
    auto ws = context.renderWindow.getSize();
    e.addComponent<xy::Transform>().setPosition(ws.x/2, ws.y/2);
    
    // Camera entity
    auto cam = m_scene.createEntity();
    cam.addComponent<xy::Transform>();
    cam.addComponent<xy::Camera>().zoom(2.f);
    e.getComponent<xy::Transform>().addChild(cam.getComponent<xy::Transform>());
    m_scene.setActiveCamera(cam);
};

bool SnakingState::handleEvent(const sf::Event &evt) {
    m_scene.forwardEvent(evt);
}

void SnakingState::handleMessage(const xy::Message &msg) {
    m_scene.forwardMessage(msg);
}

bool SnakingState::update(float dt) {
    m_scene.update(dt);
}

void SnakingState::draw() {
    auto rw = getContext().appInstance.getRenderWindow();
    rw->draw(m_scene);
}

xy::StateID SnakingState::stateID() const {
    return States::SNAKING;
}

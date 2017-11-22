//
//  Grass.cpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#include "Grass.hpp"
#include <SFML/Graphics.hpp>
#include <xyginext/ecs/Scene.hpp>
#include <xyginext/ecs/components/Camera.hpp>

GrassRenderer::GrassRenderer(xy::MessageBus& mb) :
xy::System(mb,typeid(this))
{
    requireComponent<Grass>();
    m_shape.setFillColor(sf::Color::Green);
}


void GrassRenderer::process(float dt) {
        auto cam = getScene()->getActiveCamera();
        auto r = cam.getComponent<xy::Camera>().getBounds();
        m_shape.setSize({r.width,r.height});
        m_shape.setPosition(r.left, r.top);
}

void GrassRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const { 
    
        target.draw(m_shape);
}

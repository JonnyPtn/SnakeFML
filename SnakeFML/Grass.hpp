//
//  Grass.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef Grass_hpp
#define Grass_hpp

#include <xyginext/ecs/System.hpp>

struct Grass
{
};

class GrassRenderer : public xy::System, public sf::Drawable
{
public:
    GrassRenderer(xy::MessageBus&);
    void process(float dt) override;
    
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    
    sf::RectangleShape m_shape;
    
};

#endif /* Grass_hpp */

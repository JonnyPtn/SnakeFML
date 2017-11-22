//
//  SnakeComponent.hpp
//  SnakeFML
//
//  Created by Jonny Paton on 21/11/2017.
//

#ifndef SnakeComponent_hpp
#define SnakeComponent_hpp

#include <xyginext/ecs/Component.hpp>

struct Snake
{
    float                m_speed;        //current speed
    float                m_turnSpeed;    //the speed it can turn at 
}

#endif /* SnakeComponent_hpp */

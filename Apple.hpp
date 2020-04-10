//
//  Apple.hpp
//  Game
//
//  Created by Luis Martinez on 4/4/20.
//  Copyright © 2020 UDevs. All rights reserved.
//

#ifndef Apple_hpp
#define Apple_hpp

#include <stdio.h>
#include <iostream>
#include<SFML/Graphics.hpp>

class Apple {

  typedef struct point_t {
    float x;
    float y;
  }
  Point;
  
  public:
    Apple(float x, float y);
    Point getPosition();
    sf::RectangleShape getShape() const;
    void getNewPosition();
  
  private:
    float x;
    float y;
    sf::RectangleShape appleShape;
};

#endif /* Apple_hpp */

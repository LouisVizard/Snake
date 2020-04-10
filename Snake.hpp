//
//  Snake.hpp
//  Game
//
//  Created by Luis Martinez on 4/4/20.
//  Copyright © 2020 UDevs. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include <stdio.h>
#include <iostream>
#include<SFML/Graphics.hpp>

class Snake {
  
  public:
    typedef struct point_t {
      float x;
      float y;
    }
    Point;
    
    Snake(float x, float y);
    bool eatApple(const sf::RectangleShape& shape);
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void reset();
    Point getPosition();
    sf::RectangleShape getShape() const;
    void increaseTotal();
    int getTotal();
    void update();
    std::vector<sf::RectangleShape> snakeTail;
  
  private:
    float xvel;
    float yvel;
    Point position;
    sf::RectangleShape snakeShape;
    int total;
    std::vector<Point> tail;
};

#endif /* Snake_hpp */

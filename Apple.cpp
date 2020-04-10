//
//  Apple.cpp
//  Game
//
//  Created by Luis Martinez on 4/4/20.
//  Copyright © 2020 UDevs. All rights reserved.
//

#include "Apple.hpp"
#include <stdio.h>
#include <iostream>
#include<SFML/Graphics.hpp>

const int SIZE = 50;

Apple::Apple(float x, float y) {
  this->x = x;
  this->y = y;
  
  appleShape.setSize(sf::Vector2f(SIZE, SIZE));
  appleShape.setFillColor(sf::Color::Red);
  appleShape.setPosition(x, y);
}

Apple::Point Apple::getPosition() {
  Apple::Point p;
  p.x = x;
  p.y = y;
  return p;
}

sf::RectangleShape Apple::getShape() const {
  return appleShape;
}

void Apple::getNewPosition() {
  int cols = 1500/SIZE;
  int rows = 1000/SIZE;
  x = (rand() % cols) * SIZE;
  y = (rand() % rows) * SIZE;
  appleShape.setPosition(x, y);
}


//
//  Snake.cpp
//  Game
//
//  Created by Luis Martinez on 4/4/20.
//  Copyright © 2020 UDevs. All rights reserved.
//

#include "Snake.hpp"
#include <iostream>
#include <stdio.h>
#include<SFML/Graphics.hpp>

float VELOCITY = 50;

// Shift the body segment positions
void shiftSegs(std::vector<Snake::Point>& segments, Snake::Point newPos) {
  for (int i = 0; i < segments.size() - 1; i++) {
    segments[i] = segments[i + 1];
  }
  segments[segments.size() - 1] = newPos;
}

void shiftTail(std::vector<sf::RectangleShape>& segments, sf::RectangleShape newSeg) {
  for (int i = 0; i < segments.size() - 1; i++) {
    segments[i] = segments[i + 1];
  }
  segments[segments.size() - 1] = newSeg;
}

// Constructor that initializes the snake velocity, snake starting position, and the window
Snake::Snake(float x, float y) {
  position.x = x;
  position.y = y;
  
  xvel = 0;
  yvel = 0;
  
  total = 0;
  
  snakeShape.setSize(sf::Vector2f(VELOCITY, VELOCITY));
  snakeShape.setFillColor(sf::Color(255, 255, 255));
  snakeShape.setPosition(position.x, position.y);
}

bool Snake::eatApple(const sf::RectangleShape& shape) {
  if (snakeShape.getGlobalBounds().intersects(shape.getGlobalBounds())) {
    tail.push_back(position);
    total++;
    return true;
  }
  return false;
}

// returns the position of snake head on screen
Snake::Point Snake::getPosition() {
  return position;
}

// returns the shape of the snake
sf::RectangleShape Snake::getShape() const {
  return snakeShape;
}

void Snake::moveLeft() {
  xvel = -VELOCITY;
  yvel = 0;
}

void Snake::moveRight() {
  xvel = VELOCITY;
  yvel = 0;
}

void Snake::moveUp() {
  yvel = -VELOCITY;
  xvel = 0;
}

void Snake::moveDown() {
  yvel = VELOCITY;
  xvel = 0;
}

void Snake::reset() {
  position.x = 50;
  position.y = 50;
  xvel = 0;
  yvel = 0;
  total = 0;
  tail.clear();
  snakeTail.clear();
}

void Snake::update() {
  //std::cout << tail.size() << std::endl;
  if ((total == tail.size()) && (tail.size() != 0)) {
    shiftSegs(tail, position);
  }
  
  sf::RectangleShape snakeSeg;
  snakeSeg.setSize(sf::Vector2f(VELOCITY, VELOCITY));
  snakeSeg.setFillColor(sf::Color(255, 255, 255));
  snakeSeg.setOutlineThickness(2);
  snakeSeg.setOutlineColor(sf::Color(0, 0, 0));
  for (int i = 0; i < tail.size(); i++) {
    snakeSeg.setPosition(tail[i].x, tail[i].y);
    if (snakeTail.size() != tail.size()) {
      snakeTail.push_back(snakeSeg);
    }
  }
  
  std::cout << snakeTail.size() << std::endl;
  if ((total == snakeTail.size()) && (snakeTail.size() != 0)) {
    shiftTail(snakeTail, snakeSeg);
  }
  
  position.x += xvel;
  position.y += yvel;
  snakeShape.setPosition(position.x, position.y);
}

int Snake::getTotal() {
  return total;
}

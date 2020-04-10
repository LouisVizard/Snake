//
//  main.cpp
//  Game
//
//  Created by Luis Martinez on 4/2/20.
//  Copyright © 2020 UDevs. All rights reserved.
//

#include <iostream>
#include<SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Apple.hpp"

// absolute value helper function
float abs(float val) {
  return (val < 0) ? (val*-1) : val;
}

int main() {
  // insert code here...
  sf::RenderWindow window(sf::VideoMode(1500, 1000), "My Window");
  window.setFramerateLimit(15);
  
  Snake snake(50, 50);
  Apple apple(750.0, 500.0);
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
          window.close();
      
    }
    
    //std::cout << snake.getPosition().x << ", " << snake.getPosition().y << std::endl;
    
    // keyboard detection for snake movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      snake.moveLeft();
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      snake.moveRight();
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      snake.moveUp();
    }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      snake.moveDown();
    }
    
    // Snake position resets if it goes out of bounds
    if ((snake.getPosition().x + 50) > 1500) {
      snake.reset();
      //return 0;
    }
    if (snake.getPosition().x < 0) {
      snake.reset();
      //return 0;
    }
    if ((snake.getPosition().y + 50) > 1000) {
      snake.reset();
      //return 0;
    }
    if (snake.getPosition().y < 0) {
      snake.reset();
      //return 0;
    }
    
    // relocate apple if snake eats it
    if (snake.eatApple(apple.getShape())) {
      apple.getNewPosition();
    }
    
    snake.update();
    
    window.clear();
    
    // Draw the objects here
    window.draw(snake.getShape());
    for (int i = 0; i < snake.snakeTail.size(); i++) {
      window.draw(snake.snakeTail[i]);
    }
    window.draw(apple.getShape());
    
    window.display();
  }
  
  return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <math.h>
#include "text.hpp"
#include "utilities.hpp"
#include "npc.hpp"
#include "player.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode(1366, 768), "Fair ain't square", sf::Style::Default);
  window.setFramerateLimit(60);

  //Make the font self-constructing in the future
  sf::Texture text;
  text.loadFromFile("./fontT.png");

  //Placeholder square, at least show something on screen
  sf::RectangleShape square(sf::Vector2f(150.0, 150.0));
  square.setSize(sf::Vector2f(100.0, 100.0));
  square.setFillColor(sf::Color(25, 255, 25));
  square.setPosition(sf::Vector2f(150.0, 150.0));

  std::vector<npc> npcs;
  player myPlayer(100, 100);
  myPlayer.setColour(0, 255, 0);

  while (window.isOpen()){
    sf::Event event;

    //Bunch of keyboard events that'll make our character move around
    //Running isn't used for now
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)){
      myPlayer.running=1;
    }
    else{
      myPlayer.running=0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
      myPlayer.right();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
      myPlayer.left();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
      myPlayer.up();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
       sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
      myPlayer.down();
    }

    //Pressing "C" will create a NPC, likewise, pressing "V" will delete one
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
      npc bob(rand()%500, rand()%500);
      npcs.push_back(bob);
	  npcs.back().setColour(rand()%255, rand()%255, rand()%255);
      //npcs.back().setTexture(npcTexture, 0, 0, 16, 16);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
      if(npcs.size()>0){
		npcs.pop_back();
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
      window.close();
    }

    while (window.pollEvent(event)){
      //If the window is resized, make sure our new view is still proportional
      if(event.type==sf::Event::Resized){
		sf::FloatRect visibleArea(0,0,event.size.width, event.size.height);
		window.setView(sf::View(visibleArea));
      }

      if(event.type==sf::Event::KeyReleased){
		myPlayer.stop();
      }

      //If the window is closed, well, close the window
      if (event.type==sf::Event::Closed){
		window.close();
      }
    }

	window.clear();

	for(auto &it:npcs){
      it.show(window);
    }

	myPlayer.updateMovement();
	myPlayer.show(window);
	writing myText("This is a test", 50, 50);
	myText.show(window, text);
	window.draw(square);

    window.display();
  }

  return 0;
}

#ifndef NPC_H
#define NPC_H

#include "tiles.hpp"
#include "physics.hpp"

struct npc: public tile, public physics{
private:
  std::string name="";
  double speed=0.001;
  int maxSpeed=6;
  unsigned int runningSpeed=6;
public:
  unsigned int getSpeed(){
    return speed;
  }

  void setSpeed(unsigned int input){
    speed=input;
  }

  unsigned int getRunningSpeed(){
    return runningSpeed;
  }

  void setRunningSpeed(unsigned int input){
    runningSpeed=input;
  }

  void setName(std::string input){
    name=input;
  }

  sf::Vector2f movement={0, 0};
  bool running=0;

  virtual void up(){
	changeAcceleration(0, -1*(speed+(runningSpeed*running+1)));
  }

  virtual void down(){
	changeAcceleration(0, speed+(runningSpeed*running+1));
  }

  virtual void left(){
	changeAcceleration(-1*(speed+(runningSpeed*running+1)), 0);
  }

  void right(){
	changeAcceleration(speed+(runningSpeed*running+1), 0);
  }

  void stop(){
    movement.x=0;
    movement.y=0;
  }

  void updateMovement(){
	sf::Vector2f temp=updateVelocity();
	if(temp.x<-maxSpeed){
	  temp.x=-maxSpeed;
	}
	else if(temp.x>maxSpeed){
	  temp.x=maxSpeed;
	}
	if(temp.y<-maxSpeed){
	  temp.y=-maxSpeed;
	}
	else if(temp.y>maxSpeed){
	  temp.y=maxSpeed;
	}
	move(temp.x, temp.y);
    // if(movement.x<-maxSpeed){
    //   movement.x=-maxSpeed;
    // }
  }

  //Scaling is only ever used to flip the texture
  void scale(int t_x, int t_y){
    base.setScale(t_x, t_y);
  }

  // void say(std::string &input, sf::RenderWindow &window, const sf::Texture &font){
  //   writing output(input, getXPos()+15, getYPos()-20);
  //   output.show(window, font);
  // }

  npc(){
    base.setSize(sf::Vector2f(16, 16));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }

  npc(int t_x, int t_y){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }

  npc(int t_x, int t_y, std::string input){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
    name=input;
  }

  npc(std::string input){
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
    name=input;
  }
};

#endif

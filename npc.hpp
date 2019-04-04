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

  bool intersects(const tile& input){
	return base.getGlobalBounds().intersects(input.base.getGlobalBounds());
  }

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
	if(getVelocity().x<-maxSpeed){
	  setVelocity(-maxSpeed, 0);
	}
	else if(getVelocity().x>maxSpeed){
	  setVelocity(maxSpeed, 0);
	}
	if(getVelocity().y<-maxSpeed){
	  setVelocity(0, -maxSpeed);
	}
	else if(getVelocity().y>maxSpeed){
	  setVelocity(0, maxSpeed);
	}
	move(getVelocity().x, getVelocity().y);
	updateVelocity();
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
  }

  npc(int t_x, int t_y){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
  }

  npc(int t_x, int t_y, std::string input){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    name=input;
  }

  npc(std::string input){
    base.setSize(sf::Vector2f(16, 16));
    name=input;
  }
};

#endif

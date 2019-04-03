#ifndef PHYSICS_H
#define PHYSICS_H

class physics{
private:
  sf::Vector2f acceleration={};
  sf::Vector2f velocity={};
  double accX=0.0;
  double accY=0.0;
  double velX=0.0;
  double velY=0.0;
public:
  void changeAcceleration(const double x, const double y){
	acceleration.x=x;
	acceleration.y=y;
	velocity+=acceleration;
  }
  sf::Vector2f updateVelocity(){
	return velocity;
  }
};

#endif

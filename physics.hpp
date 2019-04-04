#ifndef PHYSICS_H
#define PHYSICS_H

class physics{
private:
  sf::Vector2f acceleration={};
  sf::Vector2f velocity={};
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

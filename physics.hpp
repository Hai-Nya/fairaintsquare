#ifndef PHYSICS_H
#define PHYSICS_H

class physics{
private:
  double accX=0.0;
  double accY=0.0;
  double velX=0.0;
  double velY=0.0;
public:
  void changeAcceleration(const double x, const double y){
	accX+=x;
	accY+=y;
	velX+=accX;
	velY=accY;
  }
  sf::Vector2f updateVelocity(){
	return sf::Vector2f(velX, velY);
  }
};

#endif

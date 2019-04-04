#ifndef PHYSICS_H
#define PHYSICS_H

class physics{
private:
  sf::Vector2f acceleration={};
  sf::Vector2f velocity={};
public:
  void changeAcceleration(const double x, const double y){
	acceleration.x+=x;
	acceleration.y+=y;
	velocity+=acceleration;
  }
  void updateVelocity(const double friction=0.2){
	acceleration.x=0;
	acceleration.y=0;
	if(velocity.x>0){
	  velocity.x-=friction;
	  if(velocity.x<0){
		velocity.x=0;
	  }
	}
	else if(velocity.x<0){
	  velocity.x+=friction;
	  if(velocity.x>0){
		velocity.x=0;
	  }
	}

	if(velocity.y>0){
	  velocity.y-=friction;
	  if(velocity.y<0){
		velocity.y=0;
	  }
	}
	else if(velocity.y<0){
	  velocity.y+=friction;
	  if(velocity.y>0){
		velocity.y=0;
	  }
	}
  }

  sf::Vector2f getVelocity() const {
	return velocity;
  }

  void setVelocity(const sf::Vector2f &input){
	velocity=input;
  }

  void setVelocity(const double x, const double y){
	velocity.x=x;
	velocity.y=y;
  }
};

#endif

#ifndef PLAYER_H
#define PLAYER_H

struct player: public npc{
private:

public:
  player(){
    base.setSize(sf::Vector2f(16, 16));
    base.setOrigin(8, 8);
  }

  player(int t_x, int t_y){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
    //Origin to center to facilitate texture flipping
    base.setOrigin(8, 8);
  }
};

#endif

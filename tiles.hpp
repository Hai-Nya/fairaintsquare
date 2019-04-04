#ifndef TILES_H
#define TILES_H

struct tile{
  sf::Texture texture;
  sf::RectangleShape base;

  int getXPos() const {
    return base.getPosition().x;
  }

  int getYPos() const {
    return base.getPosition().y;
  }

  sf::Vector2f getPosition() const {
	return base.getPosition();
  }

  sf::Vector2f getSize() const {
	return base.getSize();
  }

  void show(sf::RenderWindow &window){
    window.draw(base);
  }

  void setTexture(const std::string &&name, const int posX, const int posY, const int sizeX, const int sizeY){
    texture.loadFromFile(name);
    base.setTexture(&texture);
    base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
  }

  void setTexture(const sf::Texture texture, const int posX, const int posY, const int sizeX, const int sizeY){
    base.setTexture(&texture);
    base.setTextureRect(sf::IntRect(posX, posY, sizeX, sizeY));
  }

  void setColour(const unsigned int r, const unsigned int g, const unsigned int b){
	base.setFillColor(sf::Color(r, g, b));
  }

  void setColour(const sf::Color &colour){
	base.setFillColor(colour);
  }

  void setPosition(int t_x, int t_y){
    base.setPosition(sf::Vector2f(t_x, t_y));
  }

  void setPosition(const sf::Vector2f &input){
    base.setPosition(input);
  }

  void move(int t_x, int t_y){
    base.move(sf::Vector2f(t_x, t_y));
  }

  void move(sf::Vector2f &movement){
    base.move(movement);
  }

  tile(){
    base.setSize(sf::Vector2f(16, 16));
  }

  tile(unsigned int t_x, unsigned int t_y){
    base.setSize(sf::Vector2f(16, 16));
    base.move(sf::Vector2f(t_x, t_y));
  }
};

#endif

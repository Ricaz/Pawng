#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "GameObject.hpp"

class Player : public GameObject {
	public:
		Player(sf::Vector2f, sf::Keyboard::Key*);

		sf::RectangleShape rect;

		void Update(sf::Time);
		void moveUp();
		void moveDown();

	private:
		sf::Keyboard::Key* controls;
		sf::Vector2f position;
		sf::Vector2f velocity;
		float friction;
		float rotation;
};
#endif

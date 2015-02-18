#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "GameObject.hpp"
#include <iostream>

class Ball : public GameObject {
	public:
		Ball();
		
		void Update(sf::Time);
		void Reset();
		void HandleCollision(sf::FloatRect);

	private:
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Clock timer;
		void Score();
		bool ballWaiting;
};

#endif

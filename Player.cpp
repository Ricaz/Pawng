#include "Player.hpp" 
#include "GameObject.hpp"
#include <iostream>

Player::Player(sf::Vector2f pos, sf::Keyboard::Key keys[]) : controls(keys), position(pos) {
	velocity = sf::Vector2f(0, 0);	
	friction = .8f;
	// temporary until I find a proper way to get sprite height before it's loaded
	position.y = (Game::SCREEN_HEIGHT / 2) - 40;
}


void Player::Update(sf::Time elapsed) {
	if (sf::Keyboard::isKeyPressed(controls[0])) {
		velocity.y -= 100.0;
	}
	if (sf::Keyboard::isKeyPressed(controls[1])) {
		velocity.y += 100.0;
	}

	position += velocity * elapsed.asSeconds();
	velocity *= friction;

	if (position.y < 0 || position.y > Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height)
		velocity = -velocity;

	if (position.y < 0)
		position.y = 0;

	if (position.y > Game::SCREEN_HEIGHT - GetSprite().getLocalBounds().height)
		position.y = Game::SCREEN_HEIGHT - GetSprite().getLocalBounds().height;

	SetPosition(position.x, position.y);
}

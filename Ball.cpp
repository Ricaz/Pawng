#include "Ball.hpp"

Ball::Ball() {
	//Score();
	Reset();
}

void Ball::Reset() {
	ballWaiting = false;
	int velx = rand() % 2 == 1 ? 200 : -200;
	int vely = rand() % 400 - 200;

	velocity = sf::Vector2f(velx, vely);
	position = sf::Vector2f(Game::SCREEN_WIDTH / 2 - 10, Game::SCREEN_HEIGHT / 2 - 10);
}

void Ball::Score() {
	timer.restart();	
	ballWaiting = true;
	position = sf::Vector2f(Game::SCREEN_WIDTH / 2 - 10, Game::SCREEN_HEIGHT / 2 - 10);
	SetPosition(position.x, position.y);
}

void Ball::Update(sf::Time elapsed) {
	if (ballWaiting) {
		if (timer.getElapsedTime().asSeconds() > 3)
			Reset();
		return;
	}

	if (position.y < 0) {
		position.y = 0;
		velocity.y = -velocity.y;
	}
	if (position.y > Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height) {
		position.y = Game::SCREEN_HEIGHT - GetSprite().getGlobalBounds().height;
		velocity.y = -velocity.y;
	}

	if (position.x < 0 - GetSprite().getGlobalBounds().width) {
		Score();
	}
	if (position.x > Game::SCREEN_WIDTH) {
		Score();
	}

	position += velocity * elapsed.asSeconds();
	SetPosition(position.x, position.y);
}

void Ball::HandleCollision(sf::FloatRect foreignRect) {
	if (position.x < foreignRect.left)
		position.x = foreignRect.left - GetBounds().width;
	else
		position.x = foreignRect.left + foreignRect.width;

	velocity.x = -velocity.x;
}

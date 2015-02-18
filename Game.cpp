#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

// Sets up game and starts loop
void Game::Init(void) {

	if (gameState != Uninitialized)
		return;

	window.create(sf::VideoMode(720, 480), "Pawng!");

	sf::Keyboard::Key player1keys[] = { sf::Keyboard::W, sf::Keyboard::S };
	sf::Keyboard::Key player2keys[] = { sf::Keyboard::Up, sf::Keyboard::Down };
	Player *player1 = new Player(sf::Vector2f(20, 20), player1keys);
	Player *player2 = new Player(sf::Vector2f(690, 20), player2keys);
	player1->Load("player.png");
	player2->Load("player.png");
	Ball *ball = new Ball();
	ball->Load("ball.png");

	gameObjectManager.Add("Player 1", player1);
	gameObjectManager.Add("Player 2", player2);
	gameObjectManager.Add("Ball", ball);

	Load();

	gameState = Playing;

	// Main loop
	while (window.isOpen() && gameState != Exiting) {
		sf::Time elapsed = clock.restart();
		sf::Event event;

		while (window.pollEvent(event)) {
			switch(event.type) {
				case sf::Event::Closed:
					window.close();
					break;

				case sf::Event::KeyPressed:
					switch (event.key.code) {
						case sf::Keyboard::Escape:
						case sf::Keyboard::Q:
							window.close();
							gameState = Exiting;
							break;
						default:
							break;
					}

				default:
					break;
			}
		}

		switch (gameState) {
			case Game::Playing:
				Update(elapsed);
				Draw();
				break;

			default:
				break;
		}

	}
}

// Will load all game objects (textures)
void Game::Load() {
	// gameObjectManager.LoadAll();
}

// Will update all game objects
void Game::Update(sf::Time elapsed) {
	gameObjectManager.UpdateAll(elapsed);
}

// Will draw all game objects
void Game::Draw() {
	window.clear();
	gameObjectManager.DrawAll(window);
	window.display();
}

sf::RenderWindow& Game::GetWindow() {
	return window;
}

const GameObjectManager& Game::GetGameObjectManager() {
	return Game::gameObjectManager;
}

GameObjectManager Game::gameObjectManager;
Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::window;
sf::Clock Game::clock;

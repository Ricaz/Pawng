#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "GameObjectManager.hpp"
#include "Player.hpp"
#include "Ball.hpp"

class Game {
	public:
		const static int SCREEN_HEIGHT = 480;
		const static int SCREEN_WIDTH = 720;

		static void Init(void);
		static sf::RenderWindow& GetWindow();
		const static GameObjectManager& GetGameObjectManager();

	private:
		enum GameState {
			Loading,
			Uninitialized,
			Paused,
			Playing,
			ShowingMenu,
			Exiting
		};

		static GameObjectManager gameObjectManager;
		static GameState gameState;
		static sf::RenderWindow window;
		static sf::Clock clock;
		static void Load();
		static void Update(sf::Time);
		static void Draw();
};
#endif

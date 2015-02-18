#ifndef GAMEOBJECTMANAGER
#define GAMEOBJECTMANAGER

#include "GameObject.hpp"
#include <string.h>
#include <iostream>

class GameObjectManager {
	public:
		GameObjectManager();
		~GameObjectManager();

		void Add(std::string name, GameObject* gameObject);
		void Remove(std::string name);
		int Count() const;
		GameObject* Get(std::string name) const;

		void DrawAll(sf::RenderWindow& renderWindow);
		void UpdateAll(sf::Time);

	private:
		std::map<std::string, GameObject*> gameObjects;
		sf::Clock clock;

		struct GameObjectDeallocator {
			void operator()(const std::pair<std::string, GameObject*> & p) const {
				delete p.second;
			}
		};
};

#endif

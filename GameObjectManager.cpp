#include "GameObjectManager.hpp"
#include "Game.hpp"

GameObjectManager::GameObjectManager() { }

GameObjectManager::~GameObjectManager() {
	std::for_each(gameObjects.begin(), gameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, GameObject* gameObject) {
	gameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name) {
	std::map<std::string, GameObject*>::iterator results = gameObjects.find(name);
	if (results != gameObjects.end()) {
		delete results->second;
		gameObjects.erase(results);
	}
}

GameObject* GameObjectManager::Get(std::string name) const {
	std::map<std::string, GameObject*>::const_iterator results = gameObjects.find(name);
	if (results == gameObjects.end())
		return NULL;
	return results->second;
}

int GameObjectManager::Count() const {
	return gameObjects.size();
}

void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow) {
	std::map<std::string, GameObject*>::const_iterator itr = gameObjects.begin();
	while (itr != gameObjects.end()) {
		itr->second->Draw(renderWindow);
		itr++;
	}
}

void GameObjectManager::UpdateAll(sf::Time elapsedTime) {
	for (std::map<std::string, GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		it->second->Update(elapsedTime);

		sf::FloatRect localRect = it->second->GetBounds();
		for (std::map<std::string, GameObject*>::iterator it2 = gameObjects.begin(); it2 != gameObjects.end(); ++it2) {
			if (it->first == it2->first)
				continue;

			sf::FloatRect foreignRect = it2->second->GetBounds();
			if (localRect.intersects(foreignRect))
				it->second->HandleCollision(foreignRect);
		}
	}
}

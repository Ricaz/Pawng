#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.hpp"

GameObject::GameObject() {
	isLoaded = false;
}

GameObject::~GameObject() {

}

bool GameObject::IsLoaded() {
	return isLoaded;
}

void GameObject::Load(std::string filename) {
	if (!texture.loadFromFile(filename)) {
		isLoaded = false;
	} else {
		isLoaded = true;
	}

	if (isLoaded) {
		texture.setSmooth(true);
		sprite.setTexture(texture);
	}
}

void GameObject::SetPosition(float x, float y) {
	if (isLoaded)
		sprite.setPosition(x, y);
}

void GameObject::SetRotation(float r) {
	if (isLoaded)
		sprite.setRotation(r);
}

sf::FloatRect GameObject::GetBounds() {
	return sprite.getGlobalBounds();
}

sf::Sprite& GameObject::GetSprite() {
	return sprite;
}

void GameObject::Update(sf::Time elapsed) { }

void GameObject::HandleCollision(sf::FloatRect) { }

void GameObject::Draw(sf::RenderWindow& window) {
	if (isLoaded)
		window.draw(sprite);
}

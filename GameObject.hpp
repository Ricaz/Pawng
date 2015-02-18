#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <string>

class GameObject : public sf::Drawable {
	public:
		GameObject();
		~GameObject();
		virtual void Load(std::string);
		virtual void Update(sf::Time);
		virtual void Draw(sf::RenderWindow&);
		virtual void SetPosition(float, float);
		virtual void SetRotation(float);
		virtual void HandleCollision(sf::FloatRect);

		virtual bool IsLoaded();
		virtual sf::FloatRect GetBounds();

	protected:
		sf::Sprite& GetSprite();

	private:
		bool isLoaded;

		sf::Sprite sprite;
		sf::Texture texture;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const {
			target.draw(sprite, states);
		}
};
#endif

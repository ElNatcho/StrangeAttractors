#include<iostream>
#include<SFML\Graphics.hpp>

int main() {
	sf::RenderWindow *window  = new sf::RenderWindow(sf::VideoMode(600, 400), "Strange Attractors v.1");
	sf::Event        *sfEvent = new sf::Event();

	while (window->isOpen()) {
		while (window->pollEvent(*sfEvent)) {
			if (sfEvent->type == sf::Event::Closed)
				window->close();
			if (sfEvent->type == sf::Event::KeyReleased)
				if (sfEvent->key.code == sf::Keyboard::Escape)
					window->close();
		}

		window->clear();


		window->display();
	}

	return 0;
}
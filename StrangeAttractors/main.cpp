#include<iostream>
#include<SFML\Graphics.hpp>
#include"CAttractors.hpp"

int main() {
	sf::RenderWindow *window  = new sf::RenderWindow(sf::VideoMode(600, 400), "Strange Attractors v.1");
	sf::Event        *sfEvent = new sf::Event();

	CAttractors *attr = new CAttractors();
	attr->addAttractor(sf::Vector2f(200.F, 200.F));
	attr->addAttractor(sf::Vector2f(200.F, 300.F), 10.F, sf::Color::Green);
	attr->addAttractor(sf::Vector2f(300.F, 200.F), 20.F, sf::Color::Blue);

	while (window->isOpen()) {
		while (window->pollEvent(*sfEvent)) {
			if (sfEvent->type == sf::Event::Closed)
				window->close();
			if (sfEvent->type == sf::Event::KeyReleased)
				if (sfEvent->key.code == sf::Keyboard::Escape)
					window->close();
		}

		window->clear();

		attr->render(*window);

		window->display();
	}

	return 0;
}
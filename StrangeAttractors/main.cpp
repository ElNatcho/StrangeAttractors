#include<iostream>
#include<stdio.h>
#include<SFML\Graphics.hpp>
#include"CAttractors.hpp"

int main() {
	srand(time(0));

	sf::RenderWindow *window  = new sf::RenderWindow(sf::VideoMode(800, 800), "Strange Attractors v.1");
	sf::Event        *sfEvent = new sf::Event();

	CAttractors *attr = new CAttractors();
	
	attr->addShape(5, 400.F, sf::Vector2f(400.F, 400.F));
	attr->dot->setRadius(1.F);

	while (window->isOpen()) {
		while (window->pollEvent(*sfEvent)) {
			if (sfEvent->type == sf::Event::Closed)
				window->close();
			if (sfEvent->type == sf::Event::KeyReleased)
				if (sfEvent->key.code == sf::Keyboard::Escape)
					window->close();
		}

		window->clear();

		attr->hop();
		attr->render(*window);

		window->display();
	}

	return 0;
}
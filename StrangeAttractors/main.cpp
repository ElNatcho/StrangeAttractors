#include<iostream>
#include<stdio.h>
#include<SFML\Graphics.hpp>
#include<imgui-sfml-master/imconfig-SFML.h>
#include<imgui.h>
#include"CAttractors.hpp"
#include"CGUI.hpp"

int main() {
	srand(time(0));

	// Fenster, etc. erzeugen
	sf::RenderWindow *window  = new sf::RenderWindow(sf::VideoMode(1300, 800), "Strange Attractors v.1");
	sf::Event        *sfEvent = new sf::Event();

	// ImGui initialisieren
	ImGui::SFML::Init(*window);

	// Attractors erzeugen
	CAttractors *attr = new CAttractors();

	// GUI erstellen
	CGUI *gui = new CGUI(attr);

	// DeltaClock erzeugen
	sf::Clock *deltaClock = new sf::Clock();

	while (window->isOpen()) { // Main_Prog Loop
		while (window->pollEvent(*sfEvent)) { // Events abfangen
			ImGui::SFML::ProcessEvent(*sfEvent);

			if (sfEvent->type == sf::Event::Closed)
				window->close();
			if (sfEvent->type == sf::Event::KeyReleased)
				if (sfEvent->key.code == sf::Keyboard::Escape)
					window->close();
			if (sfEvent->type == sf::Event::Resized) {
				window->setView(sf::View(sf::FloatRect(0, 0, sfEvent->size.width, sfEvent->size.height)));
			}
		}
		// ImGui updaten
		ImGui::SFML::Update(*window, deltaClock->restart());

		// Objekte zeichnen
		window->clear(sf::Color(5, 82, 139));

		if (gui->showGUI(*window, attr))

		attr->render(*window);

		ImGui::SFML::Render(*window);
		window->display();
	}

	ImGui::SFML::Shutdown();

	// Free Mem
	SAFE_DELETE(gui);
	SAFE_DELETE(attr);
	SAFE_DELETE(window);
	SAFE_DELETE(sfEvent);
	SAFE_DELETE(deltaClock);

	return 0;
}
#include"CAttractors.hpp"

// -- Konstruktor --
CAttractors::CAttractors() {
	// Alloc Mem
	_attractors = new std::vector<sf::CircleShape>();
}

// Methode setzt den Attractors-Vector zurück
//
void CAttractors::reset() {
	_attractors->clear();
}

// Methode fügt einen Attractor hinzu
// @param pos: Position des Attractors
// @param rad: Radius des Attractors
// @param col: Farbe des Attractors
//
void CAttractors::addAttractor(sf::Vector2f &pos, float rad, sf::Color col) {
	_attractors->push_back(sf::CircleShape());
	_attractors->at(_attractors->size() - 1).setPosition(pos);
	_attractors->at(_attractors->size() - 1).setRadius(rad);
	_attractors->at(_attractors->size() - 1).setFillColor(col);
}

// Methode rendert die Attractors 
// @param rWin: Aktuelles Fenster
//
void CAttractors::render(sf::RenderWindow &rWin) {
	for (int i = 0; i < _attractors->size(); i++) {
		rWin.draw(_attractors->at(i));
	}
}

// -- Destruktor --
CAttractors::~CAttractors() {
	// Free Mem
	_attractors->clear();
	SAFE_DELETE(_attractors);
}
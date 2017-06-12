#include"CAttractors.hpp"

// -- Konstruktor --
CAttractors::CAttractors() {
	// Alloc Mem
	_attractors = new std::vector<sf::CircleShape>();
	tracePoint = new sf::CircleShape();
	_dots = new std::vector<sf::CircleShape>();
	dot = new sf::CircleShape();

	// Werte setzen
	tracePoint->setFillColor(sf::Color::Green);
	tracePoint->setRadius(4.F);

	dot->setFillColor(sf::Color::Blue);
	dot->setRadius(2.F);
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

// Methode fügt eine bestimmte Anzahl Attractors in einer bestimmten Form hinzu
// @param edges    : Anzahl der Ecken
// @param shape_rad: Radius der Form
// @param pos      : Position der Form (Mittelpunk)
// @param rad      : Radius der Attractors
// @param col      : Farbe der Attractors
//
void CAttractors::addShape(int edges, float shape_rad, sf::Vector2f &pos, float rad, sf::Color col) {
	tracePoint->setPosition(pos);
	for (int i = 0; i < edges; i++) {
		addAttractor(sf::Vector2f(std::cos(((360.F / edges) * i) * PI / 180.F) * shape_rad + pos.x, 
								  std::sin(((360.F / edges) * i) * PI / 180.F) * shape_rad + pos.y),
					 rad,
					 col);	
	}
}

// Methode führt einen Hop durch (Der TracePoint wird von einem Attractor zufällig angezogen)
//
void CAttractors::hop() {
	_dots->push_back(sf::CircleShape(*dot));
	_dots->at(_dots->size() - 1).setPosition(tracePoint->getPosition());
	int i = rand() %  _attractors->size();
	tracePoint->move(
		(_attractors->at(i).getPosition().x - tracePoint->getPosition().x) * 0.6,
		(_attractors->at(i).getPosition().y - tracePoint->getPosition().y) * 0.6);
}

// Methode rendert die Attractors 
// @param rWin: Aktuelles Fenster
//
void CAttractors::render(sf::RenderWindow &rWin) {
	rWin.draw(*tracePoint);
	for (int i = 0; i < _attractors->size(); i++) {
		rWin.draw(_attractors->at(i));
	}
	for (int i = 0; i < _dots->size(); i++) {
		rWin.draw(_dots->at(i));
	}
}

// -- Destruktor --
CAttractors::~CAttractors() {
	// Free Mem
	_attractors->clear();
	SAFE_DELETE(_attractors);
}
#ifndef CATTRACTORS_HPP
#define CATTRACTORS_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<vector>
#include<cmath>
#include"Common.hpp"

// CAttractors
class CAttractors {
public:

	// -- Kon/Destruktor --
	CAttractors();
	~CAttractors();

	// -- Methoden --
	void reset();
	void addAttractor(sf::Vector2f &pos, float rad = 5.F, sf::Color col = sf::Color::Red);

	void render(sf::RenderWindow &rWin);

private:

	// -- Member Vars --
	std::vector<sf::CircleShape> *_attractors;
	sf::CircleShape *_tempCir;

};

#endif
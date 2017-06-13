#ifndef CATTRACTORS_HPP
#define CATTRACTORS_HPP

// Includes
#include<SFML\Graphics.hpp>
#include<vector>
#include<cmath>
#include"Common.hpp"

#define PI 3.141592653589793

// CAttractors
class CAttractors {
public:

	// -- Kon/Destruktor --
	CAttractors();
	~CAttractors();

	// -- Methoden --
	void reset();
	void addAttractor(sf::Vector2f &pos, float rad = 2.F, sf::Color col = sf::Color::Red);
	void addShape(int edges, float shape_rad, sf::Vector2f &pos, float rad = 2.F, sf::Color col = sf::Color::Red);
	
	void setEdgeColor(sf::Color &col);
	void setEdgeRadius(float r);

	void hop(float relDist);

	void setDotColor(sf::Color &col);
	void setDotRadius(float r);

	void render(sf::RenderWindow &rWin);

	// -- Public Vars --
	sf::CircleShape *tracePoint;
	sf::CircleShape *dot;

private:

	// -- Member Vars --
	std::vector<sf::CircleShape> *_attractors;
	sf::CircleShape *_tempCir;

	std::vector<sf::CircleShape> *_dots;

};

#endif
#pragma once
#include"ElipseShape.h"
#include"SFML/Graphics.hpp"

class Oblak
{
public:
	Oblak();
	Oblak(sf::RenderWindow * window);
	Oblak(sf::RenderWindow * window, float x, float y, float brzina);

	void set_parametre(float x, float y, float brzina);
	void draw();

private:
	sf::RenderWindow *window;

	void drawOblak();
	void oblak_();
	void koordinate();
	void set_pocetneVrijednosti();

	EllipseShape oblacic{ sf::Vector2f(35.f, 18.f) };
	EllipseShape oblak[6];

	float lijevaPozicijaOblaka[6];
	float desnaPozicijaOblaka[6];
	
	float brzina;
	float totalTime;
	float deltaTime;
	float ciklus;

	float x;
	float y;

	sf::Clock clock;

};
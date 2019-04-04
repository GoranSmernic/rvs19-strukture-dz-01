#pragma once
#include <SFML/Graphics.hpp>
#include"ElipseShape.h"
#include"Oblak.h"

class Cvijet
{
public:

	Cvijet(sf::RenderWindow *window);
	void draw();

private:
	
	sf::RenderWindow *window;
	sf::CircleShape tucak;
	sf::RectangleShape stabljika;
	sf::RectangleShape trava;
	EllipseShape listLijevo{ sf::Vector2f(70.f, 25.f) };
	EllipseShape listDesno{ sf::Vector2f(65.f, 20.f) };
	EllipseShape latica{sf::Vector2f(65.f, 20.f)};
	EllipseShape latice[16];
	sf::CircleShape vanjskiKvadratSunca;
	sf::CircleShape krugSunca;
	EllipseShape zrakaSunca{ sf::Vector2f(95.f, 45.f) };
	EllipseShape zrakeSunca[5];
	sf::CircleShape brdo;

	void set_tucak();
	void set_latica();
	void set_stabljika();
	void set_listLijevo();
	void set_listDesno();
	void set_positionLatica();
	void set_trava();
	void set_sunce();
	void set_oblaci();
	void animacijaSunca();
	void draw_cvijet();
	void set_pocetneVrijednosti();
	void set_brdo();
	void set_stablo();

	int length = 16;
	int lengthOblak = 20;
	Oblak oblak[20];

	float visina;
	float sirina;

	int bojaSunca;

	float totalTime;
	float deltaTime;
	float ciklus;

	bool provjera;
	bool provjeraBoje;

	sf::Clock clock;
};


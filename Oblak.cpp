#include "Oblak.h"
#include"ElipseShape.h"
#include"SFML/Graphics.hpp"

Oblak::Oblak()
{
	set_pocetneVrijednosti();
	oblak_();
	koordinate();
}

Oblak::Oblak(sf::RenderWindow * window)
{
	this->window = window;

	set_pocetneVrijednosti();
	oblak_();
	koordinate();
}

Oblak::Oblak(sf::RenderWindow * window, float x, float y, float brzina)
{
	this->window = window;

	set_pocetneVrijednosti();

	this->x = x;
	this->y = y;
	this->brzina = brzina;

	oblak_();
	koordinate();
}

void Oblak::set_parametre(float x, float y, float brzina)
{
	this->x = x;
	this->y = y;
	this->brzina = brzina;

	oblak_();
	koordinate();
}

void Oblak::draw()
{
	deltaTime = clock.restart().asSeconds();
	drawOblak();
}

void Oblak::drawOblak()
{
	totalTime += deltaTime;

	if (totalTime >= ciklus)
	{
		totalTime -= ciklus;
	}

	else if (totalTime >= 0.01f) {
		totalTime -= 0.01f;

		for (int i = 0; i < 6; i++)
		{
			oblak[i].setPosition(lijevaPozicijaOblaka[i], desnaPozicijaOblaka[i]);
			lijevaPozicijaOblaka[i] += brzina;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		window->draw(oblak[i]);

	if (lijevaPozicijaOblaka[i]>=2000.f)
	{
		lijevaPozicijaOblaka[i] = -800.f;
	}
	}
}

void Oblak::oblak_()
{
	oblacic.setFillColor(sf::Color(200, 200, 200));

	for (int i = 0; i < 6; i++)
	{
		oblak[i] = oblacic;
	}

	lijevaPozicijaOblaka[0] = 2.f;
	desnaPozicijaOblaka[0] = 50.f;

	lijevaPozicijaOblaka[1] = 20.f;
	desnaPozicijaOblaka[1] = 35.f;

	lijevaPozicijaOblaka[2] = 50.f;
	desnaPozicijaOblaka[2] = 35.f;

	lijevaPozicijaOblaka[3] = 20.f;
	desnaPozicijaOblaka[3] = 70.f;

	lijevaPozicijaOblaka[4] = 50.f;
	desnaPozicijaOblaka[4] = 70.f;

	lijevaPozicijaOblaka[5] = 70.f;
	desnaPozicijaOblaka[5] = 50.f;

}

void Oblak::koordinate()
{
	for (int i = 0; i < 6; i++)
	{
		lijevaPozicijaOblaka[i] += x;
		desnaPozicijaOblaka[i] += y;
	}
}

void Oblak::set_pocetneVrijednosti()
{
	ciklus = 10.f;
	totalTime = 0.f;
	deltaTime = 0.f;
	brzina = 0.45f;
	x = 0.f;
	y = 0.f;
}

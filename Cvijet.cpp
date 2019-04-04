#include "Cvijet.h"
#include <SFML/Graphics.hpp>
#include"ElipseShape.h"
#include"Oblak.h"

Cvijet::Cvijet(sf::RenderWindow * window)
{
	this->window = window;

	set_pocetneVrijednosti();
	draw_cvijet();
}

void Cvijet::draw()
{
	window->draw(vanjskiKvadratSunca);
	window->draw(krugSunca);

	deltaTime = clock.restart().asSeconds();

	animacijaSunca();

	for (int i = 0; i < 5; i++)
	{
		window->draw(zrakeSunca[i]);
	}

	for (int i = 0; i < lengthOblak; i++)
	{
		oblak[i].draw();
	}
	window->draw(brdo);

	window->draw(trava);
	window->draw(listDesno);
	window->draw(listLijevo);
	window->draw(stabljika);

	for (int i = 0; i < length; i++)
	{
	window->draw(latice[i]);
	}

	window->draw(tucak);
}

void Cvijet::set_tucak()
{
	tucak.setFillColor(sf::Color::Yellow);
	tucak.setRadius(70);
	tucak.setPosition(200.f, 320.f);
}

void Cvijet::set_latica()
{
	latica.setFillColor(sf::Color(250,0,0));

	for (int i = 0; i < length; i++)
	{
		latice[i] = latica;
	}

	set_positionLatica();
}

void Cvijet::set_stabljika()
{
	stabljika.setFillColor(sf::Color::Green);
	stabljika.setSize(sf::Vector2f(20.f, 240.f));
	stabljika.setPosition(265.f, 500.f);
}

void Cvijet::set_listLijevo()
{
	listLijevo.setFillColor(sf::Color::Green);
	listLijevo.setOutlineColor(sf::Color(0, 180, 0));
	listLijevo.setOutlineThickness(4.0f);
	listLijevo.rotate(50);
	listLijevo.setPosition(sf::Vector2f(200.f, 510.f));
}

void Cvijet::set_listDesno()
{
	listDesno.setFillColor(sf::Color::Green);
	listDesno.setOutlineColor(sf::Color(0, 180, 0));
	listDesno.setOutlineThickness(4.0f);
	listDesno.rotate(140);
	listDesno.setPosition(sf::Vector2f(390.f, 600.f));
}

void Cvijet::set_positionLatica()
{
	latice[0].setPosition(90.f, 369.f);
	latice[1].setPosition(315.f, 368.f);

	latice[2].setRotation(90);
	latice[3].setRotation(90);

	latice[2].setPosition(289.f, 424.f);
	latice[3].setPosition(289.f, 226.f);

	latice[4].setRotation(45);
	latice[5].setRotation(45);

	latice[4].setPosition(160.f, 250.f);
	latice[5].setPosition(315.f, 405.f);

	latice[6].setRotation(135);
	latice[7].setRotation(135);

	latice[6].setPosition(245.f, 435.f);
	latice[7].setPosition(405.f, 285.f);

	latice[8].setRotation(67);
	latice[9].setRotation(67);

	latice[8].setPosition(225.f, 230.f);
	latice[9].setPosition(300.f, 410.f);

	latice[10].setRotation(22);
	latice[11].setRotation(22);

	latice[10].setPosition(110.f, 302.f);
	latice[11].setPosition(310.f, 385.f);

	latice[12].setRotation(112);
	latice[13].setRotation(112);

	latice[12].setPosition(268.f, 435.f);
	latice[13].setPosition(350.f, 250.f);

	latice[14].setRotation(156);
	latice[15].setRotation(156);

	latice[14].setPosition(235.f, 420.f);
	latice[15].setPosition(440.f, 338.f);

}

void Cvijet::set_trava()
{
	trava.setFillColor(sf::Color(0, 140, 0));
	trava.setSize(sf::Vector2f(1000.0f, 400.0f));
	trava.setPosition(000.0f, 700.0f);
}

void Cvijet::set_sunce()
{
	vanjskiKvadratSunca.setRadius(300);
	vanjskiKvadratSunca.setFillColor(sf::Color(240, 0, 0));
	vanjskiKvadratSunca.setPosition(720, -350);

	krugSunca.setRadius(200);
	krugSunca.setFillColor(sf::Color::Yellow);
	krugSunca.setPosition(850, -250);

	zrakaSunca.setFillColor(sf::Color(0, 0, 255));
	
	for (int i = 0; i < 5; i++)
	{
		zrakeSunca[i] = zrakaSunca;
	}

	zrakeSunca[0].setPosition(910, 140);
	zrakeSunca[0].setRotation(135);

	zrakeSunca[1].setPosition(855, 105);
	zrakeSunca[1].setRotation(150);

	zrakeSunca[2].setPosition(960, 175);
	zrakeSunca[2].setRotation(120);

	zrakeSunca[3].setPosition(1020, 195);
	zrakeSunca[3].setRotation(105);

	zrakeSunca[4].setPosition(823, 55);
	zrakeSunca[4].setRotation(165);

}

void Cvijet::set_oblaci()
{
	Oblak oblak1(window);

	for (int i = 0; i < lengthOblak; i++)
	{
	oblak[i] = oblak1;
	}

	oblak[0].set_parametre(150, 10, 0.2f);
	oblak[1].set_parametre(150, 30, 0.2f);
	oblak[2].set_parametre(400, -13, 0.22f);
	oblak[3].set_parametre(600, 100, 0.23f);
	oblak[4].set_parametre(900, -30, 0.1f);
	oblak[5].set_parametre(-600, 5, 0.2f);
	oblak[6].set_parametre(-810, 25, 0.2f);
	oblak[7].set_parametre(-300, -50, 0.305f); 
	oblak[8].set_parametre(-150, 130, 0.2f);
	oblak[9].set_parametre(-250, 30, 0.2f);
	oblak[10].set_parametre(-400, -13, 0.2f);
	oblak[11].set_parametre(660, 100, 0.23f);
	oblak[12].set_parametre(-990, -30, 0.17f);
	oblak[13].set_parametre(-900, -10, 0.21f);
	oblak[14].set_parametre(-830, 25, 0.2f);
	oblak[15].set_parametre(-300, 60, 0.36f);
	oblak[16].set_parametre(150, 10, 0.2f);
	oblak[17].set_parametre(150, 32, 0.2f);
	oblak[18].set_parametre(-400, -33, 0.2f);
	oblak[19].set_parametre(-600, 120, 0.21f);
}

void Cvijet::animacijaSunca()
{
	totalTime += deltaTime;

			if (provjeraBoje == true)
			{
				bojaSunca--;

				if (bojaSunca <= 190)
				{
					provjeraBoje = false;
				}
			}
			else
			{
				bojaSunca++;

				if (bojaSunca >= 253)
				{
					provjeraBoje = true;
				}
			}

	if (totalTime >= ciklus)
	{
		totalTime -= ciklus;
	}

	else if (totalTime >= 0.01f) {

		totalTime -= 0.01f;

		if (visina >= 91.7f && provjera == true)
		{
			visina -= 0.028f;
			sirina -= 0.028f;

			for (int i = 0; i < 5; i++)
			{
				zrakeSunca[i].setRadius(sf::Vector2f(visina, sirina));
				vanjskiKvadratSunca.setFillColor(sf::Color(bojaSunca, 0, 0));
			}

			if (visina <= 92.1f)
			{
				provjera = false;
			}
		}

		else {

			visina += 0.06f;
			sirina += 0.06f;
			bojaSunca--;

			for (int i = 0; i < 5; i++)
			{
				zrakeSunca[i].setRadius(sf::Vector2f(visina, sirina));
				vanjskiKvadratSunca.setFillColor(sf::Color(bojaSunca, 0, 0));
			}
			if (visina >= 101.f)
			{
				provjera = true;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		window->draw(zrakeSunca[i]);
	}
}

void Cvijet::draw_cvijet()
{
	set_oblaci();
	set_sunce();
	animacijaSunca();
	set_brdo();
	set_trava();
	set_listLijevo();
	set_listDesno();
	set_stabljika();
	set_tucak();
	set_latica();
}

void Cvijet::set_pocetneVrijednosti()
{
	visina = 95.f;
	sirina = 45.f;

	totalTime = 0.f;
	deltaTime = 0.f;
	ciklus = 10.f;

	bojaSunca = 150;
	provjeraBoje = true;
	provjera = true;
}

void Cvijet::set_brdo()
{
	brdo.setFillColor(sf::Color(0, 180, 0));
	brdo.setPosition(450.f, 530.f);
	brdo.setRadius(400);
}

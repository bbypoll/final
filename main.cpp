#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "inc/class.h"

using namespace sf;

int main()
{
	const int w = 1160;
	const int h = 760;

	Texture background;
	background.loadFromFile("img/fire.jpg");
	Sprite back(background);


	RenderWindow window(VideoMode(w, h), "O neeeeet!!!");
	Clock clock;

	Music music;//������� ������ ������
	music.openFromFile("sound/music.ogg");//��������� ����
	music.play();//������������� ������
	music.setLoop(true);

	chel huggywuggy(150, 600, "HugguWuggy.png");


	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			huggywuggy.dir = 0;//����������� �����
			huggywuggy.speed = 0.8;

		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			huggywuggy.dir = 1;//����������� ������
			huggywuggy.speed = 0.8;

		}

		huggywuggy.dvig(time, w, h);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������


		window.clear();
		window.draw(back);

		window.draw(huggywuggy.huggywuggy);
		window.display();

	}
	return 0;

}
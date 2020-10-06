#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
#include"Player.h"
#include "Source.h"
static const float VIEW_HEIGHT = 512.0f;
void ResizeView(sf::RenderWindow& window, sf::View& view) {
	float aspectRatio = float(window.getSize().x / float(window.getSize().y));
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main() {
	sf::RenderWindow window(sf::VideoMode(512, 512), "Bang Bang You Die!!!", sf::Style::Close | sf::Style::Resize | sf::Style::Titlebar);
	sf::View view(sf::Vector2f(0.0f, 0.0f),sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("sprite001.png");


	Player player(&playerTexture, sf::Vector2u(32,25),0.3f,100.0f);
	float delTatime = 0.0f;
	sf::Clock clock;

	 

	while (window.isOpen()) 
{
		delTatime =clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
				}
			}
			view.setCenter(player.GetPosition());
			player.Update(delTatime);

			window.clear(sf::Color::Black);
			window.setView(view);
			player.Draw(window);
			window.display();
		}
	return 0;

}

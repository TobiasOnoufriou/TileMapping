#include "Core.h"
#include "Player.h"
#include "World.h"
#include "HealthBar.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>


int main() {
	sf::Clock clock;
	sf::Mouse mousePosChecker;
	sf::Vector2i mousePos;
	sf::Vector2i secondMousePos;

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "2D Engine",sf::Style::Default);
	sf::View gameTableView(sf::FloatRect(0.f, 0.f, window->getSize().x, window->getSize().y));
	sf::View healthBarView(sf::FloatRect(0.f,0.f, 250.f, 250.f));
	gameTableView.setViewport(sf::FloatRect(0, 0, 1.f, 1.f));
	healthBarView.setViewport(sf::FloatRect(0.85f, 0.9f, 0.3f, 0.3f));
	Player* m_Charcter = new Player();
	World* m_World = new World(10);
	HealthBar Bar = HealthBar();

	Core coreEngine = Core(window, window->getSize().x, window->getSize().y,false); 
	sf::RectangleShape shape;
	while (window->isOpen()) {
		double delta = clock.restart().asSeconds();
		sf::Event events;
		while (window->pollEvent(events)) {
			if (events.type == sf::Event::Closed) {
				window->close();
			}
			if (events.type == sf::Event::Resized) {
				sf::View areaVisible(sf::FloatRect(0, 0, events.size.width, events.size.height));
				//window->setView(areaVisible);
			}
		}
		/*mousePos = mousePosChecker.getPosition(*window);
		if (secondMousePos != mousePos) {
			std::cout << "X Pos: " << mousePos.x << std::endl;
			std::cout << "Y Pos: " << mousePos.y << std::endl;
			
		}
		secondMousePos = mousePos;*/

		m_World->worldLoop(m_Charcter->getPlayerSprite());
		m_Charcter->playerMovement(delta,m_World->getBattlemode());
		window->clear();
		//window->setView(gameTableView);
		window->draw(coreEngine);
		window->draw(*m_World);
		window->draw(*m_Charcter);
		//window->setView(healthBarView);
		window->draw(Bar);
		window->display();
		//window->setActive(false);
	}
	return 0;
}

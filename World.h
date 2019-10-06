#pragma once
#include <sfml/Graphics.hpp>
#include <random>
#include "SpriteRectangle.h"
#include "Animals.h"
#include "Core.h"

//Procedural Pokemon

class World : public sf::Drawable, public sf::Transformable, public Animal {
	public:
		World(int tileMap) {
			this->oldTime = 0;
			this->newTime = 0;
			this->m_timer = 0;
			this->m_timerMax = 1;
			bushTexture.loadFromFile("bushPlaceholder.png");
			battleMode = false;
			worldGen();
		}
		~World() {

		}
		bool getBattlemode() {
			return this->battleMode;
		}
		void worldDetection(SpriteRectangle player) {
			int chance = 30;
			for(int i = 0; i < m_Num_Bushes; i++) {
				if (m_BushArray[i].spriteRectangle.intersects(player.spriteRectangle)) {
					std::srand(std::rand() % 34212);
					int dice = std::rand() % 100;
					std::cout << dice << std::endl;
					if (dice <= chance) {
						std::cout << "Entering Battle" << std::endl;
						battleMode = true;
						battleStage(battleMode);
						break;
					}
					else {
						battleMode = false;
						break;
					}

				}
			}
		}
		
		void battleStage(bool battleMode) {
			setAnimalType('e');
			setIsEnemy(true);
			setLevel(/*getPlayerLevel()*/1);
			switch (getAnimalType()) {
				case 'f':
					break;
				case 'w':
					break;
				case 'e':
					break;
				case 'm':
					break;
				default:
					std::cout << "Bugged ass game talk to the developers" << std::endl;
					setAnimalType('e'); //This would be a defualt value.
			}
		}
		void worldLoop(SpriteRectangle player) {

			this->oldTime = this->newTime;
			this->newTime = time.getElapsedTime().asSeconds();
			
			if (m_timer >= m_timerMax) {
				battleStage(true);
				worldDetection(player);
				m_timer = 0;
			}
			
			
			
			m_delta = (newTime - oldTime);
			m_timer += m_delta;
		}
		void worldGen() {
			//100 Bushes.
			int xPos, yPos;
			std::srand(std::rand() % 2423424245);
			m_Num_Bushes = std::rand() % 100;
			SpriteRectangle tempBush;
			tempBush.sprite.setTexture(bushTexture);
			//tempBush.sprite.setScale(sf::Vector2f(0.5f, 0.5f));
			for (int i = 0; i <= m_Num_Bushes; i++) {
				sf::RectangleShape tempRect;
				xPos = std::rand() % 600;
				yPos = std::rand() % 800;
 				tempBush.sprite.setPosition(xPos, yPos);
				
				tempRect.setPosition(xPos, yPos);
				tempRect.setOutlineThickness(1.0f);
				tempRect.setOutlineColor(sf::Color::Red);
				tempRect.setSize(sf::Vector2f(10, 10));


				tempBush.spriteRectangle.left = xPos;
				tempBush.spriteRectangle.top = yPos;
				tempBush.spriteRectangle.height = 10;
				tempBush.spriteRectangle.width = 10;


				rect.push_back(tempRect);
				m_BushArray.push_back(tempBush);
			}
		}
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			for (int i = 0; i <= m_BushArray.size() - 1; i++) {
				target.draw(m_BushArray[i].sprite);
				target.draw(rect[i]);
			}
		}
	private:

		std::vector<SpriteRectangle> m_BushArray;
		sf::Texture bushTexture;
		std::vector<sf::RectangleShape> rect;
		sf::Clock time;
		bool battleMode;
		int m_Num_Bushes;
		int m_num_buildings;
		float m_delta, newTime, oldTime;
		float m_timer, m_timerMax;

};
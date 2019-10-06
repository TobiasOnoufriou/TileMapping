#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

class Core : public sf::Transformable, public sf::Drawable {
	public:
		Core(sf::RenderWindow* m_win, int x, int y, bool proceduralGen);
		~Core();
		bool readTextFiles(std::string fileName);
		void initTable(int xSize, int ySize);
		void initTileMap();
		bool readTileMap();
		void onInit();
		void onUpdate();
		void onDraw();
		void mainLoop();
		void perlinTerrain();
		bool loadTextures();
	
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			states.transform *= getTransform();

			//target.draw(shrek, states);
			if (proceduralGen) {
				for (int i = 0; i < mapSize*mapSize; i++) {
					target.draw(gameTable[i]);
				}
			}
			else {
				for (int i = 0; i < xSize*ySize; i++) {
					target.draw(gameTable[i]);
				}
			}
		}

	private:
		int xSize, ySize;
		int mapSize;
		int xWindowSize, yWindowSize;
		bool proceduralGen;
	
		std::vector<std::string> texName;
		std::vector<sf::Sprite> sprArray;
		std::vector<sf::Texture> texArray;
		std::vector<sf::RectangleShape> gameTable;
		sf::RenderWindow* m_win_class;
		//sf::RectangleShape selectSquare;
		sf::Sprite shrek;
		sf::Clock clock;
		float delta;
	protected:

	};
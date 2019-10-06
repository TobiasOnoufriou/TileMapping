#include "Core.h"
#include <math.h>
#include <algorithm>


Core::Core(sf::RenderWindow* m_win, int x, int y, bool proceduralGen) {
	xWindowSize = x;
	yWindowSize = y;
	this->proceduralGen = proceduralGen;
	this->onInit();
	this->m_win_class = m_win;

}
Core::~Core() {
	
}

void Core::perlinTerrain() {
	//Perlin Generator For map.
	this->mapSize = 256; // 256 x 256.
	initTable(mapSize, mapSize);
	for (int i = 0; i < gameTable.size(); i++) {
		std::srand(std::rand() % 23231);
		int texture = std::rand() % 2;
		gameTable[i].setTexture(&texArray[texture]);
	}
}

void Core::initTable(const int xSize, const int ySize) {
	//Get Table x Size compare to Screen Size.
	//Table will be zero based.
	//Quite Repetitve... But this can be changed.
	float pointX = 0;
	float pointY = 0;
	this->xSize = xSize;
	this->ySize = ySize;
	//std::cout << "Window" << std::endl;
	//std::cout << this->xWindowSize << std::endl;
	float incrimentSizeX = this->xWindowSize / xSize;
	//std::cout << ySize;
	float incrimentSizeY = this->yWindowSize / ySize;
	for (int x = 0; x < xSize; x++) {
		pointY = 0;
		for (int j = 0; j < ySize; j++) {
			sf::RectangleShape tempSprite;
			tempSprite.setPosition(pointX, pointY);
			tempSprite.setSize(sf::Vector2f(incrimentSizeX, incrimentSizeY));
			//tempSprite.setTexture(&texArray[0]);
			gameTable.push_back(tempSprite);

			pointY = pointY + incrimentSizeY;
		}
		pointX = pointX + incrimentSizeX;
	}
}
bool Core::readTextFiles(std::string fileName) {
	texName.clear();
	std::string string;
	sf::Texture* tex;
	std::fstream file;
	file.open(fileName);

	if (!file) {
		std::cout << "Texture file cannot be read!" << std::endl;
		return false;
	}
	else {
		while (getline(file, string)) {
			texName.push_back(string);
			//std::cout << string << std::endl;
		}
		file.close();
	}
	if (texName[0] == "[textures]") {
		loadTextures();
		return true;
	}
	if (texName[0] == "[tiles]") {
		initTileMap();
		return true;
	}
	return true;
}
bool Core::readTileMap() {
	//Will need to assign each texture a number
	//Each texture can be assigned this on the website backend

	return true;
}

void Core::onInit() {
	readTextFiles("textures.tex");
	if (!proceduralGen) {
		readTextFiles("tileMap.map");
	}
	else {
		perlinTerrain();
	}
}
void Core::onUpdate() {

}
void Core::onDraw() {
	//m_win_class->draw(shrek);
	/*for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			m_win_class->draw(gameTable[i*j]);
		}
	}*/
}
void Core::mainLoop() {

}
void Core::initTileMap() {
	//need x and y tm_array[][]
	//get reso size  e.g 1920 x 1080
	std::cout << "Initialization of tile map" << std::endl;
	int textureAmount = ((texName.at(1).size()/2) * (texName.at(1).size()/2));
	std::cout << textureAmount << std::endl;
	
	initTable(10, 10);
	
	std::string temp;
	std::cout << texName[1] << std::endl;
	int counter = 0;
	for (int i = 1; i <= texName.size() - 1; i++) {
		for (int x = 0; x <= texName.at(i).size() - 1; x++) {
			if (texName[i].at(x) != ' ') {
				int tempNumber;
				tempNumber = (int)texName[i].at(x) - (int)48;
				std::cout << tempNumber << std::endl;
				gameTable[counter].setTexture(&texArray[tempNumber]);
				counter++;
			}	
		}
		
	}
}
bool Core::loadTextures() {
	sf::Texture t_Texture; //Temp texture.
	for (int i = 1; i < texName.size(); i++) {
		if (!t_Texture.loadFromFile(texName[i])) {
			std::cout << "Couldn't find file" << std::endl;
			return false;
		}
		else {
			texArray.push_back(t_Texture);
			std::cout << texName[i] << std::endl;
		}
	}
	


	return true;
}
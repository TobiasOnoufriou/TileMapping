#pragma once
#include <SFML\Graphics.hpp>
#include "SpriteRectangle.h"

struct AnimalStates {
	enum animalType { fire = 'f', water = 'w', earth = 'e', magic = 'm' };
	char animalTypeCharcter;
	bool m_isEnemy;
	int m_level;
	int m_exp;
};

class Animal {
public:
	Animal() {

	}
	Animal(int m_newLevel, bool m_isEnemy, char m_animalType) {
		//Initailization of animals.
		sf::Texture tempTexture;
		//earthAnimalPlaceholder 0
		tempTexture.loadFromFile("earthAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//fireAnimalPlaceholder 1
		tempTexture.loadFromFile("fireAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//magicAnimalPlaceholder 2
		tempTexture.loadFromFile("magicAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//waterAnimalPlaceholder 3
		tempTexture.loadFromFile("waterAnimalPlaceHolder.png");
		animalTextures.push_back(tempTexture);

		states.m_level = m_newLevel;
		states.m_isEnemy = m_isEnemy;
		switch (m_animalType) {
		case 'f':
			states.animalTypeCharcter = states.fire;
			animalSprite.sprite.setTexture(animalTextures[0]);
			break;
		case 'w':
			states.animalTypeCharcter = states.water;
			animalSprite.sprite.setTexture(animalTextures[1]);
			break;
		case 'e':
			states.animalTypeCharcter = states.earth;
			animalSprite.sprite.setTexture(animalTextures[2]);
			break;
		case 'm':
			states.animalTypeCharcter = states.magic;
			animalSprite.sprite.setTexture(animalTextures[3]);
			break;
		};
	}


	Animal(int m_newLevel, int m_exp) {
		//Initailization of animals.
		sf::Texture tempTexture;
		//earthAnimalPlaceholder
		tempTexture.loadFromFile("earthAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//fireAnimalPlaceholder
		tempTexture.loadFromFile("fireAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//magicAnimalPlaceholder.
		tempTexture.loadFromFile("magicAnimalPlaceholder.png");
		animalTextures.push_back(tempTexture);
		//waterAnimalPlaceholder
		tempTexture.loadFromFile("waterAnimalPlaceHolder.png");
		animalTextures.push_back(tempTexture);


	}
	char getAnimalType() {
		return states.animalTypeCharcter;
	}
	void setAnimalType(char animalTypeCharacter) {
		states.animalTypeCharcter = animalTypeCharacter;
	}
	bool getIsEnemy() {
		return states.m_isEnemy;
	}
	void setIsEnemy(bool isEnemy) {
		states.m_isEnemy = isEnemy;
	}
	int getLevel() {
		return states.m_level;
	}
	void setLevel(int animalLevel) {
		states.m_level = animalLevel;
	}
	int getExp() {
		return states.m_exp;
	}
	void setExp(int addExp) {
		states.m_exp += addExp;
	}



private:
	bool m_isEnemy;
	int m_level;
	int m_exp;

	SpriteRectangle animalSprite;
	AnimalStates states;

	std::vector<sf::Texture> animalTextures;


};
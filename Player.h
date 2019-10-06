#pragma once
#include <SFML\Graphics.hpp>
#include "SpriteRectangle.h"
#include <iostream>



class Player: public sf::Drawable, public sf::Transformable{
public:
	Player() {
		 playerSetup();
		 this->m_health = 100;
		 this->m_mana = 100;
		 this->m_capsule = 3;
	}
	~Player() {

	}
	virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const {
		target.draw(m_playerSprite.sprite,states);
	}
	//Health
	virtual void incPlayerHealth(int inc_m_health) {
		this->m_health = inc_m_health;
	}
	 int getPlayerHealth() {
		return this->m_health;
	}
	//Mana
	virtual void incPlayerMana(int inc_m_mana) {
		this->m_mana = inc_m_mana;
	}
	virtual SpriteRectangle getPlayerSprite() {
		return m_playerSprite;
	}
	 int getPlayerMana() {
		return this->m_mana;
	}
	//Capsules
	virtual void incPlayerCapsules(int inc_m_capsules) {
		this->m_capsule = inc_m_capsules;
	}
	 int getPlayerCapsules() {
		return this->m_capsule;
	}
	 
	 void playerMovement(double delta, bool battleStage) {
		 int speed = 0;
		 m_playerSprite.spriteRectangle.left = m_playerSprite.sprite.getPosition().y;
		 m_playerSprite.spriteRectangle.top = m_playerSprite.sprite.getPosition().x;
		 if (!battleStage) {
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				 /*	 if (sourceRect.left >= (65 * 9)) {
						  sourceRect.left = 0;
					  }
					  else {
						  sourceRect.left += ((delta * 60)  * 80);
					  }*/
				 m_playerSprite.sprite.move(sf::Vector2f(0.0f, -1.f*(60.f * delta)));
				 //std::cout << "Left: " << m_playerSprite.spriteRectangle.left << std::endl;
				 //std::cout << "Top: " << m_playerSprite.spriteRectangle.top << std::endl;
			 }
			 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				 m_playerSprite.sprite.move(sf::Vector2f(0.0f, 1.f*(60.f * delta)));
				 //std::cout << "Left: " << m_playerSprite.spriteRectangle.left << std::endl;
				 //std::cout << "Top: " << m_playerSprite.spriteRectangle.top << std::endl;
			 }
			 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				 m_playerSprite.sprite.move(sf::Vector2f(-1.f*(60.f * delta), 0.f));
				 //std::cout << "Left: " << m_playerSprite.spriteRectangle.left << std::endl;
				 //std::cout << "Top: " << m_playerSprite.spriteRectangle.top << std::endl;


			 }
			 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				 m_playerSprite.sprite.move(sf::Vector2f(1.f*(60.f * delta), 0.f));
				 //std::cout << "Left: " << m_playerSprite.spriteRectangle.left << std::endl;
				 //std::cout << "Top: " << m_playerSprite.spriteRectangle.top << std::endl;
			 }
		 }
	 
		m_playerSprite.sprite.setTextureRect(sourceRect);
	 }
	 void playerSetup() {
		 m_playerTexture.loadFromFile("playersprite.png");
		 
		 
		 m_playerSprite.sprite.setTexture(m_playerTexture);
		 sourceRect = sf::IntRect(0, 0, 45, 65);
		 m_playerSprite.sprite.setTextureRect(sf::IntRect(0, 0, 45, 65));
		 m_playerSprite.sprite.setPosition(300, 300);
		 
		 m_playerSprite.sprite.setOrigin(sf::Vector2f(0, 0));	

		 m_playerSprite.spriteRectangle.left = 340;
		 m_playerSprite.spriteRectangle.top = 340;
		 m_playerSprite.spriteRectangle.height = 25;
		 m_playerSprite.spriteRectangle.width = 25;
		 

		 
	}

protected:
	int m_health;
	int m_mana;
	int m_capsule;
private:
	sf::Texture m_playerTexture;
	SpriteRectangle m_playerSprite;


	sf::IntRect sourceRect;

};
#include "HealthBar.h"

HealthBar::~HealthBar() {

}
void HealthBar::createBars() {
	//this->Mana;
	//this->Health;
	
	//Setting mana and health bars height.
	std::cout << m_mana << std::endl;
	std::cout << m_health << std::endl;
	//std::cout << getPlayerCapsules() << std::endl;

	this->Mana.setSize(sf::Vector2f(getPlayerMana(), 25.f));
	this->Health.setSize(sf::Vector2f(m_health, 25.f));
	//Setting Position of the 
	this->Mana.setPosition(sf::Vector2f(0.0f, 0.0f));
	this->Health.setPosition(sf::Vector2f(0.0f, 30.f));
	//Setting health bar colour.
	this->Mana.setFillColor(sf::Color(0,0,255, 150));
	this->Health.setFillColor(sf::Color(255,0,0,150));
	//Transparent
	
}



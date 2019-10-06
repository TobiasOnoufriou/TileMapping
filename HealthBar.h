#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"

class HealthBar : public sf::Drawable, public sf::Transformable, Player{
public:
	HealthBar(): Player(){
		
		createBars();
	}
	~HealthBar();
	
	void createBars();
	virtual void incPlayerMana(int inc_m_mana) {
		m_mana = inc_m_mana; 
	}
	virtual void incPlayerHealth(int inc_m_health) {
		m_health = inc_m_health;
	}
	virtual void incPlayerCapsule(int inc_m_capsule) {
		m_capsule = inc_m_capsule;
	}
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(Health,states);
		target.draw(Mana, states);
	}

private:
	
	sf::RectangleShape Health;
	sf::RectangleShape Mana;
};

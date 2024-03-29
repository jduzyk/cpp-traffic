#include <SFML/Graphics.hpp>
#include "InputHandler.h"
#include "Properties.h"




InputHandler::InputHandler(Player* player) { this->player = player; }

void InputHandler::process(float delta) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player->moveLeft();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			player->moveRight();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			Properties::SPEED_MODIFIER *= Properties::SPEED_MODIFIER_INCREASE;
			if (Properties::SPEED_MODIFIER >= Properties::SPEED_MODIFIER_MAX) {
				Properties::SPEED_MODIFIER = Properties::SPEED_MODIFIER_MAX;
			}
		} 
		else {
			Properties::SPEED_MODIFIER *= Properties::SPEED_MODIFIER_DECREASE;
			if (Properties::SPEED_MODIFIER <= Properties::SPEED_MODIFIER_MIN) {
				Properties::SPEED_MODIFIER = Properties::SPEED_MODIFIER_MIN;
			}
		}

	}

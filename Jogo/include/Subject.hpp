#pragma once

#include <SFML/Graphics.hpp>

#include "../include/Observer.hpp"

namespace Subject {
	class Subject {
		private:
			std::vector<Observer::Observer*> observers;
			std::vector<Observer::Observer*>::iterator it;

			static Subject* subject;
			Subject();
		public:
			~Subject();

			static Subject* getSubject();
			void addObserver(Observer::Observer* observer);
			void removeObserver(Observer::Observer* observer);
			void notifyKeyPressed(const sf::Keyboard::Key tecla);
			void notifyKeyReleased(const sf::Keyboard::Key tecla);
	};
}
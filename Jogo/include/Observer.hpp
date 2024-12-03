#pragma once

#include <SFML/Graphics.hpp>

namespace Subject {
	class Subject;
	namespace Observer {
		class Observer {
		private:
			static Subject* pSubject;
		public:
			Observer();
			virtual ~Observer();
			virtual void upKeyPressed(sf::Keyboard::Key tecla) = 0;
			virtual void upKeyReleased(sf::Keyboard::Key tecla) = 0;
		};
	}
}
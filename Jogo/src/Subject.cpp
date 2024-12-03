#include "../include/Subject.hpp"

namespace Subject {
	Subject* Subject::subject = nullptr;

	Subject::Subject(): it(), observers() {}

	Subject::~Subject() {
		for (it = observers.begin(); it != observers.end(); it++) {
			if (*it) {
				delete* it;
			}
			*it = nullptr;
		}
		observers.clear();
	}

	Subject* Subject::getSubject() {
		if (subject == nullptr) {
			subject = new Subject();
		}

		return subject;
	}

	void Subject::addObserver(Observer::Observer* observer) {
		observers.push_back(observer);
	}

	void Subject::removeObserver(Observer::Observer* observer) {
		for (it = observers.begin(); it != observers.end(); it++) {
			if (*it == observer) {
				observers.erase(it);
				break;
			}
		}
	}

	void Subject::notifyKeyPressed(sf::Keyboard::Key tecla) {
		for (it = observers.begin(); it != observers.end(); it++) {
			(*it)->upKeyPressed(tecla);
		}
	}

	void Subject::notifyKeyReleased(sf::Keyboard::Key tecla) {
		for (it = observers.begin(); it != observers.end(); it++) {
			(*it)->upKeyReleased(tecla);
		}
	}
}
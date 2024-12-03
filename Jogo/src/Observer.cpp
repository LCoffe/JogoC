#include "../include/Observer.hpp"
#include "../include/Subject.hpp"

#include <iostream>
using namespace std;
namespace Subject {
	namespace Observer {
		Subject* Observer::pSubject = Subject::getSubject();

		Observer::Observer(){
			if (pSubject != nullptr) {
				cout << "adicionou observer" << endl;
				pSubject->addObserver(this);
			}
		}

		Observer::~Observer() {}
	}
}
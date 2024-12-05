#include "../include/Observador.hpp"
#include "../include/Observado.hpp"

#include <iostream>
using namespace std;
namespace Observado {
	namespace Observador {
		Observado* Observador::pObservado = Observado::Observado::getObservado();

		Observador::Observador(): teclasPressionadas(){
			if (pObservado != nullptr) {
				//cout << "adicionou observer" << endl;
				pObservado->incluirObservador(this);
			}
		}

		Observador::~Observador() { pObservado = nullptr; }
	}
}
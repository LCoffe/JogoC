#include "../include/Observador.hpp"
#include "../include/Observado.hpp"

#include <iostream>
using namespace std;
namespace Observado {
	namespace Observador {
		Observado* Observador::pObservado = Observado::Observado::getObservado();
		Gerenciador::GerenciadorEstado* Observador::pGEst = Gerenciador::GerenciadorEstado::getGerEstado();

		Observador::Observador(): ativar(false){
			if (pObservado != nullptr) {
				//cout << "adicionou observer" << endl;
				pObservado->incluirObservador(this);
			}
		}

		Observador::~Observador() { 
			pObservado->removerObservador(this); 
		}
	}
}
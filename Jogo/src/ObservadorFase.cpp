#include "../include/ObservadorFase.hpp"

namespace Observado {
	namespace Observador {
		ObservadorFase::ObservadorFase(Fase::Fase* pFase) : pFase(pFase) {
		}
		ObservadorFase::~ObservadorFase() {
			pFase = nullptr;
		}
		void ObservadorFase::attTeclaPressionada(sf::Keyboard::Key tecla) {

		}
		void ObservadorFase::attTeclaUnica(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::Escape || tecla == sf::Keyboard::P ) {
				if (pGEst != nullptr) {
					pGEst->incluiEstado(IDs::IDs::estadoMenuOpcoes, IDs::IDs::nulo, false);
				}
				//pGEst->incluiEstado(IDs::IDs::estadoMenuPrincipal);
				//cout << "Pausou" << endl;
			}
		}
		void ObservadorFase::jogadorMorreu() 
		{
			if (pGEst != nullptr) {
				pGEst->incluiEstado(IDs::IDs::estadoMorreu, IDs::IDs::nulo, false);
			}
		}
		void ObservadorFase::finalizaFase(Jogador* pJog1, Jogador* pJog2)
		{
			if (pFase->getID() == IDs::IDs::fase01) {
				if (pFase->getDoisJogadores()) {
					if ((pFase->getJogador()->getPos().x > 500.0f) || pFase->getJogadorDois()->getPos().x > 500.0f) {
						pGEst->passouFase(pFase->getID());
					}
				}
				else {
					if ((pFase->getJogador()->getPos().x > 500.0f)) {
						pGEst->passouFase(pFase->getID());
					}
				}

			}
		}
	}
}
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
		void ObservadorFase::finalizaFase(Jogador* pJog1, Jogador* pJog2, bool temInimigoVivo)
		{	
			if (pFase->getID() == IDs::IDs::ponte) {
				pFase->abrePortao(temInimigoVivo);
				if (pFase->getDoisJogadores()) {
					if ((pFase->getJogador()->getPos().x > 3770.0f) && pFase->getJogadorDois()->getPos().x >3770.0f) {
						pGEst->passouFase(pFase->getID());
					}
				}
				else {
					if ((pFase->getJogador()->getPos().x > 3770.0f)) {
						pGEst->passouFase(pFase->getID());
					}
				}

			}
			else if (pFase->getID() == IDs::IDs::castelo && !temInimigoVivo) {
				pGEst->incluiEstado(IDs::IDs::estadoGanhou, IDs::IDs::nulo, false);
			}
		}

		bool ObservadorFase::verificaInimigoVivo(Lista::ListaEntidade& LP) {
			for (int i = 0; i < LP.getTamanho(); i++)
			{
				if (LP[i]->getID() == IDs::IDs::gorgona || LP[i]->getID() == IDs::IDs::minotauro || LP[i]->getID() == IDs::IDs::guerreiraAthena) {
					return true;
				}
			}
			return false;
		}
	}
}
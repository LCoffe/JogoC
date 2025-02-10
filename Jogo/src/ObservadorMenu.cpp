#include "../include/ObservadorMenu.hpp"
#include "../include/EstadoJogar.hpp"
#include "../include/EstadoMenu.hpp"
#include "../include/menus/MenuOpcoes.hpp"
#include "../include/menus/MenuSalvarColocacao.hpp"
#include "../include/menus/MenuColocacao.hpp"

namespace Observado {
	namespace Observador {
		Gerenciador::GerenciadorGrafico* ObservadorMenu::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

		ObservadorMenu::ObservadorMenu(Menu::Menu* pMenu) :Observador(), pMenu(pMenu), pGS(new Gerenciador::GerenciadorSalvar()){
			if (pMenu == nullptr) {
				throw std::invalid_argument("Menu invalido");
			}
		}

		ObservadorMenu::~ObservadorMenu() {
			pMenu = nullptr;
		}

		void ObservadorMenu::attTeclaPressionada(sf::Keyboard::Key tecla) {
		}

		void ObservadorMenu::attTeclaUnica(sf::Keyboard::Key tecla) {
			if (tecla == sf::Keyboard::Up) {
				pMenu->selecionaCima();
			}
			if (tecla == sf::Keyboard::Down) {
				pMenu->selecionaBaixo();
			}
			if (tecla == sf::Keyboard::Return) {
				if (pMenu->getIDBotao() == IDs::IDs::botaoSair) {
					pGG->fechar();
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoJogar1Jog) {
					pGEst->incluiEstado(IDs::IDs::estadoJogar1Jog, IDs::IDs::ponte,false);
				} 
				else if (pMenu->getIDBotao() == IDs::IDs::botaoJogar2Jog) {
					pGEst->incluiEstado(IDs::IDs::estadoJogar2Jog, IDs::IDs::ponte,false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoCarregar) {
					nlohmann::json jsonCarregar = pGS->carregarFase();
					for (auto& it : jsonCarregar) {
						IDs::IDs ID = static_cast<IDs::IDs>(it["IDFase"]);
						if (ID == IDs::IDs::ponte || ID == IDs::IDs::castelo) {
							bool doisJogadores = it["doisJogadores"];
							if (doisJogadores) {
								pGEst->incluiEstado(IDs::IDs::estadoJogar2Jog, ID,true);
							}
							else {
								pGEst->incluiEstado(IDs::IDs::estadoJogar1Jog, ID,true);
							}
						}
					}
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoSelecionaFase) {
					pGEst->incluiEstado(IDs::IDs::estadoMenuSelecionaFase, IDs::IDs::nulo, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoPonteJog1) {
					pGEst->removerEstado();
					pGEst->incluiEstado(IDs::IDs::estadoJogar1Jog, IDs::IDs::ponte, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoPonteJog2) {
					pGEst->removerEstado();
					pGEst->incluiEstado(IDs::IDs::estadoJogar2Jog, IDs::IDs::ponte, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoCasteloJog1) {
					pGEst->removerEstado();
					pGEst->incluiEstado(IDs::IDs::estadoJogar1Jog, IDs::IDs::castelo, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoCasteloJog2) {
					pGEst->removerEstado();
					pGEst->incluiEstado(IDs::IDs::estadoJogar2Jog, IDs::IDs::castelo, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoColocacao) {
					pGEst->incluiEstado(IDs::IDs::estadoMenuColocacao, IDs::IDs::nulo, false);
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoLimpar) {
					if (pGEst->getEstado()->getID() == IDs::IDs::estadoMenuColocacao) {
						Estado::EstadoMenu* pEM = static_cast<Estado::EstadoMenu*>(pGEst->getEstado());
						Menu::MenuColocacao* pMenuCol = static_cast<Menu::MenuColocacao*>(pEM->getMenu());
						pMenuCol->limparColocacao();
					}
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoSalvar) {
					Estado::Estado* pEst = pGEst->getEstado();
					if (pEst->getID() == IDs::IDs::estadoMenuOpcoes) {
						Estado::EstadoMenu* pEM = static_cast<Estado::EstadoMenu*>(pEst);
						Menu::MenuOpcoes* pMenuOp = static_cast<Menu::MenuOpcoes*>(pEM->getMenu());
						Fase::Fase* pFase = pMenuOp->getFase();
						if (pFase) {
							pFase->salvar();
						}
					}
					if (pEst->getID() == IDs::IDs::estadoSalvarColocacao) {
						Estado::EstadoMenu* pEM = static_cast<Estado::EstadoMenu*>(pEst);
						Menu::Menu* pMenu = pEM->getMenu();
						string nome = pMenu->getNome();
						Menu::MenuSalvarColocacao* pAux = static_cast<Menu::MenuSalvarColocacao*>(pMenu);
						Fase::Fase* pFase = pAux->getFase();
						if (pFase) {
							pFase->salvarColocacao(nome);
						}
					}
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoSalvarColocacao) {
					Estado::Estado* pEst = pGEst->getEstado();
					if (pEst->getID() == IDs::IDs::estadoMorreu || pEst->getID() == IDs::IDs::estadoGanhou) {
						Estado::EstadoMenu* pEM = static_cast<Estado::EstadoMenu*>(pEst);
						Menu::MenuOpcoes* pMenuOp = static_cast<Menu::MenuOpcoes*>(pEM->getMenu());
						Fase::Fase* pFase = pMenuOp->getFase();
						if (pFase) {
							pGEst->incluiEstado(IDs::IDs::estadoSalvarColocacao, pFase->getID(), false);
						}
					}
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoVoltar) {
					pGEst->removerEstado();
				}
				else if (pMenu->getIDBotao() == IDs::IDs::botaoMenuPrincipal) {
					pGEst->removerEstado(2);
				}
			}
			if (tecla >= sf::Keyboard::A && tecla <= sf::Keyboard::Z) {
				if (pMenu->getID() == IDs::IDs::menuSalvarColocao) {
					for (int i = 0; i < 26; i++) {
						if (tecla == sf::Keyboard::Key(i)) {
							char caracter = 'A' + i;
							pMenu->incluirLetra(caracter);
							break;
						}
					}
				}
			}
			if (tecla == sf::Keyboard::BackSpace) {
				if (pMenu->getID() == IDs::IDs::menuSalvarColocao) {
					pMenu->excluirLetra();
				}
			}
		}
	}
}
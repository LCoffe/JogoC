#include "../../include/elementosGraficos/botao.hpp"

namespace Menu {
	namespace Botao {
		Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tamSelec) :Ente(ID), texto(nullptr), tam(tam), 
			pos(pos), tamSelec(tamSelec), selecionado(false){
			caixa.setPosition(pos);
			caixa.setTexture(pGG->incluirTextura(BOTAO_PATH));
			
			switch (ID)
			{	
				case IDs::IDs::botaoJogar1Jog:
					texto = new Texto(pos, "Jogar (1 Jogador)");
					texto->setPosicao(sf::Vector2f(pos.x + 5.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 33.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoJogar2Jog:
					texto = new Texto(pos, "Jogar (2 Jogadores)");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 35.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoCarregar:
					texto = new Texto(pos, "Carregar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 22.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoSalvar:
					texto = new Texto(pos, "Salvar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 22.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoSalvarColocacao:
					texto = new Texto(pos, "Salvar Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 35.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoColocacao:
					texto = new Texto(pos, "Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 22.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoTextoColocacao:
					texto = new Texto(pos, "Texto Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					texto->setCorBordaTexto(0,0,0);
					texto->setCorTexto(218, 165, 32);
					break;
				case IDs::IDs::botaoLimpar:
					texto = new Texto(pos, "Limpar Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 35.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoVoltar:
					texto = new Texto(pos, "Voltar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 22.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoMenuPrincipal:
					texto = new Texto(pos, "Voltar ao Menu Principal");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 37.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoSair:
					texto = new Texto(pos, "Sair");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 17.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoFase01Jog1:
					texto = new Texto(pos, "Ponte de Athena (1 Jogador)");
					texto->setPosicao(sf::Vector2f(pos.x + 5.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 90.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 50.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoFase01Jog2:
					texto = new Texto(pos, "Ponte de Athena (2 Jogadores)");
					texto->setPosicao(sf::Vector2f(pos.x + 5.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 90.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 50.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoFase02Jog1:
					texto = new Texto(pos, "Castelo de Athena (1 Jogador)");
					texto->setPosicao(sf::Vector2f(pos.x + 7.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 90.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 50.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoFase02Jog2:
					texto = new Texto(pos, "Castelo de Athena (2 Jogadores)");
					texto->setPosicao(sf::Vector2f(pos.x + 5.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 90.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 50.0f, pos.y - 10.0f));
					break;
				case IDs::IDs::botaoSelecionaFase:
					texto = new Texto(pos, "Selecionar Fase");
					texto->setPosicao(sf::Vector2f(pos.x + 5.0f, pos.y + 10.0f));
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
					caixa.setPosition(sf::Vector2f(pos.x - 33.0f, pos.y - 10.0f));
					break;
				default:
					break;
			}
		}
		Botao::~Botao() {
			delete texto;
			texto = nullptr;
		}
		void Botao::desenhar() {
			pGG->desenharElemento(caixa);
			texto->desenhar();
		}
		void Botao::atualizarPosicao(const sf::Vector2f pos) {
			this->pos = pos;
			caixa.setPosition(pos);
		}
		void Botao::seleciona() {
			selecionado = !selecionado;
			if (selecionado) {
				texto->setTamFonte(30);
				texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 5.0f));
				if(ID != IDs::IDs::botaoTextoColocacao)
					caixa.setSize(caixa.getSize() + sf::Vector2f(texto->getTam().x / 3.0f, 5.0f));
			}
			else {
				texto->setTamFonte(24);
				texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
				if (ID == IDs::IDs::botaoFase01Jog1 || ID == IDs::IDs::botaoFase01Jog2 || ID == IDs::IDs::botaoFase02Jog1 || ID == IDs::IDs::botaoFase02Jog2) {
					caixa.setSize(sf::Vector2f(texto->getTam().x + 90.0f, texto->getTam().y + 40.0f));
				}
				else if (ID != IDs::IDs::botaoTextoColocacao) {
					caixa.setSize(sf::Vector2f(texto->getTam().x + 70.0f, texto->getTam().y + 40.0f));
				}
			}
		}

		void Botao::setInfoTexto(const std::string info) {
			texto->setInfoTexto(info);
		}

		const sf::Vector2f Botao::getPos() const {
			return pos;
		}
	}
}
#include "../include/Botao.hpp"

namespace Menu {
	namespace Botao {
		Botao::Botao(const sf::Vector2f tam, const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tamSelec) :Ente(ID), texto(nullptr), tam(tam), 
			pos(pos), tamSelec(tamSelec), selecionado(false){
			caixa.setSize(tam);
			caixa.setPosition(pos);
			caixa.setFillColor(sf::Color::Transparent);
			//caixa.setOutlineColor(sf::Color::Black);
			//caixa.setOutlineThickness(2.0f);
			switch (ID)
			{	
				case IDs::IDs::botaoJogar1Jog:
					texto = new Texto(pos, "Jogar (1 Jogador)");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoJogar2Jog:
					texto = new Texto(pos, "Jogar (2 Jogadores)");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoCarregar:
					texto = new Texto(pos, "Carregar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoSalvar:
					texto = new Texto(pos, "Salvar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoSalvarColocacao:
					texto = new Texto(pos, "Salvar Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoColocacao:
					texto = new Texto(pos, "Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoTextoColocacao:
					texto = new Texto(pos, "Texto Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoLimpar:
					texto = new Texto(pos, "Limpar Colocacao");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoVoltar:
					texto = new Texto(pos, "Voltar");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoMenuPrincipal:
					texto = new Texto(pos, "Voltar ao Menu Principal");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
					break;
				case IDs::IDs::botaoSair:
					texto = new Texto(pos, "Sair");
					texto->setPosicao(sf::Vector2f(pos.x + 10.0f, pos.y + 10.0f));
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
				//caixa.setSize(tamSelec);
				texto->setTamFonte(30);
			}
			else {
				//caixa.setSize(tam);
				texto->setTamFonte(24);
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
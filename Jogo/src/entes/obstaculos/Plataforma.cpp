#include "../../include/entes/obstaculos/Plataforma.hpp"

constexpr auto PLATAFORMA_PATH = "..\\Jogo\\assets\\plataformas\\pedra.png";

namespace Entidade {
	namespace Obstaculos {
		Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Obstaculo(pos, tam, ID) {
		
			corpo.setSize(tam);
			corpo.setPosition(pos);
			inicializar();
		}

		Plataforma::~Plataforma() {}

		void Plataforma::desenhar() {
			sprite.desenhar();
		}

		void Plataforma::colisao(Entidade* ent, sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getColisaoParede()) {
					pp->setAndando(false);
					pp->setVelocidade(sf::Vector2f(0.0f, 0.0f));
				}
			}
			else if (ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::gorgona) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getColisaoParede() && pp->getDirecao()) { //se a plataforma estiver a direita do inimigo e ele estiver indo para a direita
					pp->setDirecao(false);
				}
				else if (pp->getColisaoParede() && !pp->getDirecao()) { //se a plataforma estiver a esquerda do inimigo e ele estiver indo para a esquerda
					pp->setDirecao(true);
				}
			}
		}

		void Plataforma::atualizar() {
			sprite.atualizar(pos);
		}

		void Plataforma::inicializar() {
			sprite.inicializar(PLATAFORMA_PATH, pos, sf::Vector2f(TAM_PLATAFORMA_X, TAM_PLATAFORMA_Y));
		}



		void Plataforma::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = false;
			j["colisaoParede"] = false;
		}
	}
}
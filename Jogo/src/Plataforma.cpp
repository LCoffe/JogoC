#include "../include/Plataforma.hpp"

namespace Entidade {
	namespace Obstaculos {
		Plataforma::Plataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID) : Obstaculo(pos, tam, ID) {
			corpo.setFillColor(sf::Color::Red);
			corpo.setSize(tam);
			corpo.setPosition(pos);
			inicializarSprite();
		}

		Plataforma::~Plataforma() {}

		void Plataforma::desenhar() {
			pGG->getJanela()->draw(sprite);
		}

		void Plataforma::atualizar(){}

		void Plataforma::colisao(Entidade* ent, sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador){
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
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

		void Plataforma::inicializarSprite()
		{
			if (!textura.loadFromFile(PLATAFORMA_PATH)) {
				std::cerr << "Erro ao carregar textura da plataforma: " << PLATAFORMA_PATH << std::endl;
			}
			// Ativa a repetição da textura
			textura.setRepeated(true);

			sprite.setTexture(textura);

			// Define a área da textura que será repetida no tamanho do corpo da plataforma
			sprite.setTextureRect(sf::IntRect(0, 0, (int)corpo.getSize().x, (int)corpo.getSize().y));

			sprite.setPosition(corpo.getPosition());

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
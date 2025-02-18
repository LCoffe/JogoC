#include "../../include/entes/obstaculos/Portao.hpp"

namespace Entidade {
	namespace Obstaculos {
		Portao::Portao(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::portao), aberto(false) {
			inicializar();
		}
		Portao::~Portao() {}
		void Portao::inicializar() {
			inicializarSprite();
		}
		void Portao::inicializarSprite() {
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PORTAO_PATH, 1);
		}
		void Portao::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (!aberto) {
				if (ent->getID() == IDs::IDs::jogador) {
					Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
					colisaoObs(p, diferenca);
				}
			}
			if(ent->getID() == IDs::IDs::minotauro || ent->getID() == IDs::IDs::gorgona || ent->getID() == IDs::IDs::guerreiraAthena) {
				Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(p, diferenca);
				if (p->getColisaoParede() && p->getDirecao()) { //se a plataforma estiver a direita do inimigo e ele estiver indo para a direita
					p->setDirecao(false);
				}
				else if (p->getColisaoParede() && !p->getDirecao()) { //se a plataforma estiver a esquerda do inimigo e ele estiver indo para a esquerda
					p->setDirecao(true);
				}
			}
			else if (ent->getID() == IDs::IDs::plataforma) {
				colisaoPlataforma(ent, diferenca);
			}
			else if (ent->getID() == IDs::IDs::projetil) {
				Item::Projetil* p = static_cast<Item::Projetil*>(ent);
				p->setColidiu(true);
			}
		}
		void Portao::colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca) {
			sf::Vector2f pos = getPos();
			sf::Vector2f tam = getTam();
			//pos.x = corpo.getPosition().x - tam.x / 2.0f;
			//pos.y = corpo.getPosition().y + tam.y / 2.0f;
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) {
				if (pos.y < ent->getPos().y) { //Colisao em y
					pos.y += diferenca.y;
				}
				else {
					pos.y -= diferenca.y;
				}
				setPos(pos);
			}
		}
		void Portao::desenhar() {
			if (!aberto) {
				sprite.desenhar();
				pGG->desenharElemento(corpo);
				
			}
		}
		void Portao::atualizar() {
			//Força da gravidade
			const float velY = 50.0f;
			sf::Vector2f soma(0.0f, 0.0f);
			soma.y = velY * pGG->getTempo() + (GRAVIDADE * pGG->getTempo() * pGG->getTempo()) / 2.0f;

			corpo.move(soma);
			pos.y = corpo.getPosition().y;

			sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, true, sf::Vector2f(pos.x, pos.y + 40.0f), pGG->getTempo());
		}
		void Portao::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y - 20.0f} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = false;
			j["colisaoParede"] = false;
			j["aberto"] = aberto;
		}
	}
}
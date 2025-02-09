#include "../../include/entes/obstaculos/Espinho.hpp"

namespace Entidade {
	namespace Obstaculos {
		Espinho::Espinho(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::espinho), dano(DANO_ESPINHO) {
			inicializar();
		}
		Espinho::~Espinho() {
		}
		void Espinho::inicializarSprite() {
			//animaEstatica.inicializar(ESPINHO_PATH, pos, tam);
		}
		void Espinho::inicializar() {
			inicializarSprite();
		}
		void Espinho::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador) {
				Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(p, diferenca);
				p->tomarDano(dano, nullptr);
				if (!p->getMorrendo()) {
					p->setPos(sf::Vector2f(p->getDirecao() ? p->getPos().x - 20.0f : p->getPos().x + 20.0f, p->getPos().y + 10.0f));
				}
			} 
			else if (ent->getID() == IDs::IDs::minotauro || ent->getID() == IDs::IDs::gorgona || ent->getID() == IDs::IDs::guerreiraAthena) {
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
		void Espinho::desenhar() {
			pGG->desenharElemento(corpo);
			//animaEstatica.desenhar();
		}

		void Espinho::colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca) {
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) {
				if (diferenca.x > diferenca.y) { //Colisao em x
					if (pos.x < ent->getPos().x) {
						pos.x += diferenca.x;
					}
					else {
						pos.x -= diferenca.x;
					}
				}
				else {
					if (pos.y < ent->getPos().y) { //Colisao em y
						pos.y += diferenca.y;
					}
					else {
						pos.y -= diferenca.y;
					}
				}
				setPos(pos);
			}
		}

		void Espinho::atualizar() {
			//Força da gravidade
			const float velY = 50.0f;
			sf::Vector2f soma(0.0f, 0.0f);
			soma.y = velY * pGG->getTempo() + (GRAVIDADE * pGG->getTempo() * pGG->getTempo()) / 2.0f;

			corpo.move(soma);
			pos.y = corpo.getPosition().y;

			//animaEstatica.atualizar();
		}

		void Espinho::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = false;
			j["colisaoParede"] = false;
			j["aberto"] = false;
		}
	}
}

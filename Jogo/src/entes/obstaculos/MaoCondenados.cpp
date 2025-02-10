#include "../../include/entes/obstaculos/MaoCondenados.hpp"

namespace Entidade {
	namespace Obstaculos {
		MaoCondenados::MaoCondenados(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::maocondenados), lentidao(0.5f) {
			inicializar();
		}
		MaoCondenados::~MaoCondenados() {}
		void MaoCondenados::inicializar() {
			inicializarSprite();
		}
		void MaoCondenados::inicializarSprite() {
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, MAO_PATH, 5);
		}
		void MaoCondenados::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador) {
				Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(p, diferenca);
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
		void MaoCondenados::colisaoObs(Personagem::Personagem* persona, const sf::Vector2f diferenca) {
			sf::Vector2f personaPos = persona->getPos();
			sf::Vector2f personaTam = persona->getTam();
			sf::Vector2f personaVelFinal = persona->getVelocidade();
			persona->setColisaoParede(false);
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) { //houve colisao
				personaVelFinal.x *= lentidao;
				setPos(pos);
			}
			persona->setPos(personaPos);
			persona->setVelocidade(personaVelFinal);
		}
		void MaoCondenados::colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca) {
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
		void MaoCondenados::desenhar() {
			sprite.desenhar();
			//pGG->desenharElemento(corpo);
		}
		void MaoCondenados::atualizar() {
			//Força da gravidade
			const float velY = 50.0f;
			sf::Vector2f soma(0.0f, 0.0f);
			soma.y = velY * pGG->getTempo() + (GRAVIDADE * pGG->getTempo() * pGG->getTempo()) / 2.0f;

			corpo.move(soma);
			pos.y = corpo.getPosition().y;

			sf::Vector2f posicao = pos;
			posicao.x += tam.x / 2.0f;
			posicao.y += tam.y / 2.35f;
			sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, true, posicao, pGG->getTempo());
		}
		void MaoCondenados::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = false;
			j["colisaoParede"] = false;
			j["aberto"] = false;
		}
	}
}
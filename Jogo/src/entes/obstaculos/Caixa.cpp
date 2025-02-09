#include "../../include/entes/obstaculos/Caixa.hpp"

namespace Entidade {
	namespace Obstaculos {
		Caixa::Caixa(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(pos, tam, IDs::IDs::caixa), arrastado(false), lentidao(0.15f){
			inicializar();
		}
		Caixa::~Caixa() {}
		void Caixa::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (ent->getID() == IDs::IDs::jogador) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
			}
			else if (ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::gorgona || ent->getID() == IDs::IDs::minotauro) {
				Personagem::Personagem* pp = dynamic_cast<Personagem::Personagem*>(ent);
				colisaoObs(pp, diferenca);
				if (pp->getColisaoParede() && pp->getDirecao()) { //se a plataforma estiver a direita do inimigo e ele estiver indo para a direita
					pp->setDirecao(false);
				}
				else if (pp->getColisaoParede() && !pp->getDirecao()) { //se a plataforma estiver a esquerda do inimigo e ele estiver indo para a esquerda
					pp->setDirecao(true);
				}
			}
			else if (ent->getID() == IDs::IDs::plataforma || ent->getID() == IDs::IDs::espinho) {
				colisaoPlataforma(ent, diferenca);
			}
			else if (ent->getID() == IDs::IDs::projetil) {
				Item::Projetil* p = static_cast<Item::Projetil*>(ent);
				p->setColidiu(true);
			}
		}

		void Caixa::colisaoObs(Personagem::Personagem* persona, sf::Vector2f diferenca) {
			sf::Vector2f personaPos = persona->getPos();
			sf::Vector2f personaTam = persona->getTam();
			sf::Vector2f personaVelFinal = persona->getVelocidade();
			arrastado = false;
			persona->setColisaoParede(false);
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) { //houve colisao
				if (diferenca.x > diferenca.y) { //colisao em x
					if (persona->getID() == IDs::IDs::jogador && !colisaoParede) {
						personaVelFinal.x *= lentidao;
						arrastado = true;
						if (personaPos.x < pos.x) {
							pos.x -= diferenca.x;
						}
						else {
							pos.x += diferenca.x;
						}
						setPos(pos);
					}
					else {

						if (personaPos.x < pos.x) {
							personaPos.x += diferenca.x; //colisao para a direita
						}
						else {
							personaPos.x -= diferenca.x; //colisao para a esquerda
						}
					}
					persona->setColisaoParede(true);
				}
				else {
					if (personaPos.y < pos.y) { //colisao em y
						personaPos.y += diferenca.y;
					}
					else {
						personaPos.y -= diferenca.y;
					}
					personaVelFinal.y = 0.0f;
					persona->setColisaoChao(true);
				}
			}
			persona->setPos(personaPos);
			persona->setVelocidade(personaVelFinal);
		}

		void Caixa::colisaoPlataforma(Entidade* ent, const sf::Vector2f diferenca) {
			colisaoParede = false;
			if (diferenca.x < 0.0f && diferenca.y < 0.0f) {
				if (diferenca.x > diferenca.y) { //Colisao em x
					if (pos.x < ent->getPos().x) {
						pos.x += diferenca.x;
					}
					else {
						pos.x -= diferenca.x;
					}
					colisaoParede = true;
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

		void Caixa::desenhar() {			
			sprite.desenhar();
			//pGG->desenharElemento(corpo);
		}
		void Caixa::atualizar() {
			//Força da gravidade
			const float velY = 50.0f;
			sf::Vector2f soma(0.0f, 0.0f);
			soma.y = velY * pGG->getTempo() + (GRAVIDADE * pGG->getTempo() * pGG->getTempo()) / 2.0f;

			corpo.move(soma);
			pos.y = corpo.getPosition().y;

			atualizarSprite(pGG->getTempo());

			if (arrastado) {
				arrastado = false;
			}
		}
		void Caixa::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["arrastado"] = arrastado;
			j["colisaoParede"] = colisaoParede;
		}
		void Caixa::inicializar() {
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, CAIXA_ARRASTADO_PATH, 8);
			sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, CAIXA_PARADO_PATH, 1);
			
		}
		void Caixa::atualizarSprite(float dt) {
			sf::Vector2f posicao = pos;
			posicao.x += tam.x / 1.8f;
			posicao.y += tam.y / 2.8f;

			if (arrastado) {
				sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, true, posicao, dt);
			}
			else {
				sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, true, posicao, dt);
			}
		}
	}
}
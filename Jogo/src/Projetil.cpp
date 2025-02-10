#include "../../include/Projetil.hpp"

namespace Entidade {
	namespace Item {

		Projetil::Projetil(Personagem::Personagem* p, sf::Vector2f tam) : Arma(p, tam, IDs::IDs::projetil), direcao(p->getDirecao()), colidiu(false), velocidade(sf::Vector2f(0.0f, 0.0f)), IDPersonagem(p->getID()){
			if (p != nullptr) {
				dano = p->getDano() + DANO_PROJETIL;
				p->setArma(this);
				if (p->getID() == IDs::IDs::jogador)
					inicializarSprite(IDs::IDs::jogador);
				else if (p->getID() == IDs::IDs::minotauro)
					inicializarSprite(IDs::IDs::minotauro);
			}
		}
		Projetil::~Projetil() {
			setVelocidade(sf::Vector2f(0.0f, 0.0f));
			setColidiu(true);
		}
		void Projetil::inicializarSprite(IDs::IDs ID) {
			if (ID == IDs::IDs::jogador)
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PROJETIL_PATH, 1);
			else if (ID == IDs::IDs::minotauro)
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, PROJETILM_PATH, 10);
		}
		void Projetil::atualizarSprite(float dt) {
			if (!colidiu && IDPersonagem == IDs::IDs::minotauro)
				sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, pos, dt);
			else if (!colidiu && IDPersonagem == IDs::IDs::jogador) {
				sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, pos, dt);
			}
		}

		void Projetil::setColidiu(const bool colidiu)
		{
			this->colidiu = colidiu;
				
			if (colidiu) {
				velocidade = sf::Vector2f(0, 0);
				setPos(sf::Vector2f(-500.0f, -500.0f));
				setAtivo(false);
			}
		}

		void Projetil::atualizarPosicao() {
			const float dt = 0.016f;
			sf::Vector2f posFinal(0.0f, 0.0f);

			//MRU
			posFinal.x = pos.x + velocidade.x * dt;

			//MRUV
			posFinal.y = pos.y + velocidade.y * dt + (-GRAVIDADE * (dt * dt))/2.0f;

			setPos(posFinal);
		}

		void Projetil::colisao(Entidade* ent, const sf::Vector2f diferenca) {
			if (pPersonagem->getID() == IDs::IDs::jogador) {
				if (ent->getID() == IDs::IDs::gorgona || ent->getID() == IDs::IDs::guerreiraAthena || ent->getID() == IDs::IDs::minotauro) {
					Personagem::Personagem* p = dynamic_cast<Personagem::Personagem*>(ent);
					if (!p->getMorrendo()) {
						p->tomarDano(dano, pPersonagem);
						setColidiu(true);
						if (p->getMorrendo()) {
							//Morreu
						}
						else {
							sf::Vector2f posInimigo = p->getPos();
							p->setPos(sf::Vector2f(pPersonagem->getDirecao() ? posInimigo.x + 10.0f : posInimigo.x - 10.0f, posInimigo.y + 5.0f));
						}
					}
				}
			}
		}

		void Projetil::salvar(nlohmann::json& j) {
			j["ID"] = (int)getID();
			j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
			j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
			j["velocidade"] = { {"x", velocidade.x}, {"y", velocidade.y} };
			j["direcao"] = direcao;
			j["dano"] = dano;
			j["colidiu"] = colidiu;
		}

		void Projetil::desenhar() {
			if (!colidiu) {
				//pGG->desenharElemento(corpo);
				sprite.desenhar();
			}
		}

		void Projetil::atualizar() {
			if (!colidiu) {
				atualizarPosicao();
				atualizarSprite(0.016f);
				desenhar();
			}
		}
	}
}
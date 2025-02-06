#include "../../include/Projetil.hpp"

namespace Entidade {
	namespace Item {

		Projetil::Projetil(Personagem::Personagem* p, sf::Vector2f tam) : Arma(p, tam, IDs::IDs::projetil), direcao(p->getDirecao()), colidiu(false), velocidade(sf::Vector2f(0.0f, 0.0f)){
			if (p != nullptr) {
				dano = p->getDano() + DANO_PROJETIL;
			}
			p->setArma(this);
			inicializarSprite();
		}
		Projetil::~Projetil() {
		}
		void Projetil::inicializarSprite() {
			//sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PROJETIL_PATH, 1);
		}
		void Projetil::atualizarSprite(float dt) {
			if (!colidiu)
				sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, pos, dt);
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
			pGG->desenharElemento(corpo);
			//sprite.desenhar();
		}

		void Projetil::verificaSaiuTela() {
			sf::Vector2f posicao = pos;
			posicao.x += tam.x / 2.0f;
			posicao.y += tam.y / 2.0f;
			//cout << posicao.y << endl;
			if (posicao.y >= 600.0f) {
				setColidiu(true);
			}
		}

		void Projetil::atualizar() {
			if (!colidiu) {
				atualizarPosicao();
				verificaSaiuTela();
				//cout << pos.x << " " << pos.y << endl;
				//atualizarSprite(pGG->getTempo());
				desenhar();
			}
		}
	}
}
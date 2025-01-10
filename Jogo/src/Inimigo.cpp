 #include "../include/Inimigo.hpp"
#include <math.h>


namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			Inimigo::Inimigo(const sf::Vector2f pos, Jogador::Jogador* pJ) :
				Personagem(pos, sf::Vector2f(TAM_INIMIGO_X, TAM_INIMIGO_Y), VELOCIDADE_INIMIGO, IDs::IDs::inimigo), pJog(pJ){
			}

			Inimigo::~Inimigo() { pJog = nullptr; }

			bool Inimigo::procuraJogador() {
				if (pJog != nullptr) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					if (fabs(posJog.x - posInim.x) <= RAIO_VISAO_X && fabs(posJog.y - posInim.y) <= RAIO_VISAO_Y) {
						return true;
					}
				}
				return false;
			}

			void  Inimigo::mover() {
				if (procuraJogador()) {
					sf::Vector2f posJog = pJog->getPos();
					sf::Vector2f posInim = getPos();
					sf::Vector2f tamInim = getTam();
					if (posJog.x - posInim.x > 0.0f) {
						direcao = true;
						andar(direcao); // direita
					}
					else {
						direcao = false;
						andar(direcao); // esquerda
					}
				}
				else { // movimento "aleatorio", se nao achou jogador segue em uma linha reta até chegar em um limite.
					if (direcao) {
						andar(true);
					}
					else {
						andar(false);
					}
				}
			}

			void Inimigo::desenhar() {
				pGG->desenharElemento(corpo);
			}

			void Inimigo::atualizar() {
				if (getMorrendo()) {
					podeRemover();
				}
				mover();
				atualizarPosicao();
			}

			void Inimigo::colisao(Entidade* ent, const sf::Vector2f diferenca) {
				if (ent->getID() == IDs::IDs::jogador) {
					cout << "achou jogador" << endl;
				}
				switch (ent->getID())
				{
					case IDs::IDs::jogador: {
						cout << "Mamou!" << endl;
					}
					break;
					case IDs::IDs::plataforma: {
						
					}
					break;
					default:
						break;
				}
			}
			void Inimigo::inicializarSprite()
			{
			}
			void Inimigo::atualizarSprite(float dt)
			{
			}

			void Inimigo::salvar(nlohmann::json& j) {
				j["ID"] = (int)getID();
				j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
				j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
				j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
				j["direcao"] = direcao;
			}
		}
	}
}
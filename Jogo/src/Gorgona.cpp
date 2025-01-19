#include "../include/Gorgona.hpp"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gorgona::Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ)
                : Inimigo(pos, sf::Vector2f(TAMANHO_GORGONA_X, TAMANHO_GORGONA_Y), pJ, IDs::IDs::gorgona) {
				vida = VIDA_GORGONA;
				setDano(DANO_GORGONA);
                inicializarSprite();
            }

            Gorgona::Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ, Jogador::Jogador* pJ2)
                : Inimigo(pos, sf::Vector2f(TAMANHO_GORGONA_X, TAMANHO_GORGONA_Y), pJ, pJ2, IDs::IDs::gorgona) {
                vida = VIDA_GORGONA;
                setDano(DANO_GORGONA);
                inicializarSprite();
            }

            Gorgona::~Gorgona() {}

            void Gorgona::desenhar() {
                desenharInimigo();
            }

            void Gorgona::salvar(nlohmann::json& j)
            {

                j["ID"] = (int)getID();
                j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
                j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
                j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
                j["direcao"] = direcao;
                j["vida"] = vida;
                j["tempoAtaque"] = tempoAtaque;
                j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
                j["atacando"] = atacando;

            }

            void Gorgona::inicializarSprite() {
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADOG_PATH, 7);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDARG_PATH, 13);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUEG_PATH, 16);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::levouDano, DANOG_PATH, 3);
            }

            void Gorgona::atualizarSprite(float dt) {

                pos.x += TAMANHO_GORGONA_X / 2.4f;
                pos.y += TAMANHO_GORGONA_Y / 2.7f;

                if (andando && colisaoChao) {
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, pos, dt);
				}
				else if (atacando && !andando) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, pos, dt);
				}
				else if (levandoDano) {
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, pos, dt);
				}
                else
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, pos, dt);

            }

        }
    }
}

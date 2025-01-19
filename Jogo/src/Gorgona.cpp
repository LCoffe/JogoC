#include "../include/Gorgona.hpp"

namespace Entidade {
    namespace Personagem {
        namespace Inimigo {
            Gorgona::Gorgona(const sf::Vector2f pos, Jogador::Jogador* pJ)
                : Inimigo(pos, pJ, IDs::IDs::gorgona) {
                inicializarSprite();
            }

            Gorgona::~Gorgona() {}

            void Gorgona::atualizar() {
                mover();
                atualizarPosicao();
                atualizarSprite(pGG->getTempo());

            }

            void Gorgona::desenhar() {
                sprite.desenhar();
            }

            void Gorgona::salvar(nlohmann::json& j)
            {

                j["ID"] = (int)getID();
                j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
                j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
                j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
                j["direcao"] = direcao;

            }

            void Gorgona::colisao(Entidade* ent, const sf::Vector2f diferenca) {
                if (ent->getID() == IDs::IDs::jogador) {
                    cout << "Gorgona atacou o jogador!" << endl;
                }
            }


            void Gorgona::inicializarSprite() {

                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADOG_PATH, 7);
                sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDARG_PATH, 13);
            }

            void Gorgona::atualizarSprite(float dt) {

                pos.x += TAM_INIMIGO_X / 2.4f;
                pos.y += TAM_INIMIGO_Y / 2.7f;

                if (andando) {
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, pos, dt);
                }
                else 
                    sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, pos, dt);

            }

         

        }
    }
}

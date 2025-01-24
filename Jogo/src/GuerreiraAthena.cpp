#include "../include/GuerreiraAthena.hpp"

namespace Entidade {
	namespace Personagem {
		namespace Inimigo {
			GuerreiraAthena::GuerreiraAthena(const sf::Vector2f pos, Jogador::Jogador* pJ)
				: Inimigo(pos, sf::Vector2f(TAMANHO_GUERREIRA_ATHENA_X, TAMANHO_GUERREIRA_ATHENA_Y), pJ, IDs::IDs::guerreiraAthena)
			{	
				vida = VIDA_GUERREIRA_ATHENA;
				setDano(DANO_GUERREIRA_ATHENA);
				inicializarSprite();
			}
			GuerreiraAthena::GuerreiraAthena(const sf::Vector2f pos, Jogador::Jogador* pJ, Jogador::Jogador* pJ2)
				: Inimigo(pos, sf::Vector2f(TAMANHO_GUERREIRA_ATHENA_X, TAMANHO_GUERREIRA_ATHENA_Y), pJ, pJ2, IDs::IDs::guerreiraAthena)
			{
				vida = VIDA_GUERREIRA_ATHENA;
				setDano(DANO_GUERREIRA_ATHENA);
				inicializarSprite();
			}
			GuerreiraAthena::~GuerreiraAthena() {}

			void GuerreiraAthena::inicializarSprite() {
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::idle, PARADOGA_PATH, 4);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::walk, ANDANDOGA_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::attack, ATAQUEGA_PATH, 6);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::levouDano, MACHUCADOGA_PATH, 7);
				sprite.adicionarNovaAnimacao(ElementosGraficos::ID_ANIMACAO::morte, MORREGA_PATH, 7);
			}

			void GuerreiraAthena::atualizarSprite(float dt) {
				if (direcao) {
					pos.x += TAMANHO_GUERREIRA_ATHENA_X / 0.50f;
					pos.y += TAMANHO_GUERREIRA_ATHENA_Y / 2.7f;
				}
				else {
					pos.x += TAMANHO_GUERREIRA_ATHENA_X / 0.90f;
					pos.y += TAMANHO_GUERREIRA_ATHENA_Y / 2.7f;
				}
				
				if(morrendo)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::morte, direcao, pos, dt);
				else if (andando && colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, pos, dt);
				else if (atacando)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, pos, dt);
				else if(levandoDano)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, pos, dt);
				else
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, pos, dt);
			}
			void GuerreiraAthena::desenhar() {
				//pGG->desenharElemento(corpo);
				desenharInimigo();
			}

			void GuerreiraAthena::salvar(nlohmann::json& j) {
				j["ID"] = (int)getID();
				j["posicao"] = { {"x", pos.x}, {"y", pos.y} };
				j["tamanho"] = { {"x", tam.x}, {"y", tam.y} };
				j["velocidade"] = { {"x", velocidadeFinal.x}, {"y", velocidadeFinal.y} };
				j["direcao"] = direcao;
				j["vida"] = vida;
				j["tempoAtaque"] = tempoAtaque;
				j["posArma"] = { {"x", pArma->getPos().x}, {"y", pArma->getPos().y} };
				j["atacando"] = atacando;
				j["andando"] = andando;
				j["levandoDano"] = levandoDano;
				j["tempoDano"] = tempoDano;
				j["morrendo"] = morrendo;
				j["tempoMorte"] = tempoMorte;
			}
		}
	}
}
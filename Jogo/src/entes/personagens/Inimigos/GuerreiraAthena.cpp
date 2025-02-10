#include "../../include/entes/personagens/inimigos/GuerreiraAthena.hpp"

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
				sf::Vector2f posicao = pos;
				if (direcao) {
					posicao.x += TAMANHO_GUERREIRA_ATHENA_X/ 0.95f;
					posicao.y += TAMANHO_GUERREIRA_ATHENA_Y / 2.7f;
				}
				else {
					posicao.x += TAMANHO_GUERREIRA_ATHENA_X * 0.009f;
					posicao.y += TAMANHO_GUERREIRA_ATHENA_Y / 2.7f;
				}
				
				if(morrendo)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::morte, direcao, posicao, dt);
				else if (andando && colisaoChao)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::walk, direcao, posicao, dt);
				else if (atacando)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::attack, direcao, posicao, dt);
				else if(levandoDano)
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::levouDano, direcao, posicao, dt);
				else
					sprite.atualizar(ElementosGraficos::ID_ANIMACAO::idle, direcao, posicao, dt);
			}
			void GuerreiraAthena::desenhar() {
				if(!remover)
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
				j["pontuacao"] = 0;
				j["colisaoChao"] = colisaoChao;
			}
		}
	}
}
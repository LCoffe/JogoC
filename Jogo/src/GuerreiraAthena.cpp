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
				/*sprite.setSpriteSheet("GuerreiraAthena");
				sprite.setEscala(0.5f, 0.5f);
				sprite.setOrigem(0.5f, 0.5f);
				sprite.setPosicao(posicao);*/
			}

			void GuerreiraAthena::atualizarSprite(float dt) {
				/*sprite.setPosicao(posicao);
				sprite.atualizar(dt);*/
			}
			void GuerreiraAthena::desenhar() {
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
			}
		}
	}
}
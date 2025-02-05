#pragma once

#include "../../stdafx/stdafx.hpp"
#include "../../include/entes/personagens/Personagem.hpp"
#include "../../include/json.hpp"
#include "../../include/Arma.hpp"
#include "../../include/Projetil.hpp"

#define VELOCIDADE_JOGADOR 80.0f
#define ALTURA_PULO 900.0f
#define TAM_JOGADOR_X 50.0f
#define TAM_JOGADOR_Y 50.0f
#define DANO_JOGADOR 10.0f
#define VIDA_JOGADOR 100.0f

constexpr auto PARADO_PATH = "..\\Jogo\\assets\\jogador\\jogador_parado.png";
constexpr auto ANDAR_PATH = "..\\Jogo\\assets\\jogador\\jogador_andar.png";
constexpr auto PULO_PATH = "..\\Jogo\\assets\\jogador\\jogador_pulo.png";
constexpr auto ATAQUE_PATH = "..\\Jogo\\assets\\jogador\\jogador_ataque.png";
constexpr auto DANO_PATH = "..\\Jogo\\assets\\jogador\\jogador_machucado.png";
constexpr auto PETRIFICADO_PATH = "..\\Jogo\\assets\\jogador\\jogador_pedra.png";
constexpr auto MORTE_PATH = "..\\Jogo\\assets\\jogador\\jogador_morte.png";

namespace Observado {
	namespace Observador {
		class ObservadorJogador;
	}
}

namespace Entidade {
	namespace Personagem {
		namespace Jogador {
			class Jogador : public Personagem {
			private:
				vector<Item::Arma*> armas;
				int armaAtual;
				Observado::Observador::ObservadorJogador* pObs;
				bool petrificado;
				bool podePular;
				bool jogadorUm;
				int pontuacao;
				float tempoPetrificado;
			public:
				Jogador(const sf::Vector2f pos);
				~Jogador();
				void pular();
				void setJogadorUm(bool jogadorUm) { this->jogadorUm = jogadorUm; }
				bool getJogadorUm() { return jogadorUm; }
				void setPetrificado(bool petrificado) { this->petrificado = petrificado; }
				bool getPetrificado() { return petrificado; }
				void desenhar();
				void atualizar();
				void addPontuacao(int pontuacao) { this->pontuacao += pontuacao; }
				int getPontuacao() { return pontuacao; }
				void colisao(Entidade* ent, sf::Vector2f diferenca);
				void setAtivoObs(const bool ativo);
				void trocarArma();
				void setArmaAtual(int pos) { armaAtual = pos; }
				int getTamanhoArmas() { return static_cast<int>(armas.size()); }
				void inicializarSprite();
				void atualizarTempoAtaque();
				void atualizarSprite(float dt);
				void salvar(nlohmann::json& j);
				void operator+=(Item::Arma* pArma) { armas.push_back(pArma); }
			};
		}
	}
}
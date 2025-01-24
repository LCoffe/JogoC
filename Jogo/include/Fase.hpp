#pragma once

#include "../include/Ente.hpp"

#include "../include/ListaEntidade.hpp"
#include "../include/Entidade.hpp"
#include "../include/Personagem.hpp"

#include "../include/Obstaculo.hpp"
#include "../include/Plataforma.hpp"

#include "../include/GerenciadorColisoes.hpp"
#include "../include/GerenciadorSalvar.hpp"

#include "../include/GuerreiraAthena.hpp"
#include "../include/Gorgona.hpp"
#include "../include/Inimigo.hpp"
#include "../include/Jogador.hpp"
#include "../include/Arma.hpp"

namespace Observado {
	namespace Observador {
		class ObservadorFase;
	}
}

namespace Fase {
	class Fase : public Ente {
		private:
			static Observado::Observador::ObservadorFase* pObsFase;
		protected:
			Lista::ListaEntidade* pListaPersona;
			Lista::ListaEntidade* pListaObstaculo;
			static Entidade::Personagem::Jogador::Jogador* pJogador;
			static Entidade::Personagem::Jogador::Jogador* pJogadorDois;
			int pontuacao;
			bool doisJogadores;
			Gerenciador::GerenciadorColisoes* pGC;
			Gerenciador::GerenciadorSalvar* pGS;

			void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, bool jogadorUm);
			void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, sf::Vector2f posArma, bool atacando, bool petrifica, bool levandoDano
				, float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao); //Metodo usado para carregar os personagens
			void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
			void criaLimite();
		public:
			Fase(IDs::IDs ID_Fase);
			~Fase();
			Entidade::Personagem::Jogador::Jogador* getJogador() { return pJogador; }
			Entidade::Personagem::Jogador::Jogador* getJogadorDois() { return pJogadorDois; }
			void setDoisJogadores(bool doisJogadores) { this->doisJogadores = doisJogadores; }
			bool getDoisJogadores() { return doisJogadores; }
			void setPontuacao(int pontuacao) { this->pontuacao = pontuacao; }
			int getPontuacao() { return pontuacao; }
			void atualizaPontuacao();
			void salvarColocacao(string nome);
			void desenhar();
			void setAtivoObs(const bool ativo);
			void executar();
			void salvar();
			void gerenciarColisoes();
	};
}
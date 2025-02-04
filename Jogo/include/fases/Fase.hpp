#pragma once

#include "../../include/entes/Ente.hpp"

#include "../../include/listas/ListaEntidade.hpp"
#include "../../include/entes/Entidade.hpp"
#include "../../include/entes/personagens/Personagem.hpp"
#include "../../include/Parallax.hpp"

#include "../../include/entes/obstaculos/Obstaculo.hpp"
#include "../../include/entes/obstaculos/Plataforma.hpp"

#include "../../include/gerenciadores/GerenciadorColisoes.hpp"
#include "../../include/gerenciadores/GerenciadorSalvar.hpp"

#include "../../include/entes/personagens/inimigos/GuerreiraAthena.hpp"
#include "../../include/entes/personagens/Inimigos/Gorgona.hpp"
#include "../../include/entes/personagens/inimigos/Inimigo.hpp"
#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/entes/obstaculos/Caixa.hpp"
#include "../../include/Arma.hpp"
#include "../../include/Projetil.hpp"

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
		Fundo::Parallax* fundo;

		Lista::ListaEntidade* pListaPersona;
		Lista::ListaEntidade* pListaObstaculo;
		static Entidade::Personagem::Jogador::Jogador* pJogador;
		static Entidade::Personagem::Jogador::Jogador* pJogadorDois;
		int pontuacao;
		bool doisJogadores;
		Gerenciador::GerenciadorColisoes* pGC;
		Gerenciador::GerenciadorSalvar* pGS;

		virtual void iniciaFundo() = 0;
		void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, bool jogadorUm);
		void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, sf::Vector2f posArma, bool atacando, bool petrifica, bool levandoDano
			, float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao); //Metodo usado para carregar os personagens
		void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool arrastado, bool colisaoParede);
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
		void atualizaFundo();
		void salvarColocacao(string nome);
		void desenhar();
		void setAtivoObs(const bool ativo);
		void executar();
		void salvar();
		void gerenciarColisoes();
	};
}
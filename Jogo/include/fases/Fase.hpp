#pragma once

#include "../../include/entes/Ente.hpp"

#include "../../include/listas/ListaEntidade.hpp"
#include "../../include/entes/Entidade.hpp"
#include "../../include/entes/personagens/Personagem.hpp"
#include "../../include/Parallax.hpp"

#include "../../include/entes/obstaculos/Obstaculo.hpp"
#include "../../include/entes/obstaculos/Plataforma.hpp"
#include "../../include/entes/obstaculos/Caixa.hpp"
#include "../../include/entes/obstaculos/Espinho.hpp"
#include "../../include/entes/obstaculos/Portao.hpp"
#include "../../include/entes/obstaculos/MaoCondenados.hpp"

#include "../../include/gerenciadores/GerenciadorColisoes.hpp"
#include "../../include/gerenciadores/GerenciadorSalvar.hpp"

#include "../../include/entes/personagens/inimigos/GuerreiraAthena.hpp"
#include "../../include/entes/personagens/Inimigos/Gorgona.hpp"
#include "../../include/entes/personagens/Inimigos/Minotauro.hpp"
#include "../../include/entes/personagens/inimigos/Inimigo.hpp"
#include "../../include/entes/personagens/jogador/Jogador.hpp"
#include "../../include/Arma.hpp"
#include "../../include/Projetil.hpp"


#include "../mapas/Mapa.hpp"

#define NUM_MIN_INSTANCIA 3
#define NUM_MAX_INSTANCIA 4

namespace Observado {
	namespace Observador {
		class ObservadorFase;
	}
}

namespace Fase {
	class Fase : public Ente {
	private:
		Observado::Observador::ObservadorFase* pObsFase;
	protected:
		Fundo::Parallax* fundo;
		Mapa* mapa;
		Lista::ListaEntidade* pListaPersona;
		Lista::ListaEntidade* pListaObstaculo;
		static Entidade::Personagem::Jogador::Jogador* pJogador;
		static Entidade::Personagem::Jogador::Jogador* pJogadorDois;
		int pontuacao;
		bool doisJogadores;
		bool temInimigoVivo;
		Gerenciador::GerenciadorColisoes* pGC;
		Gerenciador::GerenciadorSalvar* pGS;

		virtual void iniciaFundo() = 0;
		void criaPersonagem1Jog(const sf::Vector2f pos, const IDs::IDs ID);
		void criaPersonagem2Jog(const sf::Vector2f pos, const IDs::IDs ID, bool jogadorUm);
		void carregaPersonagem1Jog(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, int armaAtual, sf::Vector2f posArma, const IDs::IDs IDArma, sf::Vector2f velArma, bool colidiu, bool direcaoArma, bool ativo, bool atacando, bool petrifica, bool levandoDano
			, float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao); //Metodo usado para carregar os personagens com 1 jogador
		void carregaPersonagem2Jog(const sf::Vector2f pos, const IDs::IDs ID, const sf::Vector2f tam, const sf::Vector2f vel, bool direcao, bool jogadorUm, float vida, float tempoAtaque, sf::Vector2f posArma, sf::Vector2f velArma, bool colidiu, bool direcaoArma, bool ativo, bool atacando, bool petrifica, bool levandoDano,
			float tempoDano, bool morrendo, float tempoMorrendo, int pontuacao, bool colisaoChao); //Metodo usado para carregar os personagens com 2 jogadores
		//void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		//void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool arrastado, bool colisaoParede);
		Entidade::Item::Arma* carregaArma(Entidade::Personagem::Personagem* p, const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool colidiu, bool direcao, const sf::Vector2f velocidade, bool ataquePetrificante, bool ativo);
		void criaLimite();
	public:
		void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID, bool arrastado, bool colisaoParede, bool aberto);
		void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		Fase(IDs::IDs ID_Fase);
		~Fase();
		void setJogador(Entidade::Personagem::Jogador::Jogador* pJogador) { this->pJogador = pJogador; }
		void setJogadorDois(Entidade::Personagem::Jogador::Jogador* pJogadorDois) { this->pJogadorDois = pJogadorDois; }
		Entidade::Personagem::Jogador::Jogador* getJogador() { return pJogador; }
		Entidade::Personagem::Jogador::Jogador* getJogadorDois() { return pJogadorDois; }
		void setInimigoVivo(bool temInimigoVivo) { this->temInimigoVivo = temInimigoVivo; }
		bool getInimigoVivo() { return temInimigoVivo; }
		void setDoisJogadores(bool doisJogadores) { this->doisJogadores = doisJogadores; }
		bool getDoisJogadores() { return doisJogadores; }
		void abrePortao(bool temInimigo);
		void setPontuacao(int pontuacao) { this->pontuacao = pontuacao; }
		int getPontuacao() { return pontuacao; }
		void atualizaPontuacao();
		void atualizaFundo();
		void salvarColocacao(string nome);
		void desenhar();
		virtual void desenharMapa() {}
		void setAtivoObs(const bool ativo);
		void executar();
		void salvar();
		void gerenciarColisoes();
	};
}
#pragma once

#include "../include/ListaEntidade.hpp"

namespace Gerenciador {
	class GerenciadorColisoes {
	private:
		Lista::ListaEntidade* pListaPersonagem;
		Lista::ListaEntidade* pListaObstaculo;
		int auxLista;
	public:
		GerenciadorColisoes(Lista::ListaEntidade* pListaPersonagem, Lista::ListaEntidade* pListaObstaculo);
		~GerenciadorColisoes();
		void tratarColisaoPerObst(); //Tratamento da colisao do personagem com o obstaculo.
		void tratarColisaoJogInimigo(); //Tratamento da colisao do jogador com o inimigo.
		void verificaDoisJogadores();
		const bool verificaColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2) const;
		const sf::Vector2f calcColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
		void executar();
	};
}
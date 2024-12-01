#pragma once

#include "../include/ListaEntidade.hpp"

namespace Gerenciador {
	class GerenciadorColisoes {
	private:
		Lista::ListaEntidade* pListaPersonagem;
		Lista::ListaEntidade* pListaObstaculo;
	public:
		GerenciadorColisoes(Lista::ListaEntidade* pListaPersonagem, Lista::ListaEntidade* pListaObstaculo);
		~GerenciadorColisoes();
		const sf::Vector2f calcColisao(Entidade::Entidade* ent1, Entidade::Entidade* ent2);
		void executar();
	};
}
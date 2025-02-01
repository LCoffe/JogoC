#pragma once	

#include <SFML/Graphics.hpp>
#include <stack>
#include "../../include/Estado.hpp"

namespace Gerenciador {
	class GerenciadorEstado {
	private:
		std::stack<Estado::Estado*> pilhaEstado;

		static GerenciadorEstado* pGEst;
		GerenciadorEstado();

		void desativarObservadores();
		void ativarObservadores();
	public:

		~GerenciadorEstado();
		static GerenciadorEstado* getGerEstado();
		Estado::Estado* getEstado();
		void incluiEstado(const IDs::IDs ID, IDs::IDs IDFase,bool carregar);
		void removerEstado();
		void removerEstado(const int qntd);
		void executar();
	};
}
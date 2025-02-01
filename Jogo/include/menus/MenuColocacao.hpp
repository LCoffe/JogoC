#pragma once

#include "Menu.hpp"
#include "../gerenciadores/GerenciadorSalvar.hpp"

namespace Menu {
	class MenuColocacao : public Menu {
		private:
			static Gerenciador::GerenciadorSalvar* pGS;

			void criarBotoes();
			void criarTitulo();
			void criarFundo();
		public:
			MenuColocacao();
			~MenuColocacao();
			void limparColocacao();
			void executar();
	};
}
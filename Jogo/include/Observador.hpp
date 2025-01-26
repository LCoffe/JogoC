#pragma once

#include "../stdafx/stdafx.hpp"
#include "../gerenciadores/GerenciadorEstado.hpp"

namespace Gerenciador {
	class GerenciadorEstado;
}

namespace Observado {
	class Observado;
	namespace Observador {
		class Observador {
		private:
			bool ativar;
		protected:
			static Observado* pObservado;
			static Gerenciador::GerenciadorEstado* pGEst;
		public:
			Observador();
			virtual ~Observador();
			void setAtivar(const bool ativar) { this->ativar = ativar; }
			const bool getAtivar() const { return ativar; }
			virtual void attTeclaPressionada(sf::Keyboard::Key tecla) = 0;
			virtual void attTeclaUnica(sf::Keyboard::Key tecla) = 0;
		};
	}
}
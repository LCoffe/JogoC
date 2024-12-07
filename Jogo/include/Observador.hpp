#pragma once

#include "../stdafx/stdafx.hpp"

namespace Observado {
	class Observado;
	namespace Observador {
		class Observador {
		protected:
			static Observado* pObservado;
		public:
			Observador();
			virtual ~Observador();
			virtual void upTeclaPressionada(sf::Keyboard::Key tecla) = 0;
			virtual void upTeclaUnica(sf::Keyboard::Key tecla) = 0;
		};
	}
}
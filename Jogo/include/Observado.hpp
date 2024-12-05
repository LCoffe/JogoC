#pragma once

#include <SFML/Graphics.hpp>
#include "../include/Observador.hpp"

namespace Observado {
	class Observado {
		private:
			std::vector<Observador::Observador*> observadores;
			std::vector<Observador::Observador*>::iterator it;

			static Observado* pObservado; //Singleton
			Observado();
		public:
			~Observado();

			static Observado* getObservado();
			void incluirObservador(Observador::Observador* observador);
			void removerObservador(Observador::Observador* observador);
			void notificaTeclaPressionada(const sf::Keyboard::Key tecla);
			void notificaTeclaUnica(const sf::Keyboard::Key tecla);
	};
}
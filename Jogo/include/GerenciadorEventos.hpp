#pragma once

#include <SFML/Graphics.hpp>
#include "../include/GerenciadorGrafico.hpp"

namespace Observado {
	class Observado;
}

namespace Gerenciador {
	class GerenciadorEventos {
		private:
			sf::Event evento;
			
			static GerenciadorEventos* pGerenciadorEventos; //Singleton
			static GerenciadorGrafico* pGG;
			static Observado::Observado* pObservado;
			GerenciadorEventos();
		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerenciadorEventos();
			void tratarEventoJanela();
			void tratarTeclaPressionada();
			void tratarTeclaUnica();
			void tratarEventos();
			const sf::Event getEvento() const;
	};
}
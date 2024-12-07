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
			
			static GerenciadorEventos* pGE; //Singleton
			static GerenciadorGrafico* pGG;
			static Observado::Observado* pObservado;
			GerenciadorEventos();
		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerEventos();
			void tratarEventoJanela();
			void tratarTeclaPressionada();
			void tratarTeclaUnica();
			void tratarEventos();
			const sf::Event getEvento() const;
	};
}
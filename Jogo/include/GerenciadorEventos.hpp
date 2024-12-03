#pragma once

#include <SFML/Graphics.hpp>
#include "../include/GerenciadorGrafico.hpp"

namespace Subject {
	class Subject;
}

namespace Gerenciador {
	class GerenciadorEventos {
		private:
			sf::Event event;
			
			static GerenciadorEventos* pGerenciadorEventos; //Singleton
			static GerenciadorGrafico* pGG;
			static Subject::Subject* pSubject;
			GerenciadorEventos();
		public:
			~GerenciadorEventos();
			static GerenciadorEventos* getGerenciadorEventos();
			void tratarEventoJanela();
			void tratarKeyPressed();
			void tratarKeyReleased();
			void tratarEventos();
			const sf::Event getEvent() const;
	};
}
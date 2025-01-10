#pragma once

#include "../include/Estado.hpp"
#include "../include/Fase.hpp"

namespace Estado {
	class EstadoJogar : public Estado {
		private:
			Fase::Fase* fase;
			
			void criarFase(IDs::IDs IDFase);
			void carregaFase(IDs::IDs IDFase);
			void mudarAtivoObs(const bool ativo);
		public:
			EstadoJogar(IDs::IDs ID, IDs::IDs IDFase);
			EstadoJogar(IDs::IDs ID, IDs::IDs IDFase, bool carregar);
			~EstadoJogar();
			Fase::Fase* getFase() { return fase; }
			void executar();
	};
}
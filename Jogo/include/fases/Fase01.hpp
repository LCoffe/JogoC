#include "../../include/fases/Fase.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

namespace Fase {
	class Fase01 : public Fase {
		private:
			void criarMapa(bool doisJogadores);
		public:
			Fase01();
			~Fase01();

			void iniciaFase(bool doisJogadores);
			void carregaFase();
			void carregar();
	};
}
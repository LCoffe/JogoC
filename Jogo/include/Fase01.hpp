#include "../include/Fase.hpp"
#include "../include/Inimigo.hpp"

namespace Fase {
	class Fase01 : public Fase {
		private:
			void criarMapa();
		public:
			Fase01();
			~Fase01();
	};
}
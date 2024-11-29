#include "../include/Ente.hpp"

#include "../include/ListaEntidade.hpp"
#include "../include/Entidade.hpp"
#include "../include/Personagem.hpp"


#include "../include/Inimigo.hpp"
#include "../include/Jogador.hpp"

namespace Fase {
	class Fase : public Ente {
		private:

		protected:
			Lista::ListaEntidade* pListaPersona;
			static Entidade::Personagem::Jogador::Jogador* pJogador;

			void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID);
			//void criarEntidades();
		public:
			Fase(IDs::IDs ID_Fase);
			~Fase();
			Entidade::Personagem::Jogador::Jogador* getJogador() { return pJogador; }
			void draw();
			void executar();
	};
}
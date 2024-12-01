#include "../include/Ente.hpp"

#include "../include/ListaEntidade.hpp"
#include "../include/Entidade.hpp"
#include "../include/Personagem.hpp"

#include "../include/Obstaculo.hpp"
#include "../include/Plataforma.hpp"

#include "../include/GerenciadorColisoes.hpp"

#include "../include/Inimigo.hpp"
#include "../include/Jogador.hpp"

namespace Fase {
	class Fase : public Ente {
		private:

		protected:
			Lista::ListaEntidade* pListaPersona;
			Lista::ListaEntidade* pListaObstaculo;
			static Entidade::Personagem::Jogador::Jogador* pJogador;

			Gerenciador::GerenciadorColisoes* pGC;

			void criaPersonagem(const sf::Vector2f pos, const IDs::IDs ID);
			void criaPlataforma(const sf::Vector2f pos, const sf::Vector2f tam, const IDs::IDs ID);
		public:
			Fase(IDs::IDs ID_Fase);
			~Fase();
			Entidade::Personagem::Jogador::Jogador* getJogador() { return pJogador; }
			void draw();
			void executar();
	};
}
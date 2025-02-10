#include "../../include/fases/Fase.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

constexpr const char* const CAMINHO_TEX_FUNDO = "assets/fundos/fundo1.png";

namespace Fase {
	class Ponte : public Fase {
	private:

		sf::Texture tileset;
		sf::VertexArray tilemap;

		void criarMapa(bool doisJogadores);
		void iniciaFundo();
	public:
		Ponte();
		~Ponte();
		void iniciaFase(bool doisJogadores);
		void carregaFase();
		void trocaFase();
		void carregar();
	};
}
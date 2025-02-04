#include "../../include/fases/Fase.hpp"
#include "../../include/entes/personagens/Inimigos/Inimigo.hpp"

constexpr const char* const CAMINHO_TEX_FUNDO = "assets/fundos/fundo1.png";

namespace Fase {
	class Fase01 : public Fase {
	private:

		sf::Texture tileset;
		sf::VertexArray tilemap;

		void criarMapa(bool doisJogadores);
		void iniciaFundo();
	public:
		Fase01();
		~Fase01();
		void iniciaFase(bool doisJogadores);
		void carregaFase();
		void carregar();
	};
}
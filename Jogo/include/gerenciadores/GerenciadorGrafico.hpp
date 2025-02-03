#pragma once

#include "../../stdafx/stdafx.hpp"
#include "../../include/Camera.hpp"

#define TELA_X 1600
#define TELA_Y 900

constexpr const char* const CAMINHO_ICONE = "assets/icone/iconeJogo.jpg";

namespace Gerenciador {
	class GerenciadorGrafico {
	private:
		sf::RenderWindow* janela;
		Camera* camera;
		sf::Clock relogio;
		static float tempo;
		std::map<const char*, sf::Font*> mapaFontes;

		//contrutora privada para evitar instanciamento
		static GerenciadorGrafico* pGG;
		GerenciadorGrafico();
		public:
			~GerenciadorGrafico();
			static GerenciadorGrafico* getGerGrafico();
			void setJanela(sf::RenderWindow* janela);
			sf::Texture* incluirTextura(const string& caminho);
			sf::RenderWindow* getJanela() { return janela; }
			const sf::Vector2f getTamJanela() const ;
			void desenharElemento(sf::RectangleShape corpo);
			void desenharTexto(sf::Text* texto);
			void mostrarElementos();
			void limpar();
			void fechar();
			void atualizarCamera(const sf::Vector2f& pos, const sf::Vector2f tamJanela);
			const sf::View getCamera() const;
			const bool estaAberto();
			void resetarRelogio();
			const float getTempo() const { return tempo; }
			sf::Font* carregarFonte(const char* caminho);

			bool carregarTexturaFundo(const std::string& caminho);
			void atualizarParallax();
			void desenharFundo();

	};
}
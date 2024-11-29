#pragma once

#include "../stdafx/stdafx.hpp"

#define TELA_X 1366
#define TELA_Y 768

namespace Gerenciador {
	class GerenciadorGrafico {
		private:
			sf::RenderWindow* window;
			sf::Clock relogio;
			static float tempo;

			//contrutora privada para evitar instanciamento
			static GerenciadorGrafico* pGrafico;
			GerenciadorGrafico();
		public:
			~GerenciadorGrafico();
			static GerenciadorGrafico* getGerGrafico();
			void setWindow(sf::RenderWindow* window);
			sf::Texture* includeTexture(const string& path);
			sf::RenderWindow* getWindow() { return window; }
			const sf::Vector2f getTamWindow() const ;
			void drawElemento(sf::RectangleShape corpo);
			void mostrarElementos();
			void limpar();
			void fechar();
			const bool estaAberto();
			void resetarRelogio();
			const float getTempo() const { return tempo; }
	};
}
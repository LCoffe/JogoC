#pragma once

#include "../stdafx/stdafx.hpp"

#define TELA_X 1366
#define TELA_Y 768

namespace Gerenciador {
	class GerenciadorGrafico {
		private:
			sf::RenderWindow* janela;
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
			const bool estaAberto();
			void resetarRelogio();
			const float getTempo() const { return tempo; }
			sf::Font* carregarFonte(const char* caminho);
	};
}
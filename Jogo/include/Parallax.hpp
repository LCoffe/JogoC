#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Fundo {
    class Parallax {
    private:
        sf::Texture textura;
        sf::Sprite sprite;
        sf::Shader shader;
        float offset;
		float velParalax;
        sf::Clock relogio;

    public:
        Parallax();
        ~Parallax();
		void setVelParalax(float vel) { velParalax = vel; }
        bool carregarTextura(const std::string& caminho);
        void atualizar();
        void desenhar(sf::RenderWindow& janela);
    };
}
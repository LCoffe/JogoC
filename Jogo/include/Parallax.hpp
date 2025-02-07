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
        sf::Clock relogio;
        bool carregado;

    public:
        Parallax();
        ~Parallax();

        bool carregarTextura(const std::string& caminho);
        void atualizar();
        void desenhar(sf::RenderWindow& janela);
    };
}
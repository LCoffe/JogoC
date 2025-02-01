#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

constexpr const char* const CAMINHO_TEX_FUNDO = "assets/fundos/fundo01.png";

class Parallax {
private:
    sf::Texture textura;
    sf::Sprite sprite;
    sf::Shader shader;
    float offset;
    sf::Clock relogio;

public:
    Parallax();
    ~Parallax();

    bool carregarTextura(const std::string& caminho);
    void atualizar();
    void desenhar(sf::RenderWindow& janela);
};

#pragma once

#include "../../include/json.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

constexpr const char* const MAPA1_PATH = "assets\\mapas\\mapa1.tmj";

namespace Fase {
    class Fase;
}

class Mapa {
private:
    Fase::Fase* fase;
    sf::Texture texturaTileset;  // Agora armazenamos a textura do tileset
    std::vector<int> tiles;
    int largura, altura;
    int larguraTile, alturaTile;

public:
    Mapa(Fase::Fase* fase, const char* caminhoMapa, const std::string& caminhoTileset);
    bool carregarMapa(const char* caminhoMapa);
    bool carregarTileset(const std::string& caminhoTileset);
    void desenharMapa(sf::RenderWindow& janela);
};

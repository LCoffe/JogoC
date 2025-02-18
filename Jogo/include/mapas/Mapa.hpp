#pragma once

#include "../../include/json.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

constexpr const char* const MAPA1_PATH = "assets\\mapas\\ponte.tmj";
constexpr const char* const MAPA2_PATH = "assets\\mapas\\castelo.tmj";

namespace Fase {
    class Fase;
}

class Mapa {
private:
    Fase::Fase* fase;
    sf::Texture texturaTileset;  // Agora armazenamos a textura do tileset
    std::vector<int> tiles;
    std::vector<int> tilesDecorativos;
    int largura, altura;
    int larguraTile, alturaTile;
    std::vector<std::vector<int>> camadas;

public:
    Mapa(Fase::Fase* fase, const char* caminhoMapa, const std::string& caminhoTileset);
    bool carregarMapa(const char* caminhoMapa);
    bool carregarTileset(const std::string& caminhoTileset);
    void desenharMapa(sf::RenderWindow& janela);
};

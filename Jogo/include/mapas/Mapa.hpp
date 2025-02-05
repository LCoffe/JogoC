#pragma once

#include "../../include/json.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


constexpr auto MAPA1_PATH = "C:/Users/alano/source/repos/JogoC/Jogo/assets/mapas/mapa1.tmj";

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
    Mapa(Fase::Fase* fase, const std::string& caminhoMapa, const std::string& caminhoTileset);
    bool carregarMapa(const std::string& caminhoMapa);
    bool carregarTileset(const std::string& caminhoTileset);
    void desenharMapa(sf::RenderWindow& janela);
};

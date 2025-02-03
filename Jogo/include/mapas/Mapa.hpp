#pragma once

#include "../../include/json.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "../fases/Fase.hpp"

constexpr auto MAPA1_PATH = "C:/Users/alano/source/repos/JogoC/Jogo/assets/mapas/mapa1.tmj";
constexpr auto TILESET1_PATH = "C:/Users/alano/source/repos/JogoC/Jogo/assets/tilesets/babylon.tsx";


class Mapa {
private:
    Fase::Fase* fase;
    sf::Texture tileset;
    sf::VertexArray tilemap;
    int largura, altura, larguraTile, alturaTile;
    std::vector<int> tiles;

public:
    Mapa(Fase::Fase* fase, const std::string& caminhoMapa, const std::string& caminhoTileset);
    ~Mapa() {}

    bool carregarMapa(const std::string& caminhoMapa);
    bool carregarTileset(const std::string& caminhoTileset);
    void desenharMapa(sf::RenderWindow& janela);
};



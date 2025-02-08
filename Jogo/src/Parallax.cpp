#include "../include/Parallax.hpp"
#include "../../include/gerenciadores/GerenciadorGrafico.hpp"

namespace Fundo {
    Parallax::Parallax() : offset(0.f), velParalax(0.001f) {}

    Parallax::~Parallax() {}

    bool Parallax::carregarTextura(const std::string& caminho) {
        if (!textura.loadFromFile(caminho)) {
            std::cerr << "Erro ao carregar textura: " << caminho << std::endl;
            return false;
        }

        textura.setRepeated(true);
        sprite.setTexture(textura);
        sprite.setTextureRect(sf::IntRect(0, 0, TELA_X * 3, TELA_Y)); // Ajusta para repetir horizontalmente
        sprite.setScale(
            static_cast<float>(TELA_X) / textura.getSize().x,
            static_cast<float>(TELA_Y) / textura.getSize().y
        );
        sprite.setPosition(-1366 / 2.0f, 0); // Move para evitar partes pretas

        if (!shader.loadFromMemory(
            "uniform float offset;"
            "void main() {"
            "    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;"
            "    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;"
            "    gl_TexCoord[0].x = gl_TexCoord[0].x + offset;"
            "    gl_FrontColor = gl_Color;"
            "}",
            sf::Shader::Vertex)) {
            std::cerr << "Erro ao carregar shader de paralax!" << std::endl;
            return false;
        }

        return true;
    }

    void Parallax::atualizar() {
        offset += relogio.getElapsedTime().asSeconds() * velParalax;  // Ajusta a velocidade do efeito
        shader.setUniform("offset", offset);
        relogio.restart();
    }

    void Parallax::desenhar(sf::RenderWindow& janela) {
        janela.draw(sprite, &shader);
    }
}
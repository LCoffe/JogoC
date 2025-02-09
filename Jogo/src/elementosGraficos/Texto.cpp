#include "../../include/elementosGraficos/Texto.hpp"

#define TEXT_SIZE 24

namespace Menu {

	Gerenciador::GerenciadorGrafico* Texto::pGG = Gerenciador::GerenciadorGrafico::getGerGrafico();

	Texto::Texto(const sf::Vector2f pos, std::string info, const char* path):info(info) {

		texto.setString(info);
		texto.setFont(*pGG->carregarFonte(path));
		texto.setCharacterSize(TEXT_SIZE);
		setAlinhamentoTexto(TextAligment::left);
		texto.setPosition(sf::Vector2f(pos.x, pos.y));
		texto.setFillColor(sf::Color::White);
	}

	Texto::~Texto() {};

	void Texto::setInfoTexto(std::string info) {

		this->info = info;
		texto.setString(this->info);

	}

	void Texto::setPosicao(sf::Vector2f pos) {
		texto.setPosition(sf::Vector2f(pos.x, pos.y));
	}

	void Texto::setCorTexto(const unsigned int R, const unsigned int G, const unsigned int B)
	{
		texto.setFillColor(sf::Color(R, G, B));

	}

	void Texto::setCorBordaTexto(const unsigned int R, const unsigned int G, const unsigned int B)
	{
		texto.setOutlineColor(sf::Color(R, G, B));
		texto.setOutlineThickness(1.0f);
	}

	void Texto::setTamFonte(const unsigned int tam)
	{

		texto.setCharacterSize(tam);

	}

	void Texto::setAlinhamentoTexto(TextAligment opcao)
	{
		switch (opcao) {
		case TextAligment::left:
			texto.setOrigin(0, 0);
			break;
		case TextAligment::right:
			texto.setOrigin(getTam().x, 0);

		case TextAligment::center:
			texto.setOrigin(getTam().x/2, getTam().y);

		default:
			texto.setOrigin(getTam().x / 2, getTam().y);
			break;

		}


	}

	sf::Vector2f Texto::getTam()
	{
		sf::FloatRect textRect = texto.getLocalBounds();
		return sf::Vector2f(textRect.width, textRect.height);
	}


	std::string Texto::getInfo() const
	{
		return info;
	}

	sf::Vector2f Texto::getPos() const
	{
		return (texto.getPosition());
	}

	void Texto::desenhar()
	{
		pGG->desenharTexto(&texto);
	}


}
#include "../Principal.hpp"

Principal::Principal(): window(sf::VideoMode(800, 600), "Minha Janela SFML"), event(), 
jogador(sf::Vector2f(100, 100), sf::Vector2f(50, 50), "C:/Users/T-GAMER/OneDrive/Documentos/GITHUB/Jogo/Jogo/assets/greeksoldier.png"),
inimigo(sf::Vector2f(300,300), sf::Vector2f(40,40), "C:/Users/T-GAMER/OneDrive/Documentos/GITHUB/Jogo/Jogo/assets/athenasoldier.png") {
	inimigo.setJogador(&jogador);
}
Principal::~Principal() {}

void Principal::executar() {
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Escape)
					window.close();

		}
		jogador.mover();
		inimigo.procuraJogador();

		window.clear();
		window.draw(jogador.getCorpo());
		window.draw(inimigo.getCorpo());
		window.draw(inimigo.getVisao());
		window.display();
	}
}
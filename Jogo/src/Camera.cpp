#include "../include/Camera.hpp"

namespace Gerenciador {
	Camera::Camera(sf::Vector2f tamJanela) : tamJanela(tamJanela.x, tamJanela.y) {
		camera.setSize(tamJanela.x, tamJanela.y);
		camera.setCenter(tamJanela.x / 2.0f, tamJanela.y / 2.0f);
	}
	Camera::~Camera() {}

	void Camera::setTamJanela(const sf::Vector2f& tamJanela) {
		this->tamJanela = tamJanela;
	}

	sf::Vector2f Camera::getTamJanela() const {
		return tamJanela;
	}

	void Camera::atualizar(const sf::Vector2f& pos, const sf::Vector2f tamJanela) {
		sf::Vector2f posCamera = camera.getCenter();  // Pega a posição atual da câmera

		// Atualiza apenas no eixo X, mantendo a posição Y fixa
		camera.setCenter(pos.x, posCamera.y);
	}
	sf::View Camera::getCamera() const {
		return camera;
	}
}
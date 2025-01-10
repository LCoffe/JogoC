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
		camera.setCenter(pos);
		if (pos.x - tamJanela.x / 2 < 0) {
			camera.setCenter(tamJanela.x / 2, pos.y);
		}
		if (pos.y - tamJanela.y / 2 < 0) {
			camera.setCenter(pos.x, tamJanela.y / 2);
		}
		if (pos.x + tamJanela.x / 2 > this->tamJanela.x) {
			camera.setCenter(this->tamJanela.x - tamJanela.x / 2, pos.y);
		}
		if (pos.y + tamJanela.y / 2 > this->tamJanela.y) {
			camera.setCenter(pos.x, this->tamJanela.y - tamJanela.y / 2);
		}
	}
	sf::View Camera::getCamera() const {
		return camera;
	}
}
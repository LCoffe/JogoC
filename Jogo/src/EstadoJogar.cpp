#include "../include/EstadoJogar.hpp"
#include "../include/Fase01.hpp"

namespace Estado {
	EstadoJogar::EstadoJogar(IDs::IDs ID, IDs::IDs IDFase) : Estado(ID), fase(nullptr) {
		criarFase(IDFase);
	}
	EstadoJogar::EstadoJogar(IDs::IDs ID, IDs::IDs IDFase, bool carregar): Estado(ID), fase(nullptr) {
		if (carregar) {
			carregaFase(IDFase);
		}
	}
	EstadoJogar::~EstadoJogar() {
		if (fase) {
			delete fase;
			fase = nullptr;
		}
	}
	void EstadoJogar::criarFase(IDs::IDs IDFase) {
		if (ID == IDs::IDs::estadoJogar1Jog) {
			if (IDFase == IDs::IDs::fase01) {
				Fase::Fase01* fase01 = new Fase::Fase01();
				fase01->iniciaFase(false);
				fase = static_cast<Fase::Fase*>(fase01);
				if (fase == nullptr) {
					throw std::invalid_argument("Fase invalida");
				}
			}
			
		}
		else if (ID == IDs::IDs::estadoJogar2Jog) {
			if (IDFase == IDs::IDs::fase01) {
				Fase::Fase01* fase01 = new Fase::Fase01();
				fase01->iniciaFase(true);
				fase = static_cast<Fase::Fase*>(fase01);
				if (fase == nullptr) {
					throw std::invalid_argument("Fase invalida");
				}
			}
		}
		else {
			throw std::invalid_argument("ID invalido");
		}
	}

	void EstadoJogar::carregaFase(IDs::IDs IDFase) {
		if (IDFase == IDs::IDs::fase01) {
			Fase::Fase01* fase01 = new Fase::Fase01();
			fase01->carregaFase();
			fase = static_cast<Fase::Fase*>(fase01);
			if (fase == nullptr) {
				throw std::invalid_argument("Fase invalida");
			}
		}
	}

	void EstadoJogar::mudarAtivoObs(const bool ativo) {
		if (ativo) {
			fase->setAtivoObs(true);
		}
		else {
			fase->setAtivoObs(false);
		}
	}

	void EstadoJogar::executar() {
		fase->executar();
	}
}
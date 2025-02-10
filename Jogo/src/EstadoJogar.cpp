#include "../include/EstadoJogar.hpp"
#include "../include/fases/Ponte.hpp"
#include "../include/fases/Castelo.hpp"

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
			if (IDFase == IDs::IDs::ponte) {
				Fase::Ponte* ponte = new Fase::Ponte();
				ponte->iniciaFase(false);
				fase = static_cast<Fase::Fase*>(ponte);
				if (fase == nullptr) {
					//throw std::invalid_argument("Fase invalida");
					exit(1);
				}
			}
			else if (IDFase == IDs::IDs::castelo) {
				Fase::Castelo* castelo = new Fase::Castelo();
				castelo->iniciaFase(false);
				fase = static_cast<Fase::Fase*>(castelo);
				if (fase == nullptr) {
					//throw std::invalid_argument("Fase invalida");
					exit(1);
				}
			}
			
		}
		else if (ID == IDs::IDs::estadoJogar2Jog) {
			if (IDFase == IDs::IDs::ponte) {
				Fase::Ponte* ponte = new Fase::Ponte();
				ponte->iniciaFase(true);
				fase = static_cast<Fase::Fase*>(ponte);
				if (fase == nullptr) {
					//throw std::invalid_argument("Fase invalida");
					exit(1);
				}
			}
			else if (IDFase == IDs::IDs::castelo) {
				Fase::Castelo* castelo = new Fase::Castelo();
				castelo->iniciaFase(true);
				fase = static_cast<Fase::Fase*>(castelo);
				if (fase == nullptr) {
					//throw std::invalid_argument("Fase invalida");
					exit(1);
				}
			}
		}
		else {
			throw std::invalid_argument("ID invalido");
		}
	}

	void EstadoJogar::carregaFase(IDs::IDs IDFase) {
		if (IDFase == IDs::IDs::ponte) {
			Fase::Ponte* ponte = new Fase::Ponte();
			ponte->carregaFase();
			fase = static_cast<Fase::Fase*>(ponte);
			if (fase == nullptr) {
				//throw std::invalid_argument("Fase invalida");
				exit(1);
			}
		}
		else if (IDFase == IDs::IDs::castelo) {
			Fase::Castelo* castelo = new Fase::Castelo();
			castelo->carregaFase();
			fase = static_cast<Fase::Fase*>(castelo);
			if (fase == nullptr) {
				//throw std::invalid_argument("Fase invalida");
				exit(1);
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
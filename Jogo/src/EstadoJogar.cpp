#include "../include/EstadoJogar.hpp"
#include "../include/fases/Fase01.hpp"
#include "../include/fases/Fase02.hpp"

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
				fase = static_cast<Fase::Fase*>(fase01);  // Não precisa do cast, pois Fase01 já herda de Fase.
			}
			else if (IDFase == IDs::IDs::fase02) {  // Criando Fase02 corretamente
				Fase::Fase02* fase02 = new Fase::Fase02();
				fase02->iniciaFase(false);
				fase = static_cast<Fase::Fase*>(fase02);
			}
		}
		else if (ID == IDs::IDs::estadoJogar2Jog) {
			if (IDFase == IDs::IDs::fase01) {
				Fase::Fase01* fase01 = new Fase::Fase01();
				fase01->iniciaFase(true);
				fase = static_cast<Fase::Fase*>(fase01);
			}
			else if (IDFase == IDs::IDs::fase02) {  // Criando Fase02 corretamente
				Fase::Fase02* fase02 = new Fase::Fase02();
				fase02->iniciaFase(true);
				fase = static_cast<Fase::Fase*>(fase02);
			}
		}
		else {
			throw std::invalid_argument("ID invalido");
		}

		if (fase == nullptr) {
			std::cerr << "Erro: Fase não foi criada corretamente!" << std::endl;
			exit(1);
		}
	}

	void EstadoJogar::carregaFase(IDs::IDs IDFase) {
		if (IDFase == IDs::IDs::fase01) {
			Fase::Fase01* fase01 = new Fase::Fase01();
			fase01->carregaFase();
			fase = static_cast<Fase::Fase*>(fase01);
			if (fase == nullptr) {
				//throw std::invalid_argument("Fase invalida");
				exit(1);
			}

		}

		else if (IDFase == IDs::IDs::fase02) {

			Fase::Fase02* fase02  = new Fase::Fase02();
			fase02->carregaFase();
			fase = static_cast<Fase::Fase*>(fase02);
			if (fase == nullptr)
				exit(1);
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
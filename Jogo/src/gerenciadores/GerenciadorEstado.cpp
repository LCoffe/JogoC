#include "../../include/gerenciadores/GerenciadorEstado.hpp"
#include "../../include/EstadoMenu.hpp"
#include "../../include/EstadoJogar.hpp"
#include "../../include/fases/Ponte.hpp"
#include "../../include/fases/Castelo.hpp"

namespace Gerenciador {
	GerenciadorEstado* GerenciadorEstado::pGEst = nullptr;
	
	GerenciadorEstado::GerenciadorEstado() : pilhaEstado() {

	}

	GerenciadorEstado::~GerenciadorEstado() {
		while (!pilhaEstado.empty()) {
			delete pilhaEstado.top();
			pilhaEstado.top() = nullptr;
			pilhaEstado.pop();
		}

		if (pGEst) {
			delete pGEst;
			pGEst = nullptr;
		}
	}
	GerenciadorEstado* GerenciadorEstado::getGerEstado() {
		if (pGEst == nullptr) {
			pGEst = new GerenciadorEstado();
		}
		return pGEst;
	}

	void GerenciadorEstado::ativarObservadores() {
		Estado::Estado* estado = getEstado();

		estado->mudarAtivoObs(true);
	}

	void GerenciadorEstado::desativarObservadores() {
		Estado::Estado* estado = getEstado();
		
		estado->mudarAtivoObs(false);
	}

	void GerenciadorEstado::passouFase(const IDs::IDs ID) {
		if (ID == IDs::IDs::ponte) {
			Estado::EstadoJogar* estado = static_cast<Estado::EstadoJogar*>(getEstado());
			IDs::IDs IDEst = estado->getID();
			Fase::Fase* fase = estado->getFase();
			Fase::Ponte* aux = static_cast<Fase::Ponte*>(fase);
			aux->trocaFase();
			removerEstado();
			incluiEstado(IDEst, IDs::IDs::castelo, false);

			estado = static_cast<Estado::EstadoJogar*>(getEstado());
			Fase::Castelo* aux2 = static_cast<Fase::Castelo*>(estado->getFase());
			aux2->carregaTrocaFase();
		}
		else if (ID == IDs::IDs::castelo) {
			Estado::EstadoJogar* estado = static_cast<Estado::EstadoJogar*>(getEstado());
			Fase::Fase* fase = estado->getFase();
			if (fase->getDoisJogadores()) {
				removerEstado();
				incluiEstado(IDs::IDs::estadoJogar2Jog, IDs::IDs::ponte, false);
			}
			else {
				removerEstado();
				incluiEstado(IDs::IDs::estadoJogar1Jog, IDs::IDs::ponte, false);
			}
		}
	}

	void GerenciadorEstado::incluiEstado(const IDs::IDs ID, const IDs::IDs IDFase ,bool carregar) {
		Estado::Estado* estado = nullptr;
		if (ID == IDs::IDs::estadoMenuPrincipal) {
			estado = static_cast<Estado::Estado*>(new Estado::EstadoMenu(ID));
		}
		else if (ID == IDs::IDs::estadoJogar1Jog) {
			if (carregar) {
				estado = static_cast<Estado::Estado*>(new Estado::EstadoJogar(ID, IDFase, true));
			}
			else {
				estado = static_cast<Estado::Estado*>(new Estado::EstadoJogar(ID, IDFase));
			}
		}
		else if (ID == IDs::IDs::estadoJogar2Jog) {
			if (carregar) {
				estado = static_cast<Estado::Estado*>(new Estado::EstadoJogar(ID, IDFase, true));
			}
			else {
				estado = static_cast<Estado::Estado*>(new Estado::EstadoJogar(ID, IDFase));
			}
		}
		else if (ID == IDs::IDs::estadoMenuOpcoes) {
			Fase::Fase* pFase = nullptr;
			if (getEstado()->getID() == IDs::IDs::estadoJogar1Jog || getEstado()->getID() == IDs::IDs::estadoJogar2Jog) {
				Estado::EstadoJogar* pEJ = static_cast<Estado::EstadoJogar*>(getEstado());
				pFase = pEJ->getFase();
			}
			Estado::EstadoMenu* pEM = new Estado::EstadoMenu(ID);
			pEM->setFase(pFase);
			estado = static_cast<Estado::Estado*>(pEM);
		}
		else if (ID == IDs::IDs::estadoSalvarColocacao) {
			Fase::Fase* pFase = nullptr;
			if (getEstado()->getID() == IDs::IDs::estadoMorreu || getEstado()->getID() == IDs::IDs::estadoGanhou) {
				Estado::EstadoMenu* pAux = static_cast<Estado::EstadoMenu*>(getEstado());
				pFase = pAux->getFase();
			}
			Estado::EstadoMenu* pEM = new Estado::EstadoMenu(ID);
			if (pFase != nullptr) {
				pEM->setFase(pFase);
			}
			//pEM->setFase(pFase);
			estado = static_cast<Estado::Estado*>(pEM);
		}
		else if (ID == IDs::IDs::estadoMenuColocacao) {
			estado = static_cast<Estado::Estado*>(new Estado::EstadoMenu(ID));
		}
		else if (ID == IDs::IDs::estadoMorreu) {
			Fase::Fase* pFase = nullptr;
			if (getEstado()->getID() == IDs::IDs::estadoJogar1Jog || getEstado()->getID() == IDs::IDs::estadoJogar2Jog) {
				Estado::EstadoJogar* pEJ = static_cast<Estado::EstadoJogar*>(getEstado());
				pFase = pEJ->getFase();
			}
			Estado::EstadoMenu* pEM = new Estado::EstadoMenu(ID);
			pEM->setFase(pFase);
			estado = static_cast<Estado::Estado*>(pEM);
		}
		else if (ID == IDs::IDs::estadoMenuSelecionaFase) {
			estado = static_cast<Estado::Estado*>(new Estado::EstadoMenu(ID));
		}
		else if (ID == IDs::IDs::estadoGanhou) {
			Fase::Fase* pFase = nullptr;
			if (getEstado()->getID() == IDs::IDs::estadoJogar1Jog || getEstado()->getID() == IDs::IDs::estadoJogar2Jog) {
				Estado::EstadoJogar* pEJ = static_cast<Estado::EstadoJogar*>(getEstado());
				pFase = pEJ->getFase();
			}
			Estado::EstadoMenu* pEM = new Estado::EstadoMenu(ID);
			pEM->setFase(pFase);
			estado = static_cast<Estado::Estado*>(pEM);
		}
		else {
			//std::cerr << "ID invalido" << std::endl;
			exit(1);
		}

		if (estado == nullptr) {
			//std::cerr << "Erro ao criar o estado" << std::endl;
			exit(1);
		}

		if (!pilhaEstado.empty()) {
			desativarObservadores();
		}
		pilhaEstado.push(estado);
		ativarObservadores();
	}

	void GerenciadorEstado::removerEstado() {
		if (pilhaEstado.empty()) {
			return;
		}
		delete pilhaEstado.top();
		pilhaEstado.top() = nullptr;
		pilhaEstado.pop();
		if (!pilhaEstado.empty()) {
			ativarObservadores();
		}
		else {
			GerenciadorGrafico::getGerGrafico()->fechar();
		}
	}

	void GerenciadorEstado::removerEstado(const int qntd) {
		for (int i = 0; i < qntd; i++) {
			if (pilhaEstado.empty()) {
				return;
			}
			delete pilhaEstado.top();
			pilhaEstado.top() = nullptr;
			pilhaEstado.pop();
		}
		if (!pilhaEstado.empty()) {
			ativarObservadores();
		}
		else {
			GerenciadorGrafico::getGerGrafico()->fechar();
		}
		/*for (int i = 0; i < qntd; i++) {
			removerEstado();
		}*/
	}

	Estado::Estado* GerenciadorEstado::getEstado() {
		if (pilhaEstado.empty()) {
			return nullptr;
		}
		return pilhaEstado.top();
	}
	void GerenciadorEstado::executar() {
		if (!pilhaEstado.empty()) {
			Estado::Estado* estado = getEstado();
			estado->executar();
		}
	}
}
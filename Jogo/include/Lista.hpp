#pragma once


#include <iostream>
#include "IDs.hpp"
using namespace std;

namespace Lista {
	template<class TL>
	class Lista {
		public:
			//Classe Elemento aninhada na classe Lista
			template<class TE>
			class Elemento {
			private:
				TE* elemento;
				Elemento<TE>* prox;
			public:
				Elemento() { prox = nullptr; elemento = nullptr; }
				~Elemento() { prox = nullptr; elemento = nullptr; }
				void setElemento(TE* elemento) { this->elemento = elemento; }
				void setProx(Elemento<TE>* prox) { this->prox = prox; }
				Elemento<TE>* getProx() const { return prox; }
				TE* getElemento() const { return elemento; }
			};
		private:
			Elemento<TL>* pInicio;
			Elemento<TL>* pFim;
			unsigned int tam; // Tamanho da lista (nao precisa ter sinal)
		public:
			Lista();
			~Lista();
			void inserir(TL* elemento);
			void remover(TL* elemento);
			void removerElemento(int pos);
			int getTamanho() const { return static_cast<int>(tam); }
			void limpar();
			void operator++() { tam++; }
			void operator--() { tam--; }
			TL* operator[](int pos);
	};
	template<class TL>
	Lista<TL>::Lista() : pInicio(nullptr), pFim(nullptr), tam(0) {}

	template<class TL>
	Lista<TL>::~Lista() { /*limpar(); vou chamar limpar nas Listas com tipos*/ }

	template<class TL>
	void Lista<TL>::inserir(TL* elemento) {
		if(elemento == nullptr){
			//cout << "Elemento nulo" << endl;
			exit(1);
		}
		Elemento<TL>* novo = new Elemento<TL>();
		novo->setElemento(elemento);
		if (pInicio == nullptr) {
			pInicio = novo;
			pFim = novo;
		}else {
			pFim->setProx(novo);
			pFim = novo;
		}
		operator++();
	}

	template<class TL>
	void Lista<TL>::removerElemento(int pos) {
		TL* elemento = operator[](pos);
		remover(elemento);
	}

	template<class TL>
	void Lista<TL>::remover(TL * elemento) {
		Elemento<TL>* anterior = nullptr;
		Elemento<TL>* atual = pInicio;
		while (atual != nullptr && atual->getElemento() != elemento) {
			anterior = atual;
			atual = atual->getProx();
		}
		if (atual != nullptr) {
			if (atual->getElemento() == elemento) { // Elemento encontrado
				if (atual == pInicio) { // Elemento a ser removido eh o primeiro
					pInicio = atual->getProx();
				}
				else if (atual == pFim) { // Elemento a ser removido eh o ultimo
					pFim = anterior;
				}
				else {
					anterior->setProx(atual->getProx());
				}
				delete atual;
				atual = nullptr;
				anterior = nullptr;
				operator--();
			}
		}
	}

	template<class TL>
	void Lista<TL>::limpar() {
		if (pInicio != nullptr) {
			Elemento<TL>* aux = pInicio;
			Elemento<TL>* aux2 = nullptr;
			int i = 0;
			while (aux != nullptr && i < (int)tam) {
				TL* elemento = aux->getElemento();
				if (elemento != nullptr) {
					delete(elemento);
					elemento = nullptr;
				}
				aux2 = aux->getProx();
				delete(aux);
				aux = nullptr;
				aux = aux2;
				i++;
			}
		}
		pInicio = nullptr;
		pFim = nullptr;
		tam = 0;
	}
	template<class TL>
	TL* Lista<TL>::operator[](int pos) {
		if (pos < 0 || pos >= (int)tam) {
			//cout << "Posicao invalida" << endl;
			exit(1);
		}
		Elemento<TL>* atual = pInicio;
		for (int i = 0; i < pos; i++) {
			atual = atual->getProx();
		}
		return atual->getElemento();
	}
}
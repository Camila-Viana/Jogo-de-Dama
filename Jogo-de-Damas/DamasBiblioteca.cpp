#include "DamasBiblioteca.h"
#include <iostream>
#include <string>


Jogador::Jogador() {
	Nome = "jogador";
	Npeças = 12;
};

void Jogador::setname(std::string nome) {
	this->Nome = nome;
};

std::string Jogador::getname() {
	return this->Nome;
};

void Jogador::decreaseNpeças() {
	Npeças--;
}

int Jogador::getNpeças() {
	return this->Npeças;
};


void Peça::movimento(SDL_Rect _PosTela, int _PosTab) {};

void Peça::opçõesMovimento(SDL_Rect _PosTela, int _PosTab) {};


PeçaNormal::PeçaNormal(Jogador _jogador, SDL_Rect _PosTela, int _PosTab) {
	this->jogador = _jogador;
	this->PosTela->x = _PosTela.x;
	this->PosTela->y = _PosTela.y;
};

void PeçaNormal::PecasIniciais(Tabuleiro TabInicial, SDL_Rect _PosTela, int _PosTab){
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (TabInicial.Tabuleiroinicial[i][j] == 1) {

			}
			if (TabInicial.Tabuleiroinicial[i][j] == 2) {

			}
		}
	}
};

void PeçaNormal::movimento(SDL_Rect _PosTela, int _PosTab) {



};

void PeçaNormal::opçõesMovimento(SDL_Rect _PosTela, int _PosTab) {

};


void TransformandoDama(PeçaNormal peça) {



};


PeçaDama::PeçaDama(Jogador _jogador, SDL_Rect _PosTela, int _PosTab) {



};

void PeçaDama::movimento(SDL_Rect _PosTela, int _PosTab) {



};

void PeçaDama::opçõesMovimento(SDL_Rect _PosTela, int _PosTab) {



};

void Tabuleiro::setTabuleiroInicial() {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i == 0 || i == 2) && j % 2 == 0) {
				this->Tabuleiroinicial[i][j] = 2;
			}
			else {
				this->Tabuleiroinicial[i][j] = 0;
			}
			if (i == 1 && j % 2 == 1) {
				this->Tabuleiroinicial[i][j] = 2;
			}
			if ((i == 5 || i == 7) && j % 2 == 1) {
				this->Tabuleiroinicial[i][j] = 1;
			}
			if (i == 6 && j % 2 == 0) {
				this->Tabuleiroinicial[i][j] = 1;
			}
		}
	}
};

void DestrutorFinal() {

};

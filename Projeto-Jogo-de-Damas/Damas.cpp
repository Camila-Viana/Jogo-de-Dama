#include "Damas.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>


Jogador::Jogador() {
	Nome = "jogador";
	Npe�as = 12;
};

void Jogador::setname(std::string nome) {
	this->Nome = nome;
};

std::string Jogador::getname() {
	return this->Nome;
};

void Jogador::decreaseNpe�as() {
	Npe�as--;
}

int Jogador::getNpe�as() {
	return this->Npe�as;
};


void Pe�a::movimento(SDL_Rect _PosTela, int _PosTab) {};

void Pe�a::op��esMovimento(SDL_Rect _PosTela, int _PosTab) {};


Pe�aNormal::Pe�aNormal(Jogador _jogador, SDL_Rect _PosTela, int _PosTab) {
	this->jogador = _jogador;
	this->PosTela->x = _PosTela.x;
	this->PosTela->y = _PosTela.y;
};

void Pe�aNormal::PecasIniciais(Tabuleiro TabInicial, SDL_Rect _PosTela, int _PosTab){
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

void Pe�aNormal::movimento(SDL_Rect _PosTela, int _PosTab) {



};

void Pe�aNormal::op��esMovimento(SDL_Rect _PosTela, int _PosTab) {

};


void TransformandoDama(Pe�aNormal pe�a) {



};


Pe�aDama::Pe�aDama(Jogador _jogador, SDL_Rect _PosTela, int _PosTab) {



};

void Pe�aDama::movimento(SDL_Rect _PosTela, int _PosTab) {



};

void Pe�aDama::op��esMovimento(SDL_Rect _PosTela, int _PosTab) {



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
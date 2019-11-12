#include "DamasBiblioteca.h"
#include <iostream>
#include <string>


Jogador::Jogador() {
	Nome = "jogador";
	Npecas = 12;
};

void Jogador::setname(std::string nome) {
	this->Nome = nome;
};

std::string Jogador::getname() {
	return this->Nome;
};

void Jogador::decreaseNpecas() {
	Npecas--;
}

int Jogador::getNpecas() {
	return this->Npecas;
};


void Peca::movimento(int _x, int _y, int _PosTab) {};

void Peca::opcoesMovimento(int _x, int _y, int _PosTab) {};


PecaNormal::PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab) {
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaNormal::PecasIniciais(Tabuleiro TabInicial, int _x, int _y, int _PosTab){
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

void PecaNormal::movimento(int _x, int _y, int _PosTab) {



};

void PecaNormal::opcoesMovimento(int _x, int _y, int _PosTab) {

};


void TransformandoDama(PecaNormal peca) {



};


PecaDama::PecaDama(Jogador _jogador, int _x, int _y, int _PosTab) {



};

void PecaDama::movimento(int _x, int _y, int _PosTab) {



};

void PecaDama::opcoesMovimento(int _x, int _y, int _PosTab) {



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

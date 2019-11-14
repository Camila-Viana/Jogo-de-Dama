#include "DamasBiblioteca.h"
#include <iostream>
#include <string>


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

Jogador::Jogador() {};

Jogador::Jogador(std::string _Nome, int Npecas) {
	this->Nome = _Nome;
	this->Npecas = Npecas;
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


void Peca::movimento(int _x, int _y, int _PosTab[2]) {};

void Peca::opcoesMovimento(int _x, int _y, int _PosTab[2]) {};

int Peca::getpositionX() { return 0; };

int Peca::getpositionY() { return 0; };


PecaNormal::PecaNormal() {};

PecaNormal::PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab[2]) {
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaNormal::movimento(int _x, int _y, int _PosTab[2]) {



};

void PecaNormal::opcoesMovimento(int _x, int _y, int _PosTab[2]) {

};

int PecaNormal::getpositionX() {
	return this->x;
};

int PecaNormal::getpositionY() {
	return this->y;
};


void TransformandoDama(PecaNormal peca) {



};


PecaDama::PecaDama(Jogador _jogador, int _x, int _y, int _PosTab[2]) {



};

void PecaDama::movimento(int _x, int _y, int _PosTab[2]) {



};

void PecaDama::opcoesMovimento(int _x, int _y, int _PosTab[2]) {



};

int PecaDama::getpositionX() {
	return this->x;
};

int PecaDama::getpositionY() {
	return this->y;
};

void DestrutorFinal() {

};

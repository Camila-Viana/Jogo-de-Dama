#include "DamasBiblioteca.h"
#include <iostream>
#include <string>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <vector>



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


void Peca::movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) {};

void Peca::opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) {
	
};

int Peca::getpositionX() { return 0; };

int Peca::getpositionY() { return 0; };

int Peca::getPosTabX() { return 0; };

int Peca::getPosTabY() { return 0; };

PecaNormal::PecaNormal() {};

PecaNormal::PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab[2]) {
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaNormal::movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) {
	if (x >= ((opcoes[0] * 60) + 250) && x <= ((opcoes[0] * 60) + 310) && y >= ((opcoes[1] * 55) + 60) && y <= (opcoes[1] * 55) + 120) {
		tab->Tabuleiroinicial[(opcoes[0])][(opcoes[1])] = 1;
		if (opcoes[2] != NULL)
			tab->Tabuleiroinicial[(targets[0])][(targets[1])] = 0;
		if (this->jogador.getname() == "Player1" && turn){
			this->x = opcoes[0] * 60 + 250;
			this->y = opcoes[1] * 55 + 60;
			this->PosTab[0] = opcoes[0];
			this->PosTab[1] = opcoes[1];
		}
		else if (this->jogador.getname() == "Player2" && !turn) {
			this->x = opcoes[0] * 60 + 250;
			this->y = opcoes[1] * 55 + 60;
			this->PosTab[0] = opcoes[0];
			this->PosTab[1] = opcoes[1];
		}
	}
};

void PecaNormal::opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) {
	opcoes = { NULL };
	targets = { NULL };
	int aux = 0;
	if (this->jogador.getname() == "Player1"){
		//Verifica a primeira casa à esquerda
		if(PosTabX - 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX - 1)][(PosTabY - 1)] == 0){
			opcoes[aux][0] = PosTabX;
			opcoes[aux][1] = PosTabY;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
			aux++;
		}
		else if (PosTabX - 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX - 1)][(PosTabY - 1)] == 2) {
			if (PosTabX - 2 >= 0 && PosTabY - 2 >= 0 && tab.Tabuleiroinicial[(PosTabX - 2)][(PosTabY - 2)] == 0) {
				opcoes[aux][0] = PosTabX - 2;
				opcoes[aux][1] = PosTabY - 2;
				targets[aux][0] = PosTabX - 1;
				targets[aux][1] = PosTabY - 1;
				aux++;
			}
		}

		//Verifica a primeira casa à direita
		if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY - 1)] == 0){
			opcoes[aux][0] = PosTabX + 1;
			opcoes[aux][1] = PosTabY - 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
		}
		else if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY - 1)] == 2) {
			if (PosTabX + 2 >= 0 && PosTabY - 2 >= 0 && tab.Tabuleiroinicial[(PosTabX - 2)][(PosTabY - 2)] == 0) {
				opcoes[aux][0] = PosTabX + 2;
				opcoes[aux][1] = PosTabY - 2;
				targets[aux][0] = PosTabX + 1;
				targets[aux][1] = PosTabY - 1;
			}
		}

	}
	else if (this->jogador.getname() == "Player2") {
		//Verifica a primeira casa à esquerda
		if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY - 1)] == 0){
			opcoes[aux][0] = PosTabX + 1;
			opcoes[aux][1] = PosTabY - 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
			aux++;
		}
		else if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY - 1)] == 2) {
			if (PosTabX + 2 >= 0 && PosTabY - 2 >= 0 && tab.Tabuleiroinicial[(PosTabX + 2)][(PosTabY - 2)] == 0) {
				opcoes[aux][0] = PosTabX + 2;
				opcoes[aux][1] = PosTabY - 2;
				targets[aux][0] = PosTabX + 1;
				targets[aux][1] = PosTabY - 1;
				aux++;
			}			
		}

		//Verifica a primeira casa à direita
		if (PosTabX + 1 >= 0 && PosTabY + 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY + 1)] == 0)
		{
			opcoes[aux][0] = PosTabX + 1;
			opcoes[aux][1] = PosTabY + 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
		}
		else if (PosTabX + 1 >= 0 && PosTabY + 1 >= 0 && tab.Tabuleiroinicial[(PosTabX + 1)][(PosTabY + 1)] == 2) {
			if (PosTabX + 2 >= 0 && PosTabY + 2 >= 0 && tab.Tabuleiroinicial[(PosTabX + 2)][(PosTabY + 2)] == 0) {
				opcoes[aux][0] = PosTabX + 2;
				opcoes[aux][1] = PosTabY + 2;
				targets[aux][0] = PosTabX + 1;
				targets[aux][1] = PosTabY + 1;
			}
		}		
	}
};

int PecaNormal::getpositionX() {
	return this->x;
};

int PecaNormal::getpositionY() {
	return this->y;
};

int PecaNormal::getPosTabX() { 
	return this->PosTab[0];
};

int PecaNormal::getPosTabY() {
	return this->PosTab[1];
};


void TransformandoDama(PecaNormal peca) {



};


PecaDama::PecaDama(Jogador _jogador, int _x, int _y, int _PosTab[2]) {



};

void PecaDama::movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) {



};

void PecaDama::opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) {



};

int PecaDama::getpositionX() {
	return this->x;
};

int PecaDama::getpositionY() {
	return this->y;
};

int PecaDama::getPosTabX() {
	return this->PosTab[0];
};

int PecaDama::getPosTabY() {
	return this->PosTab[1];
};

void DestrutorFinal() {

};

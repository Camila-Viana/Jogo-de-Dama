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

void Peca::opcoesMovimento(Tabuleiro tab, int *opcoes, int *targets, int PosTab[2]) {
	
};

int Peca::getpositionX() { return 0; };

int Peca::getpositionY() { return 0; };

int* Peca::getPosTab() { return 0; };


PecaNormal::PecaNormal() {};

PecaNormal::PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab[2]) {
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaNormal::movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) {
	if (x >= ((opcoes[1] * 60) + 250) && x <= ((opcoes[1] * 60) + 310) && y >= ((opcoes[2] * 55) + 60) && y <= (opcoes[2] * 55) + 120) {
		tab->Tabuleiroinicial[(opcoes[0])][(opcoes[1])] = 1;
		if (opcoes[2] != NULL)
			tab->Tabuleiroinicial[(targets[0])][(targets[1])] = 0;
		if (this->jogador.getname() == "Player1" && turn)
		{
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

void PecaNormal::opcoesMovimento(Tabuleiro tab, int *opcoes, int *targets, int PosTab[2]) {
	opcoes = { NULL };
	targets = { NULL };
	int pos[3];
	if (this->jogador.getname() == "Player1"){
		//Verifica a primeira casa à esquerda
		if(PosTab[0] - 1 >= 0 && PosTab[1] - 1 >= 0 && tab.Tabuleiroinicial[(PosTab[0] - 1)][(PosTab[1] - 1)] == 0)
		{
				pos[0] = PosTab[0] - 1;
				pos[1] = PosTab[1] - 1;
				pos[2] = NULL;
				opcoes[0] = *pos;
				targets[0] = NULL;
		}
		else if (PosTab[0] - 1 >= 0 && PosTab[1] - 1 >= 0 && tab.Tabuleiroinicial[(PosTab[0] - 1)][(PosTab[1] - 1)] == 2) {
			if (PosTab[0] - 2 >= 0 && PosTab[1] - 2 >= 0 && tab.Tabuleiroinicial[(PosTab[0] - 2)][(PosTab[1] - 2)] == 0) {
				pos[0] = PosTab[0] - 1;
				pos[1] = PosTab[1] - 1;
				pos[2] = 1;
				targets[1] = *pos;
				pos[0]--;
				pos[1]--;
				opcoes[1] = *pos;
			}
		}

		//Verifica a primeira casa à direita
		if (PosTab[0] + 1 >= 0 && PosTab[1] - 1 >= 0 && tab.Tabuleiroinicial[(PosTab[0] + 1)][(PosTab[1] - 1)] == 0)
		{
			pos[0] = PosTab[0] + 1;
			pos[1] = PosTab[1] - 1;
			pos[2] = NULL;
			opcoes[1] = *pos;
			targets[1] = NULL;
		}
		else if (PosTab[0] + 1 >= 0 && PosTab[1] - 1 >= 0 && tab.Tabuleiroinicial[(PosTab[0] + 1)][(PosTab[1] - 1)] == 2) {
			if (PosTab[0] + 2 >= 0 && PosTab[1] - 2 >= 0 && tab.Tabuleiroinicial[(PosTab[0] - 2)][(PosTab[1] - 2)] == 0) {
				pos[0] = PosTab[0] + 1;
				pos[1] = PosTab[1] - 1;
				pos[2] = 2;
				targets[1] = *pos;
				pos[0]++;
				pos[1]--;
				opcoes[1] = *pos;
			}
		}

	}
	else if (this->jogador.getname() == "Player2") {

		
	}

};

int PecaNormal::getpositionX() {
	return this->x;
};

int PecaNormal::getpositionY() {
	return this->y;
};

int* PecaNormal::getPosTab() { 
	return this->PosTab;
};


void TransformandoDama(PecaNormal peca) {



};


PecaDama::PecaDama(Jogador _jogador, int _x, int _y, int _PosTab[2]) {



};

void PecaDama::movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) {



};

void PecaDama::opcoesMovimento(Tabuleiro tab, int *opcoes, int *targets, int PosTab[2]) {



};

int PecaDama::getpositionX() {
	return this->x;
};

int PecaDama::getpositionY() {
	return this->y;
};

int* PecaDama::getPosTab() {
	return this->PosTab;
};

void DestrutorFinal() {

};

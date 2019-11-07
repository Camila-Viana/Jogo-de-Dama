#include "Damas.h"
#include <iostream>
#include <string>
#include <SDL.h>



void Inicializador() {

	SDL_Init(SDL_INIT_VIDEO);
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Erro: Init Video" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Window* window;
	window = SDL_CreateWindow("Jogo de Damas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1366, 768, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_SetWindowFullscreen(window, 0);
	if (!window) {
		std::cout << "Erro: Window" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface *screen;
	screen = SDL_GetWindowSurface(window);
	if (screen == NULL) {
		std::cout << "Erro: Screen" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Delay(5000);
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();

};

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

void Peça::movimento(int _PosX, int _PosY) {};

void Peça::opçõesMovimento(int _PosX, int _PosY) {};

PeçaNormal::PeçaNormal(Jogador _jogador, int _PosX, int _PosY) {
	this->jogador = _jogador;
	this->PosX = _PosX;
	this->PosY = _PosY;
};

void PeçaNormal::PeçasIniciais(Tabuleiro Tabuleiro[8][8]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (Tabuleiro[i][j] == 1) {

			}
			if (Tabuleiro[i][j] == 2) {

			}
		}
	}
};

void PeçaNormal::movimento(int _PosX, int _PosY) {



};

void PeçaNormal::opçõesMovimento(int _PosX, int _PosY) {



};

int PeçaNormal::getPositionX() {
	return this->PosX;
};

int PeçaNormal::getPositionY() {
	return this->PosY;
};

void TransformandoDama(PeçaNormal peça) {



};

PeçaDama::PeçaDama(Jogador _jogador, int _PosX, int _PosY) {



};

void PeçaDama::movimento(int _PosX, int _PosY) {



};

void PeçaDama::opçõesMovimento(int _PosX, int _PosY) {



};

int PeçaDama::getPositionX() {
	return this->PosX;
};

int PeçaDama::getPositionY() {
	return this->PosY;
};

void Tabuleiro::setTabuleiroInicial(int Tabuleiro[8][8]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i == 0 || i == 2) && j % 2 == 0) {
				Tabuleiro[i][j] = 2;
			}
			else {
				Tabuleiro[i][j] = 0;
			}
			if (i == 1 && j % 2 == 1) {
				Tabuleiro[i][j] = 2;
			}
			else {
				Tabuleiro[i][j] = 0;
			}
			if (i == 3 || i == 4) {
				Tabuleiro[i][j] = 0;
			}
			if ((i == 5 || i == 7) && j % 2 == 1) {
				Tabuleiro[i][j] = 1;
			}
			else {
				Tabuleiro[i][j] = 0;
			}
			if (i == 6 && j % 2 == 0) {
				Tabuleiro[i][j] = 1;
			}
			else {
				Tabuleiro[i][j] == 0;
			}
		}
	}
};
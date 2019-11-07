#include "Damas.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>



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

	IMG_Init(IMG_INIT_JPG);
	IMG_Init(IMG_INIT_JPG);

	SDL_Surface* Interface;
	Interface = IMG_Load("Interface.JPG");
	if (Interface == NULL) {
		std::cout << "Erro: Interface" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* TabuleiroPrincipal;
	TabuleiroPrincipal = IMG_Load("Tabuleiro.JPG");
	if (TabuleiroPrincipal == NULL) {
		std::cout << "Erro: Tabuleiro" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* Instruções;
	Instruções = IMG_Load("instruções.PNG");
	if (Instruções == NULL) {
		std::cout << "Erro: Instruções" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* PeçaBrancaNormal;
	PeçaBrancaNormal = IMG_Load("BrancaLisa.PNG");
	if (PeçaBrancaNormal == NULL) {
		std::cout << "Erro: PeçaBrancaNormal" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* PeçaBrancaNormalBrilho;
	PeçaBrancaNormalBrilho = IMG_Load("BrancaBrilho.PNG");
	if (PeçaBrancaNormalBrilho == NULL) {
		std::cout << "Erro: PeçaBrancaNormalBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* PeçaBrancaDama;
	PeçaBrancaDama = IMG_Load("BrancaEstrela.PNG");

	SDL_Surface* PeçaBRancaDamaBrilho;
	SDL_Surface* PeçaPretaNormal;
	SDL_Surface* PeçaPretaNormalBrilho;
	SDL_Surface* PeçaPretaDama;
	SDL_Surface* PeçaPretaDamaBrilho;
	SDL_Surface* Play;
	SDL_Surface* Exit;
	SDL_Surface* Instructions;
	SDL_Surface* Back;
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

void PeçaNormal::PeçasIniciais(int **Tabuleiro) {
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

void Tabuleiro::setTabuleiroInicial(int **Tabuleiro) {
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
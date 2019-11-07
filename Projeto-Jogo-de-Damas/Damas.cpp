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

	SDL_Surface* Instru��es;
	Instru��es = IMG_Load("instru��es.PNG");
	if (Instru��es == NULL) {
		std::cout << "Erro: Instru��es" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* Pe�aBrancaNormal;
	Pe�aBrancaNormal = IMG_Load("BrancaLisa.PNG");
	if (Pe�aBrancaNormal == NULL) {
		std::cout << "Erro: Pe�aBrancaNormal" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* Pe�aBrancaNormalBrilho;
	Pe�aBrancaNormalBrilho = IMG_Load("BrancaBrilho.PNG");
	if (Pe�aBrancaNormalBrilho == NULL) {
		std::cout << "Erro: Pe�aBrancaNormalBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	SDL_Surface* Pe�aBrancaDama;
	Pe�aBrancaDama = IMG_Load("BrancaEstrela.PNG");

	SDL_Surface* Pe�aBRancaDamaBrilho;
	SDL_Surface* Pe�aPretaNormal;
	SDL_Surface* Pe�aPretaNormalBrilho;
	SDL_Surface* Pe�aPretaDama;
	SDL_Surface* Pe�aPretaDamaBrilho;
	SDL_Surface* Play;
	SDL_Surface* Exit;
	SDL_Surface* Instructions;
	SDL_Surface* Back;
};

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

void Pe�a::movimento(int _PosX, int _PosY) {};

void Pe�a::op��esMovimento(int _PosX, int _PosY) {};

Pe�aNormal::Pe�aNormal(Jogador _jogador, int _PosX, int _PosY) {
	this->jogador = _jogador;
	this->PosX = _PosX;
	this->PosY = _PosY;
};

void Pe�aNormal::Pe�asIniciais(int **Tabuleiro) {
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

void Pe�aNormal::movimento(int _PosX, int _PosY) {



};

void Pe�aNormal::op��esMovimento(int _PosX, int _PosY) {



};

int Pe�aNormal::getPositionX() {
	return this->PosX;
};

int Pe�aNormal::getPositionY() {
	return this->PosY;
};

void TransformandoDama(Pe�aNormal pe�a) {



};

Pe�aDama::Pe�aDama(Jogador _jogador, int _PosX, int _PosY) {



};

void Pe�aDama::movimento(int _PosX, int _PosY) {



};

void Pe�aDama::op��esMovimento(int _PosX, int _PosY) {



};

int Pe�aDama::getPositionX() {
	return this->PosX;
};

int Pe�aDama::getPositionY() {
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
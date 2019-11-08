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

	SDL_Event* evento;


	IMG_Init(IMG_INIT_JPG);
	if (SDL_Init(IMG_INIT_JPG) < 0) {
		std::cout << "Erro: IMG_INIT_JPG" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	IMG_Init(IMG_INIT_JPG);
	if (SDL_Init(IMG_INIT_PNG) < 0) {
		std::cout << "Erro: IMG_INIT_PNG" << SDL_GetError() << std::endl;
		SDL_Quit();
	}


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
	if (PeçaBrancaDama == NULL) {
		std::cout << "Erro: PeçaBrancaDama" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* PeçaBrancaDamaBrilho;
	PeçaBrancaDamaBrilho = IMG_Load("BrancaEstrelaBrilho.PNG");
	if (PeçaBrancaDamaBrilho == NULL) {
		std::cout << "Erro: PeçaBrancaDamaBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	SDL_Surface* PeçaPretaNormal;
	PeçaPretaNormal = IMG_Load("PretaLisa.PNG");
	if (PeçaPretaNormal == NULL) {
		std::cout << "Erro: PeçaBrancaNormal" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* PeçaPretaNormalBrilho;
	PeçaPretaNormalBrilho = IMG_Load("PretaBrilho.PNG");
	if (PeçaPretaNormalBrilho == NULL) {
		std::cout << "Erro: PeçaPretaNormalBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* PeçaPretaDama;
	PeçaPretaDama = IMG_Load("PretaEstrela.PNG");
	if (PeçaPretaDama == NULL) {
		std::cout << "Erro: PeçaPretaDama" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* PeçaPretaDamaBrilho;
	PeçaPretaDamaBrilho = IMG_Load("PretaEstrelaBrilho.PNG");
	if (PeçaPretaDamaBrilho == NULL) {
		std::cout << "Erro: PeçaPretaDamaBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	SDL_Surface* Play;
	Play = IMG_Load("play.PNG");
	if (Play == NULL) {
		std::cout << "Erro: Play" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Exit;
	Exit = IMG_Load("exit.PNG");
	if (Exit == NULL) {
		std::cout << "Erro: Exit" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Instructions;
	Instructions = IMG_Load("instructions.PNG");
	if (Instructions == NULL) {
		std::cout << "Erro: Instructions" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Back;
	Back = IMG_Load("back.PNG");
	if (Back == NULL) {
		std::cout << "Erro: Back" << SDL_GetError() << std::endl;
		SDL_Quit();
	}

	Tabuleiro TabInicial;
	TabInicial.setTabuleiroInicial();

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


void Peça::movimento(int _PosX, int _PosY, int _PosTab) {};

void Peça::opçõesMovimento(int _PosX, int _PosY, int _PosTab) {};


PeçaNormal::PeçaNormal(Jogador _jogador, int _PosX, int _PosY, int _PosTab) {
	this->jogador = _jogador;
	this->PosX = _PosX;
	this->PosY = _PosY;
};

void PeçaNormal::PecasIniciais(Tabuleiro TabInicial, int _PosX, int _PosY, int _PosTab){
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

void PeçaNormal::movimento(int _PosX, int _PosY, int _PosTab) {



};

void PeçaNormal::opçõesMovimento(int _PosX, int _PosY, int _PosTab) {



};

int PeçaNormal::getPositionX() {
	return this->PosX;
};

int PeçaNormal::getPositionY() {
	return this->PosY;
};


void TransformandoDama(PeçaNormal peça) {



};


PeçaDama::PeçaDama(Jogador _jogador, int _PosX, int _PosY, int _PosTab) {



};

void PeçaDama::movimento(int _PosX, int _PosY, int _PosTab) {



};

void PeçaDama::opçõesMovimento(int _PosX, int _PosY, int _PosTab) {



};

int PeçaDama::getPositionX() {
	return this->PosX;
};

int PeçaDama::getPositionY() {
	return this->PosY;
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
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
	if (Pe�aBrancaDama == NULL) {
		std::cout << "Erro: Pe�aBrancaDama" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Pe�aBrancaDamaBrilho;
	Pe�aBrancaDamaBrilho = IMG_Load("BrancaEstrelaBrilho.PNG");
	if (Pe�aBrancaDamaBrilho == NULL) {
		std::cout << "Erro: Pe�aBrancaDamaBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}


	SDL_Surface* Pe�aPretaNormal;
	Pe�aPretaNormal = IMG_Load("PretaLisa.PNG");
	if (Pe�aPretaNormal == NULL) {
		std::cout << "Erro: Pe�aBrancaNormal" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Pe�aPretaNormalBrilho;
	Pe�aPretaNormalBrilho = IMG_Load("PretaBrilho.PNG");
	if (Pe�aPretaNormalBrilho == NULL) {
		std::cout << "Erro: Pe�aPretaNormalBrilho" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Pe�aPretaDama;
	Pe�aPretaDama = IMG_Load("PretaEstrela.PNG");
	if (Pe�aPretaDama == NULL) {
		std::cout << "Erro: Pe�aPretaDama" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Surface* Pe�aPretaDamaBrilho;
	Pe�aPretaDamaBrilho = IMG_Load("PretaEstrelaBrilho.PNG");
	if (Pe�aPretaDamaBrilho == NULL) {
		std::cout << "Erro: Pe�aPretaDamaBrilho" << SDL_GetError() << std::endl;
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


void Pe�a::movimento(int _PosX, int _PosY, int _PosTab) {};

void Pe�a::op��esMovimento(int _PosX, int _PosY, int _PosTab) {};


Pe�aNormal::Pe�aNormal(Jogador _jogador, int _PosX, int _PosY, int _PosTab) {
	this->jogador = _jogador;
	this->PosX = _PosX;
	this->PosY = _PosY;
};

void Pe�aNormal::PecasIniciais(Tabuleiro TabInicial, int _PosX, int _PosY, int _PosTab){
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

void Pe�aNormal::movimento(int _PosX, int _PosY, int _PosTab) {



};

void Pe�aNormal::op��esMovimento(int _PosX, int _PosY, int _PosTab) {



};

int Pe�aNormal::getPositionX() {
	return this->PosX;
};

int Pe�aNormal::getPositionY() {
	return this->PosY;
};


void TransformandoDama(Pe�aNormal pe�a) {



};


Pe�aDama::Pe�aDama(Jogador _jogador, int _PosX, int _PosY, int _PosTab) {



};

void Pe�aDama::movimento(int _PosX, int _PosY, int _PosTab) {



};

void Pe�aDama::op��esMovimento(int _PosX, int _PosY, int _PosTab) {



};

int Pe�aDama::getPositionX() {
	return this->PosX;
};

int Pe�aDama::getPositionY() {
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
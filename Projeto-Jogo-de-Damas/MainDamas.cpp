#include <iostream>
#include <string>
#include "Damas.h"
#include <SDL.h>
#include <SDL_image.h>



int main() {

	bool jogando = false;
	bool duringinterface = false;
	bool duringinstru��es = false;
	bool duringGame = false;
	bool vencedor = false;
	bool quit = false;

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


	SDL_Surface* screen;
	screen = SDL_GetWindowSurface(window);
	if (screen == NULL) {
		std::cout << "Erro: Screen" << SDL_GetError() << std::endl;
		SDL_Quit();
	}


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
	SDL_Rect PlayPosition;
	PlayPosition.x = 91;
	PlayPosition.y = 153;
	PlayPosition.w = 250;
	PlayPosition.h = 141;
	SDL_Surface* Exit;
	Exit = IMG_Load("exit.PNG");
	if (Exit == NULL) {
		std::cout << "Erro: Exit" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Rect ExitPosition;
	ExitPosition.x = 0;
	ExitPosition.y = 627;
	ExitPosition.w = 250;
	ExitPosition.h = 141;
	SDL_Surface* Instructions;
	Instructions = IMG_Load("instructions.PNG");
	if (Instructions == NULL) {
		std::cout << "Erro: Instructions" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Rect InstructionsPosition;
	InstructionsPosition.x = 1025;
	InstructionsPosition.y = 153;
	InstructionsPosition.w = 250;
	InstructionsPosition.h = 141;
	SDL_Surface* Back;
	Back = IMG_Load("back.PNG");
	if (Back == NULL) {
		std::cout << "Erro: Back" << SDL_GetError() << std::endl;
		SDL_Quit();
	}
	SDL_Rect BackPosition;
	BackPosition.x = 0;
	BackPosition.y = 627;
	BackPosition.w = 250;
	BackPosition.h = 141;

	Tabuleiro TabInicial;
	TabInicial.setTabuleiroInicial();

	jogando = true;
	duringinterface = true;

	while (jogando == true) {
		while (jogando == true && duringinterface == true) {
			SDL_BlitSurface(Interface, NULL, screen, NULL);
			SDL_BlitSurface(Play, &PlayPosition, screen, NULL);
			SDL_BlitSurface(Instructions, &InstructionsPosition, screen, NULL);
			SDL_BlitSurface(Exit, &ExitPosition, screen, NULL);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(5000);
			jogando = false;
			duringinterface = false;			
		}
	}

	SDL_FreeSurface(screen);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
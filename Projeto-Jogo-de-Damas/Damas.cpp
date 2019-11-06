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
	window = SDL_CreateWindow("Jogo de Damas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_FULLSCREEN_DESKTOP);
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

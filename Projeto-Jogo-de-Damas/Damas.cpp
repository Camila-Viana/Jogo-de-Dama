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

#include "Damas.h"
#include <iostream>
#include <string>

void Inicializador() {



};

Jogador::Jogador(std::string nome) {
	Nome = nome;
	Npeças = 12;
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

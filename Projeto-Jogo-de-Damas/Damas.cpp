#include "Damas.h"
#include <iostream>
#include <string>

void Inicializador() {



};

Jogador::Jogador(std::string nome) {
	Nome = nome;
	Npe�as = 12;
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
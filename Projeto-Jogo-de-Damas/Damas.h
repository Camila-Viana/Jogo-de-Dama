#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>

void Inicializador();

class Jogador {
private:
	std::string Nome;
	int Npe�as;
public:
	Jogador();
	void setname(std::string nome);
	std::string getname();
	void decreaseNpe�as();
	int getNpe�as();
};

class Pe�a {
public:
	virtual void movimento(int _PosX, int _PosY);
	virtual void op��esMovimento(int _PosX, int _PosY);
};

class Pe�aNormal : public Pe�a {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	Pe�aNormal(Jogador _jogador, int _PosX, int _PosY);
	void Pe�asIniciais(int **Tabuleiro);
	void movimento(int _PosX, int _PosY) override;
	void op��esMovimento(int _PosX, int _PosY) override;
	int getPositionX();
	int getPositionY();
};

void TransformandoDama(Pe�aNormal pe�a);

class Pe�aDama : public Pe�a {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	Pe�aDama(Jogador _jogador, int _PosX, int _PosY);
	void movimento(int _PosX, int _PosY) override;
	void op��esMovimento(int _PosX, int _PosY) override;
	int getPositionX();
	int getPositionY();
};

class Tabuleiro {
public:
	int Tabuleiro[8][8];
	void setTabuleiroInicial(int **Tabuleiro);
};

void DestrutorFinal();

#endif 

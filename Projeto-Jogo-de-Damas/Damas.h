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
	virtual void movimento(int _PosX, int _PosY, int _PosTab);
	virtual void op��esMovimento(int _PosX, int _PosY, int _PosTab);
};

class Pe�aNormal : public Pe�a {
private:
	Jogador jogador;
	int PosX;
	int PosY;
	int PosTab[2];
public:
	Pe�aNormal(Jogador _jogador, int _PosX, int _PosY, int _PosTab);
	void PecasIniciais(Tabuleiro TabInicial, int _PosX, int _PosY, int _PosTab);
	void movimento(int _PosX, int _PosY, int _PosTab) override;
	void op��esMovimento(int _PosX, int _PosY, int _PosTab) override;
	int getPositionX();
	int getPositionY();
};

void TransformandoDama(Pe�aNormal pe�a);

class Pe�aDama : public Pe�a {
private:
	Jogador jogador;
	int PosX;
	int PosY;
	int PosTab[2];
public:
	Pe�aDama(Jogador _jogador, int _PosX, int _PosY, int _PosTab);
	void movimento(int _PosX, int _PosY, int _PosTab) override;
	void op��esMovimento(int _PosX, int _PosY, int _PosTab) override;
	int getPositionX();
	int getPositionY();
};

class Tabuleiro {
public:
	int Tabuleiroinicial[8][8];
	void setTabuleiroInicial();
};

void DestrutorFinal();

#endif 

#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>

void Inicializador();

class Jogador {
private:
	std::string Nome;
	int Npeças;
public:
	Jogador();
	void setname(std::string nome);
	std::string getname();
	void decreaseNpeças();
	int getNpeças();
};

class Peça {
public:
	virtual void movimento(int _PosX, int _PosY, int _PosTab);
	virtual void opçõesMovimento(int _PosX, int _PosY, int _PosTab);
};

class PeçaNormal : public Peça {
private:
	Jogador jogador;
	int PosX;
	int PosY;
	int PosTab[2];
public:
	PeçaNormal(Jogador _jogador, int _PosX, int _PosY, int _PosTab);
	void PecasIniciais(Tabuleiro TabInicial, int _PosX, int _PosY, int _PosTab);
	void movimento(int _PosX, int _PosY, int _PosTab) override;
	void opçõesMovimento(int _PosX, int _PosY, int _PosTab) override;
	int getPositionX();
	int getPositionY();
};

void TransformandoDama(PeçaNormal peça);

class PeçaDama : public Peça {
private:
	Jogador jogador;
	int PosX;
	int PosY;
	int PosTab[2];
public:
	PeçaDama(Jogador _jogador, int _PosX, int _PosY, int _PosTab);
	void movimento(int _PosX, int _PosY, int _PosTab) override;
	void opçõesMovimento(int _PosX, int _PosY, int _PosTab) override;
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

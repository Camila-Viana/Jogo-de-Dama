#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>
#include <SDL.h>

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

class Tabuleiro {
public:
	int Tabuleiroinicial[8][8];
	void setTabuleiroInicial();
};

class Pe�a {
public:
	virtual void movimento(SDL_Rect _PosTela, int _PosTab);
	virtual void op��esMovimento(SDL_Rect _PosTela, int _PosTab);
};

class Pe�aNormal : public Pe�a {
private:
	Jogador jogador;
	SDL_Rect* PosTela;
	int PosTab[2];
public:
	Pe�aNormal(Jogador _jogador, SDL_Rect _PosTela, int _PosTab);
	void PecasIniciais(Tabuleiro TabInicial, SDL_Rect _PosTela, int _PosTab);
	void movimento(SDL_Rect _PosTela, int _PosTab) override;
	void op��esMovimento(SDL_Rect _PosTela, int _PosTab) override;
};

void TransformandoDama(Pe�aNormal pe�a);

class Pe�aDama : public Pe�a {
private:
	Jogador jogador;
	SDL_Rect* PosTela;
	int PosTab[2];
public:
	Pe�aDama(Jogador _jogador, SDL_Rect _PosTela, int _PosTab);
	void movimento(SDL_Rect _PosTela, int _PosTab) override;
	void op��esMovimento(SDL_Rect _PosTela, int _PosTab) override;
};

void DestrutorFinal();

#endif 

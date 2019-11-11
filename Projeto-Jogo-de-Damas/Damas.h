#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>
#include <SDL.h>

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

class Tabuleiro {
public:
	int Tabuleiroinicial[8][8];
	void setTabuleiroInicial();
};

class Peça {
public:
	virtual void movimento(SDL_Rect _PosTela, int _PosTab);
	virtual void opçõesMovimento(SDL_Rect _PosTela, int _PosTab);
};

class PeçaNormal : public Peça {
private:
	Jogador jogador;
	SDL_Rect* PosTela;
	int PosTab[2];
public:
	PeçaNormal(Jogador _jogador, SDL_Rect _PosTela, int _PosTab);
	void PecasIniciais(Tabuleiro TabInicial, SDL_Rect _PosTela, int _PosTab);
	void movimento(SDL_Rect _PosTela, int _PosTab) override;
	void opçõesMovimento(SDL_Rect _PosTela, int _PosTab) override;
};

void TransformandoDama(PeçaNormal peça);

class PeçaDama : public Peça {
private:
	Jogador jogador;
	SDL_Rect* PosTela;
	int PosTab[2];
public:
	PeçaDama(Jogador _jogador, SDL_Rect _PosTela, int _PosTab);
	void movimento(SDL_Rect _PosTela, int _PosTab) override;
	void opçõesMovimento(SDL_Rect _PosTela, int _PosTab) override;
};

void DestrutorFinal();

#endif 

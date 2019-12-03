#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>
#include <vector>

class Tabuleiro {
public:
	int Tabuleiroinicial[8][8];
	void setTabuleiroInicial();
};


class Jogador {
private:
	std::string Nome;
	int Npecas;
public:
	Jogador();
	Jogador(std::string _Nome, int _Npecas);
	void setname(std::string nome);
	std::string getname();
	void decreaseNpecas();
	int getNpecas();
};

class Peca {
public:
	virtual void movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y);
	virtual void opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY);
	virtual int getpositionX();
	virtual int getpositionY();
	virtual int getPosTabX();
	virtual int getPosTabY();
};

class PecaNormal : public Peca {
private:
	Jogador jogador;
	int x;
	int y;
	int PosTab[2];
public:
	PecaNormal();
	PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab[2]);
	void movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) override;
	void opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) override;
	int getpositionX() override;
	int getpositionY() override;
	int getPosTabX() override;
	int getPosTabY() override;
};

void TransformandoDama(PecaNormal peca);

class PecaDama : public Peca {
private:
	Jogador jogador;
	int x;
	int y;
	int PosTab[2];
public:
	PecaDama(Jogador _jogador, int _x, int _y, int _PosTab[2]);
	void movimento(Tabuleiro *tab, bool turn, int *opcoes, int *targets, int x, int y) override;
	void opcoesMovimento(Tabuleiro tab, int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) override;
	int getpositionX() override;
	int getpositionY() override;
	int getPosTabX() override;
	int getPosTabY() override;
};

void DestrutorFinal();

#endif 

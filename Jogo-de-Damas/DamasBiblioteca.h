#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>

class Jogador {
private:
	std::string Nome;
	int Npecas;
public:
	Jogador();
	void setname(std::string nome);
	std::string getname();
	void decreaseNpecas();
	int getNpecas();
};

class Tabuleiro {
public:
	int Tabuleiroinicial[8][8];
	void setTabuleiroInicial();
};

class Peca {
public:
	virtual void movimento(int _x, int _y, int _PosTab);
	virtual void opcoesMovimento(int _x, int _y, int _PosTab);
};

class PecaNormal : public Peca {
private:
	Jogador jogador;
	int x;
	int y;
	int PosTab[2];
public:
	PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab);
	void PecasIniciais(Tabuleiro TabInicial, int _x, int _y, int _PosTab);
	void movimento(int _x, int _y, int _PosTab) override;
	void opcoesMovimento(int _x, int _y, int _PosTab) override;
};

void TransformandoDama(PecaNormal peca);

class PecaDama : public Peca {
private:
	Jogador jogador;
	int x;
	int y;
	int PosTab[2];
public:
	PecaDama(Jogador _jogador, int _x, int _y, int _PosTab);
	void movimento(int _x, int _y, int _PosTab) override;
	void opcoesMovimento(int _x, int _y, int _PosTab) override;
};

void DestrutorFinal();

#endif 

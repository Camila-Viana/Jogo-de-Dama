#ifndef DAMAS_H_
#define DAMAS_H_

#include <string>
#include <iostream>

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
	virtual void movimento(int _x, int _y, int _PosTab[2]);
	virtual void opcoesMovimento(int _x, int _y, int _PosTab[2]);
	virtual int getpositionX();
	virtual int getpositionY();
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
	void movimento(int _x, int _y, int _PosTab[2]) override;
	void opcoesMovimento(int _x, int _y, int _PosTab[2]) override;
	int getpositionX() override;
	int getpositionY() override;
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
	void movimento(int _x, int _y, int _PosTab[2]) override;
	void opcoesMovimento(int _x, int _y, int _PosTab[2]) override;
	int getpositionX() override;
	int getpositionY() override;
};

void DestrutorFinal();

#endif 

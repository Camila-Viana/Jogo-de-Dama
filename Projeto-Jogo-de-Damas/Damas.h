#ifndef DAMAS_H_
#define DAMAS_H_

void Inicializador();

class Pe�a {
public:
	virtual void movimento();
	virtual void op��esMovimento();
};

class Pe�aNormal : public Pe�a {
private:
	Jogador _jogador;
	int _PosX;
	int _PosY;
public:
	Pe�aNorma();
	~Pe�aNormal();
	void movimento(int _PosX, int _PosY) override;
	void op��esMovimento(int _PosX, int _PosY) override;
	void getPositionX(int _PosX);
	void getPositionY(int _PosY);
};

class Pe�aDama : public Pe�a {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	Pe�aDama(Jogador _jogador, int _PosX, int _PosY);
	~Pe�aDama();
	void movimento(int PosX, int PosY) override;
	void op��esmovimento(int PosX, int PosY) override;
	void getPositionX(int PosX);
	void getPositionY(int PosY);
};

class Jogador {
private:
	char Nome;
	int Npe�as;
public:
	Jogador();
	~Jogador();
	char getname(char Nome);
	void decreaseNpe�as(int Npe�as);
	int getNpe�as(Npe�as);
};

void DestrutorFinal();

#endif 

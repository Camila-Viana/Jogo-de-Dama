#ifndef DAMAS_H_
#define DAMAS_H_

void Inicializador();

class Peça {
public:
	virtual void movimento();
	virtual void opçõesMovimento();
};

class PeçaNormal : public Peça {
private:
	Jogador _jogador;
	int _PosX;
	int _PosY;
public:
	PeçaNorma();
	~PeçaNormal();
	void movimento(int _PosX, int _PosY) override;
	void opçõesMovimento(int _PosX, int _PosY) override;
	void getPositionX(int _PosX);
	void getPositionY(int _PosY);
};

class PeçaDama : public Peça {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	PeçaDama(Jogador _jogador, int _PosX, int _PosY);
	~PeçaDama();
	void movimento(int PosX, int PosY) override;
	void opçõesmovimento(int PosX, int PosY) override;
	void getPositionX(int PosX);
	void getPositionY(int PosY);
};

class Jogador {
private:
	char Nome;
	int Npeças;
public:
	Jogador();
	~Jogador();
	char getname(char Nome);
	void decreaseNpeças(int Npeças);
	int getNpeças(Npeças);
};

void DestrutorFinal();

#endif 

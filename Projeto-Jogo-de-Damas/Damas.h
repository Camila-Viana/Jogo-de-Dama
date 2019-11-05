#ifndef DAMAS_H_
#define DAMAS_H_

void Inicializador();

class Jogador {
private:
	std::string Nome;
	int Npeças;
public:
	Jogador(std::string nome);
	std::string getname();
	void decreaseNpeças();
	int getNpeças();
};

class Peça {
public:
	virtual void movimento(int _PosX, int _PosY);
	virtual void opçõesMovimento(int _PosX, int _PosY);
};

class PeçaNormal : public Peça {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	PeçaNormal(Jogador _jogador, int _PosX, int _PosY);
	void movimento(int _PosX, int _PosY) override;
	void opçõesMovimento(int _PosX, int _PosY) override;
	int getPositionX();
	int getPositionY();
};

void TransformandoDama(PeçaNormal peça);

class PeçaDama : public Peça {
private:
	Jogador jogador;
	int PosX;
	int PosY;
public:
	PeçaDama(Jogador _jogador, int _PosX, int _PosY);
	void movimento(int _PosX, int _PosY) override;
	void opçõesMovimento(int _PosX, int _PosY) override;
	int getPositionX();
	int getPositionY();
};

void DestrutorFinal();

#endif 

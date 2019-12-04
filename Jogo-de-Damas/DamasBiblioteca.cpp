#include "DamasBiblioteca.h"
#include <iostream>
#include <string>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <vector>



void Tabuleiro::setTabuleiroInicial()
{
	int i, j;
	for (i = 0; i < 8; i++)	
	{
		for (j = 0; j < 8; j++) 
		{
			if ((i == 0 || i == 2) && j % 2 == 0) 
			{
				this->Tabuleiroinicial[i][j] = 2;
			}
			else 
			{
				this->Tabuleiroinicial[i][j] = 0;
			}
			if (i == 1 && j % 2 == 1) 
			{
				this->Tabuleiroinicial[i][j] = 2;
			}
			if ((i == 5 || i == 7) && j % 2 == 1) 
			{
				this->Tabuleiroinicial[i][j] = 1;
			}
			if (i == 6 && j % 2 == 0) 
			{
				this->Tabuleiroinicial[i][j] = 1;
			}
		}
	}
};

Jogador::Jogador() {};

Jogador::Jogador(std::string _Nome, int Npecas) 
{
	this->Nome = _Nome;
	this->Npecas = Npecas;
};

void Jogador::setname(std::string nome) 
{
	this->Nome = nome;
};

std::string Jogador::getname() 
{
	return this->Nome;
};

void Jogador::decreaseNpecas() 
{
	Npecas--;
}

int Jogador::getNpecas() 
{
	return this->Npecas;
};


void Peca::movimento(Tabuleiro *tab, bool turn, int opcoes[2][2], int targets[2][2], int x, int y) 
{
	return;
};

void Peca::opcoesMovimento(int tabuleiro[8][8], int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) 
{
	
};

int Peca::getpositionX() 
{ 
return 0; 
};

int Peca::getpositionY() 
{ 
return 0; 
};

int Peca::getPosTabX() 
{ 
return 0; 
};

int Peca::getPosTabY() 
{ 
return 0; 
};

PecaNormal::PecaNormal() 
{

};

PecaNormal::PecaNormal(Jogador _jogador, int _x, int _y, int _PosTab[2])
{
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaNormal::movimento(Tabuleiro *tab, bool turn, int opcoes[2][2], int targets[2][2], int x, int y) 
{
	for (int i = 0; i < 2; i++)
	{
		if (x >= ((opcoes[i][0] * 60) + 250) && x <= ((opcoes[i][0] * 60) + 310) && y >= ((opcoes[i][1] * 55) + 60) && y <= (opcoes[i][1] * 55) + 120) {

			if (targets[i] != NULL)
				tab->Tabuleiroinicial[(targets[i][0])][(targets[i][1])] = 0;
			if (this->jogador.getname() == "Player1" && turn)
			{
				tab->Tabuleiroinicial[(opcoes[i][0])][(opcoes[i][1])] = 1;
				this->x = opcoes[i][0] * 60 + 250;
				this->y = opcoes[i][1] * 55 + 60;
				this->PosTab[0] = opcoes[i][0];
				this->PosTab[1] = opcoes[i][1];

			}
			else if (this->jogador.getname() == "Player2" && !turn)
			{
				tab->Tabuleiroinicial[(opcoes[i][0])][(opcoes[i][1])] = 2;
				this->x = opcoes[i][0] * 60 + 250;
				this->y = opcoes[i][1] * 55 + 60;
				this->PosTab[0] = opcoes[i][0];
				this->PosTab[1] = opcoes[i][1];
				
			}
		}
	}	
};
//FUN��O QUE LIMITA A MOVIMENTA��O DAS PE�AS NO TABULEIRO

void PecaNormal::opcoesMovimento(int tabuleiro[8][8], int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) 
{
	int aux = 0;
	if (this->jogador.getname() == "Player1")
	{
		
		//VERIFICA��O DA PRIMEIRA CASA A ESQUERDA DA PE�A
		
		if(PosTabX - 1 >= 0 && PosTabY - 1 >= 0 && tabuleiro[(PosTabX - 1)][(PosTabY - 1)] == 0)
		{
			opcoes[aux][0] = 5;
			opcoes[aux][1] = 7;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
			aux++;
		}
		else if (PosTabX - 1 >= 0 && PosTabY - 1 >= 0 && tabuleiro[(PosTabX - 1)][(PosTabY - 1)] == 2) 
		{
			if (PosTabX - 2 >= 0 && PosTabY - 2 >= 0 && tabuleiro[(PosTabX - 2)][(PosTabY - 2)] == 0) 
			{
				opcoes[aux][0] = PosTabX - 2;
				opcoes[aux][1] = PosTabY - 2;
				targets[aux][0] = PosTabX - 1;
				targets[aux][1] = PosTabY - 1;
				aux++;
			}
		}

		//VERIFICA��O DA PRIMEIRA CASA A DIREITA DA PE�A

		if (PosTabX - 1 >= 0 && PosTabY + 1 >= 0 && tabuleiro[(PosTabX - 1)][(PosTabY + 1)] == 0)
		{
			opcoes[aux][0] = PosTabX - 1;
			opcoes[aux][1] = PosTabY + 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
		}
		else if (PosTabX - 1 >= 0 && PosTabY +1 >= 0 && tabuleiro[(PosTabX - 1)][(PosTabY + 1)] == 2) 
		{
			if (PosTabX - 2 >= 0 && PosTabY + 2 >= 0 && tabuleiro[(PosTabX - 2)][(PosTabY + 2)] == 0) 
			{
				opcoes[aux][0] = PosTabX - 2;
				opcoes[aux][1] = PosTabY + 2;
				targets[aux][0] = PosTabX - 1;
				targets[aux][1] = PosTabY + 1;
			}
		}

	}
	else if (this->jogador.getname() == "Player2") {
		
		//VERIFICA��O DA PRIMEIRA CASA A ESQUERDA DA PE�A

		if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tabuleiro[(PosTabX + 1)][(PosTabY - 1)] == 0){
			opcoes[aux][0] = PosTabX + 1;
			opcoes[aux][1] = PosTabY - 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
			aux++;
		}
		else if (PosTabX + 1 >= 0 && PosTabY - 1 >= 0 && tabuleiro[(PosTabX + 1)][(PosTabY - 1)] == 2) 
		{
			if (PosTabX + 2 >= 0 && PosTabY - 2 >= 0 && tabuleiro[(PosTabX + 2)][(PosTabY - 2)] == 0) 
			{
				opcoes[aux][0] = PosTabX + 2;
				opcoes[aux][1] = PosTabY - 2;
				targets[aux][0] = PosTabX + 1;
				targets[aux][1] = PosTabY - 1;
				aux++;
			}			
		}

		//VERIFICA��O DA PRIMEIRA CASA A DIREITA DA PE�A
		
		if (PosTabX + 1 >= 0 && PosTabY + 1 >= 0 && tabuleiro[(PosTabX + 1)][(PosTabY + 1)] == 0)
		{
			opcoes[aux][0] = PosTabX + 1;
			opcoes[aux][1] = PosTabY + 1;
			targets[aux][0] = NULL;
			targets[aux][1] = NULL;
		}
		else if (PosTabX + 1 >= 0 && PosTabY + 1 >= 0 && tabuleiro[(PosTabX + 1)][(PosTabY + 1)] == 2) 
			{
			if (PosTabX + 2 >= 0 && PosTabY + 2 >= 0 && tabuleiro[(PosTabX + 2)][(PosTabY + 2)] == 0) 
			{
				opcoes[aux][0] = PosTabX + 2;
				opcoes[aux][1] = PosTabY + 2;
				targets[aux][0] = PosTabX + 1;
				targets[aux][1] = PosTabY + 1;
			}
		}		
	}
	std::cout << opcoes[0][0] << " " << opcoes[0][1] << std::endl;
	std::cout << opcoes[1][0] << " " << opcoes[1][1] << std::endl;
};

//PEGA A POSI��O X DA PE�A EM RELA��O A TELA

int PecaNormal::getpositionX() 
{
	return this->x;
};

//PEGA A POSI��O Y DA PE�A EM RELA��O A TELA

int PecaNormal::getpositionY() 
{
	return this->y;
};

//PEGA A POSI��O X DA PE�A EM RELA��O AO TABULEIRO

int PecaNormal::getPosTabX() 
{ 
	return this->PosTab[0];
};

//PEGA A POSI��O Y DA PE�A EM RELA��O AO TABULEIRO

int PecaNormal::getPosTabY() 
{
	return this->PosTab[1];
};


void TransformandoDama(Peca **Vetorpeca,int pos) 
{
	//int _PosTab[2];
	//_PosTab[0] = Vetorpeca[pos].getPosTabX();
	//_PosTab[1] = Vetorpeca[pos].getPosTabY();
	//PecaDama *Dama = new PecaDama(Vetorpeca[pos].jogador.getname(), Vetorpeca[pos].getpositionX(), Vetorpeca[pos].getpositionY(), _PosTab[2]);
	//delete Vetorpeca[pos];
	//Vetorpeca[pos] = Dama;
};


PecaDama::PecaDama(Jogador _jogador, int _x, int _y, int _PosTab[2]) 
{
	this->jogador = _jogador;
	this->x = _x;
	this->y = _y;
};

void PecaDama::movimento(Tabuleiro *tab, bool turn, int opcoes[2][2], int targets[2][2], int x, int y) 
{
	for (int i = 0; i < 4; i++)
	{
		if (x >= ((opcoes[i][0] * 60) + 250) && x <= ((opcoes[i][0] * 60) + 310) && y >= ((opcoes[i][1] * 55) + 60) && y <= (opcoes[i][1] * 55) + 120) {

			if (targets[i] != NULL)
				tab->Tabuleiroinicial[(targets[i][0])][(targets[i][1])] = 0;
			if (this->jogador.getname() == "Player1" && turn)
			{
				tab->Tabuleiroinicial[(opcoes[i][0])][(opcoes[i][1])] = 1;
				this->x = opcoes[i][0] * 60 + 250;
				this->y = opcoes[i][1] * 55 + 60;
				this->PosTab[0] = opcoes[i][0];
				this->PosTab[1] = opcoes[i][1];

			}
			else if (this->jogador.getname() == "Player2" && !turn)
			{
				tab->Tabuleiroinicial[(opcoes[i][0])][(opcoes[i][1])] = 2;
				this->x = opcoes[i][0] * 60 + 250;
				this->y = opcoes[i][1] * 55 + 60;
				this->PosTab[0] = opcoes[i][0];
				this->PosTab[1] = opcoes[i][1];
				
			}
		}
	}	
};

void PecaDama::opcoesMovimento(int tabuleiro[8][8], int opcoes[2][2], int targets[2][2], int PosTabX, int PosTabY) 
{

};

int PecaDama::getpositionX() 
{
	return this->x;
};

int PecaDama::getpositionY() 
{
	return this->y;
};

int PecaDama::getPosTabX() 
{
	return this->PosTab[0];
};

int PecaDama::getPosTabY() 
{
	return this->PosTab[1];
};


#include <iostream>
#include <string>
#include "DamasBiblioteca.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <vector>

const float FPS = 180;

int main(int argc, char** argv)
{

	//INICIALIZA ALLEGRO
	
	al_init();
	
	//TRATA ERRO DE INICIALIZAÇÃO(APARECE MENSAGEM E FECHA PROGRAMA)

	if (!al_init()) 
	{
		std::cout << "Error: al_init" << std::endl;
		return -1;
	}

	//CRIA TELA: 
	
	ALLEGRO_DISPLAY* Window;
	Window = al_create_display(1000, 562);
	
	//TRATA ERRO DE CRIAÇÃO DA TELA (APARECE MENSAGEM E FECHA PROGRAMA)

	if (!Window) 
	{
		std::cout << "Error: Window" << std::endl;
		return -1;
	}

	//FAZ UPLOAD DAS IMAGENS
	
	al_init_image_addon();
	ALLEGRO_BITMAP* Interface = al_load_bitmap("Imagens/Interface.jpg");
	ALLEGRO_BITMAP* TabuleiroImagem = al_load_bitmap("Imagens/Tabuleiro.jpg");
	ALLEGRO_BITMAP* Instrucoes = al_load_bitmap("Imagens/Instrucoes.jpg");	
	ALLEGRO_BITMAP* BrancaLisa = al_load_bitmap("Imagens/BrancaLisa.png");
	ALLEGRO_BITMAP* BrancaDama = al_load_bitmap("Imagens/BrancaDama.png");
	ALLEGRO_BITMAP* PretaLisa = al_load_bitmap("Imagens/PretaLisa.png");
	ALLEGRO_BITMAP* PretaDama = al_load_bitmap("Imagens/PretaDama.png");
	
	//TRATA ERRO DE UPLOAD (APARECE MENSAGEM E FECHA PROGRAMA)

	if (!Interface || !TabuleiroImagem || !Instrucoes || !BrancaLisa ||	!BrancaDama || !PretaLisa || !PretaDama) 
	{
		std::cout << "Error: Uploads das Imagens" << std::endl;
		return -1;
	}

	//INSTALAÇÃO DO MOUSE E TECLADO:
	
	al_install_mouse();
	al_set_system_mouse_cursor(Window, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	al_install_keyboard();
	
	//TRATA ERRO DE INSTALAÇÃO DO MOUSE E TECLADO (APARECE MENSAGEM E FECHA PROGRAMA)

	if (!al_install_mouse()) 
	{
		std::cout << "Error: Instalacao do mouse" << std::endl;
		return -1;
	}
	
	if (!al_set_system_mouse_cursor(Window, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)) 
	{
		std::cout << "Error: Mouse Cusor" << std::endl;
		return -1;
	}
	
	if (!al_install_keyboard()) 
	{
		std::cout << "Error: Instalacao Teclado" << std::endl;
		return -1;
	}

	//INICIALIZA FILA DE EVENTOS

	ALLEGRO_EVENT_QUEUE* EventosPrincipais = al_create_event_queue();
	
	//TRATA ERRO DE INICIALIZAÇÃO DA FILA DE EVENTOS (APARECE MENSAGEM E FECHA PROGRAMA)

	if (!EventosPrincipais) 
	{
		std::cout << "Error: Fila de Eventos" << std::endl;
		return -1;
	}


	//INICIALIZA TIMER

	ALLEGRO_TIMER* TimerPrincipal = al_create_timer(1.0 / FPS);

	//TRATA ERRO DE INICIALIZAÇÃO DO TIMER (APARECE MENSAGEM E FECHA PROGRAMA)

	if (!TimerPrincipal) 
	{
		std::cout << "Error: Timer" << std::endl;
		return -1;
	}

	//FONTE:
	ALLEGRO_FONT* Fonte = NULL;

	al_init_font_addon();

	if (!al_init_ttf_addon())
	{
		std::cout << "Error: Iniciar Fonte" << std::endl;
		return -1;
	}

	Fonte = al_load_font("FonteNomes.ttf", 32, 0);

	if (!Fonte)
	{
		al_destroy_display(Window);
		std::cout << "Error: Fonte" << std::endl;
		return -1;
	}

	const char* texto1 = "A peca pode nao pode pular para tras";
	const char* texto2 =  "Damas podem voar";
	const char* texto3 = "A peca somente vira dama se parar na ultima fileira";
	const char* texto4 = "Para ganhar o jogador deve comer todas as pecas do adversario";
	const char* texto5 = "Para jogar basta clicar em play!";
	const char* texto6 = "Bom jogo!";
	//CRIA TABULEIRO

	Tabuleiro TabInicial;
	TabInicial.setTabuleiroInicial();

	//CRIA JOGADORES E PEÇAS
	Jogador Player1("Player1", 12);
	Jogador Player2("Player2", 12);
	Peca **VetorPecasPlayer1 = new Peca*[12];
	Peca **VetorPecasPlayer2 = new Peca*[12];
	
	//CRIANDO VETORES PARA MOVIMENTAR E ELIMINAR AS PEÇAS

	int opcoes[2][2] = {0};
	int targets[2][2] = {0};

	//CRIAÇÃO DE PEÇAS (INÍCIO)

	bool criandopecas = true;
	while (criandopecas == true) 
	{
		int i, j, _PosTab[2], aux;
		for (i = 0; i < 8; i++) 
		{
			for (j = 0; j < 8; j++) 
			{
				if (i <= 2 && TabInicial.Tabuleiroinicial[i][j] == 2) 
				{
					_PosTab[0] = { i };
					_PosTab[1] = { j };
					PecaNormal *PecaPlayer2 = new PecaNormal(Player2, (j * 60) + 250, (i * 55) + 60, _PosTab);
					if (i % 2 == 0) 
					{
						aux = (i * 4) + (j / 2);
					}
					else 
					{
						aux = (i * 4) + ((j - 1) / 2);
					}
					VetorPecasPlayer2[aux] = PecaPlayer2;
				}
				else if (i >= 5 && TabInicial.Tabuleiroinicial[i][j] == 1) 
				{
					_PosTab[0] = { i };
					_PosTab[1] = { j };
					PecaNormal *PecaPlayer1 = new PecaNormal(Player1, (j * 60) + 250, (i * 55) + 60, _PosTab);
					if (i % 2 == 0) 
					{
						aux = (i * 4) + ((j - 1) / 2);
					}
					else 
					{
						aux = (i * 4) + (j / 2);
					}
					aux = ((i - 5) * 4) + (j/2);
					VetorPecasPlayer1[aux] = PecaPlayer1;
				}
			}
		}
		criandopecas = false;
	}

	//CRIAÇÃO DE PEÇAS (FIM)

	//INICIALIZANDO AS VARIÁVEIS DE ESTADO

	bool jogando = false;
	bool duringInterface = false;
	bool duringInstructions = false;
	bool duringGame = false;
	bool duringPremacao = false;
	bool printandopecas = true;
	bool turn = true;

	//REGISTRO DE EVENTOS DO ALLEGRO

	al_register_event_source(EventosPrincipais, al_get_display_event_source(Window));
	al_register_event_source(EventosPrincipais, al_get_timer_event_source(TimerPrincipal));
	al_register_event_source(EventosPrincipais, al_get_keyboard_event_source());
	al_register_event_source(EventosPrincipais, al_get_mouse_event_source());
	al_register_event_source(EventosPrincipais, al_get_keyboard_event_source());

	al_flip_display();
	al_start_timer(TimerPrincipal);


	//INICIANDO O LOOP PRINCIPAL DO JOGO
 
	jogando = true;
	duringInterface = true;

	while (jogando == true) 
	{
		while (jogando == true && duringInterface == true) 
		{
			
			Inicio:
			al_draw_bitmap(Interface, 0, 0, 0);
			al_flip_display();

			ALLEGRO_EVENT e_interface;
			al_wait_for_event(EventosPrincipais, &e_interface);

			if (e_interface.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
			{
				//CRIANDO O BOTÃO DE PLAY

				if (e_interface.mouse.x >= 340 && e_interface.mouse.x <= 672 && e_interface.mouse.y >= 332 && e_interface.mouse.y <= 447) 
				{
					duringGame = true;
					duringInterface = false;
				}
				
				//CRIANDO O BOTÃO DE INSTRUCTIONS

				else if (e_interface.mouse.x >= 800 && e_interface.mouse.x <= 980 && e_interface.mouse.y >= 502 && e_interface.mouse.y <= 542) 
				{
					duringInstructions = true;
				}
				
				//CRIANDO O BOTÃO DE EXIT
				
				else if (e_interface.mouse.x >= 20 && e_interface.mouse.x <= 100 && e_interface.mouse.y >= 20 && e_interface.mouse.y <= 60) 
				{
					duringInterface = 0;
					jogando = 0;
				}
			}
			else if (e_interface.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
			{
				jogando = false;
			}

			//TELA DE INSTRUÇÕES

			while (jogando == true && duringInterface == true && duringInstructions == true) 
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(Instrucoes, 0, 0, 0);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 200, ALLEGRO_ALIGN_LEFT, "%s", texto1);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 240, ALLEGRO_ALIGN_LEFT, "%s", texto2);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 280, ALLEGRO_ALIGN_LEFT, "%s", texto3);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 320, ALLEGRO_ALIGN_LEFT, "%s", texto4);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 360, ALLEGRO_ALIGN_LEFT, "%s", texto5);
				al_draw_textf(Fonte, al_map_rgb(255, 255, 255), 100, 400, ALLEGRO_ALIGN_LEFT, "%s", texto6);
				al_flip_display();

				ALLEGRO_EVENT e_inst;
				al_wait_for_event(EventosPrincipais, &e_inst);

				if (e_inst.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
				{
					if (e_inst.mouse.x >= 20 && e_inst.mouse.x <= 100 && e_inst.mouse.y >= 20 && e_inst.mouse.y <= 60) 
					{
						duringInstructions = false;
						goto Inicio;
					}
				}
				else if (e_inst.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
				{
					jogando = false;
				}
			}			
		}

		//INICIANDO JOGO

		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(TabuleiroImagem, 0, 0, 0);
		al_flip_display();

		//INICIANDO LOOP DO JOGO

		while (jogando == true && duringGame == true) 
		{
			if (printandopecas == true) 
			{
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(TabuleiroImagem, 0, 0, 0);
				while (printandopecas == true) 
				{
					for (int i = 0; i < 12; i++) 
					{
						al_draw_bitmap(PretaLisa, VetorPecasPlayer2[i]->getpositionX(), VetorPecasPlayer2[i]->getpositionY(), 0);
						al_draw_bitmap(BrancaLisa, VetorPecasPlayer1[i]->getpositionX(), VetorPecasPlayer1[i]->getpositionY(), 0);
						al_flip_display();
					}
					printandopecas = false;
				}
			}
			
			ALLEGRO_EVENT e_game;

			//INICIA MOVIMENTAÇÃO DE PEÇAS

			al_wait_for_event(EventosPrincipais, &e_game);
			if (e_game.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
			{
				
				//VERIFICA A SELEÇÃO DE PEÇAS

				for (int i = 0; i < 12; i++) 
				{
					
					//SELEÇÃO DE PEÇAS DO JOGADOR 1

					if (turn && e_game.mouse.x >= VetorPecasPlayer1[i]->getpositionX() && e_game.mouse.x <= (VetorPecasPlayer1[i]->getpositionX() + 59) && e_game.mouse.y >= VetorPecasPlayer1[i]->getpositionY() && e_game.mouse.y <= (VetorPecasPlayer1[i]->getpositionY() + 60)) 
					{
						
						VetorPecasPlayer1[i]->opcoesMovimento(TabInicial.Tabuleiroinicial, opcoes, targets, VetorPecasPlayer1[i]->getPosTabX(), VetorPecasPlayer1[i]->getPosTabY());

						//std::cout << opcoes[0][0] << " " << opcoes[0][1] << std::endl;
						//std::cout << opcoes[1][0] << " " << opcoes[1][1] << std::endl;
						
						while(!printandopecas)
						{
							al_wait_for_event(EventosPrincipais, &e_game);
							if (e_game.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 
							{
								VetorPecasPlayer1[i]->movimento(&TabInicial, turn, opcoes, targets, e_game.mouse.x, e_game.mouse.y);
								if (VetorPecasPlayer1[i]->getPosTabX() == 0)
									TransformandoDama(VetorPecasPlayer1,i);
								turn = false;
								for (int j = 0; j < 12; j++) 
								{
									for (int z = 0; z < 2; z++) 
									{
										if (VetorPecasPlayer2[j]->getpositionX() == targets[z][0] && VetorPecasPlayer2[j]->getpositionY() == targets[z][1]) 
										{
											VetorPecasPlayer2[j] = NULL;
										}
									}
								}
								
								printandopecas = true;
							}
						}
					}

					//SELEÇÃO DE PEÇAS DO JOGADOR 2

					else if (!turn && e_game.mouse.x >= VetorPecasPlayer2[i]->getpositionX() && e_game.mouse.x <= (VetorPecasPlayer2[i]->getpositionX() + 59) && e_game.mouse.y >= VetorPecasPlayer2[i]->getpositionY() && e_game.mouse.y <= (VetorPecasPlayer2[i]->getpositionY() + 60)) 
					{
						VetorPecasPlayer2[i]->opcoesMovimento(TabInicial.Tabuleiroinicial, opcoes, targets, VetorPecasPlayer2[i]->getPosTabX(), VetorPecasPlayer2[i]->getPosTabY());
												
						while (!printandopecas) 
						{
							al_wait_for_event(EventosPrincipais, &e_game);
							if (e_game.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) 				
							{
								VetorPecasPlayer2[i]->movimento(&TabInicial, turn, opcoes, targets, e_game.mouse.x, e_game.mouse.y);
								if (VetorPecasPlayer2[i]->getPosTabX() == 8)
									TransformandoDama(VetorPecasPlayer2,i);
								turn = false;
								for (int j = 0; j <= 12; j++) 
								{
									for (int z = 0; z < 2; z++) 
									{
										if (VetorPecasPlayer1[j]->getpositionX() == targets[z][1] && VetorPecasPlayer1[j]->getpositionY() == targets[z][2]) 
										{
											VetorPecasPlayer1[i] = NULL;
										}
									}
								}
							}

							printandopecas = true;							
						}
					}
				}
			}
			
			//FINALIZANDO JOGO

			else if (e_game.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
			{
				jogando = false;
			}
		}
	}

	//DESTRUINDO VETORES, EVENTOS E IMAGENS

	delete *VetorPecasPlayer1;
	delete *VetorPecasPlayer2;

	al_destroy_display(Window);
	al_destroy_event_queue(EventosPrincipais);
	al_destroy_timer(TimerPrincipal);
	al_destroy_bitmap(Interface);
	al_destroy_bitmap(TabuleiroImagem);
	al_destroy_bitmap(Instrucoes);
	al_destroy_bitmap(BrancaLisa);
	al_destroy_bitmap(BrancaDama);
	al_destroy_bitmap(PretaLisa);
	al_destroy_bitmap(PretaDama);

  return 0;
}

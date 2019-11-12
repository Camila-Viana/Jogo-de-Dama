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

const float FPS = 180;

int main(int argc, char** argv){

	//Inicializa Allegro:
	al_init();
	if (!al_init()) {
		std::cout << "Error: al_init" << std::endl;
		return -1;
	}

	//Tela: 
	ALLEGRO_DISPLAY* Window;
	ALLEGRO_DISPLAY_MODE   Window_data;
	al_get_display_mode(al_get_num_display_modes() - 1, &Window_data);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	Window = al_create_display(Window_data.width, Window_data.height);
	if (!Window) {
		std::cout << "Error: Window" << std::endl;
		return -1;
	}

	//Uploads das Imagens:
	al_init_image_addon();
	ALLEGRO_BITMAP* Interface = al_load_bitmap("Imagens/Interface.jpg");
	ALLEGRO_BITMAP* Tabuleiro = al_load_bitmap("Imagens/Tabuleiro.jpg");
	ALLEGRO_BITMAP* Instrucoes = al_load_bitmap("Imagens/instrucoes.png");
	ALLEGRO_BITMAP* Play = al_load_bitmap("Imagens/play.png");
	ALLEGRO_BITMAP* Instructions = al_load_bitmap("Imagens/instructions.png");
	ALLEGRO_BITMAP* Back = al_load_bitmap("Imagens/back.png");
	ALLEGRO_BITMAP* Exit = al_load_bitmap("Imagens/exit.png");
	ALLEGRO_BITMAP* BrancaLisa = al_load_bitmap("Imagens/BrancaLisa.png");
	ALLEGRO_BITMAP* BrancaBrilho = al_load_bitmap("Imagens/BrancaBrilho.png");
	ALLEGRO_BITMAP* BrancaDama = al_load_bitmap("Imagens/BrancaEstrela.png");
	ALLEGRO_BITMAP* BrancaDamaBrilho = al_load_bitmap("Imagens/BrancaEstrelaBrilho.png");
	ALLEGRO_BITMAP* PretaLisa = al_load_bitmap("Imagens/PretaLisa.png");
	ALLEGRO_BITMAP* PretaBrilho = al_load_bitmap("Imagens/PretaBrilho.png");
	ALLEGRO_BITMAP* PretaDama = al_load_bitmap("Imagens/PretaEstrela.png");
	ALLEGRO_BITMAP* PretaDamaBrilho = al_load_bitmap("Imagens/PretaEstrelaBrilho.png");
	if (!Interface || !Tabuleiro || !Instrucoes || !Play || !Instructions || !Back || !Exit || !BrancaLisa ||
		!BrancaBrilho || !BrancaDama || !BrancaDamaBrilho || !PretaLisa || !PretaBrilho || !PretaDama || !PretaDamaBrilho) {
		std::cout << "Error: Uploads das Imagens" << std::endl;
		return -1;
	}

	//Mouse e teclado:
	al_install_mouse();
	if (!al_install_mouse()) {
		std::cout << "Error: Instalacao do mouse" << std::endl;
		return -1;
	}
	al_set_system_mouse_cursor(Window, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	if (!al_set_system_mouse_cursor(Window, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)) {
		std::cout << "Error: Mouse Cusor" << std::endl;
		return -1;
	}
	al_install_keyboard();
	if (!al_install_keyboard) {
		std::cout << "Error: Instalacao Teclado" << std::endl;
		return -1;
	}

	//Fila de Eventos:
	ALLEGRO_EVENT_QUEUE* EventosPrincipais = al_create_event_queue();
	if (!EventosPrincipais) {
		std::cout << "Error: Fila de Eventos" << std::endl;
		return -1;
	}

	//Timer:
	ALLEGRO_TIMER* TimerPrincipal = al_create_timer(1.0 / FPS);
	if (!TimerPrincipal) {
		std::cout << "Error: Timer" << std::endl;
		return -1;
	}

	//Variaveis de Estado:
	bool jogando = false;
	bool duringInterface = false;
	bool duringInstructions = false;
	bool duringGame = false;
	bool duringPremacao = false;
	
	//Fonte:
	al_init_font_addon();
	ALLEGRO_FONT* FonteNomes;
	FonteNomes = al_load_font("FonteNomes.ttf", 48, 0);
	if (!FonteNomes) {
		std::cout << "Error: Upload Fonte Nomes" << std::endl;
		return -1;
	}

	//Registro de eventos:
	al_register_event_source(EventosPrincipais, al_get_display_event_source(Window));
	al_register_event_source(EventosPrincipais, al_get_timer_event_source(TimerPrincipal));
	al_register_event_source(EventosPrincipais, al_get_keyboard_event_source());
	al_register_event_source(EventosPrincipais, al_get_mouse_event_source());
	al_register_event_source(EventosPrincipais, al_get_keyboard_event_source());

	al_flip_display();
	al_start_timer(TimerPrincipal);
//---------------------------------------------------------------------------------------------------------------------//

	//Jogo: 
	jogando = true;
	duringInterface = true;

	while (jogando == true) {
		while (jogando == true && duringInterface == true) {
			
			Inicio:
			al_draw_bitmap(Interface, 0, 0, 0);
			al_draw_bitmap(Play, 91, 153, 0);
			al_draw_bitmap(Instructions, 1025, 153, 0);
			al_draw_bitmap(Exit, 0, 627, 0);
			al_flip_display();

			ALLEGRO_EVENT e_interface;
			al_wait_for_event(EventosPrincipais, &e_interface);

			if (e_interface.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
				//Play:
				if (e_interface.mouse.x >= 91 && e_interface.mouse.x <= 341 && e_interface.mouse.y >= 153 && e_interface.mouse.y <= 294) {
					duringGame = true;
					duringInterface = false;
				}
				//Instructions: 
				else if (e_interface.mouse.x >= 1025 && e_interface.mouse.x <= 1275 && e_interface.mouse.y >= 153 && e_interface.mouse.y <= 294) {
					duringInstructions = true;
				}
				//Exit:
				else if (e_interface.mouse.x >= 0 && e_interface.mouse.x <= 250 && e_interface.mouse.y >= 627 && e_interface.mouse.y <= 768) {
					duringInterface = 0;
					jogando = 0;
				}
			}
			else if (e_interface.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				jogando = false;
			}

			//Instrucoes:
			while (jogando == true && duringInterface == true && duringInstructions == true) {
				
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_bitmap(Instrucoes, 0, 0, 0);
				al_draw_bitmap(Back, 0, 627, 0);
				al_draw_bitmap(Play, 1100, 627, 0);
				al_flip_display();

				ALLEGRO_EVENT e_inst;
				al_wait_for_event(EventosPrincipais, &e_inst);

				if (e_inst.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
					if (e_inst.mouse.x >= 0 && e_inst.mouse.x <= 250 && e_inst.mouse.y >= 627 && e_inst.mouse.y <= 768) {
						duringInstructions = false;
						goto Inicio;
					}
					else if (e_inst.mouse.x >= 1100 && e_inst.mouse.x <= 1350 && e_inst.mouse.y >= 627 && e_inst.mouse.y <= 768) {
						duringInstructions = false;
						duringGame = true;
						duringInterface = false;
					}
				}
				else if (e_interface.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
					jogando = false;
				}
			}			
		}
		while (jogando == true && duringGame == true) {

		}
	}

	al_destroy_display(Window);
	al_destroy_event_queue(EventosPrincipais);
	al_destroy_font(FonteNomes);
	al_destroy_timer(TimerPrincipal);
	al_destroy_bitmap(Interface);
	al_destroy_bitmap(Tabuleiro);
	al_destroy_bitmap(Instrucoes);
	al_destroy_bitmap(Play);
	al_destroy_bitmap(Instructions);
	al_destroy_bitmap(Back);
	al_destroy_bitmap(Exit);
	al_destroy_bitmap(BrancaLisa);
	al_destroy_bitmap(BrancaBrilho);
	al_destroy_bitmap(BrancaDama);
	al_destroy_bitmap(BrancaDamaBrilho);
	al_destroy_bitmap(PretaLisa);
	al_destroy_bitmap(PretaBrilho);
	al_destroy_bitmap(PretaDama);
	al_destroy_bitmap(PretaDamaBrilho);

  return 0;
}

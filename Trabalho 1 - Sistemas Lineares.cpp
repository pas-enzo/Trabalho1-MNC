//Sistemas Lineares - Métodos Numéricos Computacionais
/*Trabalho feito por:
Manuele S. Christófalo - RA: 221029261
BOTEM O NOME E O RA DE VCS AQUI!
*/
//UNESP Bauru - 04/06/2023

#include <bits/stdc++.h>
#include <windows.h>
#include <locale.h>
#include <conio.h>
using namespace std;

#define ESC 27
#define ENTER 13
#define BACKSPACE 8
#define UP 72
#define DOWN 80

#define BRANCO 127
#define PRETO 112
#define CINZA 120
#define VERDE 114
#define AZUL 113
#define VERMELHO 116


//FORMATAÇÃO =========================================================================================================
void gotoxy(int x, int y){ //Posição do cursor
	COORD pos={x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor(bool val){ //Esconde o cursor
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = val;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int SetColor(char color){ //Cor
	HANDLE h;
	h=GetStdHandle (STD_OUTPUT_HANDLE);
	return SetConsoleTextAttribute (h,color);
}

void limpaTela(){ //Limpa a tela
	system("cls");
	SetColor(CINZA);
}

void menuSelecao(int pos){ //Menu de Seleção
	limpaTela();
	SetColor(AZUL); cout << "\n Qual a operacao desejada?\n\n\n"; SetColor(BRANCO);
	cout << "  Calcular o determinante" << endl;
	cout << "  Resolver sistema triangular inferior" << endl;
	cout << "  Resolver sistema triangular superior" << endl;
	cout << "  Resolver por Decomposicao LU" << endl;
    cout << "  Resolver por Cholesky" << endl;
	cout << "  Resolver por Gauss Compacto" << endl;
	cout << "  Resolver por Gauss-Jordan" << endl;
	cout << "  Resolver por Jacobi" << endl;
	cout << "  Resolver por Gauss-Seidel" << endl;
	cout << "  Calcular matriz inversa" << endl;
	cout << "  SAIR";

	switch(pos){
		case 1: gotoxy(2, 4); SetColor(CINZA); cout << "  Calcular o determinante" << endl; break;
		case 2: gotoxy(2, 5); SetColor(CINZA); cout << "  Resolver sistema triangular inferior" << endl; break;
		case 3: gotoxy(2, 6); SetColor(CINZA); cout << "  Resolver sistema triangular superior" << endl; break;
		case 4: gotoxy(2, 7); SetColor(CINZA); cout << "  Resolver por Decomposiçao LU" << endl; break;
		case 5: gotoxy(2, 8); SetColor(CINZA); cout << "  Resolver por Cholesky" << endl; break;
		case 6: gotoxy(2, 9); SetColor(CINZA); cout << "  Resolver por Gauss Compacto" << endl; break;
		case 7: gotoxy(2, 10); SetColor(CINZA); cout << "  Resolver por Gauss-Jordan" << endl; break;
		case 8: gotoxy(2, 11); SetColor(CINZA); cout << "  Resolver por Jacobi" << endl; break;
		case 9: gotoxy(2, 12); SetColor(CINZA); cout << "  Resolver por Gauss-Seidel" << endl; break;
		case 10: gotoxy(2, 13); SetColor(CINZA); cout << "  Calcular matriz inversa" << endl; break;
		case 11: gotoxy(2, 14); SetColor(VERMELHO); cout << "  SAIR"; break;
	}
}

bool voltaMenu(){
	char saida='a'; cursor(false);
	SetColor(BRANCO); cout << "\n\nPressione ";
	SetColor(AZUL); cout<<"<ENTER>"; SetColor(BRANCO); cout << " para tentar com outros valores ou ";
	SetColor(AZUL); cout<<"<ESC>"; SetColor(BRANCO); cout << " para voltar ao menu de opcoes.";
	while(saida!=ENTER && saida!=ESC) saida=getch();

	if(saida==ESC) return 1;
	return 0;
}

//FUNÇÕES ===========================================================================================================
void exemplo(){
	/*Essa é só uma função de exemplo,
	neste campo ficariam as funções usadas
	nos cálculos - ex: Cholensky*/
}


//MAIN ==============================================================================================================
int main(){
    system("color 70");
	HWND console=GetConsoleWindow();
 	RECT r;
  	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 400, TRUE);
	setlocale(LC_ALL, "Portuguese_Brasil");

	bool ON=true;
	int pos;
	char selecao, teste;
	

	//PARTE 1: PROGRAMA
	while(ON==true){
		selecao='a'; pos=1;

		while(selecao!=ENTER){ //1.0 - Controle do menu
			cursor(false);
			menuSelecao(pos);

			if(pos==11) SetColor(VERMELHO);
			else SetColor(AZUL);

			gotoxy(0, 3+pos); cout << ">";

			selecao=getch();
			if(pos!=11) if(selecao==DOWN) pos++;
			if(pos!=1) if(selecao==UP) pos--;
		}
			
		

		//PARTE 2: SELEÇÃO FEITA
		while(pos==1){ //2.1 - Calcular determinante
			limpaTela(); cursor(true);
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Calcular o determinante"; SetColor(BRANCO);

			cout << endl << endl << "Teste: ";
			cin >> teste;

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==2){ //2.2 - Sistema Triangular Inferior
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver sistema triangular inferior"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==3){ //2.3 - Sistema Triangular Superior
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver sistema triangular superior"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==4){ //2.4 - Decomposição LU
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Decomposicao LU"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==5){ //2.5 - Cholensky
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Cholensky"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==6){ //2.6 - Gauss Compacto
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Gauss Compacto"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==7){ //2.7 - Gauss-Jordan
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Gauss-Jordan"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==8){ //2.8 - Jacobi
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Jacobi"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==9){ //2.9 - Gauss-Seidel
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Resolver por Gauss-Seidel"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}

		while(pos==10){ //2.10 - Matriz inversa
			limpaTela();
			SetColor(BRANCO); cout << "Opcao selecionada: ";
			SetColor(AZUL); cout << "Calcular matriz inversa"; SetColor(BRANCO);

			if(voltaMenu()==1){
				selecao='a';
				break;
			}
		}
		
		if(pos==11){ //2.11 - SAIR
			SetColor(AZUL); cout << "\n\nAgradecemos por ver o nosso trabalho. Espero que tenha gostado :)\n";
			ON=false;
			system("pause");
		}
	}
}
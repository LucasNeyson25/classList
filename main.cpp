#include <iostream>
#include <cstdlib>
#include "cabecalho.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	Lista *listaAluno;
	int menu = 0, x = 0;
	while(menu == 0){
		system("cls");
		if(x>0){
			imprimeMenu(listaAluno);
		}else{
			imprimeMenu();
		}
		cin >> menu;
		
		switch(menu){
			case 1:
				if(x>=1){
					x++;
					cout << "Lista J� criada, tente outra op��o" << endl;
					cout << "* " ;
					cin >> menu;
					// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
					while( menu != 0){
						cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
						cin >> menu;
					}
					break;
				}
				x++;
				Lista *lsAluno;
				lsAluno = criarLista();
				listaAluno = lsAluno;
				menu = 0;
				break;
			case 2:
				inserirInicio(lsAluno,dados());
				cout << "|0| VOLTAR AO MENU " << endl;		
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 3:
				inserirOrdenado(lsAluno,dados());
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 4:
				inserirFinal(lsAluno,dados());
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 5:
				removerInicio(lsAluno);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;	
			case 6:
				int mat;
				cout << "Informe a MATR�CULA do aluno: ";
				cin >> mat;
				removerOrdenado(lsAluno,mat);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 7:
				removerFinal(lsAluno);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 8:
				int i;
				cout << "Informe a POSI��O do aluno: ";
				cin >> i;
				buscarPosicao(lsAluno,i);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 9:
				int bscMat;
				cout << "Informe a MATR�CULA do aluno: ";
				cin >> bscMat;
				buscarMatricula(lsAluno,bscMat);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 10:
				cout << "M�dia da turma: " << calcularMediaTurma(lsAluno) << endl;
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			case 11:
				imprimirLista(lsAluno);
				cout << "|0| VOLTAR AO MENU " << endl;
				cin >> menu;
				// While com fun��o apenas de proteger, sendo impossivel digitar outro valor al�m do ZERO
				while( menu != 0){
					cout << "Digito inv�lido, digite 0 para voltar ao MENU " << endl;
					cin >> menu;
				}
				break;
			default:
				if(limparLista(lsAluno) == 0){
					break;
				}
				cout << "Lista Apagada com Sucesso ";
				break;					
		}
		
	}
	return 0;
}

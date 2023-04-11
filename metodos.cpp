#include <iostream>
#include <cstdlib>
#include "cabecalho.h"

using namespace std;

struct Elemento{
	Aluno dados;
	Elemento *proximo;
};

struct Lista{
	Elemento *primeiro;
	Elemento *ultimo;
};

Lista* criarLista(){
	Lista *lista;
	lista = (Lista*) malloc(sizeof(Lista));
	if(lista == NULL){
		cout << "Erro ao criar Lista de Alunos";
		exit(0);
	}
	lista->primeiro=NULL;
	lista->ultimo=NULL;
	return lista;
}

int inserirInicio(Lista *lsAluno, Aluno dados){
	if(lsAluno == NULL){
		cout << "Erro";
		return 0;
	}
	Elemento *no = (Elemento*) malloc(sizeof(Elemento));
	if(no == NULL){
		cout << "Erro";
		return 0;
	}
	no->dados = dados;
	no->proximo = NULL;
	if(lsAluno->ultimo == NULL){
		lsAluno->primeiro = no;
		lsAluno->ultimo = no;
		no->proximo = NULL;
	}else{
		no->proximo = lsAluno->primeiro;
		lsAluno->primeiro = no;
	}
	
	cout << " * Aluno inserido com SUCESSO. *" << endl << endl;
	return 1;
	
}

int inserirOrdenado(Lista *lsAluno, Aluno dados){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	
	Elemento *no = (Elemento*) malloc(sizeof(Elemento));
	Elemento *aux = (Elemento*) malloc(sizeof(Elemento));
	Elemento *pecorreLista = (Elemento*) malloc(sizeof(Elemento));
	
	if(no == NULL || aux == NULL || pecorreLista == NULL){
		cout << "Erro";
		return 0;
	}
	no->dados = dados;
	no->proximo = NULL;
	pecorreLista = lsAluno->primeiro;
	int cont=0;
	
	if(tamanhoLista(lsAluno)==0){
		lsAluno->primeiro = no;
		lsAluno->ultimo = no;
		no->proximo = NULL;
		return 1;
	}
	// Caso o elemento seja inserido na primeira posição
	while(cont <= tamanhoLista(lsAluno)){
		if(no->dados.matricula < pecorreLista->dados.matricula){
				no->proximo = pecorreLista;
				lsAluno->primeiro = no;
				cout << " * Aluno inserido com SUCESSO. *" << endl << endl;
				return 1;
		}
		cont++;
	}
	while(no != NULL){
		if(no->dados.matricula > pecorreLista->dados.matricula){
			if(pecorreLista == lsAluno->ultimo){
				pecorreLista->proximo = no;
				cout << " * Aluno inserido com SUCESSO. *" << endl << endl;
				return 1;
			}
			aux = pecorreLista;
			pecorreLista = pecorreLista->proximo;
			
		}else{
			aux->proximo = no;
			no->proximo = pecorreLista;
			cout << " * Aluno inserido com SUCESSO. *" << endl << endl;
			return 1;		
		}	
	}	
}

int inserirFinal(Lista *lsAluno, Aluno dados){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	Elemento *no = (Elemento*) malloc(sizeof(Elemento));
	if(no == NULL){
		cout << "Erro";
		return 0;
	}
	no->dados = dados;
	no->proximo = NULL;
	if(lsAluno->ultimo == NULL){
		lsAluno->primeiro = no;
	}else{
		lsAluno->ultimo->proximo = no;
	}
	lsAluno->ultimo = no;
	cout << " * Aluno inserido com SUCESSO. *" << endl << endl;
	return 1;
}

int removerInicio(Lista *lsAluno){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia" << endl;
		return 0;
	}
	free(lsAluno->primeiro);
	lsAluno->primeiro = lsAluno->primeiro->proximo;
	cout << " * Aluno removido com SUCESSO. *" << endl << endl;
	return 1;
}

int removerOrdenado(Lista *lsAluno,int matricula){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia" << endl;
		return 0;
	}
	Elemento *no = lsAluno->primeiro;
	Elemento *aux = no;
	while( no != NULL ){
		if(matricula == lsAluno->primeiro->dados.matricula){
			lsAluno->primeiro = no->proximo;
			cout << " * Aluno removido com SUCESSO. *" << endl << endl;
			return 1;
		}
		if(matricula == no->dados.matricula){
			aux->proximo = no->proximo;
			free(no);
		}
		aux = no;
		no = no->proximo;
	}
	cout << " * Aluno removido com SUCESSO. *" << endl << endl;
	return 1;
}

int removerFinal(Lista *lsAluno){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia" << endl;
		return 1;
	}
	Elemento *no = lsAluno->primeiro;
	Elemento *aux =  lsAluno->primeiro;
	free(lsAluno->ultimo);
	while ( no != NULL){
		if(no->proximo == NULL){
			lsAluno->ultimo = aux;
			aux->proximo = NULL;
			cout << " * Aluno removido com Sucesso." << endl;
 			return 1;
		}
		aux = no;
		no = no->proximo;
	}
	cout << " * Aluno removido com Sucesso." << endl; 
}

int buscarMatricula(Lista *lsAluno,int matricula){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia";
		return 1;
	}
	Elemento *no = lsAluno->primeiro;
	int cont = 0;
	char esc = 'a';
	while(no != NULL){
		if(matricula == no->dados.matricula){
			cout << "| ALUNO " << cont+1 << " |" << endl;
			cout << "Nome: " << no->dados.nome << endl;
			cout << "Matrícula: " << no->dados.matricula << endl;
			cout << "Idade: " << no->dados.idade << endl;
			cout << "Nota 1: " << no->dados.nota1 << endl;
			cout << "Nota 2: " << no->dados.nota2 << endl;
			cout << "Média Final: " << no->dados.mediaFinal << endl;
			if(no->dados.situacao == -1){
				cout << "Situação: Cursando" << endl;
			}
			cout << endl;

			cout << "Deseja inserir/alterar as notas do aluno? 's' ou 'n':  ";
			cin >> esc; 
			esc = toupper(esc);
			while(esc !='S' && esc != 'N'){
				cin >> esc;
				esc = toupper(esc);
				cout << "Valor invalido, tente novamente" << endl;
			}
			if(esc == 'S'){
				cout << "| ALUNO " << cont+1 << " |" << endl;
				cout << "Nota 1: " ;
				cin >> no->dados.nota1;
				while( no->dados.nota1 < 0 || no->dados.nota1 > 10){
					cout << "Insira um valor válido, entre 0 a 10." << endl;
					cin >> no->dados.nota1;
				}
				cout << "Nota 2: " ;
				cin >> no->dados.nota2;
				while( no->dados.nota2 < 0 || no->dados.nota2 > 10){
					cout << "Insira um valor válido, entre 0 a 10." << endl;
					cin >> no->dados.nota2;
				}
				no->dados.mediaFinal = ((no->dados.nota1*0.4) + (no->dados.nota2*0.6));
				cout << "Media Final: " << no->dados.mediaFinal << endl;
				if(no->dados.mediaFinal >= 6 ){
					no->dados.situacao = 1;
					cout << "Situação: Aprovado";
					cout << endl << endl;
					return 1;	
				}else{
					no->dados.situacao = 0;
					cout << "Situação: Reprovado";
					cout << endl << endl;
					return 1;
				}	
			}else{
				return 1;
			}
			cout << endl;
			return 1;
		}
		no = no->proximo;
		cont++;
	}
	return 1;
}

int buscarPosicao(Lista *lsAluno,int posicao){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia";
		return 1;
	}
	Elemento *no = lsAluno->primeiro;
	int cont = 0;
	char esc = 'a';
	while (no != NULL){
		if(posicao-1 == cont){
			cout << "| ALUNO " << cont+1 << " |" << endl;
			cout << "Nome: " << no->dados.nome << endl;
			cout << "Matrícula: " << no->dados.matricula << endl;
			cout << "Idade: " << no->dados.idade << endl;
			cout << "Nota 1: " << no->dados.nota1 << endl;
			cout << "Nota 2: " << no->dados.nota2 << endl;
			cout << "Média Final: " << no->dados.mediaFinal << endl;
			if(no->dados.situacao == -1){
				cout << "Situação: Cursando" << endl;
			}
			cout << endl;

			cout << "Deseja inserir/alterar as notas do aluno? 's' ou 'n':  ";
			cin >> esc; 
			esc = toupper(esc);
			while(esc !='S' && esc != 'N'){
				cout << "Valor invalido, tente novamente" << endl;
				cin >> esc;
				esc = toupper(esc);
			}
			if(esc == 'S'){
				cout << "| ALUNO " << cont+1 << " |" << endl;
				cout << "Nota 1: " ;
				cin >> no->dados.nota1;
				while( no->dados.nota1 < 0 || no->dados.nota1 > 10){
					cout << "Insira um valor válido, entre 0 a 10." << endl;
					cin >> no->dados.nota1;
				}
				cout << "Nota 2: " ;
				cin >> no->dados.nota2;
				while( no->dados.nota2 < 0 || no->dados.nota2 > 10){
					cout << "Insira um valor válido, entre 0 a 10." << endl;
					cin >> no->dados.nota2;
				}
				no->dados.mediaFinal = ((no->dados.nota1*0.4) + (no->dados.nota2*0.6));
				cout << "Media Final: " << no->dados.mediaFinal << endl;
				if(no->dados.mediaFinal >= 6 ){
					no->dados.situacao = 1;
					cout << "Situação: Aprovado";
					cout << endl << endl;
					return 1;	
				}else{
					no->dados.situacao = 0;
					cout << "Situação: Reprovado";
					cout << endl << endl;
					return 1;
				}	
			}else{
				return 1;
			}
			cout << endl;
			return 1;
		}
		no = no->proximo;
		cont++;
	}
	
}

void imprimirLista(Lista *lsAluno){
	if(lsAluno == NULL){
		exit(0);
	}
	if(tamanhoLista(lsAluno)==0){
		cout << "Lista Vazia" << endl;
	}
	int cont=0;
	Elemento *no = lsAluno->primeiro;
	while(no != NULL){
		cout<<"Dados do Aluno "<< "| " << cont+1 << " |" << endl;
			cout<<"Nome: " << no->dados.nome<<endl;
			cout<<"Matricula: "<< no->dados.matricula<<endl;
			cout<<"Idade: "<< no->dados.idade<<endl;
			cout << "Nota 1: " << no->dados.nota1<< endl;
			cout << "Nota 2: " << no->dados.nota2<< endl;
			cout << "Media Final: " << no->dados.mediaFinal << endl;
			if(no->dados.situacao == -1){
				cout << "Situação: Cursando" << endl;
			}else if(no->dados.situacao == 0){
				cout << "Situação: Reprovado" << endl;
			}else if(no->dados.situacao == 1){
				cout << "Situação: Aprovado" << endl;
			}		
			no = no->proximo;
			cont++;
			cout << endl;
		}
}

int tamanhoLista(Lista *lsAluno){
	if(lsAluno == NULL){
		cout<<"Lista Vazia!";
		return 0;
	} else{
		int cont=0;
		Elemento *no = lsAluno->primeiro;
		while(no != NULL){
			cont++;
			no = no->proximo;
		}
		return cont;
	}
}

float calcularMediaTurma(Lista *lsAluno){
	if(lsAluno == NULL){
		cout << "Erro inesperado";
		return 0;
	}
	if(lsAluno->ultimo == NULL){
		cout << "Lista Vazia";
		return 1;
	}
	Elemento *no = lsAluno->primeiro;
	float mediaTurma = 0;
	int cont = 0;
	while(no != NULL){
		mediaTurma = no->dados.mediaFinal + mediaTurma;
		no = no->proximo;
		cont++;
	}
	mediaTurma = mediaTurma/cont;
	return mediaTurma;
}

int limparLista(Lista *lsAluno){
	if(tamanhoLista(lsAluno)==0){
		cout << "Lista Vazia" << endl;
		return 0;
	}else{
		while(tamanhoLista(lsAluno) > 0){
			Elemento *no = lsAluno->primeiro;
			lsAluno->primeiro = lsAluno->primeiro->proximo;
			if(lsAluno->primeiro == NULL){
				lsAluno->ultimo = NULL;
			}
			free(no);	
		}	
	}	
	return 1;
}

Aluno dados(){
	Aluno dados;
	cout << "Nome: ";
	cin >> dados.nome;
	cout << "Matricula: ";
	cin >> dados.matricula;
	cout << "Idade: ";
	cin >> dados.idade;
	dados.nota1 = 0;
	dados.nota2 = 0;
	dados.mediaFinal = 0;
	dados.situacao = -1;
	cout << endl;
	return dados;
}

void imprimeMenu(){	
		cout << " |1| CRIAR LISTA" << endl << endl;
		
		cout << " |2| INSERIR ALUNO NO *INICIO* DA LISTA" << endl;
		cout << " |3| INSERIR ALUNO ORDENADO POR *MATRÍCULA* NA LISTA" << endl;
		cout << " |4| INSERIR ALUNO NO *FINAL* DA LISTA" << endl << endl;
		
		cout << " |5| REMOVER ALUNO NO *INICIO* DA LISTA" << endl;
		cout << " |6| REMOVER ALUNO ORDENADO PELA *MATRÍCULA* DA LISTA" << endl;
		cout << " |7| REMOVER ALUNO NO *FINAL* DA LISTA" << endl << endl;
		
		cout << " |8| CONSULTAR ALUNO PELA *POSIÇÃO* NA LISTA" << endl;
		cout << " |9| CONSULTAR ALUNO PELA *MATRÍCULA* NA LISTA" << endl << endl;
		
		cout << "|10| MÉDIA DA TURMA" << endl << endl;
		
		cout << "|11| IMPRIMIR LISTA" << endl << endl;
		
		cout << "|QUALQUER OUTRO VALOR FECHARÁ O PROGRAMA|" << endl << endl;
		
		cout << "* ";
}

void imprimeMenu(Lista *lsAluno){
		cout << " ** LISTA CRIADA COM " << tamanhoLista(lsAluno) << " ALUNO(S) **"<< endl << endl;
		
		cout << " |2| INSERIR ALUNO NO *INICIO* DA LISTA" << endl;
		cout << " |3| INSERIR ALUNO ORDENADO POR *MATRÍCULA* NA LISTA" << endl;
		cout << " |4| INSERIR ALUNO NO *FINAL* DA LISTA" << endl << endl;
		
		cout << " |5| REMOVER ALUNO NO *INICIO* DA LISTA" << endl;
		cout << " |6| REMOVER ALUNO ORDENADO PELA *MATRÍCULA* DA LISTA" << endl;
		cout << " |7| REMOVER ALUNO NO *FINAL* DA LISTA" << endl << endl;
		
		cout << " |8| CONSULTAR ALUNO PELA *POSIÇÃO* NA LISTA" << endl;
		cout << " |9| CONSULTAR ALUNO PELA *MATRÍCULA* NA LISTA" << endl << endl;
		
		cout << "|10| MÉDIA DA TURMA" << endl << endl;
		
		cout << "|11| IMPRIMIR LISTA" << endl << endl;
		
		cout << "|QUALQUER OUTRO VALOR FECHARÁ O PROGRAMA|" << endl << endl;
		
		cout << "* ";
}

/* Alunos: Lucas Neyson Ara�jo Marinho - Matr�cula: 202121895
		   Lucas Eve F�lix da Silva - Matr�cula: 202017823
		   Caroline Vit�ria Rodrigues de Melo Mendes - Matr�cula: 202114604 */

struct Aluno{
	char nome[50];
	int matricula;
	int idade;
	float nota1,nota2,mediaFinal;
	int situacao;
};

struct Elemento;
struct Lista;

Lista* criarLista();

int inserirInicio(Lista *lsAluno, Aluno dados);
int inserirOrdenado(Lista *lsAluno, Aluno dados);
int inserirFinal(Lista *lsAluno, Aluno dados);

int removerInicio(Lista *lsAluno);
int removerOrdenado(Lista *lsAluno,int matricula);
int removerFinal(Lista *lsAluno);

int buscarMatricula(Lista *lsAluno,int matricula);
int buscarPosicao(Lista *lsAluno,int posicao);

float calcularMediaTurma(Lista *lsAluno);

int limparLista(Lista *lsAluno);

void imprimirLista(Lista *lsAluno);
int tamanhoLista(Lista *lsAluno);

void imprimeMenu();
void imprimeMenu(Lista *lsAluno);
Aluno dados();


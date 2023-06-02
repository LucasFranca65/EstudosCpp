#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
//Estrutura para armanezar as informa��es dos alunos na lista
struct aluno {
	string nome;
	float nota;
};

struct lista {
	aluno info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da lista
	int total; //A vari�vel total vai determinar a quantidade de elementos que est�o na lista
};

//Fun��o para exibir o menu
char menu (void)
{
     char op;
     
     system("cls");
     cout << "1 - Incluir aluno na lista" << endl;
     cout << "2 - Excluir aluda da lista" << endl;
     cout << "3 - Exibir lista de alunos (ordem de nome)" << endl;
     cout << "4 - Alterar a nota de um aluno" << endl;
     cout << "5 - Pesquisar um aluno" << endl;
     cout << "6 - Excluir toda a lista" << endl;
     cout << "7 - Exibir lista de alunos (ordem de nota)" << endl;    
	 cout << "0 - Sair" << endl;
     cout << "Opcao: ";
     cin >> op;
     
     return op;
}

//Fun��o que inicializa a lista
//Quando a variavel total for igual a zero siginifca que a lista esta vazia
void inicia_lista(lista & l) {
	l.total = 0;
}

//Fun��o que identfica se a lista esta cheia
//A lista est� cheia quando a vari�vel total � igual ao tamanho m�ximo definido
bool lista_cheia (lista l, int tam_max) {
	if (l.total == tam_max)
		return true;
	else
		return false;
}

//Fun��o que identfica se a lista esta vazia
//A lista est� vazia quando a vari�vel total � igual a 0
bool lista_vazia (lista l) {
	if (l.total == 0)
		return true;
	else
		return false;
}

//Fun��o para realizar a inclus�o de um novo elemento na lista
void incluir_lista(lista & l, aluno e, int tam_max) {
	//Verifica se a lista est� cheia.
     //Caso a lista esteja cheia, n�o � poss�vel incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Inclui o elemento na �ltima posi��o da lista
		l.info[l.total] = e;
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Aluno '" << e.nome << "' incluido na lista" << endl;
	}
	system("pause");
}

//Fun��o para realizar a inclus�o de um novo elemento na lista em ordem crescente
void incluir_lista_ordenada(lista & l, aluno e, int tam_max) {
	int i, j;
	//Verifica se a lista est� cheia.
     //Caso a lista esteja cheia, n�o � poss�vel incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Iniciar a leitura a lista pela primeira posi��o
		i = 0;
		//Repeti��o para encontrar a posi��o aonde o novo elemento deve ser inclu�do,
		//considerando a ordem crescente
		//Caso todos os elementos sejam menores do qual est� sendo inserido,
		//vai incluir no final
		while (l.info[i].nome < e.nome && i < l.total)
			i++;
		
		//A partir do �ltimo elemento at� a posi��o aonde o novo elemento ser�
		//inserido, desloca cada elemento para a direita. Assim a posi��o encontrada
		//para o novo elemento, fica dispon�vel
		for (j = l.total; j > i; j--)
			l.info[j] = l.info[j-1];
			
		//Inclui o elemento na posi��o correta da ordem
		l.info[i] = e;	
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Aluno '" << e.nome << "' incluido na lista" << endl;
	}
	system("pause");
}

//Fun��o para exibir todos os elementos da lista
void exibir_lista (lista l) {
	int i;
	//Verifica se a lista est� vazia
	if (lista_vazia(l) == true)
		cout << "Lista vazia" << endl;
	else
		//Loop para exibir todos os elementos da lista
		for (i = 0; i < l.total; i++) {
			cout << "Nome: " << l.info[i].nome << endl;
			cout << "Nota: " << l.info[i].nota << endl;
			cout << "----------------------------" << endl;
		}
	system("pause");
}


//Fun��o para exibir todos os elementos da lista na ordem da nota
//Mesmo alterando a ordem da lista, isso n�o vai permanecer quando 
//a fun��o terminar de ser executado porque o par�metro n�o foi
//passado por refer�ncia
void exibir_lista_ordem_nota (lista l) {
	int i, j;
	aluno aux;
	
	//Verifica se a lista est� vazia
	if (lista_vazia(l) == true)
		cout << "Lista vazia" << endl;
	else {
	
		//Essa repeti��o avalia se a nota est� em posi��o incorreta em rela��o a ordem 
		//e inverte as posi��es
		for (i = 0; i < l.total; i++)
			for (j = 0; j < l.total; j++) 
				if (l.info[i].nota < l.info[j].nota) {
					aux = l.info[i];
					l.info[i] = l.info[j];
					l.info[j] = aux;
				}
	
		//Loop para exibir todos os elementos da lista
		for (i = 0; i < l.total; i++) {
			cout << "Nome: " << l.info[i].nome << endl;
			cout << "Nota: " << l.info[i].nota << endl;
			cout << "----------------------------" << endl;
		}
	system("pause");
}


//Fun��o que retorno a posi��o no vetor do elemento buscado
int buscar (lista l, string e) {
	int i, p = -1;
	
	if (lista_vazia(l) == true)
		return -1;
	else {
		//Loop para verificar se existe algum elemento na 
		//lista que corresponda ao elemento buscao
		for (i = 0; i < l.total; i++)
			if (l.info[i].nome == e)
				//Se o elemento for localizado, guarda a informa��o 
				//da sua posi��o do vetor na vari�vel pos
				p = i;
		//Retorna a posi��o do vetor aonde o elemento foi localizado,
    	//ou, se o elemento n�o foi encontrado, retorna o n�mero -1
		return p;	
	}
}

//Fun��o para alterar um elemento na lista
void alterar (lista & l, aluno e) {
	int pos;
	//Chama a fun��o "buscar" para identificar a posi��o no vetor do elemento que ser� alterado
	pos = buscar(l, e.nome);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a fun��o "buscar" retornou -1 significa que n�o localizou o elemento)
	if (pos == -1)
		cout << "Aluno nao encontrado" << endl;
	else {
		//Armazena na mesma posi��o aonde foi localizado, o elemento que deve ser alterado
		l.info[pos].nota = e.nota;
		cout << "Nota alterada" << endl;
	}
	system("pause");
}

//Fun��o para excluir um elemento da lista
void excluir (lista & l, string e) {
	int pos, i;
	
	//Chama a fun��o "buscar" para identificar a posi��o no vetor do elemento que ser� exclu�do
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a fun��o "buscar" retornou -1 significa que n�o localizou o elemento)
	if (pos == -1)
		cout << "Aluno nao encontrado" << endl;
	else {
		//Loop para deslocar todos os elementos a direita do elemento uma 
		//posi��o � esquerda. Dessa forma, o elemento a ser exclu�do � sobrescrito
		for (i = pos; i < l.total - 1; i++)
			l.info[i] = l.info[i+1];
		
		//Atualiza a quantidade de elementos na lista
		l.total --;
		cout << "Aluno excluido" << endl;
	}
	system("pause");
}

//Fun��o principal
int main() {
	lista l; //A vari�vel l representa a lista (definida pela struct lista)
	char op;
	string nome_aluno;
	aluno elemento, novo_elem;
	int tam_max = 5; //A vari�vel tam_max define a quantidade m�xima de elementos que a lista pode ter
	int pos;
	
	//Inicia a lista. Essa fun��o determina que a vari�vel total � igual a 0
	inicia_lista(l);
	
	do {
		//Fun��o que exibe o menu e retorna a op��o selecionada
		op = menu();
		
		//Op��o de inclus�o
		if (op == '1') {
			//Solicita o valor do novo elemento
			cout << "Qual o nome do aluno a ser incluido na lista: ";
			cin >> elemento.nome;
			cout << "Qual a nota do aluno: ";
			cin >> elemento.nota;
			
			//Executa a fun��o para incluir o novo elemento na lista
			incluir_lista_ordenada(l, elemento, tam_max);
		}
		
		//Op��o de exclus�o
		else if (op == '2') {
			//Solicita o valor do elemento que ser� exclu�do
			cout << "Qual o nome do aluno a ser excluido: ";
			cin >> nome_aluno;
			
			//Executa a fun��o para excluir o elemento da lista
			excluir(l, nome_aluno);
		}
		
		//Op��o para exibir a lista
		else if (op == '3')
			//Executa a fun��o para exibir todos os elementos da lista
			exibir_lista(l);
			
		//Op��o para alterar o valor de um elemento da lista
		else if (op == '4') {
			//Solicita o valor do elemento que ser� alterado
			cout << "Nome do aluno: ";
			cin >> elemento.nome;
			
			//Solicita o novo valor do elemento
			cout << "Nova nota: ";
			cin >> elemento.nota;
			
			//Executa a fun��o para altarar o valor do elemento da lista
			alterar(l, elemento);
		}
		
		//Op��o para pesquisar um elemento na lista
		else if (op == '5') {
			//Solicita o valor do elemento que ser� pesquisado
			cout << "Nome do aluno ser buscado: ";
			cin >> nome_aluno;
			
			//Executa a fun��o para pesquisar a posi��o do elemento na lista
			pos = buscar(l, nome_aluno);
			
			//Se a fun��o "buscar" retornar -1 significa que o elemento n�o foi localizado
			if (pos == -1)
				cout << "Elemento nao encontrado" << endl;
			else
				//Exibe a posi��o do vetor aonde o elemento est� posicionado
				cout << "O elemento esta na posicao " << pos << endl;
			system("pause");
		}

		//Op��o para excluir toda a lista
		else if (op == '6')
			//A fun��o "inicia_lista" vai tornar a l.total = 0, indicando que a lista est� vazis
			inicia_lista(l);
		
		//Op��o para exibir a lista em ordem crescente de nota
		else if (op == '7')
			exibir_lista_ordem_nota(l);
	} while (op != '0');
}

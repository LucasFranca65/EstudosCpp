#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct lista {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da lista
	int total; //A vari�vel total vai determinar a quantidade de elementos que est�o na lista
};

//Fun��o para exibir o menu
char menu (void)
{
     char op;
     
     system("cls");
     cout << "1 - Incluir elemento na lista" << endl;
     cout << "2 - Excluir elemento na lista" << endl;
     cout << "3 - Exibir os elemento da lista" << endl;
     cout << "4 - Alterar um elemento da lista" << endl;
     cout << "5 - Pesquisar elemento na lista" << endl;
     cout << "6 - Excluir toda a lista" << endl;
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
void incluir_lista(lista & l, char e, int tam_max) {
	//Verifica se a lista est� cheia.
     //Caso a lista esteja cheia, n�o � poss�vel incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Inclui o elemento na �ltima posi��o da lista
		l.info[l.total] = e;
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Elemento '" << e << "' incluido na lista" << endl;
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
		for (i = 0; i < l.total; i++)
			cout << l.info[i] << endl;
	system("pause");
}

//Fun��o que retorno a posi��o no vetor do elemento buscado
int buscar (lista l, char e) {
	int i, p = -1;
	
	if (lista_vazia(l) == true)
		return -1;
	else {
		//Loop para verificar se existe algum elemento na 
		//lista que corresponda ao elemento buscao
		for (i = 0; i < l.total; i++)
			if (l.info[i] == e)
				//Se o elemento for localizado, guarda a informa��o 
				//da sua posi��o do vetor na vari�vel pos
				p = i;
		//Retorna a posi��o do vetor aonde o elemento foi localizado,
    	//ou, se o elemento n�o foi encontrado, retorna o n�mero -1
		return p;	
	}
}

//Fun��o para alterar um elemento na lista
void alterar (lista & l, char e, char novo) {
	int pos;
	//Chama a fun��o "buscar" para identificar a posi��o no vetor do elemento que ser� alterado
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a fun��o "buscar" retornou -1 significa que n�o localizou o elemento)
	if (pos == -1)
		cout << "Elemento nao encontrado" << endl;
	else {
		//Armazena na mesma posi��o aonde foi localizado, o elemento que deve ser alterado
		l.info[pos] = novo;
		cout << "Valor alterado" << endl;
	}
	system("pause");
}

//Fun��o para excluir um elemento da lista
void excluir (lista & l, char e) {
	int pos, i;
	
	//Chama a fun��o "buscar" para identificar a posi��o no vetor do elemento que ser� exclu�do
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a fun��o "buscar" retornou -1 significa que n�o localizou o elemento)
	if (pos == -1)
		cout << "Elemento nao encontrado" << endl;
	else {
		//Loop para deslocar todos os elementos a direita do elemento uma 
		//posi��o � esquerda. Dessa forma, o elemento a ser exclu�do � sobrescrito
		for (i = pos; i < l.total - 1; i++)
			l.info[i] = l.info[i+1];
		
		//Atualiza a quantidade de elementos na lista
		l.total --;
		cout << "Elemento excluido" << endl;
	}
	system("pause");
}

//Fun��o principal
int main() {
	lista l; //A vari�vel l representa a lista (definida pela struct lista)
	char op, elemento, novo_elem;
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
			cout << "Qual o elemento a ser incluido na lista: ";
			cin >> elemento;
			
			//Executa a fun��o para incluir o novo elemento na lista
			incluir_lista(l, elemento, tam_max);
		}
		
		//Op��o de exclus�o
		else if (op == '2') {
			//Solicita o valor do elemento que ser� exclu�do
			cout << "Elemento a ser excluido: ";
			cin >> elemento;
			
			//Executa a fun��o para excluir o elemento da lista
			excluir(l, elemento);
		}
		
		//Op��o para exibir a lista
		else if (op == '3')
			//Executa a fun��o para exibir todos os elementos da lista
			exibir_lista(l);
			
		//Op��o para alterar o valor de um elemento da lista
		else if (op == '4') {
			//Solicita o valor do elemento que ser� alterado
			cout << "Elemento para ser alterado: ";
			cin >> elemento;
			
			//Solicita o novo valor do elemento
			cout << "Novo valor para o elemento: ";
			cin >> novo_elem;
			
			//Executa a fun��o para altarar o valor do elemento da lista
			alterar(l, elemento, novo_elem);
		}
		
		//Op��o para pesquisar um elemento na lista
		else if (op == '5') {
			//Solicita o valor do elemento que ser� pesquisado
			cout << "Elemento a ser buscado: ";
			cin >> elemento;
			
			//Executa a fun��o para pesquisar a posi��o do elemento na lista
			pos = buscar(l, elemento);
			
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
	} while (op != '0');
}

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct fila {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da fila
	int total; //A vari�vel total vai determinar a quantidade de elementos que est�o na fila
	int ini, fin; //As vari�veis ini e fin indicam, respectivamente, a posi��o inicial e final da fila no vetor info
};

//Fun��o para exibir o menu
char menu (void)
{
     char op;
     
     system("cls");
     cout << "1 - Enfileiar" << endl;
     cout << "2 - Desenfileirar" << endl;
     cout << "3 - Exibir fila" << endl;
     cout << "0 - Sair" << endl;
     cout << "Opcao: ";
     cin >> op;
     
     return op;
}

//Fun��o que inicializa a fila
//Quando a variavel total for igual a zero siginifca que a lista esta vazia
//A vari�vel fin inicia com -1 porque a primeira a��o para enfileirar � aumentar
//essa vari�vel
void inicia_fila(fila & f) {
	f.total = 0; 
	f.ini = 0;
	f.fin = -1;
}

//Fun��o que identifica se a fila est� cheia
bool fila_cheia(fila f, int tam) {
	if (f.total == tam) 
		return true;
	else
		return false;
}

//Fun��o que identifica se a fila est� vazia
bool fila_vazia(fila f) {
	if (f.total == 0)
		return true;
	else
		return false;
}

//A fun��o incrementar � necess�rio para implementar a fila circlar
//Se a vari�vel estiver na �ltima posi��o do vetor, ela retorna para posi��o 0,
//caso contr�rio, ela � incrementada de uma posi��o
int incrementar (int x, int tam) {
	if (x == tam - 1)
		x = 0;
	else
		x++;
	return x;
}

//Fun��o para enfileirar um elemento
void enfileirar (fila & f, char e, int tam) {
	//Verifica se a fila est� cheia, antes de enfileirar
	if (fila_cheia(f, tam) == true)
		cout << "Fila cheia" << endl;
	else {
		//Incrementa a quantidade de itens na fila
		f.total ++;
		//Define a posi��o final da fila
		f.fin = incrementar(f.fin, tam);
		//Inclui o elemento na posi��o final da fila
		f.info[f.fin] = e;
		cout << "Elemento enfileirado" << endl;
	}
}

//Fun��o para desenfileirar um elemento
void desenfileirar(fila & f, int tam) {
	//Verifica se a fila est� vazia antes de desenfileirar
	if (fila_vazia(f) == true)
		cout << "Fila Vazia" << endl;
	else {
		//Exibi o elemento que est� no in�cio da fila e ser� desenfileirado
		cout << "O elemento '" << f.info[f.ini] << "' foi desenfileirado" << endl;
		//Diminui a quantidade de elementos na fila
		f.total --;
		//Define a nova posi��o inicial da fila
		f.ini = incrementar(f.ini, tam);
	}
	system("pause");
}

//Fun��o para exibir a fila
void exibir_fila (fila f, int tam) {
	int i, j;
	//Verifica se a fila est� vazia, antes de exibir a fila
	if (fila_vazia(f) == true)
		cout << "Fila Vazia" << endl;
	else {
		//Posiciona o �ndice na in�cio da fila
		i = f.ini;
		//Repete a quantidade de vezes que existe de elementos na fila
		for (j = 1; j <= f.total; j++) {
			//Exibe o elemento da fila
			cout << f.info[i] << " - ";
			//Posiciona o �ndice na pr�xima posi��o da fila
			i = incrementar(i, tam);
		}
	}
	system("pause"); 
}

//Fun��o principal
int main() {
	fila f; //A vari�vel f representa a fila (definida pela struct fila)
	char op, elemento;
	int tam_max = 5; //A vari�vel tam_max define a quantidade m�xima de elementos que a fila pode ter
	
	//Inicia a fila
	inicia_fila(f);
	
	do {
		//Fun��o que exibe o menu e retorna a op��o selecionada
		op = menu();
		
		//Op��o de enfileiramento
		if (op == '1') {
			//Solicita o valor do novo elemento
			cout << "Qual o elemento a ser enfileirado: ";
			cin >> elemento;
			
			//Executa a fun��o para enfileira o elemento na fila
			enfileirar(f, elemento, tam_max);
		}
		
		//Op��o de desempilhar
		else if (op == '2') 
			//Executa a fun��o para desenfileirar um elemento
			desenfileirar(f, tam_max); 
		
		//Op��o para exibir a fila
		else if (op == '3')
			//Executa a fun��o para exibir todos os elementos da fila
			exibir_fila(f, tam_max);
		
	} while (op != '0');
}

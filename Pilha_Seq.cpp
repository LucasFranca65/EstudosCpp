#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct pilha {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da pilha
	int topo; //A vari�vel topo vai indicar o topo da pilha
};

//Fun��o para exibir o menu
char menu (void)
{
     char op;
     
     system("cls");
     cout << "1 - Empilhar" << endl;
     cout << "2 - Desempilhar" << endl;
     cout << "3 - Exibir pilha" << endl;
     cout << "4 - Desempilhar todos os elementos" << endl;
     cout << "0 - Sair" << endl;
     cout << "Opcao: ";
     cin >> op;
     
     return op;
}

//Fun��o que inicializa a pilha
//A vari�vel topo inicia com -1 porque a primeira a��o para empilhar � aumentar
//essa vari�vel
void inicia_pilha(pilha & p) {
	p.topo = -1;
}

//Fun��o que identifica se a pilha est� cheia
bool pilha_cheia(pilha p, int tam) {
	//Como o topo indica a posi��o do vetor aonde est� o topo da pilha, 
	//o teste consiste em avaliar se ele � igual ao tamanho m�ximo da pilha -1
	if (p.topo == tam - 1) 
		return true;
	else
		return false;
}

//Fun��o que identifica se a pilha est� vazia
bool pilha_vazia(pilha p) {
	if (p.topo == -1)
		return true;
	else
		return false;
}

//Fun��o para empilhar um elemento
void empilhar(pilha & p, char e, int tam) {
	//Verifica se a pilha est� cheia antes de empilhar um novo elemento
	if (pilha_cheia(p, tam) == true)
		cout << "Pilha cheia" << endl;
	else {
		//Aumenta o topo da pilha
		p.topo ++;
		//Inclui o novo elemento no topo da pilha
		p.info[p.topo] = e;
		cout << "Elemento empilhado" << endl;
	}
	system("pause");
}

//Fun��op para desemepilhar um elemento
bool desempilhar (pilha & p, char & elem_desemp) {	
	//Verifica se a pilha est� vazia antes de deseppilhar
	//Se estiver vazia, retorna falso para fun��o principal,
	//indicando que n�o foi poss�vel desempilhar
	if (pilha_vazia(p) == true)
		return false;
	else {
		//Armazena o elemento do topo da pilha na vari�vel elem_desemp
		//Essa vari�vel foi passada como par�metro por refer�ncia e ser� 
		//retornada para a fun��o principal
		elem_desemp = p.info[p.topo];
		//Baixa o topo da pilha
		p.topo --;
		//Retorna verdadeiro para a fun��o principal, indicando que foi 
		//poss�vel desempilhar
		return true;
	}
	system("pause");
}

//Fun��o para exibir os elementos da pilha
void exibir_pilha (pilha p) {
	int i;
	//Verifica se a pilha est� vazia
	if (pilha_vazia(p) == true)
		cout << "Pilha Vazia" << endl;
	else
		//Repete a exibi��o dos elementos no vetor
		//iniciando no topo e descendo at� a base da pilha
		for (i = p.topo; i >= 0; i--)
			cout << p.info[i] << endl;
	system("pause");
}

//Fun��o principal
int main() {
	pilha p; //A vari�vel p representa a pilha (definida pela struct pilha)
	char op, elemento;
	int tam_max = 5; //A vari�vel tam_max define a quantidade m�xima de elementos que a pilha pode ter
	
	//Inicia a pilha. 
	inicia_pilha(p);
	
	do {
		//Fun��o que exibe o menu e retorna a op��o selecionada
		op = menu();
		
		//Op��o de empilhamento
		if (op == '1') {
			//Solicita o valor do novo elemento a ser empilhado
			cout << "Qual o elemento a ser empilhado: ";
			cin >> elemento;
			
			//Executa a fun��o para empilhar o novo elemento na lista
			empilhar(p, elemento, tam_max);
		}
		
		//Op��o de desempilhar
		else if (op == '2') {
			//Verifica se a fun��o desempulhar retornou verdadeiro,
			//indicando que houver desempilhamento
			if (desempilhar(p, elemento) == true) 
				//Exibe o elemento que foi retirado do topo da pilha
				cout << "O elemento '" << elemento << "' foi desempilhado" << endl;
			else
				cout << "Pilha Vazia" << endl;
			system("pause");
		}
		
		//Op��o para exibir a pilha
		else if (op == '3')
			//Executa a fun��o para exibir todos os elementos da lista
			exibir_pilha(p);

		//op��o para desempilhar todos os elementos da pilha		
		else if (op == '4') {
			//Enquanto houver elementos para serem desempilhados 
			//exibir o elemento que foi retirado da pilha
			while (desempilhar(p, elemento) == true)
				cout << "O elemento '" << elemento << "' foi desempilhado" << endl;
			system("pause");
		}
			
	} while (op != '0');
}

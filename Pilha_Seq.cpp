#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct pilha {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da pilha
	int topo; //A variável topo vai indicar o topo da pilha
};

//Função para exibir o menu
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

//Função que inicializa a pilha
//A variável topo inicia com -1 porque a primeira ação para empilhar é aumentar
//essa variável
void inicia_pilha(pilha & p) {
	p.topo = -1;
}

//Função que identifica se a pilha está cheia
bool pilha_cheia(pilha p, int tam) {
	//Como o topo indica a posição do vetor aonde está o topo da pilha, 
	//o teste consiste em avaliar se ele é igual ao tamanho máximo da pilha -1
	if (p.topo == tam - 1) 
		return true;
	else
		return false;
}

//Função que identifica se a pilha está vazia
bool pilha_vazia(pilha p) {
	if (p.topo == -1)
		return true;
	else
		return false;
}

//Função para empilhar um elemento
void empilhar(pilha & p, char e, int tam) {
	//Verifica se a pilha está cheia antes de empilhar um novo elemento
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

//Funçãop para desemepilhar um elemento
bool desempilhar (pilha & p, char & elem_desemp) {	
	//Verifica se a pilha está vazia antes de deseppilhar
	//Se estiver vazia, retorna falso para função principal,
	//indicando que não foi possível desempilhar
	if (pilha_vazia(p) == true)
		return false;
	else {
		//Armazena o elemento do topo da pilha na variável elem_desemp
		//Essa variável foi passada como parâmetro por referência e será 
		//retornada para a função principal
		elem_desemp = p.info[p.topo];
		//Baixa o topo da pilha
		p.topo --;
		//Retorna verdadeiro para a função principal, indicando que foi 
		//possível desempilhar
		return true;
	}
	system("pause");
}

//Função para exibir os elementos da pilha
void exibir_pilha (pilha p) {
	int i;
	//Verifica se a pilha está vazia
	if (pilha_vazia(p) == true)
		cout << "Pilha Vazia" << endl;
	else
		//Repete a exibição dos elementos no vetor
		//iniciando no topo e descendo até a base da pilha
		for (i = p.topo; i >= 0; i--)
			cout << p.info[i] << endl;
	system("pause");
}

//Função principal
int main() {
	pilha p; //A variável p representa a pilha (definida pela struct pilha)
	char op, elemento;
	int tam_max = 5; //A variável tam_max define a quantidade máxima de elementos que a pilha pode ter
	
	//Inicia a pilha. 
	inicia_pilha(p);
	
	do {
		//Função que exibe o menu e retorna a opção selecionada
		op = menu();
		
		//Opção de empilhamento
		if (op == '1') {
			//Solicita o valor do novo elemento a ser empilhado
			cout << "Qual o elemento a ser empilhado: ";
			cin >> elemento;
			
			//Executa a função para empilhar o novo elemento na lista
			empilhar(p, elemento, tam_max);
		}
		
		//Opção de desempilhar
		else if (op == '2') {
			//Verifica se a função desempulhar retornou verdadeiro,
			//indicando que houver desempilhamento
			if (desempilhar(p, elemento) == true) 
				//Exibe o elemento que foi retirado do topo da pilha
				cout << "O elemento '" << elemento << "' foi desempilhado" << endl;
			else
				cout << "Pilha Vazia" << endl;
			system("pause");
		}
		
		//Opção para exibir a pilha
		else if (op == '3')
			//Executa a função para exibir todos os elementos da lista
			exibir_pilha(p);

		//opção para desempilhar todos os elementos da pilha		
		else if (op == '4') {
			//Enquanto houver elementos para serem desempilhados 
			//exibir o elemento que foi retirado da pilha
			while (desempilhar(p, elemento) == true)
				cout << "O elemento '" << elemento << "' foi desempilhado" << endl;
			system("pause");
		}
			
	} while (op != '0');
}

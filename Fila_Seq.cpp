#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct fila {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da fila
	int total; //A variável total vai determinar a quantidade de elementos que estão na fila
	int ini, fin; //As variáveis ini e fin indicam, respectivamente, a posição inicial e final da fila no vetor info
};

//Função para exibir o menu
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

//Função que inicializa a fila
//Quando a variavel total for igual a zero siginifca que a lista esta vazia
//A variável fin inicia com -1 porque a primeira ação para enfileirar é aumentar
//essa variável
void inicia_fila(fila & f) {
	f.total = 0; 
	f.ini = 0;
	f.fin = -1;
}

//Função que identifica se a fila está cheia
bool fila_cheia(fila f, int tam) {
	if (f.total == tam) 
		return true;
	else
		return false;
}

//Função que identifica se a fila está vazia
bool fila_vazia(fila f) {
	if (f.total == 0)
		return true;
	else
		return false;
}

//A função incrementar é necessário para implementar a fila circlar
//Se a variável estiver na última posição do vetor, ela retorna para posição 0,
//caso contrário, ela é incrementada de uma posição
int incrementar (int x, int tam) {
	if (x == tam - 1)
		x = 0;
	else
		x++;
	return x;
}

//Função para enfileirar um elemento
void enfileirar (fila & f, char e, int tam) {
	//Verifica se a fila está cheia, antes de enfileirar
	if (fila_cheia(f, tam) == true)
		cout << "Fila cheia" << endl;
	else {
		//Incrementa a quantidade de itens na fila
		f.total ++;
		//Define a posição final da fila
		f.fin = incrementar(f.fin, tam);
		//Inclui o elemento na posição final da fila
		f.info[f.fin] = e;
		cout << "Elemento enfileirado" << endl;
	}
}

//Função para desenfileirar um elemento
void desenfileirar(fila & f, int tam) {
	//Verifica se a fila está vazia antes de desenfileirar
	if (fila_vazia(f) == true)
		cout << "Fila Vazia" << endl;
	else {
		//Exibi o elemento que está no início da fila e será desenfileirado
		cout << "O elemento '" << f.info[f.ini] << "' foi desenfileirado" << endl;
		//Diminui a quantidade de elementos na fila
		f.total --;
		//Define a nova posição inicial da fila
		f.ini = incrementar(f.ini, tam);
	}
	system("pause");
}

//Função para exibir a fila
void exibir_fila (fila f, int tam) {
	int i, j;
	//Verifica se a fila está vazia, antes de exibir a fila
	if (fila_vazia(f) == true)
		cout << "Fila Vazia" << endl;
	else {
		//Posiciona o índice na início da fila
		i = f.ini;
		//Repete a quantidade de vezes que existe de elementos na fila
		for (j = 1; j <= f.total; j++) {
			//Exibe o elemento da fila
			cout << f.info[i] << " - ";
			//Posiciona o índice na próxima posição da fila
			i = incrementar(i, tam);
		}
	}
	system("pause"); 
}

//Função principal
int main() {
	fila f; //A variável f representa a fila (definida pela struct fila)
	char op, elemento;
	int tam_max = 5; //A variável tam_max define a quantidade máxima de elementos que a fila pode ter
	
	//Inicia a fila
	inicia_fila(f);
	
	do {
		//Função que exibe o menu e retorna a opção selecionada
		op = menu();
		
		//Opção de enfileiramento
		if (op == '1') {
			//Solicita o valor do novo elemento
			cout << "Qual o elemento a ser enfileirado: ";
			cin >> elemento;
			
			//Executa a função para enfileira o elemento na fila
			enfileirar(f, elemento, tam_max);
		}
		
		//Opção de desempilhar
		else if (op == '2') 
			//Executa a função para desenfileirar um elemento
			desenfileirar(f, tam_max); 
		
		//Opção para exibir a fila
		else if (op == '3')
			//Executa a função para exibir todos os elementos da fila
			exibir_fila(f, tam_max);
		
	} while (op != '0');
}

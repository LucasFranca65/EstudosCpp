#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

struct lista {
	char info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da lista
	int total; //A variável total vai determinar a quantidade de elementos que estão na lista
};

//Função para exibir o menu
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

//Função que inicializa a lista
//Quando a variavel total for igual a zero siginifca que a lista esta vazia
void inicia_lista(lista & l) {
	l.total = 0;
}

//Função que identfica se a lista esta cheia
//A lista está cheia quando a variável total é igual ao tamanho máximo definido
bool lista_cheia (lista l, int tam_max) {
	if (l.total == tam_max)
		return true;
	else
		return false;
}

//Função que identfica se a lista esta vazia
//A lista está vazia quando a variável total é igual a 0
bool lista_vazia (lista l) {
	if (l.total == 0)
		return true;
	else
		return false;
}

//Função para realizar a inclusão de um novo elemento na lista
void incluir_lista(lista & l, char e, int tam_max) {
	//Verifica se a lista está cheia.
     //Caso a lista esteja cheia, não é possível incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Inclui o elemento na última posição da lista
		l.info[l.total] = e;
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Elemento '" << e << "' incluido na lista" << endl;
	}
	system("pause");
}

//Função para exibir todos os elementos da lista
void exibir_lista (lista l) {
	int i;
	
	//Verifica se a lista está vazia
	if (lista_vazia(l) == true)
		cout << "Lista vazia" << endl;
	else
		//Loop para exibir todos os elementos da lista
		for (i = 0; i < l.total; i++)
			cout << l.info[i] << endl;
	system("pause");
}

//Função que retorno a posição no vetor do elemento buscado
int buscar (lista l, char e) {
	int i, p = -1;
	
	if (lista_vazia(l) == true)
		return -1;
	else {
		//Loop para verificar se existe algum elemento na 
		//lista que corresponda ao elemento buscao
		for (i = 0; i < l.total; i++)
			if (l.info[i] == e)
				//Se o elemento for localizado, guarda a informação 
				//da sua posição do vetor na variável pos
				p = i;
		//Retorna a posição do vetor aonde o elemento foi localizado,
    	//ou, se o elemento não foi encontrado, retorna o número -1
		return p;	
	}
}

//Função para alterar um elemento na lista
void alterar (lista & l, char e, char novo) {
	int pos;
	//Chama a função "buscar" para identificar a posição no vetor do elemento que será alterado
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a função "buscar" retornou -1 significa que não localizou o elemento)
	if (pos == -1)
		cout << "Elemento nao encontrado" << endl;
	else {
		//Armazena na mesma posição aonde foi localizado, o elemento que deve ser alterado
		l.info[pos] = novo;
		cout << "Valor alterado" << endl;
	}
	system("pause");
}

//Função para excluir um elemento da lista
void excluir (lista & l, char e) {
	int pos, i;
	
	//Chama a função "buscar" para identificar a posição no vetor do elemento que será excluído
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a função "buscar" retornou -1 significa que não localizou o elemento)
	if (pos == -1)
		cout << "Elemento nao encontrado" << endl;
	else {
		//Loop para deslocar todos os elementos a direita do elemento uma 
		//posição à esquerda. Dessa forma, o elemento a ser excluído é sobrescrito
		for (i = pos; i < l.total - 1; i++)
			l.info[i] = l.info[i+1];
		
		//Atualiza a quantidade de elementos na lista
		l.total --;
		cout << "Elemento excluido" << endl;
	}
	system("pause");
}

//Função principal
int main() {
	lista l; //A variável l representa a lista (definida pela struct lista)
	char op, elemento, novo_elem;
	int tam_max = 5; //A variável tam_max define a quantidade máxima de elementos que a lista pode ter
	int pos;
	
	//Inicia a lista. Essa função determina que a variável total é igual a 0
	inicia_lista(l);
	
	do {
		//Função que exibe o menu e retorna a opção selecionada
		op = menu();
		
		//Opção de inclusão
		if (op == '1') {
			//Solicita o valor do novo elemento
			cout << "Qual o elemento a ser incluido na lista: ";
			cin >> elemento;
			
			//Executa a função para incluir o novo elemento na lista
			incluir_lista(l, elemento, tam_max);
		}
		
		//Opção de exclusão
		else if (op == '2') {
			//Solicita o valor do elemento que será excluído
			cout << "Elemento a ser excluido: ";
			cin >> elemento;
			
			//Executa a função para excluir o elemento da lista
			excluir(l, elemento);
		}
		
		//Opção para exibir a lista
		else if (op == '3')
			//Executa a função para exibir todos os elementos da lista
			exibir_lista(l);
			
		//Opção para alterar o valor de um elemento da lista
		else if (op == '4') {
			//Solicita o valor do elemento que será alterado
			cout << "Elemento para ser alterado: ";
			cin >> elemento;
			
			//Solicita o novo valor do elemento
			cout << "Novo valor para o elemento: ";
			cin >> novo_elem;
			
			//Executa a função para altarar o valor do elemento da lista
			alterar(l, elemento, novo_elem);
		}
		
		//Opção para pesquisar um elemento na lista
		else if (op == '5') {
			//Solicita o valor do elemento que será pesquisado
			cout << "Elemento a ser buscado: ";
			cin >> elemento;
			
			//Executa a função para pesquisar a posição do elemento na lista
			pos = buscar(l, elemento);
			
			//Se a função "buscar" retornar -1 significa que o elemento não foi localizado
			if (pos == -1)
				cout << "Elemento nao encontrado" << endl;
			else
				//Exibe a posição do vetor aonde o elemento está posicionado
				cout << "O elemento esta na posicao " << pos << endl;
			system("pause");
		}

		//Opção para excluir toda a lista
		else if (op == '6')
			//A função "inicia_lista" vai tornar a l.total = 0, indicando que a lista está vazis
			inicia_lista(l);
	} while (op != '0');
}

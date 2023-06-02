#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;
//Estrutura para armanezar as informações dos alunos na lista
struct aluno {
	string nome;
	float nota;
};

struct lista {
	aluno info[5]; //Esse vetor vai ser utilizado para armazenar os elementos da lista
	int total; //A variável total vai determinar a quantidade de elementos que estão na lista
};

//Função para exibir o menu
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
void incluir_lista(lista & l, aluno e, int tam_max) {
	//Verifica se a lista está cheia.
     //Caso a lista esteja cheia, não é possível incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Inclui o elemento na última posição da lista
		l.info[l.total] = e;
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Aluno '" << e.nome << "' incluido na lista" << endl;
	}
	system("pause");
}

//Função para realizar a inclusão de um novo elemento na lista em ordem crescente
void incluir_lista_ordenada(lista & l, aluno e, int tam_max) {
	int i, j;
	//Verifica se a lista está cheia.
     //Caso a lista esteja cheia, não é possível incluir novos elementos
	 if (lista_cheia(l, tam_max) == true)
		cout << "Lista cheia" << endl;
	else {
		//Iniciar a leitura a lista pela primeira posição
		i = 0;
		//Repetição para encontrar a posição aonde o novo elemento deve ser incluído,
		//considerando a ordem crescente
		//Caso todos os elementos sejam menores do qual está sendo inserido,
		//vai incluir no final
		while (l.info[i].nome < e.nome && i < l.total)
			i++;
		
		//A partir do último elemento até a posição aonde o novo elemento será
		//inserido, desloca cada elemento para a direita. Assim a posição encontrada
		//para o novo elemento, fica disponível
		for (j = l.total; j > i; j--)
			l.info[j] = l.info[j-1];
			
		//Inclui o elemento na posição correta da ordem
		l.info[i] = e;	
		
		//Incrementa a quantidade de elementos na lista
		l.total ++;
		cout << "Aluno '" << e.nome << "' incluido na lista" << endl;
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
		for (i = 0; i < l.total; i++) {
			cout << "Nome: " << l.info[i].nome << endl;
			cout << "Nota: " << l.info[i].nota << endl;
			cout << "----------------------------" << endl;
		}
	system("pause");
}


//Função para exibir todos os elementos da lista na ordem da nota
//Mesmo alterando a ordem da lista, isso não vai permanecer quando 
//a função terminar de ser executado porque o parâmetro não foi
//passado por referência
void exibir_lista_ordem_nota (lista l) {
	int i, j;
	aluno aux;
	
	//Verifica se a lista está vazia
	if (lista_vazia(l) == true)
		cout << "Lista vazia" << endl;
	else {
	
		//Essa repetição avalia se a nota está em posição incorreta em relação a ordem 
		//e inverte as posições
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


//Função que retorno a posição no vetor do elemento buscado
int buscar (lista l, string e) {
	int i, p = -1;
	
	if (lista_vazia(l) == true)
		return -1;
	else {
		//Loop para verificar se existe algum elemento na 
		//lista que corresponda ao elemento buscao
		for (i = 0; i < l.total; i++)
			if (l.info[i].nome == e)
				//Se o elemento for localizado, guarda a informação 
				//da sua posição do vetor na variável pos
				p = i;
		//Retorna a posição do vetor aonde o elemento foi localizado,
    	//ou, se o elemento não foi encontrado, retorna o número -1
		return p;	
	}
}

//Função para alterar um elemento na lista
void alterar (lista & l, aluno e) {
	int pos;
	//Chama a função "buscar" para identificar a posição no vetor do elemento que será alterado
	pos = buscar(l, e.nome);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a função "buscar" retornou -1 significa que não localizou o elemento)
	if (pos == -1)
		cout << "Aluno nao encontrado" << endl;
	else {
		//Armazena na mesma posição aonde foi localizado, o elemento que deve ser alterado
		l.info[pos].nota = e.nota;
		cout << "Nota alterada" << endl;
	}
	system("pause");
}

//Função para excluir um elemento da lista
void excluir (lista & l, string e) {
	int pos, i;
	
	//Chama a função "buscar" para identificar a posição no vetor do elemento que será excluído
	pos = buscar(l, e);
	
	//Verifica se o elemento foi localizado na lista 
	//(se a função "buscar" retornou -1 significa que não localizou o elemento)
	if (pos == -1)
		cout << "Aluno nao encontrado" << endl;
	else {
		//Loop para deslocar todos os elementos a direita do elemento uma 
		//posição à esquerda. Dessa forma, o elemento a ser excluído é sobrescrito
		for (i = pos; i < l.total - 1; i++)
			l.info[i] = l.info[i+1];
		
		//Atualiza a quantidade de elementos na lista
		l.total --;
		cout << "Aluno excluido" << endl;
	}
	system("pause");
}

//Função principal
int main() {
	lista l; //A variável l representa a lista (definida pela struct lista)
	char op;
	string nome_aluno;
	aluno elemento, novo_elem;
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
			cout << "Qual o nome do aluno a ser incluido na lista: ";
			cin >> elemento.nome;
			cout << "Qual a nota do aluno: ";
			cin >> elemento.nota;
			
			//Executa a função para incluir o novo elemento na lista
			incluir_lista_ordenada(l, elemento, tam_max);
		}
		
		//Opção de exclusão
		else if (op == '2') {
			//Solicita o valor do elemento que será excluído
			cout << "Qual o nome do aluno a ser excluido: ";
			cin >> nome_aluno;
			
			//Executa a função para excluir o elemento da lista
			excluir(l, nome_aluno);
		}
		
		//Opção para exibir a lista
		else if (op == '3')
			//Executa a função para exibir todos os elementos da lista
			exibir_lista(l);
			
		//Opção para alterar o valor de um elemento da lista
		else if (op == '4') {
			//Solicita o valor do elemento que será alterado
			cout << "Nome do aluno: ";
			cin >> elemento.nome;
			
			//Solicita o novo valor do elemento
			cout << "Nova nota: ";
			cin >> elemento.nota;
			
			//Executa a função para altarar o valor do elemento da lista
			alterar(l, elemento);
		}
		
		//Opção para pesquisar um elemento na lista
		else if (op == '5') {
			//Solicita o valor do elemento que será pesquisado
			cout << "Nome do aluno ser buscado: ";
			cin >> nome_aluno;
			
			//Executa a função para pesquisar a posição do elemento na lista
			pos = buscar(l, nome_aluno);
			
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
		
		//Opção para exibir a lista em ordem crescente de nota
		else if (op == '7')
			exibir_lista_ordem_nota(l);
	} while (op != '0');
}

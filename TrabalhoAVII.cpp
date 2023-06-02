// Atividade Pontuada Esrutura de dados com C++
// Aluno: Lucas Olivira França
// Matricula: 202208651151
// Codigo adaptado do exercicio de lista Encadeada Ordenada

#include <iostream>
#include<cstdlib>
using namespace std;

// Estrutura para armazenar os produtos
struct produto {
    string nome; //Armazenar nome do produto
    float valor;//Armazenar o valor
    float totalVenda;
    int qtd;//Armazenar a quantidade em estoque
	produto *link; //Campo para armazenar o endereço de memória do próximo 
                 //elemento da lista
};

// Função para testar se a lista está vazia
char lista_vazia(produto *l){
     //Quando o endereço inicial (l) tem valor nulo, a lista está vazia
	 if (l == NULL)
        return 'S';
     else
        return 'N';
}

produto* inserir_em_ordem (produto *l, string nome, float valor){
     produto *n, *p;
     
	// Solicita uma nova posicao de memoria e armazena o novo elemento
     n = new produto;
     n->nome = nome;
     n->valor = valor;
     n->qtd = 0;
     n->totalVenda = 0;
     n->link = NULL;
     
	// Verifica se a lista está vazia
     if (lista_vazia(l) == 'S')
     {
        cout << "Produto " << nome << " inserido na lista" << endl;
        system("pause");
		//Se a stiver vazia, retorna o endereço da nova posição para o ponteiro "L", que indica a primeira posição da lista
        return n;
     }
     else
     {
        //Posiciona o ponteiro "P" na primeira posição da lista
        p = l;
        
        //Testa se o primeiro elemento da lista é maior que o elemento que será inserido
        if (p->nome > nome)
        {
           //Faz o novo elmento apontar para o primeiro elmento da lista
           n->link = l;
           cout << "Produto " << nome << " inserido na lista" << endl;
           system("pause");
           //Retorona o endereço do novo elemento para o ponteiro "L". Assim o novo elemento passa a ser o primeiro da lista
           return n;
        }
        else
        {
            //Testa se chegou ao fim da fila e se o elemento seguinte é menor que o novo elemento
            while (p->link != NULL && p->link->nome < nome)
            {
               //Posiciona o ponteiro "P" no próximo elemento da lista
               p = p->link;
            }
            
            //Quando for localizada a posição correta para o novo elemento ser inserido,
            //faz o link do novo elemento apontar para próximo
            n->link = p->link;
            //Faz o o link do elemento anterior apontar para o novo elemento
            p->link = n;
            cout << "Produto " << nome << " inserido na lista" << endl;
            system("pause");
            return l;
        }
     }     
}


produto *excluir(produto *l, string nome){
      produto *p, *t;
      
      //Verifica se a lista está vazia
      if (lista_vazia(l) == 'S'){
         cout << "Não há Produtos Cadastrado" << endl;
         system("pause");
         return l;
      }
      else
      	 //Verifica se o elemento a ser excluído é menor do que o primeiro elemento
      	 //Por ser uma lista ordenada, se essa condição for verdadeira,
      	 //siginifica que o elemento não está na lista
         if (l->nome > nome){
            cout << "O produto " << nome << " nao esta na lista" << endl;
            system("pause");
            return l;
         }
         else
         {
             //O ponteiro "p" aponta para o início da lista
			 p = l;
             
			 //Verifica se o primeiro elemento é o elemento a ser excluído
			 if (p->nome == nome)
             {
                //O ponteiro que contém o primeiro elemento da lista
                //passa a apontar para o segundo elemento da lista
				l = p->link;
				//Apaga o elemento
                delete p;
                cout << "Produto " << nome << " excluido da lista" << endl;
                system("pause");
                return l;
             }
             else
             {
             	 //Faz a repetição buscando o elemento a ser excluído
             	 //ou o final da lista
                 while (p->link != NULL and p->link->nome < nome)
                    //Passa para o próximo elemento da lista
                    p = p->link;
                 //Verifica se encontrou o elemento a ser excluído
                 if (p->link != NULL and p->link->nome == nome)
                 {
                    //O ponteiro "t" passa a apontar para o elemento a ser
                    //excluído
					t = p->link;
					//Liga o elemento anterior ao que está sendo excluído
					//ao elemento posterior ao que está sendo excluído
                    p->link = p->link->link;
                    //Exclui o elemento
                    delete t;
                    cout << "Produto " << nome << " excluido do estoque" << endl;
                    system("pause");
                    return l;
                 }
                 else
                 {
                    cout << "O Produto " << nome << " nao foi encontrado no estoque" << endl;
                    system("pause");
                    return l;
                 }                 
             }
         }
}

void buscar(produto *l, string nome){
	int pos = 1;
	
      //Verifica se a lista está vazia
      if (lista_vazia(l) == 'S')
      {
         cout << "Estoque vazio. Elemento nao Encontrado" << endl;
         system("pause");
	  }
      else {
	   	 //Percorre a lista enquanto não encontrar o elemento buscado
	   	 //ou chegar ao final da lista
         while (l != NULL and l->nome != nome) {
         	//Passa para o próximo elemento da lista
            l = l->link;
            pos ++;
        }
        
		//Verifica se encontrou o elemento buscado
        if (l != NULL and l->nome == nome)
    	{
		cout <<"Nome      ";
 		cout <<"Valor     ";     
    	cout <<"Estoque  ";
    	cout <<"Total Vendas"<<endl;
         
		cout << l->nome<<"       ";
		cout <<"R$"<<l->valor<<"    ";
		cout << l->qtd<<"        ";
		cout <<"R$"<<l->totalVenda<<" "<<endl;
		system("pause");
	    }
        else
        {
        	cout << "O Produto " << nome << "' nao esta na lista" << endl;
            system("pause");
        }                 
	}
}

void vender_produto(produto *l, string nome, int qtd){
	int pos = 1;
	int nqtd=0; // variavel temporaria para atualizar a quantidade em estoque 
    float tv=0;//  variavel temporaria valor total da venda  	  
	float ttv=0;  
	  //Verifica se a lista está vazia
      if (lista_vazia(l) == 'S'){
         cout << "Estoque vazio. Elemento nao Encontrado" << endl;
         system("pause");
	  }
      else{
	   	 //Percorre a lista enquanto não encontrar o elemento buscado
	   	 //ou chegar ao final da lista
         while (l != NULL and l->nome != nome) {
         	//Passa para o próximo elemento da lista
            l = l->link;
            pos ++;
        }        
		//Verifica se encontrou o elemento buscado
        if (l != NULL and l->nome == nome){
            //Verifica se a quantidade no estoque é suficiente para a venda
			if(l->qtd < qtd){
				cout << "Saldo Atual "<<l->qtd<<", menor que a quantidade a ser vendida"<<endl;
				system("pause");	
				}
			else{
			nqtd = l->qtd - qtd;
			tv = (qtd * l->valor);
			l->qtd = nqtd;
			ttv = (l->totalVenda+tv);
			l->totalVenda = ttv; 
			cout << "Produto "<<nome<<" vendido com sucesso"<<endl;
			cout << "Valor Total da Venda R$ " <<tv<<endl; 
			cout << "Saldo Atual "<<l->qtd<<endl;
    		system("pause");					
				}
		}
		else{
        	cout << "O Produto " << nome << "' nao esta na lista" << endl;
            system("pause");
        }                 
	}
	
	
}

void reabastecer_estoque(produto *l, string nome, int qtd){
	int pos = 1;
	int nqtd=0;
      //Verifica se a lista está vazia
      if (lista_vazia(l) == 'S')
      {
         cout << "Estoque vazio. Produto nao encontrado" << endl;
         system("pause");
	  }
      else {
	   	 //Percorre a lista enquanto não encontrar o elemento buscado
	   	 //ou chegar ao final da lista
         while (l != NULL and l->nome != nome) {
         	//Passa para o próximo elemento da lista
            l = l->link;
            pos ++;
        }        
		//Verifica se encontrou o elemento buscado
        if (l != NULL and l->nome == nome)
    	{
            nqtd = l->qtd + qtd;
			l->qtd = nqtd;
			cout << "Produto "<<nome<<" estoque reabastecido"<<endl;
			cout << "Saldo Atual "<<l->qtd<<endl;
            system("pause");
	    }
        else
        {
        	cout << "O Produto " << nome << "' nao foi encontrado" << endl;
            system("pause");
        }                 
	}
	
	
}

void exibir(produto *l){
	produto *p;
     
     //Verifica se a lista está vazia     
  	if (lista_vazia(l) == 'S')
 	 cout << "Lista vazia" << endl;
	else{
         //O ponteiro "p" aponta para o início da lista
		p = l;
		cout <<"Nome      ";
 		cout <<"Valor     ";     
    	cout <<"Estoque  ";
    	cout <<"Total Vendas"<<endl;
         //Exibe o primeiro elemento da lista
		cout << p->nome<<"       ";
		cout <<"R$"<<p->valor<<"    ";
		cout << p->qtd<<"        ";
		cout <<"R$"<<p->totalVenda<<" "<<endl;
         
         //Testa se não chegou ao fim da lista
         while (p->link != NULL){
            //Posiciona o ponteiro "p" no próximo item da lista
            p = p->link;
            //Exibe o elemento
             cout << p->nome<<"       ";
	         cout <<"R$"<< p->valor<<"      ";
	         cout << p->qtd<<"        ";
	         cout <<"R$"<<p->totalVenda<<" "<<endl;
    	}
	}
	system("pause");
}

char menu(void){
    char op;
     
    system("cls");
    cout << "1 - Cadastrar produto no Estoque" << endl;
    cout << "2 - Comprar produto / Reabastecer Estoque" << endl;
    cout << "3 - Realizar venda de produto" << endl;
	cout << "4 - Busca produto no estoque" << endl;
	cout << "5 - Exibir a lista de produtos cadastrados" << endl;
	cout << "6 - Excluir produto do estoque" << endl;
	cout << "0 - Sair" << endl;
    cout << "Opcao: ";
    cin >> op;
    return op;
}

int main (void){
    
	produto *l; //ponteiro da lista
    string nome;
    float valor = 0;
    int qtd = 0;
	char op;
    
    l = NULL;
    
    op = menu();
    
    while (op != '0'){
		if (op == '1') {
			cout << "Cadastrar novo produto" << endl;
			cout << "Nome do produto: ";
			cin >> nome;	
			cout << "Valor do Produto (0.00): ";
			cin >> valor;             
			l = inserir_em_ordem(l, nome, valor);
		}
		else if(op == '2'){
 	 		cout << "Comprar produto / Reabastecer Estoque" << endl;
 	 		cout << "Nome do produto: ";
			cin >> nome;	
			cout << "Quantidade a ser inserida: ";
			cin >> qtd; 
 	 		reabastecer_estoque(l, nome, qtd);
	  	  }
		else if(op == '3'){
 	 		cout << "Venda de Produto" << endl;
 	 		cout << "Nome do produto: ";
			cin >> nome;	
			cout << "Quantidade: ";
			cin >> qtd; 
 	 		vender_produto(l, nome, qtd);
 	  	  }
		else if (op == '4'){
			cout << "Produto a ser buscado: ";
		  	cin >> nome;
		  	buscar(l, nome);
			  }
		else if (op == '5'){
			exibir(l);
			}	
		else if (op == '6') {
    		cout << "Produto a ser excluido: ";
          	cin >> nome;
          	l = excluir(l, nome);
			  }
		op = menu();
	}
    
    return 0;
}
     


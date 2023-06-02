#include <iostream>
#include<cstdlib>
using namespace std;

//Estrutura para armazenar a lista
struct lista {
    string dado; //Campo para armazenar o conte�do da lista
    lista *link; //Campo para armazenar o endere�o de mem�ria do pr�ximo 
                 //elemento da lista
};

//Fun��o para testar se a lista est� vazia
char lista_vazia(lista *l)
{
     //Quando o endere�o inicial (l) tem valor nulo, a lista est� vazia
	 if (l == NULL)
        return 'S';
     else
        return 'N';
}

lista* inserir_em_ordem (lista *l, string elemento)
{
     lista *n, *p;
     
     //Solicita uma nova posicao de memoria e armazena o novo elemento
     n = new lista;
     n->dado = elemento;
     n->link = NULL;
     
     //Verifica se a lista est� vazia
     if (lista_vazia(l) == 'S')
     {
        cout << "Elemento " << elemento << " inserido na lista" << endl;
        system("pause");
        //Se a lista estiver vazia, retorna o endere�o da nova posi��o para o ponteiro "L", que indica a primeira posi��o da lista
        return n;
     }
     else
     {
        //Posiciona o ponteiro "P" na primeira posi��o da lista
        p = l;
        
        //Testa se o primeiro elemento da lista � maior que o elemento que ser� inserido
        if (p->dado > elemento)
        {
           //Faz o novo elmento apontar para o primeiro elmento da lista
           n->link = l;
           cout << "Elemento " << elemento << " inserido na lista" << endl;
           system("pause");
           //Retorona o endere�o do novo elemento para o ponteiro "L". Assim o novo elemento passa a ser o primeiro da lista
           return n;
        }
        else
        {
            //Testa se chegou ao fim da fila e se o elemento seguinte � menor que o novo elemento
            while (p->link != NULL && p->link->dado < elemento)
            {
               //Posiciona o ponteiro "P" no pr�ximo elemento da lista
               p = p->link;
            }
            
            //Quando for localizada a posi��o correta para o novo elemento ser inserido,
            //faz o link do novo elemento apontar para pr�ximo
            n->link = p->link;
            //Faz o o link do elemento anterior apontar para o novo elemento
            p->link = n;
            cout << "Elemento " << elemento << " inserido na lista" << endl;
            system("pause");
            return l;
        }
     }     
}

lista *inserir(lista *l, string elemento)
{
      lista *n, *p;
      
      //Solicita uma nova posicao de memoria e armazena o novo elemento
      n = new lista;
      n->dado = elemento;
      n->link = NULL;
      
      //Testa se a lista est� vazia
      if (lista_vazia(l) == 'S')
      {
          cout << "Elemento incluido com sucesso" << endl;
          system("pause");
         //devolve o endereco de mem�ria do novo elemento para a vari�vel "l", que armazena o endere�o inicial da lista
         return n;
      }
      else
      {
          //O ponteiro "p" aponta para o in�cio da lista
          p = l;
          
          //Testa se j� chegou no final da lista
          while (p->link != NULL)
          {
             //Posiciona o ponteiro "p" no pr�xima item da lista
             p = p->link;
          }
          
          //Faz com que o �ltimo elemento da lista aponte para o novo elemento;
          p->link = n;
          
          cout << "Elemento incluido com sucesso" << endl;
          system("pause");
          return l;
      }     
}

lista *excluir(lista *l, string elemento)
{
      lista *p, *t;
      
      //Verifica se a lista est� vazia
      if (lista_vazia(l) == 'S')
      {
         cout << "Lista vazia" << endl;
         system("pause");
         return l;
      }
      else
      	 //Verifica se o elemento a ser exclu�do � menor do que o primeiro elemento
      	 //Por ser uma lista ordenada, se essa condi��o for verdadeira,
      	 //siginifica que o elemento n�o est� na lista
         if (l->dado > elemento)
         {
            cout << "O elemento " << elemento << " nao esta na lista" << endl;
            system("pause");
            return l;
         }
         else
         {
             //O ponteiro "p" aponta para o in�cio da lista
			 p = l;
             
			 //Verifica se o primeiro elemento � o elemento a ser exclu�do
			 if (p->dado == elemento)
             {
                //O ponteiro que cont�m o primeiro elemento da lista
                //passa a apontar para o segundo elemento da lista
				l = p->link;
				//Apaga o elemento
                delete p;
                cout << "Elemento " << elemento << " excluido da lista" << endl;
                system("pause");
                return l;
             }
             else
             {
             	 //Faz a repeti��o buscando o elemento a ser exclu�do
             	 //ou o final da lista
                 while (p->link != NULL and p->link->dado < elemento)
                    //Passa para o pr�ximo elemento da lista
                    p = p->link;
                 //Verifica se encontrou o elemento a ser exclu�do
                 if (p->link != NULL and p->link->dado == elemento)
                 {
                    //O ponteiro "t" passa a apontar para o elemento a ser
                    //exclu�do
					t = p->link;
					//Liga o elemento anterior ao que est� sendo exclu�do
					//ao elemento posterior ao que est� sendo exclu�do
                    p->link = p->link->link;
                    //Exclui o elemento
                    delete t;
                    cout << "Elemento " << elemento << " excluido da lista" << endl;
                    system("pause");
                    return l;
                 }
                 else
                 {
                    cout << "O elemento " << elemento << " nao esta na lista" << endl;
                    system("pause");
                    return l;
                 }                 
             }
         }
}

void buscar(lista *l, string elemento)
{
	int pos = 1;
	
      //Verifica se a lista est� vazia
      if (lista_vazia(l) == 'S')
      {
         cout << "Lista vazia. Elemento nao localizado" << endl;
         system("pause");
	  }
      else {
	   	 //Percorre a lista enquanto n�o encontrar o elemento buscado
	   	 //ou chegar ao final da lista
         while (l != NULL and l->dado != elemento) {
         	//Passa para o pr�ximo elemento da lista
            l = l->link;
            pos ++;
        }
        
		//Verifica se encontrou o elemento buscado
        if (l != NULL and l->dado == elemento)
    	{
            cout << "O elemento '" << elemento << "' foi localizado na posicao " << pos << endl;
            cout << "Endereco de memoria: " << l << endl;
            system("pause");
	    }
        else
        {
        	cout << "O elemento '" << elemento << "' nao esta na lista" << endl;
            system("pause");
        }                 
	}
}


void exibir(lista *l)
{
     lista *p;
     
     //Verifica se a lista est� vazia     
     if (lista_vazia(l) == 'S')
        cout << "Lista vazia" << endl;
     else
     {
         //O ponteiro "p" aponta para o in�cio da lista
         p = l;

         //Exibe o primeiro elemento da lista
         cout << p->dado << endl;
         
         //Testa se n�o chegou ao fim da lista
         while (p->link != NULL)
         {
            //Posiciona o ponteiro "p" no pr�ximo item da lista
            p = p->link;
            //Exibe o elemento
            cout << p->dado << endl;
         }
      }
     system("pause");
}

char menu(void)
{
     char op;
     
     system("cls");
     cout << "1 - Incluir elemento na lista" << endl;
     cout << "2 - Excluir elemento da lista" << endl;
     cout << "3 - Busca o elemento na lista" << endl;
     cout << "4 - Exibir a lista" << endl;
     cout << "0 - Sair" << endl;
     cout << "Opcao: ";
     cin >> op;
     return op;
}

int main (void)
{
    lista *l;
    string elemento;
    char op;
    
    l = NULL;
    
    op = menu();
    
    while (op != '0')
    {
          if (op == '1') {
             cout << "Novo elemento: ";
             cin >> elemento;
             l = inserir_em_ordem(l, elemento);
          }
          else if (op == '2') {
          	cout << "Elemento a ser excluido: ";
          	cin >> elemento;
          	l = excluir(l, elemento);
		  }
		  else if (op == '3') {
		  	cout << "Elemento a ser buscado: ";
		  	cin >> elemento;
		  	buscar(l, elemento);
		  }
          else if (op == '4')
			 exibir(l);
          
          op = menu();
    }
    
    return 0;
}
     


#include <iostream>

using namespace std;

void foo(int n){
	n = 20;
}

int main(int argc, char** argv)
{
	int var = 10;
	int *ponteiro;
	ponteiro = &var; //recebe o endereço da variavel var
	
	cout << *ponteiro << endl; // exibe o conteudo do endereço do ponteiro
	cout << var << endl;
	
	foo(var);
	cout << var << endl;
	return 0;
}
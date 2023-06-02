#include <iostream>
 
using namespace std;

int verificar_opc(int opc){
	
	if( 5 < opc > 0){
		cout << "Opção Invalida" << endl;
	}else
	
	return 0;
}

void lancar_notas(float alunos[20][5],int pos){
	
	cout << " Iforme a matricula do aluno (0000) : ";
	cin >> alunos[pos][0];
	cout << " Iforme a primeira nota (0.00): ";
	cin >> alunos[pos][1];
	cout << " Iforme a seginda nota (0.00) : ";
	cin >> alunos[pos][2];
	cout << " Iforme a terceira nota (0.00) : ";
	cin >> alunos[pos][3];
	
}

void exibir_notas(float alunos[20][5], int pos){
	cout << " Matricula   Nota 1   Nota 2   Nota 3   Media "<< endl;
	for(int i =0; i < pos; i++){
	cout << "     " << alunos[i][0] <<"       "<< alunos[i][1]<<"      "<< alunos[i][2]<<"      "<< alunos[i][3]<< endl;					
	}
}

void calcula_media(float alunos[20][5], int pos){
	   cout << " Matricula   Nota 1   Nota 2   Nota 3 "<< endl;
	for(int i =0; i < pos; i++){
		alunos[i][5] = (alunos[i][1]+alunos[i][2]+alunos[i][3])/3;
		
	cout << "     " << alunos[i][0] <<"       "<< alunos[i][1]<<"      "<< alunos[i][2]<<"      "<< alunos[i][3]<<"      "<< alunos[i][4]<< endl;					
	}	
	
	
}
int main(int argc, char** argv)
{
	int opc, pos = 0;
	float alunos[20][5];
		
	do {
		cout << " ---- Sistema de Calculo de Notas ---- "<< endl;
		cout << " 1 - Lancar nota do Aluno  "<< endl;
		cout << " 2 - Exibir notas dos Alunos "<< endl;
		cout << " 3 - Calcular Media dos Alunos "<< endl;
		cout << " 4 - Verificar se o aluno foi aprovado "<< endl;
		cout << " 0 - Sair "<< endl;		
		cout << " Escolha uma opcao do Menu para continuar: "<< endl;
		cin >> opc;
		verificar_opc(opc);
		
		switch(opc)
		{
			case 0:
				cout << " Saindo !!! "<< endl;
				break;		
			case 1:
				lancar_notas(alunos, pos);			
				pos++;
				break;
			case 2:
				exibir_notas(alunos, pos);
				break;
			case 3:
				calcula_media(alunos,pos);
				break;
			case 4:
				cout << " Escolheu a opção 4 "<< endl;
				break;
			default:
				cout << " Opcao invalida "<< endl;			
				break;
		}
		
		
	}while(opc != 0);
	{
		cout << " Obrigado por utilizar nosso programa "<< endl;		
	}	
	
	return 0;
}
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n1 = 20, n2 = 10;

	cout << "Soma:" << n1 <<" + "<< n2 << " = " << n1+n2 << endl;
	cout << "Subtra��o:" << n1 <<" - "<< n2 << " = " << n1-n2 << endl;
	cout << "Multiplica��o:" << n1 <<" * "<< n2 << " = " << n1*n2 << endl;
	cout << "Auto Incremento antecesdente: ++n1 -> " << ++n1 << " ++n2 ->" << ++n2 << endl;
	return 0;
}
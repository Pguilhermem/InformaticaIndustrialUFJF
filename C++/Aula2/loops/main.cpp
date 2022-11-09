#include <iostream>

using namespace std;

int main()
{
	//Loop For
	cout<<"Contagem com o loop for" << endl;
	for(int i = 0;i<10;i++)
	{
		cout<<i<<endl;
	}

	//Loop while
	int cont=0;
	cout<<"Contagem com while" << endl;
	while(cont>0&&cont<10)
	{
		++cont;
		cout<<cont<<endl;		
	}

	//Loop do..while
	cont = 0;
	cout<<"Contagem com do..while"<<endl;
	do
	{
		++cont;
		cout<<cont<<endl;
		
	} while(cont>0&&cont<10);

	//Palavra-chave continue
	cont=0;
	cout<<"Utilizacao da palavra chave continue para pular uma iteracao" << endl;
	while(cont>=0&&cont<10)
	{
		++cont;
		if(cont==5)
			continue;
		cout<<cont<<endl;		
	}

	//Palavra-chave break
	cont=0;
	cout<<"Utilizacao da palavra chave break para parar um loop" << endl;
	while(cont>=0&&cont<10)
	{
		++cont;
		if(cont==5)
			break;
		cout<<cont<<endl;		
	}

	system("pause");

	return 0;
}
#include <iostream>
using namespace std;
int main ()
{
	int n, s=0, x, max, min;
	double p;
	
	cout<<"Ingresa la cantidad de numeros que quieres comparar: \n";
	cin>>n;
	max=1;
	min=1;
	
	for (int i=1; i<=n; i++){
		cout<<"Numero: \n";
		cin>>x;
		s=s+x;
		
		if(x>max){
			max=x;
		}
		if(x<min){
			min=x;
		}
	}
	
	p=s/n;
	cout<<"El promedio es: \n"<<p<<"\n";
	cout<<"El numero mayor es: \n"<<max<<"\n"<<"Y el menor es: \n"<<min;
	return 0;

}

#include<bits/stdc++.h>
using namespace std;
int feynman(int n){
	int aux;
	if (n==1) return (1);
	aux = feynman (n-1);
	return (aux + n*n);
}
int main (){
	int n;
	scanf ("%d",&n);
	while (n!=0){
		printf ("%d\n",feynman(n));
		scanf ("%d",&n);
	}
	
	return (0);
}
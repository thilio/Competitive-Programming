#include<bits/stdc++.h>
using namespace std;
int main(){
	long long A[1000][1000],x,y,m,n,aux=1,soma1=0,soma2=0,i,j;
	scanf ("%lld",&n);
	scanf ("%lld",&m);
	while (m!=0 && n!=0){
		for (i=0;i<n;i++){
			for (j=0;j<m;j++){
				scanf ("%lld",&A[i][j]);
			}
		}
		scanf ("%lld",&x);
		scanf ("%lld",&y);
		soma1+=x;
		soma2+=y;
		while (x!=0||y!=0){
			scanf ("%lld",&x);
			soma1+=x;
			scanf ("%lld",&y);
			soma2+=y;
		}
		while (soma1<0)
			soma1+=m;
		while (soma2<0)
			soma2+=n;
		soma1=soma1%m;
		soma2=soma2%n;
		printf ("Teste %lld\n",aux);aux++;
		for (i=0;i<n;i++){
			for (j=0;j<m;j++){
				printf ("%lld ",A[(i+soma2)%n][(j-soma1 + m)%m]);
			}
			printf ("\n");
		}
		printf ("\n");
		soma1=0;soma2=0;
		scanf ("%lld",&n);
		scanf ("%lld",&m);
	}
	return (0);
}
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000

long long maxi(long long v[MAX],long long np){
	long long i,max=0;
	for (i=0;i<np;i++){
		if (v[i]>max)
			max=v[i];
	}
	return (max);
}
long long boo(long long v[MAX],double h,long long f,long long np){
	long long i,cont=0;
	for (i=0;i<np;i++){
		cont = cont + (long long)(pow(v[i],2)/h);
		if (cont>=f)
			return (0);
	}
	return (1);

}
double bb (long long v[MAX],long long f,long long np){
	double h,i,fi;
	long long c;
	i=0.0;
	fi= pow(maxi (v,np),2);
	for (c=0;c<100;c++){
		h=(i+fi)/2;
		if (boo(v,h,f,np)==1)
			fi=h;
		else
			i=h;
	}
	return (h);
}
int main(){
	long long np,nf,gl,i,j,v[MAX];
	double pi = acos(-1),aux;
	scanf ("%lld",&gl);
	for (i=0;i<gl;i++){
		scanf ("%lld",&np);
		scanf ("%lld",&nf);
		for (j=0;j<np;j++)
			scanf ("%lld",&v[j]);
		aux= bb (v,nf + 1,np);
		printf ("%.4f\n",aux*pi);
	}
	return (0);
}

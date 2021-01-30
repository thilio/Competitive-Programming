#include<bits/stdc++.h>
using namespace std;
int v[11234],aux[11234];
int main (){
	int au,i,j,k,n,t,q,u,a,b,c,d;
	scanf ("%d",&t);
	for (i=0;i<t;i++){
		scanf ("%d",&n);
		scanf ("%d",&u);
		for (k=0;k<n;k++){
			v[k]=0;
			aux[k]=0;
		}
		for (j=0;j<u;j++){
			scanf ("%d",&a);
			scanf ("%d",&b);
			scanf ("%d",&c);
			aux [a]+= c;
			if (b<(n-1))
				aux[b+1]-=c;
		}
		d=0;
		for (k=0;k<n;k++){
			d+=aux[k];
			v[k]=d;
		}
		scanf ("%d",&q);
		for (k=0;k<q;k++){
			scanf ("%d",&au);
			printf ("%d\n",v[au]);
		}
	}
	return (0);
}
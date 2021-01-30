#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long m,n,c[112345],t[112345],i,r=0,aux,j;
	scanf ("%I64d",&n);
	scanf ("%I64d",&m);
	scanf ("%I64d",&c[0]);
	for (i=1;i<n;i++){
		scanf ("%I64d",&aux);
		if (aux==c[i-1]){
			n--;
			i--;
		}
		else
			c[i]=aux;
	}
	scanf ("%I64d",&t[0]);
	for (i=1;i<m;i++){
		scanf ("%I64d",&aux);
		if (aux==t[i-1]){
			i--;
			m--;
		}
		else
			t[i]=aux;
	}
	j=0;
	for (i=0;i<n && j<m;i++){
		for (;j<(m-1) && (abs(t[j]-c[i])>abs(t[j+1]-c[i]));j++);
		if (r<abs(t[j]-c[i])){
			r=abs(t[j]-c[i]);
		}
	}
	printf ("%I64d\n",r);
	return (0);
}
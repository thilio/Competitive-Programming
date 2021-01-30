#include<bits/stdc++.h>
using namespace std;
int v[112345],va,V[112345];
void add (int i){
	if (v[i]==0)
		va--;
	v[i]++;
}
void rem (int i){
	if (v[i]==1)
		va++;
	v[i]--;
}
int main(){
	int i,m,n,q,a,b;
	scanf ("%d",&n);
	scanf ("%d",&m);
	scanf ("%d",&q);
	va=m;
	for (i=0;i<n;i++){
		scanf ("%d",&a);
		add (a);
		V[i+1]=a;

	}
	for (i=0;i<q;i++){
		scanf ("%d",&a);
		scanf ("%d",&b);
		rem (V[a]);
		add (b);
		V[a]=b;
		printf ("%d\n",va);
	}
	return (0);
}
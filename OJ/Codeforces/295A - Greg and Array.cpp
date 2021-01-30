#include<bits/stdc++.h>
using namespace std;
struct op{
	long long l,r,d;
};
long long v[112345],aux[112345],auxl[112345];
int main (){
	long long n,m,k,l,r,d,i,x,y,sa=0;
	op a[112345];
	scanf ("%I64d",&n);
	scanf ("%I64d",&m);
	scanf ("%I64d",&k);
	for (i=1;i<(n+1);i++){
		scanf ("%I64d",&v[i]);
	}
	for (i=1;i<(m+1);i++){
		scanf ("%I64d",&a[i].l);
		scanf ("%I64d",&a[i].r);
		scanf ("%I64d",&a[i].d);
	}
	for (i=0;i<k;i++){
		scanf ("%I64d",&x);
		scanf ("%I64d",&y);
		aux[x]+=1;
		aux[y+1]-=1;
	}
	for (i=1;i<(m+1);i++){
		sa+=aux[i];
		a[i].d*=sa;
	}
	for (i=1;i<(m+1);i++){
		auxl[a[i].l]+=a[i].d;
		auxl[a[i].r + 1]-=a[i].d;
	}
	sa=0;
	for (i=1;i<(n+1);i++){
		sa+=auxl[i];
		v[i]+=sa;
		printf ("%I64d ",v[i]);
	}
	printf ("\n");
	return (0);
}
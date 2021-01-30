#include<bits/stdc++.h>
using namespace std;
long long mini(long long v[],long long n){
	long long i,min=0;
	for (i=1;i<n;i++){
		if (v[i]<v[min])
			min=i;
	}
	return (min);
}
int boo (long long v[],long long n,long long m,long long w,long long h){
	long long l[112345],i,t=0,sa=0,a;
	for (i=0;i<n;i++){
		l[i]=0;
	}
	for (i=0;i<n;i++){
		sa=sa + l[i];
		if ((sa + v[i])<h){
			a=h-sa-v[i];
			sa+=a;
			t+=a;
			l[i]+=a;
			if ((i+w)<n)
				l[i+w]=-a;
		}
	}
	if (t<=m)
		return (1);
	return (0);


}
long long bb(long long v[],long long n,long long m,long long w){
	long long mid,best,il,fl,x;
	x=mini(v,n);
	il=v[x];fl=v[x]+m;
	while (fl>=il){
		mid=(il+fl)/2;
		if (boo(v,n,m,w,mid)==1){
			best=mid;
			il=mid+1;
		}
		else
			fl=mid-1;
	}
	return (best);
}
int main(){
	long long mx=0,mn,v[112345],m,w,n,i,aux;
	scanf ("%I64d",&n);
	scanf ("%I64d",&m);
	scanf ("%I64d",&w);
	for (i=0;i<n;i++){
		scanf ("%I64d",&v[i]);
	}
	aux=bb(v,n,m,w);
	printf ("%I64d\n",aux);
	return (0);
}
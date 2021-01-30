#include<bits/stdc++.h>
using namespace std;
long long p;
long long chk(long long v[],long long n,long long k,long long m){
	long long i,j,sa=0,kl=0;
	i=m-1;
	for (j=0;j<m;j++){
		sa=sa+(v[m-1]-v[j]);
	}

	while (i<n){
		if (sa<=k){
			p=v[i];
			return (1);
		}
		i++;
		sa=sa - (v[i-1]-v[i-m]);
		sa=sa + ((m-1)*(v[i]- v[i-1]));		
	}
	return(0);
}
long long bb(long long v[],long long n,long long k){
	long long i,f,m,best;
	i=1;f=n;
	while (f>=i){
		m=(i+f)/2;
		if (chk(v,n,k,m)==1){
			best=m;
			i=m+1;
		}
		else
			f=m-1;
	}
	return (best);
}
int main(){
	long long i,n,k,v[112345],aux;
	scanf ("%I64d",&n);
	scanf ("%I64d",&k);
	for (i=0;i<n;i++){
		scanf ("%I64d",&v[i]);
	}
	sort (v,v+n);
	aux=bb(v,n,k);
	printf ("%I64d %I64d\n",aux,p);
	return (0);
}
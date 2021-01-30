#include<bits/stdc++.h>
using namespace std;
long long i=0;
void gera (long long s[],long long v[],long long n){
	long long k,j;
	if (n==1){
		s[i]=v[0];
		i++;
	}
	else{
		gera (s,v,n-1);
		j=i;
		s[i]=v[n-1];
		i++;
		for (k=0;k<j;k++){
			s[i]=(v[n-1] + s[k]);
			i++;
		}
	}
}
int main(){
	long long i,n,*v,*m,k,min,sa=0,x;
	scanf ("%lld",&n);
	v=(long long*)malloc(n*sizeof(long long));
	m=(long long*)malloc(pow(2,n)*sizeof(long long));
	for(k=0;k<n;k++){
		scanf ("%lld",&v[k]);
		sa+=v[k];
	}
	gera (m,v,n);
	min=abs(sa-2*m[0]);
	for (k=0;k<(pow(2,n)-1);k++){
		x=abs(sa-2*m[k]);
		if (x<min)
			min=x;
	}
	printf ("%lld\n",min);
	return (0);
}
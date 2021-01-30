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
	long long k,n,*v,*s,l,r,x,ctg=0,mn,mx,j,z;
	scanf ("%I64d",&n);
	v=(long long*)malloc(n*sizeof(long long));
	s=(long long*)malloc(pow(2,n)*sizeof(long long));
	scanf ("%I64d",&l);
	scanf ("%I64d",&r);
	scanf ("%I64d",&x);
	for(k=0;k<n;k++){
		scanf ("%I64d",&v[k]);
	}
	gera (s,v,n);
	for (k=1;k<(pow(2,n));k++){
		z=k;
		if (s[k-1]>=l && s[k-1]<=r){
			mx=0;mn=s[k-1];
			for (j=0;j<n;j++){
				if (z%2==1){
					if (v[j]>mx)
						mx=v[j];
					if (v[j]<mn)
						mn=v[j];
				}
				z=z/2;
			}
			if ((mx-mn)>=x)
				ctg++;
		}
	}
	printf ("%I64d\n",ctg);
	return (0);
}
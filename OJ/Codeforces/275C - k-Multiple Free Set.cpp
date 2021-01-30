#include<bits/stdc++.h>
using namespace std;
long long bb (long long v[],long long x,long long n){
	long long i,f,m;
	i=0;f=n-1;
	while (f>=i){
		m=(i+f)/2;
		if (v[m]==x){
			return (m);
		}
		if (v[m]>x)
			f=m-1;
		if (v[m]<x)
			i=m+1;
	}
	return (-1);
}
long long maxxi(long long a,long long b){
	if (a>b)
		return (a);
	return (b);
}
int main(){
	long long i,n,k,v[112345],l[112345],ct=0,x,par,impar,aux,ctg=0;
	scanf ("%I64d",&n);
	scanf ("%I64d",&k);
	for (i=0;i<n;i++){
			scanf ("%I64d",&v[i]);
			l[i]=0;
	}
	if (k==1)printf ("%I64d\n",n);
	else{
		sort (v,v+n);
		for (i=0;i<n;i++){
			if (l[i]==0){
				l[i]=1;
				x=v[i];
				par=0;
				impar=0;
				ct=0;
				aux=0;
				while (x<=v[n-1]&& aux != -1){
					aux = bb (v,x,n);
					if (aux!=-1){
						l[aux]=1;
						if (ct%2==0)
							par++;
						else
							impar++;
					}
					ct++;
					x=x*k;
				}
				ctg = ctg + maxxi(par,impar) ;
			}
		}
		printf ("%I64d\n",ctg);
	}
	return (0);
}
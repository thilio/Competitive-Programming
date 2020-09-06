#include<bits/stdc++.h>
using namespace std;

long long da (long long k,long long* v,long long w,long long n){
	int i;
	if (k>w)
		return (-1);
	if (k<0)
		return (0);
	for(i=0;i<n;i++){
		k=k+v[i];
		if (k>w)
			return (-1);
		if (k<0)
			return (0);
	}
	return (1);

}

int main (){
	long long i,n,w,at,max=0,min,v[1123],ini,fim,b=-1,c=-1,x,meio;
	cin >> n;
	cin >> w;
	for (i=0;i<n;i++){
		cin >> v[i];
	}
	ini=0;
	fim = pow(10,9);
	while (fim >= ini){
			meio = (fim + ini + 1)/2;
			x=da(meio,v,w,n);
			if (x==1){
				ini = meio+1;
				b = meio;
			}
			else if (x==0){
				ini = meio + 1;
			}
			else
				fim = meio -1;

	}
	ini=0;
	fim = pow(10,9);
	while (fim >= ini){
			meio = (fim + ini + 1)/2;
			x=da(meio,v,w,n);
			if (x==1){
				fim = meio-1;
				c = meio;
			}
			else if (x==0){
				ini = meio + 1;
			}
			else
				fim = meio -1;

	}
	//cout << b << c <<endl;


	if (b-c >= 0 && c!= -1)
		cout << b-c + 1;
	else
		cout << '0';
	cout << endl;

	return (0);

}
#include<bits/stdc++.h>
using namespace std;

int main (){
	long long m,n,i,v[222345],at,ini,fim,meio,b;
	cin >> n;
	cin >> m;
	cin >> v[0];
	for (i=1;i<n;i++){
		cin >> at;
		v[i]=v[i-1] + at;

	}
	for (i=0;i<m;i++){
		cin >> at;
		ini=0;
		fim=n-1;
		if (at <= v[0])
			cout << '1' << ' ' << at << endl;
		else{
			while (fim >= ini){
				meio = (fim + ini + 1)/2;
				if (at - v[meio] > 0){
					ini = meio+1;
					b = meio;
				}
				else
					fim = meio -1;

			}
			b++;
			cout << b+1 <<' '<< at - v[b-1]  << endl;

		}
		


	}
	return (0);
}
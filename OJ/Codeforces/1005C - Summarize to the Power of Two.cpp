#include <bits/stdc++.h>
using namespace std;

int n,v[120030],maxi,pot[31],fr[120030];

int bbmin(int ini,int fim,int val){
	if (ini>fim) return (pow(10,9));
	int best,meio = (ini+fim)/2;
	//cout << meio <<endl;
	if (v[meio]==val){
		best = meio;
		return (min(meio,bbmin(ini,meio-1,val)));
	}
	if(v[meio] > val){
		return (bbmin(ini,meio-1,val));
	}
	if (v[meio] < val){
		return (bbmin(meio+1,fim,val));
	}
}

int bbmax(int ini,int fim,int val){
	if (ini>fim) return (-1);
	int best,meio = (ini+fim)/2;
	//cout <<meio<<endl;
	if (v[meio]==val){
		best = meio;
		return (max(meio,bbmax(meio+1,fim,val)));
	}
	if(v[meio] > val){
		return (bbmax(ini,meio-1,val));
	}
	if (v[meio] < val){
		return (bbmax(meio+1,fim,val));
	}
}

int main(){

	cin >> n;
	int i,j,k;
	
	
	for (i=0;i<n;i++){
		cin >> v[i];
	}

	sort (v,v+n);
	maxi=v[n-1];
	pot[0] = 1;

	for (i=1;i<31;i++){
		pot[i] = 2*pot[i-1];
	}

	for (i=0;i<n;i++){
		if (i>0 && v[i] == v[i-1]){
			fr[i] = fr[i-1];
			continue;
		}
		for (j=0;j<31;j++){
			int r,l;
			//cout << i <<j<<endl;
			if (pot[j]-v[i] <1) continue;
			r = bbmin (i+1,n-1,pot[j]-v[i]);
			l = bbmax(i+1,n-1,pot[j]-v[i]);
			if (l==-1) continue;
			for (k=r;k<=l;k++){
				//cout << 'a' <<k <<endl;
				fr[k]=1;
			}
			fr[i] = 1;
		}
	}
	int tot = 0;
	for (i=0;i<n;i++){
		if (fr[i] == 0)
			tot ++;
	}

	cout << tot<< endl;

	return (0);
}
#include <bits/stdc++.h>
using namespace std;


int main (){

	int n;
	cin >> n;
	int tot=0,at,ant;
	vector <int> V;
	cin >> ant;
	at = -1;
	for (int i=1;i<n;i++){
		cin >> at;
		if (at == 1){
			V.push_back(ant);
			tot++;
		}
		if (i==n-1){
			V.push_back(at);
			tot++;
		}
		ant=at;

	}

	if (at == -1){
		cout << '1' << endl << "1" << endl;
	}
	else{
		cout << tot << endl;
		for(int i=0;i<V.size();i++){
			cout << V[i] << ' ';
		}
		cout << endl;
	}

	return (0);
}

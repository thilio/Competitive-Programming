#include<bits/stdc++.h>
using namespace std;
long long s=0;
void intercala(int v[],int ini,int fim,int meio){
	int i,j;
	vector<int> t;
	i=ini;j=meio;
	while (t.size()<(fim-ini+1)){
		if (i==meio)
			while (j<=fim){
				t.push_back(v[j]);
				j++;
			}
		else if (j>fim)
			while (i<meio){
				t.push_back(v[i]);
				i++;
			}
		else if (v[i]>v[j]){
			t.push_back(v[j]);
			j++;
			s+= meio - i;

		}
		else{
			t.push_back(v[i]);
			i++;
			; 
		}
	}
	for (i=0;i<t.size();i++){
		v[ini+i]=t[i];
	}
}
void merge (int v[],int ini, int fim){
	if (fim<=ini) return;
	merge (v,ini,(ini + fim)/2);
	merge (v,((ini+fim)/2)+1,fim);
	intercala (v,ini,fim,((ini+fim)/2)+1);
}
int main(){
	int n,i,v[1123456],t;
	t=1;
	while (t>0){
		s=0;
		scanf ("%d",&n);
			for(i=0;i<n;i++){
			v[i]=0;
			scanf ("%d",&v[i]);
		}
		merge(v,0,n-1);
		printf ("%lld\n",s);
		t--;
	}
	
	return (0);

}
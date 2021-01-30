#include<bits/stdc++.h>
using namespace std;
struct hora{
	int in,fi;
};
bool com (hora a, hora b){
	return(a.fi<b.fi);
}

int main (){
	int n,j,i,t,T,fim;
	hora v[112345];
	scanf ("%d",&T);
	for (i=0;i<T;i++){
		t=1;
		scanf ("%d",&n);
		for(j=0;j<n;j++){
			scanf ("%d",&v[j].in);
			scanf ("%d",&v[j].fi);
		}
		sort (v,v+n,com);
		fim=v[0].fi;
		for (j=1;j<n;j++){
			if (v[j].in >= fim){
				t++;
				fim=v[j].fi;
			}
		}
		printf ("%d\n",t);
	}
	return (0);
}
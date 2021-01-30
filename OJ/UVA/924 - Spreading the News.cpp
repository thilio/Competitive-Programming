#include<bits/stdc++.h>
using namespace std;
vector<int> V[3000];
int f[3000];
void BFS (int a){
	queue<int> fila;
	int i,j,ct=0,boo=0;
	fila.push(a);
	while (!fila.empty()){
		i=fila.front();
		fila.pop();
		if (f[i]==-1) f[i]=ct;
		boo=0;
		for (j=0;j<V[i].size();j++){
			if (f[V[i][j]]==-1){
				f[V[i][j]]=f[i] + 1;
				fila.push(V[i][j]);
				boo=1;
			}
		}
		ct+=boo;
	}
}
void Zeraf(){
	int i;
	for (i=0;i<3000;i++){
		f[i]=-1;
	}
}
int transforma(int n,int* p1,int* p2){
	int i,z[3000],max=0,maxi=0;
	for (i=0;i<3000;i++){
		z[i]=0;
	}
	for (i=0;i<n;i++){
		z[f[i]]++;
	}
	for (i=0;i<n;i++){
		if (z[i]>max){
			maxi=i;
			max = z[i];
		}
	}
	if(maxi==0) maxi++;
	*p1=max;
	*p2=maxi;
}
int main(){
	int i,n,E,t,e,j,a,thi,at,x,p1,p2;
	scanf("%d",&E);
	for (i=0;i<E;i++){
		scanf("%d",&e);
		for (j=0;j<e;j++){
			scanf ("%d",&a);
			V[i].push_back(a);
		}
	}
	scanf ("%d",&t);
	for(i=0;i<t;i++){
		Zeraf();
		scanf("%d",&at);
		if (V[at].empty()) printf("0\n");
		else{
			BFS (at);
			x=transforma(E,&p1,&p2);
			printf ("%d %d\n",p1,p2);
		}
	}
	return (0);

}
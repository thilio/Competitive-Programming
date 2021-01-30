#include<bits/stdc++.h>
using namespace std;
int M[50][50],p=1,n,m,v[400];
char C[50][50],land;
void DFS(int i,int j){
	M[j][i]=p;
	v[p]++;
	if (C[j][(i+1)%n]==land && M[j][(i+1)%n]==0){
		DFS ((i+1)%n,j);
		
	}
	if (C[j][(i-1+n)%n]==land && M[j][(i-1+n)%n]==0){
		DFS ((i-1+n)%n,j);
		
	}
	if (j<(m-1)){
		if (C[j+1][i]==land && M[j+1][i]==0){
			DFS (i,j+1);
			
		}
	}
	if (j>0){
		if (C[j-1][i]==land && M[j-1][i]==0){
			DFS (i,j-1);
		}
	}
}
int main (){
	int i,j,x,y,max=0;
	char a;
	while(cin>>m){
		cin>>n;
		for(i=0;i<400;i++){
			v[i]=0;
		}
		for(j=0;j<50;j++){
			for(i=0;i<50;i++){
				M[j][i]=0;
			}
		}
		max=0;
		p=1;
		for (j=0;j<m;j++){
			for (i=0;i<n;i++){
				cin>>a;
				if (a>='!' && a<='~')
					C[j][i]=a;
				else
					i--;
			}
		}
		cin>>x;
		cin>>y;
		land=C[x][y];
		for (j=0;j<m;j++){
			for (i=0;i<n;i++){
				if (C[j][i]==land && M[j][i]==0){
					DFS (i,j);
					p++;
				}
			}
		}
		v[M[x][y]]=-1;
		for (i=1;i<p;i++){
			if (v[i]>max)
				max=v[i];
		}
		cout<<max<<"\n";
	}
	return (0);
}
#include<bits/stdc++.h>
using namespace std;
int m[200][200],v[200],freq[200];
void DFS(int i){
	if (freq[i]==0){
		freq[i]=1;
		while (m[i][v[i]]!=0){
			DFS(m[i][v[i]]);
			v[i]++;
		}
	}
}
int main (){
	int i,e,l,a,b,pk=1,gl=1,j;
	scanf ("%d",&e);
	scanf ("%d",&l);
	while (e!=0 && l!=0){
		for (i=0;i<200;i++){
			v[i]=1;
			freq[i]=0;
			for (j=0;j<200;j++){
				m[i][j]=0;
			}

		}
		for (i=0;i<l;i++){
			scanf ("%d",&a);
			scanf ("%d",&b);
			m[a][v[a]]=b;
			v[a]++;
			m[b][v[b]]=a;
			v[b]++;	
		}
		for (i=0;i<200;i++){
			v[i]=1;
		}
		DFS (1);
		for (i=1;i<(e+1);i++){
			pk=pk*freq[i];
		}
		//for (i=1;i<(e+1);i++){
		//	for (j=1;j<(e+1);j++){
		//		printf ("%d ",m[i][j]);
		//	}
		//	printf ("\n");
		//}
		printf ("Teste %d\n",gl);gl++;
		if (pk==1)
			printf ("normal\n");
		else
			printf ("falha\n");
		printf ("\n");
		pk=1;
		scanf ("%d",&e);
		scanf ("%d",&l);
	}
	return (0);
}
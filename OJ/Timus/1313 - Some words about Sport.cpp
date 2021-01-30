#include<bits/stdc++.h>
using namespace std;
int A[500][500],n;
void pri (int i,int j){
	while (i>=0){
		printf ("%d ",A[i][j]);
		i--;
		j++;
	}
}
void pro(int i,int j){
	while (j<=(n-1)){
		printf ("%d ",A[i][j]);
		i--;
		j++;
	}
}
int main(){
	int i,j;
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf ("%d",&A[i][j]);
		}
	}
	for (i=0;i<n;i++){
		pri(i,0);
	}
	for (j=1;j<n;j++){
		pro(n-1,j);
	}
	return (0);
}

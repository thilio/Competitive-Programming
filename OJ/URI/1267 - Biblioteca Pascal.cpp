#include<bits/stdc++.h>
using namespace std;
int A[1000][1000];
int main (){
	int m,n,i,j,val=0,ct=0;
	scanf ("%d",&m);
	scanf ("%d",&n);
	while (m!=0 && n!=0){
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			scanf ("%d",&A[i][j]);
		}
	}
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (A[j][i]==1)
				ct++;
		}
		if (ct==n)
			val=1;
		ct=0;
	}
	if (val==1){
		printf ("yes\n");
	}
	else
		printf ("no\n");
	val=0;ct=0;
	scanf ("%d",&m);
	scanf ("%d",&n);
	}
	return (0);
}
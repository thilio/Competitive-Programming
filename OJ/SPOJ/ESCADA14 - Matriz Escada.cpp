#include<bits/stdc++.h>
using namespace std;
int A[500][500];
int posi (int i,int m){
	int k;
	for (k=0;k<m;k++){
		if (A[i][k]!=0)
			return (k);
	}
	return (m);
}
int main(){
	int m,n,i,j,val=1;
	scanf ("%d %d",&n,&m);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			scanf ("%d",&A[i][j]);
		}
	}
	for (i=0;i<n-1 && val==1;i++){
		if (posi(i,m)==m){
			for (j=i;j<n;j++){
				if (posi(j,m)!=m)
					val=0;
			}
		}
		else{
			if (posi(i+1,m)<=posi(i,m))
				val=0;
		}

	}
	if (val==0)
		printf ("N\n");
	else
		printf("S\n");
	return (0);

}
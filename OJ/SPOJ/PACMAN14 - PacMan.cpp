#include<bits/stdc++.h>
using namespace std;
char A[500][500];
int main(){
	int n,i,j,ct=0,max=0;
	char aux;
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			scanf ("%c",&aux);
			if (aux=='o'||aux=='.'||aux=='A')
				A[i][j]=aux;
			else
				j--;
		}
	}
	for (i=0;i<n;){
		for (j=0;j<n;j++){
			if (A[i][j]=='o')
				ct++;
			if (A[i][j]=='A'){
				if (ct>max)
					max=ct;
				ct=0;
			}
		}
		i++;
		if (i<n){
			for (j=n-1;j>=0;j--){
				if (A[i][j]=='o')
					ct++;
				if (A[i][j]=='A'){
					if (ct>max)
						max=ct;
					ct=0;
				}
			}
		}
		i++;
	}
	if (ct>max)
		max=ct;
	printf ("%d\n",max);
	return (0);

}
#include<bits/stdc++.h>
using namespace std;
int valor[5],tenho[5],atual[5];
int cambio (int val,int pg,int min){
	int troco,k,div;
	troco=pg-val;
	for (k=min-1;k>-1;k--){
		div  = troco/valor[k];
		//printf ("%d\n",div);
		if (div > tenho [k]){
			troco = troco - tenho[k]*valor[k];
			tenho[k]=0;
		}
		else{
			troco = troco - div*valor[k];
			tenho[k]-=div;
		}
	}
	//printf ("%d\n",troco);
	if (troco==0)
		return (1);
	return (0);

}
int main(){
	int n,i,pg=0,val,min,pk=1,at,j;
	valor[0]=1;valor[1]=5;valor[2]=10;valor[3]=20;valor[4]=50;
	scanf ("%d",&n);
	for (i=0;i<n && pk==1;i++){
		pg=0;
		scanf ("%d",&val);
		min=6;
		for (j=0;j<5;j++){
			scanf ("%d",&at);
			if (at!=0 && min==6)
				min=j;
			pg+=at*valor[j];
			tenho[j]+=at;
		}
		pk = cambio (val,pg,min);

	}
	if (pk==1)
		printf ("yes\n");
	else
		printf ("no\n");
	return (0);
}
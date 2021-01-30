#include<bits/stdc++.h>
using namespace std;
int f[112345];
struct vaca{
	int leite,tmp;
};
bool comp (vaca a,vaca b){
	return (a.leite > b.leite);
}
int main(){
	int n,i,t=1,to=0,j;
	vaca v[112345];
	scanf ("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&v[i].leite);
		scanf("%d",&v[i].tmp);
	}
	sort (v,v+n,comp);
	for (i=0;i<n;i++){
		for (j=v[i].tmp;j>0;j--){
			if (f[j]==0){
				f[j]=1;
				to+=v[i].leite;
				break;
			}
		}
	}
	printf ("%d\n",to);
	return (0);
}
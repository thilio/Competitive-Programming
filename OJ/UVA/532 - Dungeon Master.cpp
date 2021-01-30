#include<bits/stdc++.h>
using namespace std;
int pk,aux[30][30][30];
char m[30][30][30];
typedef struct {
	int x;
	int y;
	int z;
} pos;
int BFS (int l,int r,int c,pos sai){
	queue <pos> f;
	int i,j,k;
	pos atual;
	aux[sai.x][sai.y][sai.z]=0;
	f.push(sai);
	while (!f.empty()){
		atual=f.front();
		f.pop();
		//printf ("%d %d %d %c\n",atual.x,atual.y,atual.z,m[atual.x][atual.y][atual.z]);
		if (m[atual.x][atual.y][atual.z]=='E')
			return (aux[atual.x][atual.y][atual.z]);
		if (atual.x > 0 && aux[atual.x - 1][atual.y][atual.z]==-1 && m[atual.x - 1][atual.y][atual.z]!='#'){
			atual.x--;
			aux[atual.x][atual.y][atual.z]=aux[atual.x + 1][atual.y][atual.z] + 1;
			f.push(atual);
			atual.x++;
		}
		if (atual.x < (r-1) && aux[atual.x + 1][atual.y][atual.z]==-1 && m[atual.x + 1][atual.y][atual.z]!='#'){
			atual.x++;
			aux[atual.x][atual.y][atual.z]=aux[atual.x - 1][atual.y][atual.z] + 1;
			f.push(atual);
			atual.x--;
		}
		if (atual.y >0 && aux[atual.x][atual.y - 1][atual.z]==-1 && m[atual.x][atual.y - 1][atual.z]!='#'){
			atual.y--;
			aux[atual.x][atual.y][atual.z]=aux[atual.x][atual.y+1][atual.z] + 1;
			f.push(atual);
			atual.y++;
		}
		if (atual.y < (c-1) && aux[atual.x][atual.y + 1][atual.z]==-1 && m[atual.x][atual.y + 1][atual.z]!='#'){
			//printf("A\n");
			atual.y++;
			aux[atual.x][atual.y][atual.z]=aux[atual.x][atual.y-1][atual.z] + 1;
			f.push(atual);
			atual.y--;
		}
		if (atual.z >0 && aux[atual.x][atual.y][atual.z - 1]==-1 && m[atual.x][atual.y][atual.z - 1]!='#'){
			atual.z--;
			aux[atual.x][atual.y][atual.z]=aux[atual.x][atual.y][atual.z+1] + 1;
			f.push(atual);
			atual.z++;
		}
		if (atual.z < (l-1) && aux[atual.x][atual.y][atual.z + 1]==-1 && m[atual.x][atual.y][atual.z+1]!='#'){
			atual.z++;
			aux[atual.x][atual.y][atual.z]=aux[atual.x][atual.y][atual.z-1] + 1;
			f.push(atual);
			atual.z--;
		}
	}
	return (-1);

	
}
int main(){
	int l,r,c,i,j,k;
	char cha;
	pos atual;
	scanf ("%d %d %d",&l,&r,&c);
	while (l + r + c != 0){
		pk=0;
		for (i=0;i<30;i++){
			for (j=0;j<30;j++){
				for (k=0;k<30;k++){
					m[i][j][k]='.';
					aux[i][j][k]=-1;
				}		
			}
		}
		for (i=0;i<l;i++){
			for (j=0;j<r;j++){
				for (k=0;k<c;k++){
					scanf ("%c",&cha);
					while (cha!= '.' && cha!= 'S' && cha!= 'E' && cha!= '#')
						scanf ("%c",&cha);
					m[j][k][i]=cha;
					if (cha=='S'){
						atual.x=j;
						atual.y=k;
						atual.z=i;
					}
				}	
			}
		}
		pk=BFS(l,r,c,atual);
		/*for (i=0;i<l;i++){
			for (j=0;j<r;j++){
				for (k=0;k<c;k++){
					printf("%d ",aux[j][k][i]);
				}		
				printf("\n");
			}
			printf("\n");
		}*/
		if (pk>0)
			printf ("Escaped in %d minute(s).\n",pk);
		else
			printf("Trapped!\n");	
		scanf ("%d %d %d",&l,&r,&c);
	}
	return (0);
}


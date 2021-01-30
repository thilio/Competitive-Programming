#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int x;
	int y;
	int ni;
}pos;

char C[1000][1000];
int r,c,t,movx[4]={0,1,0,-1},movy[4]={1,0,-1,0},aux[1000][1000],auxf[1000][1000];
queue <pos> fi,f;

int isvalid (int x,int y){
	if (y<0 || y >= c)
		return (0);
	if (x<0 || x >= r)
		return (0);
	return (1);
}

int BFS (char a,int t){
	int i,j;
	pos at;

	if (a=='F'){
		if (fi.empty())
			return(-1);
		at = fi.front();
		while (!fi.empty()){
			at=fi.front();
			if (at.ni > t)
				break;
			fi.pop();
			for (i=0;i<4;i++){
				if (isvalid(at.x + movx[i],at.y + movy[i])){
					if (C[at.x + movx[i]][at.y + movy[i]]!='#' && auxf[at.x + movx[i]][at.y + movy[i]] != 1){
						C[at.x + movx[i]][at.y + movy[i]] = 'F';
						at.x += movx[i];
						at.y += movy[i];
						at.ni++;
						auxf[at.x][at.y] = 1;
						fi.push(at);
						at.x -= movx[i];
						at.y -= movy[i];
						at.ni--;

					}

				}
			}
		}
	}
	if (a=='J'){
		at = f.front();
		while (!f.empty()){
			at=f.front();
			
			//printf("%d%d%d\n",at.x,at.y,at.ni);
			if (at.ni > t)
				break;
			f.pop();
			if (C[at.x][at.y]!='J')
				continue;
			if (at.x == 0 || at.x == r-1 || at.y == 0 || at.y == c-1)
				return ((at.ni)+1);
			for (i=0;i<4;i++){
				if (isvalid(at.x + movx[i],at.y + movy[i])){
					if (C[at.x + movx[i]][at.y + movy[i]]=='.' && aux[at.x + movx[i]][at.y + movy[i]] != 1){
						C[at.x + movx[i]][at.y + movy[i]] = 'J';
						at.x += movx[i];
						at.y += movy[i];
						at.ni++;
						aux[at.x][at.y] = 1;
						f.push(at);
						at.x -= movx[i];
						at.y -= movy[i];
						at.ni--;

					}

				}
			}
		}
	}

	/*printf("\n%c\n",a);

	printf ("\n");
	for (i=0;i<r;i++){
		for (j=0;j<c;j++){
			printf("%c ",C[i][j]);
		}
		printf ("\n");
	}
	printf ("\n");*/
	

	return (-1);


}

int sol (){
	int i,j,t = 0,x;
	while (!f.empty()){
		x=BFS('J',t);
		if (x!=-1)
			return (x);
		x = BFS ('F',t);
		t++;
	}

	return (-1);
}

int main(){
	int num,te,i,j;
	pos at,atl;
	char a;

	scanf("%d",&t);
	for (te=0;te<t;te++){
		//printf ("%d\n",te);
		for(i=0;i<1000;i++){
			for(j=0;j<1000;j++){
				C[i][j]='.';
				aux[i][j]=0;
				auxf[i][j]=0;
			}
		}
		while (fi.size()>0){
			fi.pop();
		}
		while (f.size()>0)
			f.pop();
		scanf("%d",&r);
		scanf("%d",&c);
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%c",&a);
				while (a!='.' && a!='#' && a != 'J' && a != 'F')
					scanf("%c",&a);
				C[i][j]=a;
				if (a=='J'){
					at.y = j;
					at.x = i;
					at.ni = 0;
					f.push(at);

				}
				if (a=='F'){
					atl.y=j;
					atl.x=i;
					atl.ni = 0;
					fi.push(atl);
				}

			}
		}
		if (at.x == 0 || at.x == r-1 || at.y == 0 || at.y == c-1)
			num = 1;
		else{
			num = sol ();
		}
		if (num == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",num);

	}
	return (0);

}
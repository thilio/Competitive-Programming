#include<bits/stdc++.h>
using namespace std;
int movx[6]={-1,-1,0,1,1,0},movy[6] = {0,1,1,0,-1,-1},r,c,A[100][100],freq[100][100];
char C[100][100];

typedef struct{
	int x;
	int y;
}pos;

queue<pos> f;

int isvalid (int x,int y){
	if (x>=0 && x<r && y>=0 && y<c)
		return(1);
	return (0);
}


void BFS (pos at){
	queue <pos> q;
	pos p;
	int i,hor,ant;

	A[at.x][at.y]=1;
	q.push (at);
	while (!q.empty()){

		p=q.front();
		q.pop();
		//hor=0;ant=0;
		for (i=0;i<6;i++){
			if (isvalid(p.x + movx[i],p.y + movy[i])){
				p.x+=movx[i];p.y+=movy[i];

				/*if (C[p.x][p.y] != '.' && A[p.x][p.y]==1)
					hor = 1;
				if (C[p.x][p.y] != '.' && A[p.x][p.y]==-1)
					ant = 1;
				if (C[p.x][p.y] != '.' && A[p.x][p.y]==2){
					hor=ant=1;
				}*/
				//cout << "b" << p.x <<' '<<p.y<<endl;
				//cout << "c" << C[p.x][p.y] <<' '<<A[p.x][p.y]<<endl;
				if (C[p.x][p.y] == '*' && A[p.x][p.y] == 0){
					A[p.x][p.y] = (-1)*A[p.x - movx[i]][p.y-movy[i]];
					q.push(p);
				}
				p.x-=movx[i];p.y-=movy[i];
			}
			
		}
		/*if (hor && ant)
			A[p.x][p.y] = 2;*/

	}
	
}

void marca (){
	int i,j,k;
	for (i=0;i<r;i++){
		for (j=0;j<c;j++){
			for (k=0;k<6;k++){
				if (isvalid (i + movx[k],j + movy[k])){
					if (A[i][j]*A[i + movx[k]][j + movy[k]]!=0 && A[i][j]*A[i + movx[k]][j + movy[k]]!=-1){
						A[i][j]=2;
						A[i + movx[k]][j + movy[k]]=2;
					}
				}
			}
		}
	}

}

void pin (pos at){
	queue <pos> q;
	pos p;
	int i;

	p=at;
	q.push(p);
	freq[at.x][at.y] = 1;
	while (!q.empty()){
		p = q.front();
		q.pop();
		for (i=0;i<6;i++){
			if (isvalid(p.x + movx[i],p.y + movy[i]) && freq[p.x + movx[i]][p.y + movy[i]]==0 && C[p.x + movx[i]][p.y + movy[i]]!='.'){
				p.x+=movx[i];p.y+=movy[i];
				freq[p.x][p.y] = 1;
				A[p.x][p.y]=2;
				q.push (p);
				p.x-=movx[i];p.y-=movy[i];
			}

		}
	}

} 

void atu (){
	int i,j;
	pos at;
	queue <pos> q;
	for (i=0;i<r;i++){
		for(j=0;j<c;j++){
			if (A[i][j]==2){
				at.x=i;
				at.y=j;
				pin (at);
			}
		}
	}

}

int main (){
	int i,j;
	char a;
	pos at;
	vector <pos> V;

	cin >> r;
	cin >> c;

	while (r!=0 || c!=0){
		V.clear();
		for(i=0;i<100;i++){
			for(j=0;j<100;j++){
				A[i][j] = 0;
				C[i][j] = '.';
				freq[i][j]=0;
			}
		}
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				scanf("%c",&a);
				while (a!='.' && a!='I' && a != '*')
					scanf("%c",&a);
				
				C[i][j]=a;
				if (a=='I'){
					at.x = i;			
					at.y = j;
					V.push_back(at);
				}
			}
		}


		for (i=0;i<V.size();i++){
			BFS(V[i]);
		}


		//BFS(at);
		marca();
		atu ();

		cout << endl;
		for (i=0;i<r;i++){
			for(j=0;j<c;j++){
				//cout << A[i][j] << ' ';
				if (C[i][j] == '.')
					cout<< '.';
				else if (C[i][j] != '.' && A[i][j] == 1)
					cout << '(';
				else if (C[i][j] != '.' && A[i][j] == -1)
					cout << ')';
				else if(C[i][j] != '.' && A[i][j] == 2)
					cout <<'B';
				else
					cout << 'F';
			}
			cout << endl;
		}

		cin >> r;
		cin >> c;


	}

	return (0);

	
}
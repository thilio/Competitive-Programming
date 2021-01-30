#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define pq priority_queue
#define grtp greater< pair<int,int> >

#define gnl cout << endl
#define olar cout << "olar" << endl

typedef pair<int,int> pii;
typedef vector<int,int> vi;
typedef vector< pair<int,int> > vii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;

char table[210][210];
int dist[210][210];

int dx[3]={0,0,1};
int dy[3]={-1,1,0};

int n,m;

bool compatible(int i, int j){
	if(i>=0 && i<n && j>=0 && j<m-1 && table[i][j]=='S' && table[i][j+1]!='S')	return true;
	return false;
}

bool ngbr(int x, int y){
	if(x>=0 && x<n && y>=0 && y<m && table[x][y]=='S')	return true;
	return false;
}

int bfs(int col){

	queue<pii> fila;
	ms(dist,-1);
	dist[0][col]=0;
	
	fila.push(mp(0,col));
	
	while(!fila.empty()){
		pii v = fila.front();
		fila.pop();
		if(v.fst==n-1)	return dist[v.fst][v.snd];

		fr(i,3){
			int lin = v.fst+dx[i];
			int row = v.snd+dy[i];
			
			if( ngbr(lin,row) && dist[lin][row]==-1 ){
				dist[lin][row]=1+dist[v.fst][v.snd];
				fila.push(mp(lin,row));
			}

		}
	}

}

void run(int n, int m){
	
	fr(i,n){
		fr(j,m){
			cin >> table[i][j];
		}
		getchar();
	}

	fr(i,n){
		fr(j,m){
			if(compatible(i,j)){
				table[i][j+1]='S';
				break;
			}
		}
	}


	int x0 = 0;
	fr(i,m){
		if(table[0][i]=='S'){
			x0=i;
			break;
		}
	}

	int ans=bfs(x0);
	if(x0+1<m && table[0][x0+1]=='S')	ans=min(ans,bfs(x0+1));
	cout << ans+1 << endl;

}

int main(){

	n=m=-1;
	while(n!=0){
		cin >> n >> m;
		if(n==0)	break;
		run(n,m);
	}


}
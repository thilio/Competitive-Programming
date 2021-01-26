#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int m[11][11];

pii memo[101][11][11][3][225];
int f[101][11][11][3];
int n;
int dx[8] = {2,2,-2,-2,1,-1,1,-1};
int dy[8] = {1,-1,1,-1,2,2,-2,-2};
int ddx[4] = {1,1,-1,-1};
int ddy[4] = {1,-1,1,-1};

bool is(int x,int y){
	if(x>0 && x<= n && y>0 && y <=n) return true;
	return false;

}

pii pd(int num,int x,int y,int p,int t){

	if(t > 220) return(mp(INF,INF));
	if(num > n*n) return (mp(0,0));

	pii &pdm = memo[num][x][y][p][t];
	if(pdm!=mp(-1,-1)) return (pdm);

	pdm = {INF,INF};

	if(p == 0){
		frr(i,n){
			if(m[i][y] == num){
				pii a = pd(num + 1,i,y,0,t+1);
				pdm = a;
				pdm.fst ++;
				return (pdm);
			}
		}

		frr(i,n){
			if(m[x][i] == num){
				pii a = pd(num + 1,x,i,0,t+1);
				pdm = a;
				pdm.fst ++;
				return (pdm);
			}
		}

		pii a = pd(num,x,y,1,t+1);
		pdm = a;
		pdm.snd++;
		pdm.fst++;
		

		
		a = pd(num,x,y,p+2,t+1);
		a.snd++;
		a.fst++;
		pdm = min(pdm,a);
		

		frr(i,n){
		
			pii a = pd(num,i,y,0,t+1);
			a.fst ++;
			pdm = min(pdm,a);

		}

		frr(i,n){
			
			a = pd(num,x,i,0,t+1);
			a.fst ++;
			pdm = min(pdm,a);
	
		}

		return (pdm);
	}

	if(p == 1){
		fr(i,8){
			if(is(x + dx[i],y + dy[i]) && m[x+dx[i]][y+dy[i]] == num){
				pii a = pd(num + 1,x+dx[i],y+dy[i],1,t+1);
				a.fst++;
				pdm = a;
				return pdm;
			}
		}
		
		pii a = pd(num,x,y,2,t+1);
		pdm = a;
		pdm.snd++;
		pdm.fst++;
		

		
		a = pd(num,x,y,0,t+1);
		a.snd++;
		a.fst++;
		pdm = min(pdm,a);
		
		fr(i,8){
			if(is(x + dx[i],y + dy[i])){
				a = pd(num,x+dx[i],y+dy[i],1,t+1);
				a.fst++;
				pdm = min(a,pdm);
			}
		}

		return (pdm);
		
	}

	if(p==2){
		fr(i,4){
			frr(j,n){
				if(is(x + ddx[i]*j,y + ddy[i]*j) && m[x + ddx[i]*j][y + ddy[i]*j] == num){
					pii a = pd(num + 1,x + ddx[i]*j,y + ddy[i]*j,2,t+1);
					a.fst++;
					pdm = a;
					return (pdm);
				}
			}
		}
		

		pii a = pd(num,x,y,1,t+1);
		pdm = a;
		pdm.snd++;
		pdm.fst++;
		

		
		a = pd(num,x,y,0,t+1);
		a.snd++;
		a.fst++;
		pdm = min(pdm,a);
		

		fr(i,4){
			frr(j,n){
				if(is(x + ddx[i]*j,y + ddy[i]*j)){
					a = pd(num ,x + ddx[i]*j,y + ddy[i]*j,2,t+1);
					a.fst++;
					pdm = min(a,pdm);
					
				}
			}
		}

		return pdm;
	}

	return pdm;


}

int main(){

	fastio;
	
	cin >> n;

	fr(i,101){
		fr(j,11){
			fr(k,11){
				fr(l,3){
					fr(p,221)
					memo[i][j][k][l][p] = mp(-1,-1);
				}
			}
		}
	}

	frr(i,n){
		frr(j,n){
			cin >> m[i][j];
		}
	}

	int auxi,auxj;

	frr(i,n){
		frr(j,n){
			if(m[i][j] == 1){
				auxi = i;
				auxj = j;
			}
		}
	}
	pii ans = {INF,INF};

	fr(i,3){
		ans = min(ans,pd(2,auxi,auxj,i,0));
	}
	//dbg(memo[9][1][1][2].fst);
	cout<<ans.fst << ' '<<ans.snd << endl;





}


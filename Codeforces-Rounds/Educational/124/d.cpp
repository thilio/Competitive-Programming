#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

vector<array<int, 2>> v;
map<array<int, 2>, int> M;

map<array<int, 2>, int> dist;
map<array<int, 2>, array<int, 2>> priv;

int dx[4] = {+1, -1, 0, 0};
int dy[4] = {0, 0, +1, -1};

int main(){

	fastio;

	int n;
	cin >> n;

	v.resize(n);

	fr(i, n){
		cin >> v[i][0] >> v[i][1];
		M[v[i]] = i;
	}

	queue<array<int, 2> > q;

	for(auto x: v){

		fr(i, 4){
			array<int, 2> y = x;
			y[0] += dx[i];
			y[1] += dy[i]; 
			if(!M.count(y)){
				dist[x] = 1;
				priv[x] = y;
				q.push(x);
				break;
			}	
		}
	}

	while(!q.empty()){
		array<int, 2> y = q.front();
		q.pop();

		fr(i, 4){
			array<int, 2> z = y;
			z[0] += dx[i];
			z[1] += dy[i];

			if(M.count(z) && !priv.count(z)){
				priv[z] = priv[y];
				q.push(z);
			}
		}
	}

	for(auto x: v){
		cout << priv[x][0] << ' ' << priv[x][1] << endl;
	}

}

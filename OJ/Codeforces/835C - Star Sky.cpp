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

vector<int> v[110][110][12];

int sum[110][110][12];

int n,q,c;

int main(){

	fastio;

	cin >> n >> q >> c;

	fr(i,n){
		int x,y,s;
		cin >> x >> y >> s;

		v[x][y][0].pb(s);
	}

	frr(i,c){
		frr(x,100){
			frr(y,100){
				fr(k,v[x][y][0].size()){
					v[x][y][i].pb((v[x][y][0][k] + i)%(c+1));
				}
			}
		}
	}

	fr(i,c+1){
		frr(x,100){
			frr(y,100){
				fr(k,v[x][y][0].size()){
					sum[x][y][i] += v[x][y][i][k];
				}
			}
		}
	}

	fr(i,c+1){
		frr(x,100){
			frr(y,100){
				
				sum[x][y][i] += sum[x-1][y][i];
				
			}
		}
	}

	fr(i,q){
		int t;
		cin >> t;

		t = t %(c+1);

		int x1,y1,x2,y2;

		cin >> x1 >> y1 >>x2 >> y2;

		int ans = 0;

		for(int i = y1;i <= y2;i++)
			ans+= sum[x2][i][t] - sum[x1-1][i][t];

		cout << ans << endl;
	}




}

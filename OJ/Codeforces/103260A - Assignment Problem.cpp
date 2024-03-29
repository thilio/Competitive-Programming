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

int n, m;
int A[20][1100];

bool ans[1100];
bool used[1100];

void backtrack(int mask){
	//dbg(mask);
	if((mask + 1) == (1 << m)) return;

	for(int i = 0; i < m; i++){
		if(((1 << i)&mask) == 0){
			for(int j = 0; j < n; j++){
				if(!used[A[i][j]]){
					used[A[i][j]] = true;
					ans[A[i][j]] = true;
					backtrack(mask^(1 << i));
					used[A[i][j]] = false;
					break;
				}
			}
		}

	}
}

int main(){

	fastio;

	cin >> n >> m;
	fr(i, m){
		fr(j, n){
			int x;
			cin >> x;
			A[i][j] = x;
		}
	}

	backtrack(0);

	vector<int> ok;
	frr(i, n) if(ans[i]) ok.pb(i);

	sort(all(ok));

	cout << ok.size() << endl;
	for(auto x: ok) cout << x << ' ';
	gnl;


}

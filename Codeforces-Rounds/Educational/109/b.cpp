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

vi v;
int n;

bool ord(){
	fr(i, n) if(v[i] != i + 1) return false;
	return true;
}

int work(){
	if(ord()) return 0;
	if(v[0] == 1 || v[n - 1] == n) return 1;
	if(v[0] == n && v[n - 1] == 1) return 3;
	return 2;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		v.clear();
		cin >> n;
		v.resize(n);
		fr(i, n) cin >> v[i];

		cout << work() << endl;
	}

}

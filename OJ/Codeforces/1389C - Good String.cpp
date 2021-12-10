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

string s;
int n;
int freq[10];


int tent(int i, int j){
	int ans = 0;
	int now = i;
	for(auto x: s){
		if(x == now + '0'){
			ans++;
			now = i + j - now;
		}
	}

	ans -= ans%2;

	return ans;
}

void solve(){
	fr(i, 10) freq[i] = 0; 
	for(auto x: s) freq[x - '0']++;
	
	n = s.size();

	int ans = 1;


	for(int i = 0; i < 10; i++){
		ans = max(ans, freq[i]);
	}

	for(int i = 0; i < 10; i++){
		for(int j = 0 ; j < 10; j++){
			if(i == j) continue;
			ans = max(ans, tent(i, j));
		}
	}

	cout << n - ans << endl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> s;
		solve();
	}


}

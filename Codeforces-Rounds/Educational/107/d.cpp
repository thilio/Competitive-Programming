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

string s;

void build(int k){
	s.pb('a');
	s.pb('a');

	for(int i = 2; i <= k; i++){
		s.pb('a' + i - 1);
		char c = 'a' + i - 2;
		while(c >= 'a'){
			s.pb('a' + i - 1);
			s.pb(c);
			c--;
		}
	}
}

int main(){

	fastio;

	int n, k;

	cin >> n >> k;

	if(k == 1){
		fr(i, n) cout << 'a';
		gnl;
		return 0;
	}
	build(k);

	if(n <= k*k + 1){
		fr(i, n) cout << s[i];
		gnl;
		return 0;
	}
	else{
		cout << s;
		n -= k*k + 1;
		string t;
		fr(i, s.size()) if(i != 0) t.pb(s[i]);
		fr(i, n) cout << t[i % t.size()];
		gnl;
	}

}

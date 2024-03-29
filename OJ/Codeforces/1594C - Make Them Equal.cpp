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

int n;
char c;
string s;
vector<int> dif;

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> n;
		cin >> c;
		cin >> s;

		dif.clear();

		fr(i, n) if(s[i] != c) dif.pb(i + 1);

		if(dif.size() == 0){
			cout << 0 << endl;
			continue;
		}

		int last = -1;
		fr(i, n) if(s[i] == c) last = i + 1;

		//dbg(last);

		if(last > n/2){
			cout << 1 << endl;
			cout << last << endl;
		}
		else{
			cout << 2 << endl;
			cout << n << ' ' << n - 1 << endl;
		}
	}

}

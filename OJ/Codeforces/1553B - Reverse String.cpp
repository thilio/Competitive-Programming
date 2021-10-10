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

string s, t;

bool test(int i, int j){

	if(j - i + 1 > t.size()) return false;

	int p = i;
	int q = 0;

	while(p <= j){
		if(s[p] != t[q]) return false;
		p++;
		q++;
	}

	p = j - 1;

	while(p >= 0 && q < t.size()){
		if(s[p] != t[q]) return false;
		p--;
		q++;
	}

	if(q == t.size()) return true;
	return false;

}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		cin >> s >> t;

		bool ok = false;
		for(int i = 0; i < s.size(); i++){
			for(int j = i; j < s.size(); j++){
				ok |= test(i, j);
			}
		}

		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl; 


	}

}

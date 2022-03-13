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

vector<array<int, 2>> factor(int x){
	vector<array<int, 2>> pri;
	int k = x;
	for(int i = 2; i * i <= k; i++){
		if(k%i == 0){
			int ct = 0;
			while(k % i == 0){
				ct++;
				k /= i;
			}
			pri.pb({i, ct});
		}
	}
	if(k != 1){
		pri.pb({k, 1});
	}

	return pri;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int d, x;

		cin >> x >> d;

		int df = 0;
		while(x % d == 0){
			df++;
			x /= d;
		}

		if(df < 2){
			cout << "NO" << endl;
			continue;
		}

		vector<array<int, 2>> v = factor(x);

		if(v.size() > 1 || (v.size() == 1 && v[0][1] > 1)){
			cout << "YES" << endl;
			continue;
		}

		if(df == 2){
			cout << "NO" << endl;
			continue;
		}

		vector<array<int, 2>> w = factor(d);

		if(w.size() > 1){
			cout << "YES" << endl;
			continue;
		}

		if(w[0][1] == 1){
			cout << "NO" << endl;
			continue; 
		}

		if(x != w[0][0]){
			cout << "YES" << endl;
			continue;
		}

		if(w[0][1] == 2 && df == 3){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}

}

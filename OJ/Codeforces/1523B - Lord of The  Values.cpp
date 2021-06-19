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
#define endl '\n';

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

void go(int i, int j){
	//cout << 2 << ' ' << i << ' ' << j << endl;
	cout << 2 << ' ' << i << ' ' << j << endl;
	cout << 1 << ' ' << i << ' ' << j << endl;
	cout << 2 << ' ' << i << ' ' << j << endl;
}

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int x;
		fr(i ,n) cin >> x;

		cout << 3*n << endl;
		for(int i = 1; i<= n; i+= 2){
			go(i, i + 1);
			go(i, i + 1);
		}
	}

}

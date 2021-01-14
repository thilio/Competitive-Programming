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

int v[100100];
int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){

		int n,k;
		
		cin >> n >> k;
		bool ok = false;
		frr(i,n){
			int a;
			cin >> a;
			if(a < k) v[i] = -1;
			if(a == k) v[i] = 0;
			if(a > k) v[i] = 1;

			if(a == k) ok = true;
		}

		if(!ok){
			cout << "no" << endl;
			continue;
		}

		if(n == 1){
			cout << "yes" << endl;
			continue;
		}

		ok = false;

		frr(i,n-1){
			if(v[i] >= 0 && v[i+1] >= 0){
				ok  = true;
			}
		}

		frr(i,n-2){
			int x = v[i];
			int y = v[i+1];
			int z = v[i+2];

			if(x >= 0 && y >= 0) ok = true;
			if(z >= 0 && y >= 0) ok = true;
			if(x >= 0 && z >= 0) ok = true;
		}

		if(ok) cout << "yes" << endl;
		else cout << "no" << endl;

	}

}

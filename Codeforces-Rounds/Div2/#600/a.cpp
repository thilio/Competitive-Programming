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

int a[100100];
int b[100100];

int main(){

	fastio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fr(i,n) cin >> a[i];
		fr(i,n) cin >> b[i];

		int j = -1;
		fr(i,n){
			if(a[i] != b[i]){
				j = i;
				break;
			}
		}

		if(j == -1){
			cout << "YES\n";
			continue;
		}
		int k = -1;
		for(int i = n-1;i >= 0; i--){
			if(a[i] != b[i]){
				k = i;
				break;
			}
		}

		bool ok = true;

		for(int i = j; i <= k; i++){
			if(a[i] - b[i] != a[j] - b[j]) ok = false;
		}

		if((a[j] - b[j]) > 0) ok = false;

		if(ok) cout <<"YES\n";
		else cout << "NO\n";
	}

}

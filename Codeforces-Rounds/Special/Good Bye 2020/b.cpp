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
int freq[400100];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		frr(i,n){
			cin >> v[i];
			freq[2*i] = freq[2*i - 1] = 0;
		}
		freq[2*n + 1] = freq[2*n + 2] = 0;

		int ans = 1;
		freq[v[1]] = 1;
		for(int i = 2; i <= n; i++){
			if(freq[v[i]] == 0){
				ans++;
				freq[v[i]] = 1;
			}
			else if(freq[v[i] + 1] == 0){
				freq[v[i] + 1] = 1;
				ans++;

			}
		}

		cout << ans << endl;
	}

}

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
int sum;
int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;int x;
		cin >> n >> x;

		sum = 0;
		fr(i,n){
			cin >> v[i];
			sum += v[i];
		}

		int fst = n;
		int last = n;

		fr(i,n){
			if(v[i]%x){
				fst = min(fst,i);
				last = i;
			}
		}

		if (sum%x){
			cout << n << endl;
			continue;
		}
		if(fst == n){
			cout << -1 << endl;
		}
		else{
			int ans1 = max(fst + 1,n - fst - 1);
			int ans2 = max(last, n - last);

			cout << max(ans1,ans2) << endl;
		}

	}

}

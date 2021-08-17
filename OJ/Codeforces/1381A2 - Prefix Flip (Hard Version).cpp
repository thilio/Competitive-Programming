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

string a, b;
vi ans;

int main(){

	fastio;
	int T;
	cin >> T;

	while(T--){
		ans.clear();
		int n;
		cin >> n;
		cin >> a >> b;
		reverse(all(a));
		a.pb('$');
		reverse(all(a));

		reverse(all(b));
		b.pb('$');
		reverse(all(b));
		
		int pa, qa, pb;
		pa = 1; qa = n; pb = n;

		frr(i, n){
			if(i%2 == 1){
				if(a[pa] == b[pb]){
					ans.pb(1);
					ans.pb(n - i + 1);
				}
				else{
					ans.pb(n - i + 1);
				}
				pa++;
				pb--;
			}
			else{
				if(a[qa] == b[pb]){
					ans.pb(n - i + 1);
				}
				else{
					ans.pb(1);
					ans.pb(n - i + 1);
				}
				qa--;
				pb--;
			}
		}

		cout << ans.size();
		for(auto x: ans) cout << ' ' << x;
		gnl;


	}

}

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

int g = 1;

int ati[10010];

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		tuple<int,int,int> t[1010];
		ms(ati,0);

		fr(i,n){
			cin >> get<0>(t[i]) >> get<1>(t[i]);
			get<2>(t[i]) = i;

			ati[get<0>(t[i])]++;
			ati[get<1>(t[i])]--;

		}

		cout << "Case #" << g++ <<": ";

		int sum = 0;
		bool ok = false;
		fr(i,10010){
			sum += ati[i];
			if(sum > 2) ok = true;

		}

		if(ok){
			cout << "IMPOSSIBLE\n";
			continue;
		}

		sort(t,t+n);

		int time = -1;
		char ans[10010];

		fr(i,n){
			if(get<0>(t[i]) >= time){
				ans[get<2>(t[i])] = 'C';
				time = get<1>(t[i]);
			}
			else ans[get<2>(t[i])] = 'J';
		}

		fr(i,n) cout << ans[i];

		cout << endl;
	}

}

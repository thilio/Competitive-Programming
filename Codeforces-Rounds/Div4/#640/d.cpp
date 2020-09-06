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

int main(){

	fastio;

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int v[1010];

		fr(i,n) cin >> v[i];

		int suma,sumb;
		suma = sumb = 0;

		int a = 0;
		int b = n-1;

		int r = 1;

		bool turn = 1;
		suma += v[a];
		a++;
		int prev = v[0];

		while(a <= b){
			r++;
			int cur;
			if(turn){
				cur = 0;
				while(a <= b && cur <= prev){
					sumb += v[b];
					cur += v[b];
					b--;
				}
			}
			else{
				cur = 0;
				while(a <= b && cur <= prev){
					suma += v[a];
					cur += v[a];
					a++;
				}
			}
			turn = !turn;
			prev = cur;

		}

		cout << r << ' ' << suma << ' ' << sumb << endl;

	}

}

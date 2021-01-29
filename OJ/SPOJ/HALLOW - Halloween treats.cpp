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

ll n,c;

ll v[100100];
ll acum[100100];
ll freq[100100];

int main(){

	fastio;

	cin >> c >> n;
	while(n != 0 && c != 0){
		ms(freq,0);
		frr(i,n){
			cin >> v[i];
			v[i] = v[i]%c;
		}
		acum[1] = v[1];
		for(int i = 1; i <= n;i++){
			acum[i] = v[i] + acum[i-1];
			acum[i] = acum[i] % c;
			freq[acum[i]]++;
		}

		if(freq[0] != 0){
			int j;
			frr(i,n){
				if(acum[i] == 0){
					j = i;
					break;
				}
			}

			frr(i,j) cout << i << ' ';
			gnl;
		}

		else{
			int j;
			frr(i,c-1){
				if(freq[i] > 1){
					j = i;
					break;
				}
			}

			ll l,r;
			l = r = -1;

			frr(i,n){
				if(acum[i] == j){
					if(l == -1){
						l = i;
					}
					else{
						r = i;
						break;
					}
				}
			}

			for(int i = l + 1; i<= r; i++){
				cout << i << ' ';
			}

			gnl;
		}

		cin >> c >> n;
	}

}

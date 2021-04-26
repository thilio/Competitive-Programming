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

int card[500];
int n, q;

int main(){

	fastio;

	cin >> n >> q;

	frr(i, n){
		int x;
		cin >> x;
		if(card[x] == 0) card[x] = i;
	}

	frr(i, q){
		int x;
		cin >> x;

		cout << card[x] << ' ';

		frr(i, 50){
			if(card[i] != 0 && card[i] < card[x]) card[i]++;
		}
		card[x] = 1;
	}
	gnl;

}

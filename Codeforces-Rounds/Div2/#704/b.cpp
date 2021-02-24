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
int freq[100100];

int main(){

	fastio;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;

		frr(i,n) cin >> v[i];
		frr(i,n) freq[i] = 0;
		int i = n;
		int target = n;
		while(v[i] != target) i--;
		int j = n + 1;
		while(target > 0){
			
			for(int k = i; k < j; k++) cout << v[k] << ' ';
			for(int k = i; k < j; k++) freq[v[k]]++;

			while(freq[target] > 0 && target > 0) target--;
			j = i;
			while(v[i] != target && i > 0) i--;
			
		}
		gnl;
	}

}

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

int freq[30300];

int para(int x,int y){
	return max(x,y) - min(x,y);
}

int main(){

	fastio;

	int n,x,y;
	cin >> n >> x >> y;

	frr(i,n){
		for(int j = i + 1;j <=n;j++){
			int k = para(i,j);
			k = min(k,1 + para(i,x) + para(y,j));
			k = min(k,1 + para(i,y) + para(x,j));
			freq[k]++;
		}
	}

	frr(i,n-1) cout << freq[i] << endl;

}

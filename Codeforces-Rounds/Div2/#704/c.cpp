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

int p[200200];
int pr[200200];
int n,m;
string s,t;

void go(){
	int i = 0;
	int j = 0;

	while(j < m){
		while(t[j] != s[i]) i++;
		p[j] = i;
		j++;
		i++;
	}
}

void go_rev(){
	int i = n - 1;
	int j = m - 1;

	while(j >= 0){
		while(t[j] != s[i]) i--;
		pr[j] = i;
		j--;
		i--;
	}
}

int main(){

	fastio;

	cin >> n >> m;
	cin >> s >> t;

	go();
	go_rev();

	int mx = 0;

	for(int i = 0; i < m - 1; i++){
		mx = max(mx, pr[i + 1] - p[i]);
	}

	cout << mx << endl;

}

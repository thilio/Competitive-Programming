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

int k = 5000500;
map<int, pii> M;
vii v;

vi freq[5000500];

int main(){

	fastio;

	int n;
	cin >> n;

	fr(i,n){
		int x;
		cin >> x;
		v.pb(mp(x, i + 1));
		freq[x].pb(i + 1);
	}

	pii g2;
	g2 = {0,0};

	fr(i,k){
		if(freq[i].size() >= 4){
			cout << "YES" << endl;
			fr(j,4) cout << freq[i][j] << ' ';
			gnl;
			return 0;
		}
		if(freq[i].size() >= 2){
			if(g2.fst == 0) g2.fst = i;
			else g2.snd = i;
		}
	}

	if(g2.fst != 0 && g2.snd != 0){
		cout << "YES" << endl;
		cout << freq[g2.fst][0] << ' ';
		cout << freq[g2.snd][0] << ' ';
		cout << freq[g2.fst][1] << ' ';
		cout << freq[g2.snd][1] << endl;
		return 0;
	}

	sort(all(v));

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			pii x = {i,j};
			int s = v[i].fst + v[j].fst;
			if(M.count(s)){
				pii y = M[s];
				if(y.fst < x.fst && x.snd < y.snd){
					cout << "YES" << endl;
					cout << v[x.fst].snd << ' ' << v[x.snd].snd << ' ' << v[y.fst].snd << ' ' << v[y.snd].snd << endl;
					return 0;
				}
				else if(y.fst == x.fst){
					M[s].snd = j;
				}
				else if(y.snd == x.fst){
					M[s] = x;
				}
			}
			else{
				M[s] = {i, j};
			}
		}
	}

	cout << "NO" << endl;

}

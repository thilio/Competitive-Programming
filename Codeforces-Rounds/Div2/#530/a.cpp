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
	pii sno;
	pii p1;
	pii p2;

	cin >> sno.fst >> sno.snd >> p1.fst >> p1.snd >> p2.fst >> p2.snd;

	for(int i = sno.snd; i>0;i--){
		sno.fst += i;
		if(i == p1.snd){
			sno.fst = max(sno.fst - p1.fst,0);
		}
		if(i == p2.snd){
			sno.fst = max(sno.fst - p2.fst,0);
		}
	}

	cout << sno.fst << endl;

}

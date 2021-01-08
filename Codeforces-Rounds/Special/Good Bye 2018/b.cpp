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

pii v[1123];
set<pii> s;
int n;

bool testa (pii t){
	pii aux;
	fr(i,n){
		aux = v[i];
		if(s.find(mp(t.fst - aux.fst,t.snd - aux.snd)) == s.end())
			return false;
	}

	return true;
}

int main(){

	fastio;
	
	cin >> n;

	fr(i,n){
		cin >> v[i].fst >>v[i].snd;
	}

	int a,b;

	fr(i,n){
		cin >> a >> b;
		s.insert(mp(a,b));
	}
	auto it = s.begin();
	pii aux = *it;

	//dbg(aux.fst);
	///dbg(aux.snd);


	fr(i,n){
		if(testa(mp(aux.fst + v[i].fst,aux.snd + v[i].snd))){
			cout << aux.fst + v[i].fst<<' '<<aux.snd + v[i].snd<<endl;
			return 0;
		}

		
	}



}

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
int W,H;
int area;
vector<pii> v;
vector<pii> in;
vector<pii> cand;
int perm;
vi aux;

pii pos[7];
int n;
int fat;

bool is(pii a, int i){
	fr(j,i)
		if(pos[j].fst <= a.fst && a.fst < pos[j].fst + v[j].fst)
			if(pos[j].snd <= a.snd && a.snd < pos[j].snd + v[j].snd) return false;
	if(a.fst + v[i].fst <= W && a.snd + v[i].snd <= H) return true;
	return false;
}

bool interx(int i, pii a, int j, pii b){
	if(a.fst >= b.fst + v[j].fst || b.fst >= a.fst + v[i].fst) return false;
	return true;
}

bool intery(int i, pii a, int j, pii b){
	if(a.snd >= b.snd + v[j].snd || b.snd >= a.snd + v[i].snd) return false;
	return true;
}

bool inter(int i, pii a, int j, pii b){
	if(interx(i,a,j,b) && intery(i,a,j,b)) return true;
	return false;
}


bool tent(int mask){
	v.clear();
	fr(i,n){
		v.pb(in[aux[i]]);
	}
	fr(i,n){
		if(((1 << i)&mask) > 0) swap(v[i].fst, v[i].snd);
	}
	cand.clear();
	cand.pb(mp(0,0));

	int i = 0;
	int area_at = 0;
	while(i < n){
		pii best = {1000,1000};
		for(auto x: cand){
			if(is(x,i)){
				if(best.snd > x.snd) best = x;
				else if(best.snd == x.snd && best.fst > x.fst) best = x;
			}
		}
		if(best.fst == 1000) return false;
		for(int j = 0; j < i; j++){
			if(inter(i,best,j,pos[j])) return false;
			
		}
		pos[i] = best;
		area_at += v[i].fst*v[i].snd;

		cand.pb(mp(pos[i].fst + v[i].fst, pos[i].snd));
		cand.pb(mp(pos[i].fst, pos[i].snd + v[i].snd));

		if(area_at == area) return true;
		i++;
		
	}

	return false;
}

int main(){

	fastio;
	cin >> W >> H;
	area = W*H;


	int c;
	cin >> c;

	fr(i,c){
		int a,w,h;
		cin >> a >> w >> h;
		fr(j,a) in.pb(mp(w,h));
	}

	n = in.size();
	fr(i,n) aux.pb(i);
	fat = 1;
	frr(i,n) fat*= i;

	bool ok = false;
	perm = 0;

	while(perm < fat){
		for(int mask = 0; mask < (1 << n); mask++){
			ok |= tent(mask);
		}
		perm++;
		next_permutation(all(aux));
	}

	if(ok){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}
}

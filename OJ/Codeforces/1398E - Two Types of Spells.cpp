#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define endl '\n'
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

set<ll> fire, light;
set<pll> mx;

int nlight;
int nfire;

ll peso_t;
ll peso_mx;

void print(){
	ll ans = peso_t + peso_mx;
	if(!mx.empty() && nfire == fire.size()){
		auto it = mx.begin();
		ans -= (*it).fst;
		if(!fire.empty()){
			auto ite = fire.end();
			ite--;
			ans += *(ite);
		}
	}
	cout << ans << endl;
}

void update(){
	//olar;
	if(nlight <= mx.size() && !mx.empty()){
		auto it = mx.begin();
		peso_mx -= (*it).fst;
		mx.erase(it);
		if((*it).snd == 0) fire.insert((*it).fst);
		else light.insert((*it).fst);
	}
	if(nlight > mx.size()){
		auto itf = fire.end();
		auto itl = light.end();
		ll fires, lights;
		fires = lights = 0;
		if(fire.begin() != fire.end()){
			itf--;
			fires = *itf;
		}
		if(light.begin() != light.end()){
			itl--;
			lights = *itl;
		}

		if(fires >= lights){
			fire.erase(itf);
			mx.insert({fires, 0});
			peso_mx += fires;
		}
		else{
			light.erase(itl);
			mx.insert({lights, 1});
			peso_mx += lights;
		}
	}
}

void add_fire(ll d){
	nfire++;
	peso_t += d;
	fire.insert(d);
	update();
}

void add_light(ll d){
	nlight++;
	peso_t += d;
	light.insert(d);
	update();
}

void rem_fire(ll d){
	nfire--;
	peso_t -= d;
	if(mx.find({d, 0}) != mx.end()){
		mx.erase(mx.find({d, 0}));
		peso_mx -= d;
		update();
	}
	else{
		fire.erase(d);
	}
}

void rem_light(ll d){
	nlight--;
	peso_t -= d;
	if(mx.find({d, 1}) != mx.end()){
		mx.erase(mx.find({d, 1}));
		peso_mx -= d;
	}
	else{
		light.erase(d);
	}
	update();
}

int main(){

	fastio;

	int n;
	cin >> n;

	fr(i, n){
		ll t, d;
		cin >> t >> d;

		if(t == 0 && d > 0) add_fire(d);
		if(t == 0 && d < 0) rem_fire(-d);
		if(t == 1 && d > 0) add_light(d);
		if(t == 1 && d < 0) rem_light(-d);

		print();

		//dbg(peso_t); dbg(peso_mx);	
	}

}

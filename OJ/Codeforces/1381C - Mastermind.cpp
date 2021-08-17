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

int n, x, y;
int bob[100100];
int fix[100100];
int freq[100100];
int qtos[100100];
int alice[100100];
int esp_color;
vi rot;

void clear(){
	frr(i, n + 1){
		fix[i] = freq[i] = qtos[i] = alice[i] = 0;
	}
	rot.clear();
	esp_color = 0;
}

void find_esp(){
	int S[n + 1];
	frr(i, n + 1) S[i] = 1;
	frr(i, n) S[bob[i]]--;
	frr(i, n + 1) if(S[i] == 1) esp_color = i;
}
void find_fixed(){
	priority_queue<pii> pq;
	frr(i, n + 1) if(freq[i] != 0) pq.push({freq[i], i});

	fr(i, x){
		pii a = pq.top();
		pq.pop();
		qtos[a.snd]++;
		a.fst--;
		pq.push(a);
	}

	frr(i, n){
		if(qtos[bob[i]] > 0){
			fix[i] = 1;
			qtos[bob[i]]--;
		}
	}
}

void find_rot(){
	vii aux;
	frr(i, n){
		if(!fix[i]) aux.pb({bob[i], i});
	}

	sort(all(aux));

	//for(auto x: aux) cout << x.fst << ' ' << x.snd << endl;

	vii help;
	int k = (n - x)/2;
	help.resize(aux.size());

	fr(i, aux.size()){
		help[i] = aux[(i + k)%aux.size()];
	}

	rot.resize(n + 1);

	fr(i, aux.size()){
		rot[aux[i].snd] = help[i].fst;
	}

}

void solve(){
	clear();
	cin >> n >> x >> y;
	frr(i, n) cin >> bob[i];
	frr(i, n) freq[bob[i]]++;
	find_esp();
	find_fixed();

	//frr(i, n) dbg(fix[i]);

	frr(i, n + 1) freq[i] = 0;
	frr(i, n) if(!fix[i]) freq[bob[i]]++;

	int mx = 0;
	frr(i, n + 1) mx = max(mx, freq[i]);

	if(n - y < 2*mx - (n - x)){
		cout << "NO\n";
		return;
	}

	find_rot();
	//for(auto x: rot) dbg(x);
	cout << "YES\n";

	int k = n - y;
	frr(i, n){
		if(fix[i]) alice[i] = bob[i];
		else{
			if(bob[i] == rot[i]){
				alice[i] = esp_color;
				k--;
			}
		}
	}
	frr(i, n){
		if(fix[i]) continue;
		else{
			if(alice[i] != 0){
				continue;
			}
			if(k > 0){
				alice[i] = esp_color;
				k--;
				continue;
			}
			alice[i] = rot[i];
		}
	}

	frr(i, n) cout << alice[i] << ' ';
	gnl;


}

int main(){

	fastio;
	int T;
	cin >> T;

	while(T--){
		solve();
	}

}

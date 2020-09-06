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

set<int> s1;
set<int> s0;
int n;
int v[1000100],w[1000100];

vi v1,v0;
void cons1(){

	auto p = s1.begin();

	int i = 0;
	int cur = -1;
	while(p != s1.end() && p != s0.end()){
		if(i%2 == 0){
			auto it = s1.lower_bound(cur);
			if(it == s1.end()) break;
			cur = *(it);
			v1.pb(cur);
		}
		else{
			auto it = s0.lower_bound(cur);
			if(it == s0.end()) break;
			cur = *(it);
			v1.pb(cur);
		}
		i++;
	}

}

void cons0(){
	auto p = s1.begin();

	int i = 0;
	int cur = -1;
	while(p != s1.end() && p != s0.end()){
		if(i%2 == 0){
			auto it = s0.lower_bound(cur);
			if(it == s0.end()) break;
			cur = *(it);
			v0.pb(cur);
		}
		else{
			auto it = s1.lower_bound(cur);
			if(it == s1.end()) break;
			cur = *(it);
			v0.pb(cur);
		}
		i++;
	}

}
void cons(){
	cons1();
	cons0();

	if(v1.size()%2) v1.pop_back();
	if(v0.size()%2) v0.pop_back();
}


int main(){

	fastio;

	cin >> n;
	string s;
	getline(cin,s);
	getline(cin,s);

	frr(i,n){
		v[i] = s[i-1] - '0';
	}
	getline(cin,s);

	frr(i,n){
		w[i] = s[i-1] - '0';
	}

	int sumv,sumw;
	sumv = sumw = 0;

	int mistakes= 0;

	frr(i,n){
		sumv += v[i];
		sumw += w[i]; 
		if(v[i] != w[i]){
			mistakes++;
			if(v[i] == 1) s1.insert(i);
			else s0.insert(i);
		}
	}

	if(sumv != sumw){
		cout << -1 << endl;
		return 0;
	}

	int ans = 0;

	while(mistakes > 0){
		v1.clear();
		v0.clear();

		cons();
		ans++;
		if(v1.size() > v0.size()){
			mistakes -= v1.size();
			fr(i,v1.size()){
				if(i%2) s0.erase(v1[i]);
				else s1.erase(v1[i]);
			}
		}
		else{
			mistakes -= v0.size();
			fr(i,v0.size()){
				if(i%2) s1.erase(v0[i]);
				else s0.erase(v0[i]);
			}

		}

	}


	cout << ans << endl;


}

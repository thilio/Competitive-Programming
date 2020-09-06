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

int v[200200];
int n,k;

bool ti(int l){

	int p=0;
	int imp=0;

	bool last;
	last = false;
	int tem = 0;

	int ult = -1;
	frr(i,n){
		if(last == true){
			last = false;
			continue;
		}

		if(v[i] <= l){
			tem++;
			last = true;
			ult = i;
		}

	}

	if(k%2){
		if(tem >= (k+1)/2) return true;
		else return false;
	}
	else{
		if(tem > k/2) return true;
		if(tem == k/2 && ult != n) return true;
		return false;
	}
}

bool tp(int l){

	bool last1;
	last1 = false;
	int tem1 = 0;

	int pri1 = n+1;
	int ult1 = -1;
	frr(i,n){
		if(last1 == true){
			last1 = false;
			continue;
		}

		if(v[i] <= l){
			tem1++;
			last1 = true;
			pri1 = min(pri1,i);
			ult1 = i;
		}
	}

	bool last2;
	last2 = false;
	int tem2 = 0;

	int pri2 = n+1;
	int ult2 = -1;

	for(int i = 2; i <=n;i++){
		if(last2 == true){
			last2 = false;
			continue;
		}

		if(v[i] <= l){
			tem2++;
			last2 = true;
			pri2 = min(pri2,i);
			ult2 = i;
		}
	}

	

	if(k%2){
		if(tem1 > k/2 + 1) return true;
		if(tem1 > k/2){
			if(pri1 != 1 || ult1 != n) return true;
		}
		if(tem1 == k/2){
			if(pri1 != 1 && ult1 != n) return true;
		}

		if(tem2 > k/2) return true;
		if(tem2 == k/2 && ult2 != n) return true;
		return false;
	}
	else{
		if(tem1 > k/2) return true;
		if(tem1 == k/2 && pri1 !=1) return true;
		if(tem2 >= k/2) return true;
		return false;
	}
}


bool ok(int l){
	if(ti(l)) return true;
	if(tp(l)) return true;
	return false;
}


int main(){

	fastio;

	cin >> n >> k;

	int mx = 0;
	frr(i,n){
		cin >> v[i];
		mx = max(mx,v[i]);
	}

	int l = 1;
	int r = max(mx,1000);

	int best = -1;

	while(l <= r){
		int m = (l + r)/2;
		//dbg(m);

		if(ok(m)){
			r = m -1;
			best = m;
		}
		else l = m + 1;
	}

	cout << best << endl;

}

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

ll n, m , k;
vi a;
vi b;

ll wzm[500500];
ll match[500500];
ll quando[500500];
map<int, int> M;

void whenzero(){
	ms(wzm, - 1);
	wzm[0] = 1;
	ll last = 1 + n;
	ll j = n%m;
	while(j != 0){
		wzm[j] = last;
		j = (j + n)%m;
		last += n;
	}
}

void mat(){
	fr(i,b.size()){
		M[b[i]] = i;
	}
	fr(i, a.size()){
		if(M.count(a[i])){
			match[i] = M[a[i]];
		}
		else match[i] = -1;
	}
}

void preprocess(){
	fr(i,a.size()){
		if(match[i] == -1){
			quando[i] = -1;
		}
		else{
			quando[i] = wzm[(match[i] - i + m)%m] + i;
		}
	}
}

void corner(){
	int mis = -1;
	fr(i,n){
		if(quando[i] == -1) mis = i;
	}

	if(mis == -1){
		if(quando[0] == -1){
			cout << k << endl;
		}
		else{
			cout << 2*k - (1 - quando[0]) << endl;
		}
	}
	else{
		cout << (k - 1)*n + (mis + 1) << endl;	
	}

	
	exit(0);
}

int main(){

	fastio;
	cin >> n >> m >> k;

	fr(i,n){
		int x;
		cin >> x;
		a.pb(x);
	}

	fr(i,m){
		int x;
		cin >> x;
		b.pb(x);
	}

	if(n > m){
		swap(m,n);
		swap(a,b);
	}

	whenzero();
	mat();
	preprocess();

	ll combina = 0;
	fr(i, n){
		if(quando[i] != -1) combina++;
	}

	ll ans = 0;

	ll mmc = (m*n)/(__gcd(m,n));

	if(k > (mmc - combina)){
		if((mmc - combina) == 1) corner();
		if(k%(mmc - combina) != 0){
			ans += (k/(mmc - combina))*(mmc);
			k %= (mmc - combina);
		}
		else{
			k--;
			ans += (k/(mmc - combina))*(mmc);
			k %= (mmc - combina);
			k++;
		}
	}

	vi v;

	fr(i,n){
		if(quando[i] != -1) v.pb(quando[i]);
	}

	sort(all(v));
	int estou = 0;

	fr(i, v.size()){

		if(k < v[i] - estou){
			cout << ans + k << endl;
			return 0;
		}
		else{
			k -= v[i] - estou - 1;
			if(estou == 1 && v[i] == 1) k--;
			ans += v[i] - estou;
			estou = v[i];
		}
	}

	cout << ans + k << endl;
}

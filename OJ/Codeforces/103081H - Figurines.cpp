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

int v[100100];
bool esta[100100];

struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

vector<Vertex*> root;
vector<Vertex*> day;

Vertex* build(int l, int r) {
    if (l == r)
        return new Vertex(v[l]);
    int m = (l + r) / 2;
    return new Vertex(build(l, m), build(m+1, r));
}

ll query(Vertex* v, int l, int r, int a, int b) {
    if(l > b || r < a) return 0;
    if(a <= l && r <= b) return v -> sum;
    int m = (l + r)/2;
	return query(v -> l, l, m, a , b) + query(v -> r, m + 1, r, a, b);  
}

Vertex* update(Vertex* v, int l, int r, int pos, ll val) {
    if (l == r)
        return new Vertex(v -> sum + val);
    int m = (l + r) / 2;
    if (pos <= m)
        return new Vertex(update(v->l, l, m, pos, val), v->r);
    else
        return new Vertex(v->l, update(v->r, m+1, r, pos, val));
}

int main(){

	fastio;

	int n;
	cin >> n;
	string s;
	getline(cin, s);

	day.pb(build(0, n - 1));
	Vertex* ori = day[0];

	fr(i, n){
		getline(cin, s);
		stringstream ss(s);

		int x;
		while(ss >> x){
			x = abs(x);
			if(esta[x]){ 
				ori = update(ori, 0, n - 1, x, -1);
				esta[x] = false;
			}
			else {
				ori = update(ori, 0, n - 1, x, 1);
				esta[x] = true;
			}
		}
		day.pb(ori);
	}
	ll x = 0;
	fr(i, n){
		int d;
		cin >> d;

		x = (x + query(day[d], 0, n -1, x, n - 1))%n;
		//dbg(x);
	}

	cout << x << endl;

}

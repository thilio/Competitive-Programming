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

struct show{
	int l;
	int r;
	int val;
	int bit;
};

typedef struct show show;

int tam;
int prox[1123];
int memo[3000][1010];
vector<show> v;
int n;

int pd(int mask,int pos){
	//dbg(mask);
	if(pos == tam){
		if(mask == (1<<n) - 1)
			return(0);
		else
			return(-INF);
	}

	int &pdm = memo[mask][pos];

	if(pdm!= -1)
		return(pdm);

	show a = v[pos];

	int i,j;
	int mas = (1<<a.bit);

	i = a.val + pd(mask|mas,prox[pos]);
	j = pd(mask,pos+1);

	pdm = max(i,j);
	return(pdm);

}

bool comp(show a,show b){
	if(a.l < b.l)
		return(true);
	
	if(a.l == b.l && a.r < b.r)
		return (true);

	return (false);
}

int main(){

	fastio;
	int m;
	cin >> n;
	
	fr(i,n){
		show a;
		cin >> m;
		fr(j,m){
			int b,c,d;
			cin >> b >> c >> d;
			a.l = b;
			a.r = c;
			a.val = d;
			a.bit = i;
			v.pb(a);
		}
	}

	sort(v.begin(),v.end(),comp);

	tam = v.size();
	//dbg(tam);

	fr(i,tam){
		show a = v[i];
		int final = a.r;
		int j;
		for(j = i+1;j<tam;j++){
			if(v[j].l >= final) break;
		}
		prox[i] = j;
	}

	//fr(i,tam)
	//	dbg(prox[i]);

	ms(memo,-1);

	int ans = pd(0,0);

	if (ans<0) ans = -1;

	cout << ans << endl;

}

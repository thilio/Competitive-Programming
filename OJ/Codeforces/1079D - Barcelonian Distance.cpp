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
typedef double dd;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

double a,b,c;

double modu (dd x){
	if(x<0.0) return -x;
	return x;
}

double mn (dd a, dd b){
	if(a<b) return a;
	else return b;
}

double disth(pair<dd,dd> x,pair<dd,dd> y){
	return (modu(x.fst-y.fst) + modu(x.snd-y.snd));
}

double dist(pair<dd,dd> x,pair<dd,dd> y){
	dd p = (x.fst-y.fst)*(x.fst-y.fst) + (x.snd-y.snd)*(x.snd-y.snd);
	return (pow(p,0.5));
}

double incogx(dd y){
	dd p = -c - b*y;
	return (p/a);
}

double incogy(dd x){
	dd p = -c - a*x;
	return (p/b);

}

int main(){

	fastio;
	cout.precision(15);

	
	cin >> a >> b >> c;
	pair<double,double> A,B;

	cin >> A.fst >> A.snd;
	cin >> B.fst >> B.snd;

	dd D = disth(A,B);

	if(modu(a)< 1e-8 || modu(b) < 1e-8){
		cout << D << endl;
		return (0);
	}

	dd d1;

	pair<dd,dd> aux1,aux2;

	aux1.fst = A.fst;
	aux1.snd = incogy(A.fst);
	aux2.snd = B.snd;
	aux2.fst = incogx(B.snd);
	
	d1 = disth(A,aux1);
	d1 += dist(aux1,aux2);
	d1+= disth(aux2,B);

	D = mn(D,d1);
	//////////////////////////////////

	aux1.fst = A.fst;
	aux1.snd = incogy(A.fst);
	aux2.snd = incogy(B.fst);
	aux2.fst = B.fst;
	
	d1 = disth(A,aux1);
	d1 += dist(aux1,aux2);
	d1+= disth(aux2,B);

	D = mn(D,d1);

	///////////////////////////////

	aux1.fst = incogx(A.snd);
	aux1.snd = A.snd;
	aux2.snd = B.snd;
	aux2.fst = incogx(B.snd);
	
	d1 = disth(A,aux1);
	d1 += dist(aux1,aux2);
	d1+= disth(aux2,B);

	D = mn(D,d1);

	///////////////////////////////

	aux1.fst = incogx(A.snd);
	aux1.snd = A.snd;
	aux2.snd = incogy(B.fst);
	aux2.fst = B.fst;
	
	d1 = disth(A,aux1);
	d1 += dist(aux1,aux2);
	d1+= disth(aux2,B);

	D = mn(D,d1);

	cout << D << endl;


}

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

using coord = long long int;
const long double pi = acos(-1);
const long double EPS = 1e-8;

int sign(coord x) { return (x > EPS) - (x < -EPS); }
coord sq(coord x) { return x * x; }

struct point {
	coord x, y;
	point() : x(0), y(0) {} point(coord _x, coord _y): x(_x), y(_y) {}
	inline point operator+(point p){ return {x + p.x, y + p.y}; }
	inline point operator-(point p){ return {x - p.x, y - p.y}; }
	inline point operator*(coord o){ return {x * o, y * o}; }
	inline point operator/(coord o){ return {x / o, y / o}; }
	inline void operator=(point p){ x = p.x, y = p.y; }

	inline coord operator*(point p){ return x * p.x + y * p.y; } // |a||b|cos(tht)
	inline coord operator^(point p){ return x * p.y - y * p.x; } // |a||b|sin(tht), this -> p

	inline int ccw(point p){ return sign(*this ^ p); } // ccw  1 left, 0 over, -1 right

	inline long double norm(){ return hypot(x, y); }
	inline coord norm2(){ return x * x + y * y; }

	inline point rot90(){return {-y, x}; }

	inline void print(){ cout<<x<<' '<<y<<'\n'; }
};

struct line {
	point p; coord c; //p * <x,y> = c
	line() {} line(point _p, coord _c): p(_p), c(_c) {}
	line(point a, point b) : p((b - a).rot90()), c(p * a) {}
	line get_parall(point v){ return line(p, p * v); }// parallel line at point v
	line get_perp(){ return line(p.rot90(), c); }// perpendicular line

	bool contains(point v){ return sign(p * v - c) == 0; }
	bool intsec(line l){ return sign(p ^ l.p) != 0; } // false if is the same line

	coord dist(point v){ return abs(p * v - c) / p.norm(); }

	point get_intsec(line l){ coord d = p^l.p; return point((c*l.p.y - l.c*p.y)/d, (p.x*l.c - c*l.p.x)/d); }
};

struct segment {
	point a, b; // a != b
	segment() {} segment(point _a, point _b): a(_a), b(_b) {}

	bool contains(point p){ return sign((p-a)^(b-a)) == 0 and sign((p-a)*(b-a)) >= 0 and sign((p-b)*(a-b)) >= 0; }
	bool intsec(segment q){ segment p = *this;
		if (p.contains(q.a) or p.contains(q.b) or q.contains(p.a) or q.contains(p.b)) return true;
		return p.ccw(q.a)*p.ccw(q.b) == -1 and q.ccw(p.a)*q.ccw(p.b) == -1;	
	}

	int ccw(point p){ return((b - a).ccw(p - a)); } // ccw  1 left, 0 over, -1 right  of seg a->b

	coord len2(){ return (a - b).norm2(); }
	coord dist(segment q){segment p = *this; 
		return p.intsec(q)? 0 : min({p.dist(q.a), p.dist(q.b), q.dist(p.a), q.dist(p.b)});	}
	coord dist(point p){
		if (sign(((p - a) * (b - a))) >= 0 and sign((p - b) * (a - b)) >= 0)
			return abs((p - a) ^ (b - a)) / (b - a).norm();
		return min((p - a).norm(), (p - b).norm());
	}

};

int s,k,w;
vector<point> kids;
vector<segment> wall;
int freq_w[100100];
point ori;
point swipe;

void reset(){
	kids.clear();
	wall.clear();
}

point get_point(pii a){
	point aa;
	if(a.fst == 2){
		aa = kids[a.snd];
	}
	else{
		ll sig = (wall[a.snd].a - ori)^(wall[a.snd].b - ori);
		//if(a.snd == 2186) dbg(sig);
		if(sig > 0 && a.fst == 0) aa = wall[a.snd].a;
		if(sig > 0 && a.fst == 1) aa = wall[a.snd].b;
		if(sig < 0 && a.fst == 0) aa = wall[a.snd].b;
		if(sig < 0 && a.fst == 1) aa = wall[a.snd].a;
	}
	return aa;
}
int get_quadrant(point a){
	if(a.y > ori.y ||(a.y == ori.y && a.x > ori.x)) return 1;
	return -1;
}

bool mycomp(pii a, pii b){
	point aa;
	point bb;
	aa = get_point(a);
	bb = get_point(b);

	int qa, qb;
	qa = get_quadrant(aa);
	qb = get_quadrant(bb);
	if(qa != qb){
		return qa > qb;
	}
	else{
		return (sign((aa - ori)^(bb - ori)) > 0);
	}
}

bool comp(int a,int b){
	line t = {ori, swipe};
	line sa = {wall[a].a, wall[a].b};
	line sb = {wall[b].a, wall[b].b};
	point aa = t.get_intsec(sa);
	point bb = t.get_intsec(sb);

	return (aa - ori).norm2() < (bb - ori).norm2();
}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return comp(lhs,rhs);}
};

void solve(int i){
	ori = kids[i];
	vector<pii> v;
	v.clear();

	fr(j,k){
		if(j != i) v.pb({2,j});
	}
	fr(j,w){
		v.pb({0,j});
		v.pb({1,j});
	}

	sort(all(v), mycomp);
	set<int, classcomp> ev;

	ev.clear();
	fr(i,w) freq_w[i] = 0;

	//swipe = get_point(v[0]);
	swipe = ori;
	swipe.x++;

	for(auto x: v){
		if(x.fst == 0) freq_w[x.snd]++;
		if(x.fst == 1 && freq_w[x.snd] != 1){
			ev.insert(x.snd);
		}
	}
	//int tt;
	//if(ev.size() > 1) tt = *(ev.begin());

	//for(auto x: v) get_point(x).print();

	int ans = 0;
	for(auto x: v){
		swipe = get_point(x);
		if(x.fst == 1){
			ev.erase(x.snd);
		}
		if(x.fst == 0){
			ev.insert(x.snd);
		}
		if(x.fst == 2){
			if(ev.empty()) ans++;
			else{
				int j = *(ev.begin());
				segment s = wall[j];
				segment t = {ori, kids[x.snd]};
				if(!s.intsec(t)) ans++;
			}
		}
	}
	cout << ans << endl;
}

int main(){

	fastio;

	while(cin >> s >> k >> w){
		reset();
		fr(i,k){
			point p;
			cin >> p.x >> p.y;
			kids.pb(p);
		}

		fr(i,w){
			point a,b;
			cin >> a.x >> a.y >> b.x >> b.y;
			segment s = {a,b};
			wall.pb(s); 
		}
		fr(i,s){
			solve(i);
		}
	}

}

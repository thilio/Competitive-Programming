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
typedef pair<pii,int> pi;

const int INF = 0x3f3f3f3f;
const ll llINF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9+7;

int dx[4] = {+1,-1,0,0},dy[4] = {0,0,+1,-1};
int r,c;
char cam[112][112];
int freq[112][112][20];

bool is(int x,int y){
	if(x>= 0 && x < r && y >=0 && y < c){
		if(cam[x][y] == '#') return false;
		return true;
	}
	return false;
}


void solve(){
	string s;
	int kx,ky;

	ms(freq,-1);
	getline(cin,s);
	fr(i,r){
		getline(cin,s);
		fr(j,c){
			cam[i][j] = s[j];
			if(cam[i][j] == '*'){
				kx = i;
				ky = j;
			}
		}
	}


	queue <pi> q;
	pi aux;
	aux.fst.fst = kx;
	aux.fst.snd = ky;
	aux.snd = 0;

	freq[kx][ky][aux.snd] = 0;

	int mask;

	q.push(aux);
	int ans = -1;


	while(!q.empty()){
		aux = q.front();
		q.pop();
		kx = aux.fst.fst;
		ky = aux.fst.snd;
		mask = aux.snd;

		int omask = mask;

		if(cam[kx][ky] == 'X'){
			ans = freq[kx][ky][mask];
			break;

		}

		if(cam[kx][ky] == 'g'){
			mask = mask|(1<<3);
		}

		if(cam[kx][ky] == 'r'){
			mask = mask|(1<<1);
		}

		if(cam[kx][ky] == 'y'){
			mask = mask|(1<<2);
		}

		if(cam[kx][ky] == 'b'){
			mask = mask|(1<<0);
		}

		fr(i,4){
			if(!is(kx + dx[i],ky + dy[i])) continue;
			if(freq[kx + dx[i]][ky + dy[i]][mask] != -1) continue;
			if(cam[kx + dx[i]][ky + dy[i]] == 'B' && (mask&(1<<0)) == 0) continue;
			if(cam[kx + dx[i]][ky + dy[i]] == 'R' && (mask&(1<<1)) == 0) continue;
			if(cam[kx + dx[i]][ky + dy[i]] == 'Y' && (mask&(1<<2)) == 0) continue;
			if(cam[kx + dx[i]][ky + dy[i]] == 'G' && (mask&(1<<3)) == 0) continue;

			pi h;
			h.fst.fst = kx + dx[i];
			h.fst.snd = ky + dy[i];
			h.snd = mask;
			q.push(h);
			freq[h.fst.fst][h.fst.snd][h.snd] = 1 + freq[kx][ky][omask];
		}
	}

	if(ans ==-1){
		cout <<"The poor student is trapped!" << endl;
	}

	else{
		cout << "Escape possible in " <<ans << " steps." << endl;
	}
	


}

int main(){

	fastio;

	cin >> r >> c;
	while(r!=0){
		solve();
		cin >> r >> c;
	}


}

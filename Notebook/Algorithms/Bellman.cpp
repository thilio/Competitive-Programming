#include "bits/stdc++.h"
using namespace std;

const int MAXN = 2500;
const int INF = 1e9;

int n,m;
vector<pair<int,pair<int,int>>> edge;
int v;

void Bellman(){
    vector<int> d (n + 1, INF);
    d[v] = 0;
    for (int i = 0; i< n-1; i++)
        for (int j = 0; j < m; j++)
            if (d[edge[j].second.first] < INF)
                d[edge[j].second.second] = min (d[edge[j].second.second], d[edge[j].second.first] + edge[j].first);
    
}

int main(){

}

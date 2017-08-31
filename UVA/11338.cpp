/*
 * main.cpp
 *
 *  Created on: Aug 31, 2017
 *      Author: ahmed
 */

#include <bits/stdc++.h>
#define MAX 10010
#define EPS 1e-100
using namespace std;
vector< pair<int, float> > adj[MAX];
bool vis[MAX];
int w,h,n;
float d;

struct Point {
	float x,y;
} P[MAX];

float dis(Point a, Point b) {
	return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}
float dist[MAX];

bool Dijkstra(int src) {
	dist[src] = 0;
	priority_queue< pair<float, int > > pq;
	pq.push({0.0, 0});

	while(pq.size()) {
		pair<float, int> top = pq.top(); pq.pop();
		int u = -1 * top.second;
		float d = -1 * top.first;

		if(d > dist[u]) continue;
		for(auto& x : adj[u]) {

			int v = x.first;
			float w = x.second;


			if((dist[v]-(dist[u]+w) > EPS)) {
				dist[v] = dist[u] + w;
				pq.push({-dist[v], -v});
			}
		}
	}

	return dist[n+1] <= d;
}

void solve() {

	for(auto& x : adj) x.clear();
	float MXF = numeric_limits<float>::max();
	fill(dist, dist+n+10, MXF);
	for(int i=0;i<=n+1;i++) for(int j=i+1;j<=n+1;j++) {

		float dst = dis(P[i], P[j]);

		if(dst <= 1.5) {

			adj[i].push_back({ j, dst });
			adj[j].push_back({ i, dst });
		}
	}
	printf((Dijkstra(0) ? "I am lucky!\n": "Boom!\n"));
}
int main() {


	//freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	while((scanf("%d%d", &w, &h)) == 2) {

		scanf("%d", &n);

		P[0].x = 0, P[0].y = 0;
		P[n+1].x = w, P[n+1].y = h;

		int i;
		for(i=1;i<=n;i++) {
			scanf("%f%f", &P[i].x, &P[i].y);
		}

		scanf("%f", &d);

		solve();
	}
	return 0;
}


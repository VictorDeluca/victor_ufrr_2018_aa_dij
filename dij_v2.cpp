#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int graph[1001][1001],n,e; //Limite de 1000 vertices

vector<int> dijkstra(int source){
	vector<int> dist(n,INF); vector<int> pai(n,INF); dist[source] = 0;
	set<pair<int,int> > Q; Q.insert(make_pair(dist[source],source));
	while(!Q.empty()){
		set<pair<int,int> >::iterator top = Q.begin();
		int u = top->second;
		Q.erase(top);
	
		for(int i=0;i<n;i++){
			int cost = graph[u][i];
			if(graph[u][i] != INF && dist[u] + cost < dist[i]){
				if(Q.find(make_pair(dist[i],i))!=Q.end()) Q.erase(Q.find(make_pair(dist[i],i)));
				dist[i] = dist[u] + cost;
				pai[i] = u;
				Q.insert(make_pair(dist[i],i));
			}
		}
	}

	return pai;
}

int main(){
	int i,j; FILE *f = fopen("input.txt","r");
	while(1){
		fscanf(f,"%d%d",&n,&e);
		if(n==0 && e==0) break;
		for(i=0;i<n;i++) for(j=0;j<n;j++) graph[i][j] = INF;

		for(i=0;i<e;i++){
			int x,y,h; fscanf(f,"%d%d%d",&x,&y,&h); x--; y--;
			graph[x][y] = h;
		}

		int k; fscanf(f,"%d",&k);
		for(i=0;i<k;i++){
			int o,d; fscanf(f,"%d%d",&o,&d); o--; d--;
			vector<int> ans = dijkstra(o);
			if(ans[d]==INF) printf("Nao existe caminho entre os dois pontos\n");
			else{
				while(d!=o){
					printf("%d <- ",d+1);
					d = ans[d];
				}
				printf("%d\n",o+1);
			}
		}
		printf("\n");
	}
	fclose(f);

	return 0;
}

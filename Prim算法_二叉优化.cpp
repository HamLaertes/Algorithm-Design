#include <iostream>
#include <vector>
#include <queue>
#define INF 0xfffffff
#define MAXN 100+10

using namespace std;

struct Point{
    int v, weight;
    Point(int v=0, int weight=0):v(v),weight(weight){}
    bool operator < (const Point& p) const{
        return this->weight > p.weight;
    }
};

vector<Point> graph[MAXN];
bool inTree[MAXN];
int mindist[MAXN];

void Init(int n){
    for (int i = 1; i <= n; i++){
        mindist[i] = INF;
        inTree[i] = false;
        graph[i].clear();
    }
}

int Prim(int s, int n){
    priority_queue<Point> q;
    Point temp;
    int res = 0;
    inTree[s] = true;
    for (int i = 0; i < graph[s].size(); i++){
        int v = graph[s][i].v;
        if(graph[s][i].weight < mindist[v]){
            mindist[v] = graph[s][i].weight;
            q.push(Point(v, mindist[v]));
        }
    }
    //q中存了到所有被发现的点的距离（如有多种路径，则取最小的）
    while(!q.empty()){
        temp = q.top();
        q.pop();
        int addNode = temp.v;
        if(inTree[addNode])
            continue;
        inTree[addNode] = true;
        res += mindist[addNode];
        //重复上面那个循环，过呢更新到集合的距离
        for (int i = 0; i< graph[addNode].size(); i++){
            int tempPoint = graph[addNode][i].v;
            if(!inTree[tempPoint] && mindist[tempPoint] > graph[addNode][i].weight){
                mindist[tempPoint] = graph[addNode][i].weight;
                q.push(Point(tempPoint, mindist[tempPoint]));
            }
        }
    }
    return res;
}

int main(){
    int n;
    int v1, v2, weight;
    printf("Total point number:");
    scanf("%d", &n);
    printf("Total side number:");
    int m;
    scanf("%d", &m);
    Init(n);
    for (int i = 0; i < m; i++){//n个点的完全图，边数一共n*(n-1)/2
        scanf("%d %d %d", &v1, &v2, &weight);
        graph[v1].push_back(Point(v2, weight));
        graph[v2].push_back(Point(v1, weight));
    }
    printf("The length of minimum cost path:%d\n", Prim(1, n));
    for (int i = 0; i < n; i++){
        if(inTree[i])
            printf("%d ", i);
    }
        return 0;
}
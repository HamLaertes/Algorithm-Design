#include <iostream>
#include <string.h>

using namespace std;

int  matrix[100][100]; // 邻接矩阵
bool visited[100];     // 标记数组
int  dist[100];        // 源点到顶点i的最短距离
int  path[100];        // 记录最短路的路径
int  source;           // 源点
int  vertex_num;       // 顶点数
int  edge_num;         // 边数

void Dijkstra(int source){
    memset(visited, 0, sizeof(visited));  // 初始化标记数组
    visited[source] = true;
    for (int i = 0; i < vertex_num; i++){
        dist[i] = matrix[source][i];
        path[i] = source;
    }
    int min_cost;        // 权值最小
    int min_cost_index;  // 权值最小的下标
    for (int i = 1; i < vertex_num; i++){ // 找到源点到另外 vertex_num-1 个点的最短路径
        min_cost = INT_MAX;
        for (int j = 0; j < vertex_num; j++){
            if (visited[j] == false && dist[j] < min_cost){  // 找到权值最小
                min_cost = dist[j];
                min_cost_index = j;
            }
        }
        visited[min_cost_index] = true;  // 该点已找到，进行标记
        for (int j = 0; j < vertex_num; j++){// 更新 dist 数组
            if (visited[j] == false &&
                matrix[min_cost_index][j] != INT_MAX &&  // 确保两点之间有边
                matrix[min_cost_index][j] + min_cost < dist[j]){ //选择最短的一个路径
                dist[j] = matrix[min_cost_index][j] + min_cost;
                path[j] = min_cost_index;
            }
        }
    }
}

int main()
{
    cout << "Total Point Number on the Graph:";
    cin >> vertex_num;
    cout << "Total Edge Number on the Graph:";
    cin >> edge_num;
    for (int i = 0; i < vertex_num; i++)
        for (int j = 0; j < vertex_num; j++)
            matrix[i][j] = (i != j) ? INT_MAX : 0;  // 初始化 matrix 数组,一开始互相独立，设为无穷大

    cout << "Please Input the edge information:\n";
    int u, v, w;
    for (int i = 0; i < edge_num; i++){
        cin >> u >> v >> w;
        matrix[u][v] = matrix[v][u] = w;
    }
    cout << "Source Number:";
    cin >> source;
    Dijkstra(source);
    for (int i = 0; i < vertex_num; i++){
        if (i != source){
            cout << source << "The closest path costs:" << dist[i] << "And it is:" << i;
            int t = path[i];
            while (t != source){
                cout << "--" << t;
                t = path[t];
            }
            cout << "--" << source << endl;
        }
    }
    return 0;
}
// 图论，岛屿数量

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void DFS(std::vector<std::vector<int>>& graph, int x, int y) {
        std::vector<int> X{1, -1, 0, 0};
        std::vector<int> Y{0, 0, 1, -1};

        for(int i = 0; i < 4; i++){
            int next_x = x + X[i];
            int next_y = y + Y[i];
            if(next_x < 0 || next_x >= graph.size() || next_y < 0 || next_y >= graph[i].size()){
                continue;
            }
            if(1 == graph[next_x][next_y]){
                graph[next_x][next_y] = 2;
                DFS(graph, next_x, next_y);
            }
        }
    }

    int countIsland(std::vector<std::vector<int>>& graph){
        int count = 0;
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                if(1 == graph[i][j]){
                    graph[i][j] = 2;
                    ++count;
                    DFS(graph, i, j);
                }
            }
        }
        return count;
    }
};


int main() {
    std::vector<std::vector<int>> graph;
    graph.emplace_back(std::vector<int>{1,1,1,1,0});
    graph.emplace_back(std::vector<int>{1,1,0,1,0});
    graph.emplace_back(std::vector<int>{1,1,0,0,0});
    graph.emplace_back(std::vector<int>{0,0,0,1,0});

    Solution solution;
    int result = solution.countIsland(graph);
    cout << result << endl;

    return 0;
}
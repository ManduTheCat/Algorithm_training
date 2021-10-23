#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool adj_arr[2000][2000];
vector<int> adj_list[2000];
vector<pair<int,int>> edges_list;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int from, to;
        cin >> from >> to;
        edges_list.push_back({from, to});
        edges_list.push_back({to, from});
        adj_arr[from][to] = adj_arr[to][from] = true;
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    m *= 2;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            // A -> B
            int A = edges_list[i].first;
            int B = edges_list[i].second;
            // C -> D
            int C = edges_list[j].first;
            int D = edges_list[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if (!adj_arr[B][C]) {
                continue;
            }
            // D -> E
            for (int E : adj_list[D]) {
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}

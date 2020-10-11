#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<iterator>

using namespace std;

class Graph {
    
    int numV;
    list<int> *adj_list;
    vector<int> visited;
    vector<int> parent;
    vector<int> level;
    queue<int> queue;

    public:

        Graph(int numV) {
            this->numV = numV;
            adj_list = new list<int>[numV];
        }

        void add_edge(int x, int y) {
            adj_list[x].push_back(y);
            adj_list[y].push_back(x);
        }
        void print_graph() {
            for (int i = 0; i < numV; ++i) {
                cout<< i << "->";
                // for (int nbr:adj_list[i])
                //     cout<<nbr<< " ";
                list<int>::iterator j;
                for (j = adj_list[i].begin(); j != adj_list[i].end(); ++j) {
                    cout<< *j << " ";
                }
                cout<<"\n";
            }
        }

        void bfs_traversal(int i) {
            for (int j = 0; j < numV; ++j) {
                visited.push_back(0);
            }

            visited[i] = 1;
            queue.push(i);

            while (!queue.empty()) {
                int j = queue.front();
                cout<< j << " ";
                queue.pop();
                for (list<int>::iterator k = adj_list[j].begin(); k != adj_list[j].end(); ++k)  {
                    if (visited[*k] == 0) {
                        visited[*k] = 1;
                        queue.push(*k);
                        // cout<< *k << " ";
                    }

                }
                // cout<< endl;
            }

        }

        void bfs_traversal_enhanced(int i) {
            for (int j = 0; j < numV; ++j) {
                level[j] = -1;
                parent[j] = -1;
            }

            level[i] = 0;
            queue.push(i);

            while (!queue.empty()) {
                int j = queue.front();
                cout<< j << " ";
                queue.pop();
                for (list<int>::iterator k = adj_list[j].begin(); k != adj_list[j].end(); ++k)  {
                    if (level[*k] == -1) {
                        level[*k] = 1 + level[j];
                        parent[*k] = j;
                        queue.push(*k);
                        // cout<< *k << " ";
                    }

                }
                // cout<< endl;
            }

        }
};



int main() {
    Graph graph(5);
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,3);
    graph.add_edge(2,3);
    graph.add_edge(3,4);
    
    graph.print_graph();

    cout<< endl;

    graph.bfs_traversal(4);

    return 0;
}
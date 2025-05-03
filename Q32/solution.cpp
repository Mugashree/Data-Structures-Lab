
//Program to implement adjacency list


#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>


using namespace std;


class Graph {
    int V;
    vector<list<int>> adj;


public:
    Graph(int v) {
        V = v;
        adj.resize(V);
    }


    void AddE(int, int);
    void DelE(int, int);
    void SearchE(int, int);
    void Display();
};


void Graph::AddE(int a, int b) {
    if (a >= V || b >= V || a < 0 || b < 0) {
        printf("Invalid vertices.\n");
        return;
    }


    adj[a].push_back(b);
    adj[b].push_back(a);
    printf("Edge added between %d and %d\n", a, b);
}


void Graph::DelE(int a, int b) {
    if (a >= V || b >= V || a < 0 || b < 0) {
        printf("Invalid vertices.\n");
        return;
    }


    adj[a].remove(b);
    adj[b].remove(a);
    printf("Edge between %d and %d is deleted.\n", a, b);
}


void Graph::SearchE(int a, int b) {
    if (a >= V || b >= V || a < 0 || b < 0) {
        printf("Invalid vertices.\n");
        return;
    }


    for (int node : adj[a]) {
        if (node == b) {
            printf("Edge exists between %d and %d\n", a, b);
            return;
        }
    }
    printf("No edge exists between %d and %d\n", a, b);
}


void Graph::Display() {
    for (int i = 0; i < V; i++) {
        printf("%d -> ", i);
        for (int node : adj[i]) {
            printf("%d ", node);
        }
        printf("\n");
    }
}


int main() {
    int V;
    printf("Enter the number of vertices: \n");
    scanf("%d", &V);
    Graph g(V);
    int chc, a, b;


    while (1) {
        printf("\n\n MENU: \n");
        printf(" 1. Insert Edge \n 2. Delete Edge \n 3. Search \n 4. Display \n 5. Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &chc);


        switch (chc) {
            case 1:
                printf("Enter the vertices a and b: \n");
                scanf("%d %d", &a, &b);
                g.AddE(a, b);
                break;


            case 2:
                printf("Enter the vertices a and b: \n");
                scanf("%d %d", &a, &b);
                g.DelE(a, b);
                break;


            case 3:
                printf("Enter the vertices a and b: \n");
                scanf("%d %d", &a, &b);
                g.SearchE(a, b);
                break;


            case 4:
                g.Display();
                break;


            case 5:
                printf("Exiting the program...\n");
                return 0;


            default:
                printf("Invalid choice. \n");
        }
    }
}

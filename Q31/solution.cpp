//Program to implement adjacency matrix


#include <cstdio>
#define max 10


class Graph{
    
    int mat[max][max];
    int v;


    public:


    Graph(){
        v = 0;
        for(int i = 0; i < max; i++){
            for(int j = 0; j < max; j ++){
                mat[i][j] = 0;
            }
        }
        }


        void AddV();
        void AddE(int,int);
        void DelE(int,int);
        void SearchE(int,int);
        void Display();




};


int main(){


    Graph g;
    int chc, a, b;


    while(1){
        
        printf("\n\n MENU: \n");
        printf(" 1. Insert Vertex\n 2. Insert Edge \n 3. Delete Edge \n 4. Search \n 5. Display \n 6. Exit \n");
        printf("Enter your choice: \n");
        scanf("%d", &chc);


        switch(chc){


            case 1:


            g.AddV();
            break;


            case 2:


            printf("Enter the vertices a and b: \n");
            scanf("%d %d", &a, &b);
            g.AddE(a,b);
            break;


            case 3:
            
            printf("Enter the vertices a and b: \n");
            scanf("%d %d", &a, &b);
            g.DelE(a,b);
            break;


            case 4:
            printf("Enter the vertices a and b: \n");
            scanf("%d %d", &a, &b);
            g.SearchE(a,b);
            break;


            case 5:
            g.Display();
            break;


            case 6:
            printf("Exiting the program...\n");
            return 0;
            break;


            default:
            printf("Invalid choice. \n");


        }
    }
}


void Graph :: AddV(){


    if(v > max){
        printf("Maximum no. of vertices reached.\n");
        return;
    }


    printf("Vertex %d added.\n", v);
    v++;
}


void Graph :: AddE(int a, int b){


    if(a < 0 || b < 0 || a >= v || b >= v){
        printf("Invalid vertices.\n");
        return;
    }


    mat[a][b] = mat[b][a] = 1;
    printf("Edge added between %d and %d", a,b);
}


void Graph :: DelE(int a, int b){


    if(a < 0 || b < 0 || a >= v || b >= v || mat[a][b] == 0){
        printf("No edges to delete.\n");
        return;
    }


    mat[a][b] = mat[b][a] = 0;
    printf("Edge between %d and %d is deleted.\n", a, b);


}


void Graph :: SearchE(int a, int b){


    if(a < 0 || b < 0 || a >= v || b >= v){
        printf("Invalid vertices.\n");
        return;
    }


    if(mat[a][b]){
        printf("Edge exists between %d and %d\n", a, b);
    }
    else{
        printf("No edge exists.\n");
    }
}


void Graph :: Display(){
    printf("Adjacency Matrix: \n");


    for(int i = 0; i < v; i ++){
        for(int j = 0; j < v; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

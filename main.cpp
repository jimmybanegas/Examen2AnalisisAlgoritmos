#include "Test.h"
#include <iostream>
#include "Edge.h"
using namespace std;

int cont = 0;

vector<Edge> getEdges(int ** graph, int size)
{
    vector<Edge> edges;
    for (int i = 0; i <size; i++)
        for (int j = 0; j < size; j++)
            if(graph[i][j]!=-1)
            {
                Edge edge(i,j,graph[i][j]);
                edges.push_back(edge);
            }
    return edges;
}

void findPath(int destination,vector<Edge> edges,int initialDestination){
   printf("%d \n",destination);

   for(int x = 0; x< edges.size(); x++){
        if(initialDestination == edges[x].destination){
            cont+=1;
            break;
        }
        if(edges[x].source == destination){
            findPath(edges[x].destination,edges,initialDestination);
        }
   }
}

//Counts the number of posibles paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int countPaths(int** DAG, int size, int origin, int destination)
{
      cont = 0;
      printf("origin %d \n",origin);
      printf("destination %d \n",destination);
     // cont = 0;
   // return -1;
   vector<Edge> edges = getEdges(DAG,size);
 //  printf (" edges size %d", edges.size());


    for (int j = 0; j <edges.size(); j++)
    {
        int u = edges[j].source;
        int v = edges[j].destination;
        int weight = edges[j].weight;

       if(cont > 0)
            break;

        if(edges[j].source == origin){

            printf("\n source %d",u);
            printf(" destination %d",v);
            printf(" weight %d  \n",weight);

            findPath(edges[j].destination,edges,destination);
        }

        printf("cont al salir %d \n", cont);

    }

    return cont+1;
}

//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    return answer;
}

int main ()
{
    test();
    return 0;
}

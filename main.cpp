#include "Test.h"
#include <iostream>
using namespace std;

int cont;

void countPaths(int** DAG, int size, int origin, int destination, int current)
{
    for(int i=0; i<size; i++)
    {
        if(DAG[current][i] != -1)
        {
            if(destination == i)
                cont++;
            countPaths(DAG,size,origin,destination,i);
        }
    }
}

//Counts the number of posibles paths from origin to destination in the given DAG (Directed Acyclic Graph)
//Use Dynamic Programing to optimize the process
int countPaths(int** DAG, int size, int origin, int destination)
{
    cont = 0;
    countPaths(DAG,size,origin,destination,origin);
    return cont;
}


//Returns a vector that maps each vertex to a color (or number)
//Two adjacent vertex cannot have the same color
//The less colors used, the better
//Use a Greedy Paradigm to optimize the process
//The best solution is not required
vector<int> getVertexColors(int** graph, int size)
{
    vector<int> answer;
    for(int k = 0; k < size; ++k) {
        answer.push_back(0);
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(graph[i][j] != -1 && answer[i] == answer[j])
                answer[j] = i+1;
        }
    }
    return answer;
}

int main ()
{
    test();
    return 0;
}

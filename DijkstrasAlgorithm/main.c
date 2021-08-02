#include <stdio.h>
#include <limits.h>

#define VERTICES        7
#define INF             INT_MAX
#define INVALID_VERTEX  -1
#define V1        0
#define V2        1
#define V3        2
#define V4        3
#define V5        4
#define V6        5
#define V7        6

#define TRUE    1
#define FALSE   0

#define KNOWN   TRUE
#define UNKNOWN FALSE

typedef int BOOL;

/* GLOBAL DATA */
BOOL known[VERTICES];
int min_costs[VERTICES];
int previous_vertex[VERTICES];

int graph[VERTICES][VERTICES] = {
                                         //   v1    v2   v3   v4   v5    v6   v7
                                    /*v1*/ { INF,   2,   INF, 1,   INF,  INF, INF  },
                                    /*v2*/ { INF,   INF, INF, 3,   10,   INF, INF  },
                                    /*v3*/ { 4,     INF, INF, INF, INF,  5,   INF  },
                                    /*v4*/ { INF,   INF, 2,   INF, 2,    8,   4  },
                                    /*v5*/ { INF,   INF, INF, INF, INF,  INF, 6  },
                                    /*v6*/ { INF,   INF, INF, INF, INF,  INF, INF  },
                                    /*v7*/ { INF,   INF, INF, INF, INF,  1,   INF  },

                                    };



void InitalizeUtilityData();
void DijkstrasShortestPath(int start_vertex);
int FindSmallestUnknown();
void PrintMinCosts(int start_vertex);
void PrintPreviousVertex();

void InitalizeUtilityData()
{
    int i;

    for (i = 0; i < VERTICES; ++i) {
        known[i] = UNKNOWN;
        min_costs[i] = INF;
        previous_vertex[i] = INVALID_VERTEX;
    }
}

int FindSmallestUnknown()
{
    int i;
    int min_cost = INF;
    int min_cost_vertex = INVALID_VERTEX;

    for (i = 0; i < VERTICES; ++i) {
        if (UNKNOWN == known[i])
            if (min_costs[i] < min_cost) {
                min_cost = min_costs[i];
                min_cost_vertex = i;
            }
    }

    return min_cost_vertex;
}



void DijkstrasShortestPath(int start_vertex)
{
    int min_cost_vertex;
    int i, cost;

    // Set start vertex' cost as 0 (min)
    min_costs[start_vertex] = 0;

    // Find "min cost vertex" "among unknown ones"
    while (INVALID_VERTEX != (min_cost_vertex = FindSmallestUnknown())) {

        // Make "KNOWN" selected vertex
        known[min_cost_vertex] = KNOWN;

        // Check selected vertex' neighbors
        for (i = 0; i < VERTICES; ++i) {
            // Check UNKNOWN neighbors
            // INF != graph_weiss[min_cost_vertex][i] : means "i" is a neighbor of min_cost_vertex
            if (INF != graph[min_cost_vertex][i] && UNKNOWN == known[i]) {
                // UNKNOWN neighbor's cost from selected vertex
                cost = graph[min_cost_vertex][i];

                // If cost of neigbor can be lowered then set this new cost as the
                // current min cost of it (i.e neighbor's)
                if (min_costs[min_cost_vertex] + cost < min_costs[i]) {
                    min_costs[i] = min_costs[min_cost_vertex] + cost;
                    previous_vertex[i] = min_cost_vertex;
                }
            } // if
        }// for
    }// while
}

void PrintMinCosts(int start_vertex)
{
    int i;

    for (i = 0; i < VERTICES; ++i)
        printf("V%d's min cost from %d is %d\n", (i + 1), start_vertex, min_costs[i] );
}

void PrintPreviousVertex()
{
    int i;

    for (i = 0; i < VERTICES; ++i)
        printf("V%d's previous vertex is V%d\n", (i + 1), (previous_vertex[i] + 1) );
}

void PrintPath(int vertex)
{
    if (INVALID_VERTEX != vertex) {
        PrintPath(previous_vertex[vertex]);
        printf("V%d -> ", (vertex + 1));
    }

}


int main()
{
    int i;

    InitalizeUtilityData();

    DijkstrasShortestPath(V1);

    PrintMinCosts(V1);
    printf("-----------------\n");

    PrintPreviousVertex();
    printf("-----------------\n");

    printf("PATHS\n");
    for (i = 0; i < VERTICES; ++i) {
        printf("PATH to reach V%d is ", (i + 1));
        PrintPath(i);
        printf(" %d (min. cost) \n", min_costs[i]);
    }

    return 0;
}

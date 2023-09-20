#include "common.h"

char **AddEdge(char **, int, int);
char **PrintGraph(char **, int);

int main(int argc, char **argv)
{
	char **matrix = NULL;
	int vertexNum = 0, edgeNum = 0;
	int buffer1 = 0, buffer2 = 0;

	printf("(Vertices, Edges) = ");
	scanf("%d %d", &vertexNum, &edgeNum);
	matrix = (char **)malloc(sizeof(char *)*vertexNum);
	for (int i=0 ; i<vertexNum ; i++){
		matrix[i] = (char *)malloc(sizeof(char)*vertexNum);
	}

	for (int i=0 ; i<edgeNum ; i++){
		printf("[Edge%d] (NodeA, NodeB) = ", i+1);
		scanf("%d %d", &buffer1, &buffer2);
		AddEdge(matrix, buffer1, buffer2);
	}

	PrintGraph(matrix, vertexNum);

	return 0;
}

char **AddEdge(char **graphArg, int rowArg, int colArg)
{
	//Exception Handling
	if (graphArg == NULL)
		return NULL;

	graphArg[rowArg][colArg] = 1;
	graphArg[colArg][rowArg] = 1;

	return graphArg;
}

char **PrintGraph(char **graphArg, int sizeArg)
{
	for (int i=0; i<sizeArg ; i++){
		for (int j=0; j<sizeArg; j++){
			printf("%d ", (int)(graphArg[i][j]));
		}
		printf("\n");
	}
	return graphArg;
}

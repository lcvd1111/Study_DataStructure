#include "mylib.h"

#define USE_FILE

int main(int argc, char **argv)
{
	int nodeNum = 0;
	int edgeNum = 0;
	char inputNode1[STRING_LEN]={0,}, inputNode2[STRING_LEN]={0,};
	NODE *tempNode = NULL;

	GRAPH testGraph;
#ifdef USE_FILE
	freopen("testInput.txt", "r", stdin);
#endif
#ifndef USE_FILE
	printf("(Node Number, Edge Number): ");
#endif
	scanf("%d %d", &nodeNum, &edgeNum);

	Constructor_Graph(&testGraph, (long int)nodeNum);

	for (int i=0; i<edgeNum ; i++){
#ifndef USE_FILE
		printf("[Edge%d](Node X, Node Y): ", i+1);
#endif
		scanf("%s %s", inputNode1, inputNode2);

		if (testGraph.GetIndex(&testGraph, inputNode1) == -9999){
			if(testGraph.AddVertex(&testGraph, inputNode1)==NULL){
				printf("Graph is full already.\n");
				printf("%s can't be inserted.\n", inputNode1);
				break;
			}
		}

		if (testGraph.GetIndex(&testGraph, inputNode2) == -9999){
			if(testGraph.AddVertex(&testGraph, inputNode2)==NULL){
				printf("Graph is full already.\n");
				printf("%s can't be inserted.\n", inputNode2);
				break;
			}
		}

		if(testGraph.AddEdge(&testGraph, testGraph.GetIndex(&testGraph, inputNode1), testGraph.GetIndex(&testGraph, inputNode2)) == NULL){
			DEBUG("ERROR: AddEdge Failed.\n");
			return -1;
		}
	}

	//Printing the graph
	for (int i=0;  i<testGraph.currentSize ; i++){
		printf("[Vertx%d]:%s [Linked Vertexes]:", i+1, testGraph.vertexList[i]->name);
		tempNode = testGraph.vertexList[i];
		while (1){
			if (tempNode != testGraph.vertexList[i]){
				printf("%s ", tempNode->name);
			}
			if (tempNode->next == NULL)
				break;
			tempNode = tempNode->next;
		}
		printf("\n");
	}
	
	if (Destructor_Graph(&testGraph)){
		DEBUG("ERROR: Destructor Failed.\n");
		return -9999;
	}
	return 0;
}

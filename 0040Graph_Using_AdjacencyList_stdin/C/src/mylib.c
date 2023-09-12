#include "mylib.h"

//Function Declarations
GRAPH Constructor_Graph(GRAPH *self, long int sizeArg)
{
	GRAPH ret;

	if (self == NULL) //When the return value is exploited
	{
		ret.maxSize = sizeArg;
		ret.currentSize = 0;
		ret.vertexList = (GRAPH_NODE **)malloc(sizeof(GRAPH_NODE *)*sizeArg);

		ret.GetIndex = &Method_GetIndex;
		ret.AddVertex = &Method_AddVertex;
		ret.AddEdge = &Method_AddEdge;

		return ret;
	}
	
	self->maxSize = sizeArg;
	self->currentSize = 0;
	self->vertexList = (GRAPH_NODE **)malloc(sizeof(GRAPH_NODE *)*sizeArg);
	
	self->GetIndex = &Method_GetIndex;
	self->AddVertex = &Method_AddVertex;
	self->AddEdge = &Method_AddEdge;

	return *self;
}

int Destructor_Graph(GRAPH *self)
{
	NODE **tempArray = NULL;
	NODE *tempNode = NULL;

	if (self==NULL)
		return -1;

	if (self->vertexList == NULL){
		return -2;
	}

	if (self->currentSize==0){
		free(self->vertexList);
		return 0;
	}

	tempArray = self->vertexList;

	for (long int i=0; i<(self->currentSize) ; i++){
		if (tempArray[i]==NULL)
			break;

		tempNode = tempArray[i];
		while(1){
			if (tempNode->next == NULL){
				free(tempNode);
				break;
			}
			tempNode = tempNode->next;
			free(tempNode->prev);
		}
	}

	self->vertexList = NULL;
	return 0;
}

long int Method_GetIndex(GRAPH *self, char *nameArg)
{
	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->vertexList is NULL.\n");
		return -2;
	}

	//When the Graph is empty.
	if (self->currentSize == 0){
		return -9999;
	}

	//Simple Linear Search
	for (long int i=0;  i<(self->currentSize) ; i++){
		if (strcmp((self->vertexList)[i]->name, nameArg) == 0){
			return i;
		}
	}

	return -9999;
}

GRAPH *Method_AddVertex(GRAPH *self, char *nameArg)
{
	NODE **tempArray = NULL;
	long int tempIndex = 0;

	//Exception Handling
	if (self == NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->veretxList is NULL.\n");
		return NULL;
	}

	//When the Graph is FULL
	if (self->currentSize == self->maxSize){
		return NULL;
	}

	tempIndex =self->GetIndex(self, nameArg);
	//When there already exists a vertex with same name in the graph
	if (tempIndex >= 0){
		return NULL;
	}

	//Exception Handling
	if (tempIndex != -9999){
		DEBUG("ERROR: GetIndex( ) failed.\n");
		return NULL;
	}

	tempArray = self->vertexList;

	//Excpetion Handling
	if (tempArray[self->currentSize] != NULL){
		DEBUG("ERROR: tempArray[self->currentSize] is not NULL.\n");
		return NULL;
	}

	tempArray[self->currentSize] = (NODE *)malloc(sizeof(NODE));
	(tempArray[self->currentSize])->next = NULL;
	(tempArray[self->currentSize])->prev = NULL;
	strncpy((tempArray[self->currentSize])->name, nameArg, STRING_LEN);
	self->currentSize += 1;

	return self;
}

GRAPH *Method_AddEdge(GRAPH *self, long int indexA, long int indexB)
{
	NODE **tempArray = NULL;
	NODE *tempNode = NULL;
	char bufferA[STRING_LEN];
	char bufferB[STRING_LEN];
	//Exception Handling
	if (self==NULL){
		DEBUG("ERROR: self is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (self->vertexList == NULL){
		DEBUG("ERROR: self->vertexList is NULL.\n");
		return NULL;
	}

	tempArray = self->vertexList;

	//Exception Handling3
	if (indexA > self->currentSize-1){
		DEBUG("ERROR: indexA > currentSize-1\n");
		return NULL;
	}

	//Exception Handling4
	if (indexB > self->currentSize-1){
		DEBUG("ERROR: indexB > currentSize-1\n");
		return NULL;
	}

	//Exception Handling5
	if (tempArray[indexA] == NULL){
		DEBUG("ERROR: tempArray[indexA] is NULL\n");
		return NULL;
	}
	
	//Exception Handling6
	if (tempArray[indexB] == NULL){
		DEBUG("ERROR: tempArray[indexB] is NULL\n");
		return NULL;
	}

	//Save the node name to buffer
	strncpy(bufferA, tempArray[indexA]->name, STRING_LEN); 
	strncpy(bufferB, tempArray[indexB]->name, STRING_LEN);

	//Add linked list node
	tempNode = tempArray[indexA];
	while(1){
		if ( (strcmp(tempNode->name, bufferB)==0) && (tempNode != tempArray[indexA]) ){
			//When the edge already exists.
			return NULL;
		}
		if (tempNode->next == NULL){
			break;
		}
		tempNode = tempNode->next;
	}

	tempNode->next = (NODE *)malloc(sizeof(NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	strncpy(tempNode->next->name, bufferB, STRING_LEN);

	tempNode = tempArray[indexB];
	while(1){
		if (tempNode->next == NULL){
			break;
		}
		tempNode = tempNode->next;
	}

	tempNode->next = (NODE *)malloc(sizeof(NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	strncpy(tempNode->next->name, bufferA, STRING_LEN);

	return self;
}

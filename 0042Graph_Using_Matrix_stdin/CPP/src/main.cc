#include "common.hh"
#define ERROR std::cout<<"["<<__func__<<", "<<__LINE__<<"] ERROR:"
class GRAPH {
public:
	char **matrix;
	int size;

	GRAPH(void);
	GRAPH(int);
	~GRAPH(void);
	GRAPH *AddEdge(int, int);
	GRAPH *Print(void);
};


int main(int argc, char **argv)
{
	int sizeNum=0, edgeNum=0;
	int buffer1=0, buffer2=0;

	std::cout << "(Vertices, Edges) = " ;
	std::cin >> sizeNum >> edgeNum;

	GRAPH myGraph(sizeNum);

//std::cout << "myGraph.size: " << myGraph.size << std::endl;

	for (int i=0; i<edgeNum ; i++){
		std::cout << "[Edge" << i+1 << "]" << "(nodeA, nodeB) = " ;
		std::cin >> buffer1 >> buffer2;
		myGraph.AddEdge(buffer1, buffer2);
	}

	myGraph.Print();

	return 0;
}

GRAPH::GRAPH(void)
{
	(*this).matrix = NULL;
	(*this).size = 0;
//std::cout << "void CONSTRUCTOR called." << std::endl;
	return ;
}

GRAPH::GRAPH(int sizeArg)
{
	//Exception Handling
	if (sizeArg < 1){
		ERROR << "sizeArg < 1." << std::endl;
		(*this).matrix = NULL;
		return;
	}

//std::cout << "non-void CONSTRUCTOR called. sizeArg: " << sizeArg << std::endl;

	(*this).size = sizeArg;
	(*this).matrix = new char *[sizeArg];
//std::cout << "size: " << (*this).size << std::endl;

	for (int i=0; i<sizeArg ; i++){
		((*this).matrix)[i] = new char [sizeArg];
		for (int j=0 ; j<sizeArg ; j++){
			((*this).matrix)[i][j] = 0;
		}
	}

	return ;
}

GRAPH::~GRAPH(void)
{
	if ((*this).matrix == NULL){
//std::cout << "DESTRUCTOR TEST1" << std::endl;
		return ;
	}

//std::cout << "DESTRUCTOR TEST2. size: " << (*this).size << std::endl;
	for (int i=0; i < ((*this).size) ; i++){
		delete[] ((*this).matrix)[i];
	}

	delete[] ((*this).matrix);

	return ;
}

GRAPH *GRAPH::AddEdge(int rowArg, int colArg)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		ERROR << "(*this).matrix is NULL." << std::endl;
		return NULL;
	}

	if (rowArg >= (*this).size){
		ERROR << "rowArg >= size." << std::endl;
		return NULL;
	}

	if (colArg >= (*this).size){
		ERROR << "colArg >= size." << std::endl;
		return NULL;
	}

	((*this).matrix)[rowArg][colArg] = 1;
	((*this).matrix)[colArg][rowArg] = 1;

	return this;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		ERROR << "(*this).matrix is NULL." << std::endl;
		return NULL;
	}

	for (int i=0 ; i<(*this).size ; i++){
		for (int j=0 ; j<(*this).size ; j++){
			std::cout << (int)(((*this).matrix)[i][j]) << " ";
		}
		std::cout << std::endl;
	}
	return this;
}

#include "mylib.hh"

GRAPH::_GRAPH(void)
{
	(*this).matrix = NULL;
	DEBUG<<"ERROR: Positivie Integer must be inputted in constructor."<<std::endl;
}

GRAPH::_GRAPH(int sizeArg)
{
	//Exception Handling
	if (sizeArg<1){
		DEBUG<<"ERROR: sizeArg < 1." << std::endl;
		(*this).matrix = NULL;
		return;
	}

	(*this).size = sizeArg;

	(*this).matrix = new char *[sizeArg];

	for (int i=0; i<sizeArg; i++){
		(*this).matrix[i] = new char [sizeArg];
		for (int j=0; j<sizeArg ; j++){
			(*this).matrix[i][j] = 0;
		}
	}
	return ;
}

GRAPH::~_GRAPH(void)
{
	if ((*this).matrix == NULL)
		return;

	for (int i=0 ; i<(*this).size ; i++){
		delete[] ((*this).matrix[i]);
	}

	delete[] (*this).matrix;

	return ;
}

GRAPH *GRAPH::AddVertex(int row, int col)
{
	//Exception Handling1
	if ((*this).matrix == NULL){
		DEBUG<<"ERROR: (*this).matrix is NULL."<<std::endl;
		return NULL;
	}

	//Exception Handling2
	if (row >= (*this).size){
		DEBUG<<"ERROR: row>=size."<<std::endl;
		return NULL;
	}

	//Exception Handling3
	if (col>=(*this).size){
		DEBUG<<"ERROR: col>=size."<<std::endl;
		return NULL;
	}

	//When the edge already exists.
	if (((*this).matrix)[row][col] == 1){
		return NULL;
	}

	//When the edge doesn't exist currently.
	if (((*this).matrix)[row][col] == 0){
		((*this).matrix)[row][col] = 1;
		((*this).matrix)[col][row] = 1;
		return this;
	}

	//Exception Handling
	DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;

	return NULL;
}

GRAPH *GRAPH::DeleteVertex(int row, int col)
{
	//Exception Hanlidng1.
	if ((*this).matrix == NULL){
		DEBUG<<"ERROR: (*this).matrix is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2.
	if (row >= (*this).size){
		DEBUG<<"ERROR: row>=size." << std::endl;
		return NULL;
	}

	//Exception Handling3.
	if (col >= (*this).size){
		DEBUG<<"ERROR: col>=size." << std::endl;
		return NULL;
	}

	//When the edge is already absent.
	if (((*this).matrix)[row][col] == 0)
		return NULL;

	//When the edge exists currently.
	if (((*this).matrix)[row][col] == 1){
		((*this).matrix)[row][col] = 0;
		((*this).matrix)[col][row] = 0;
		return this;
	}

	//Exception Handling
	DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;

	return NULL;
}

GRAPH *GRAPH::Print(void)
{
	//Exception Handling
	if ((*this).matrix == NULL){
		DEBUG << "ERROR: (*this).matrix is NULL." << std::endl;
		return NULL;
	}

	for (int i=0; i<(*this).size ; i++){
		for (int j=0 ; j<(*this).size ; j++){
			std::cout << (int)(((*this).matrix)[i][j]) << " ";
		}
		std::cout << std::endl;
	}

	return this;
}

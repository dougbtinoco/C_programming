#include<iostream>
using namespace std;

int ** createMatrix(int m_size, int r_size){

	int **m = new int*[m_size];
	int i, j, k=0;
	

	for(int i = 0; i < m_size; ++i){
		m[i]= new int[m_size];
	}

	for(i=0; i<m_size; i++){
		for(j=0; j<m_size; j++, k++){
			m[i][j] = 0;
		}
	}

	return(m);
}


void printMatrix(int **matrix, int matrix_size){

	int i, j;

	for(i=0; i<matrix_size; i++){
		for(j=0; j<matrix_size; j++){
			cout << matrix[i][j] << " | ";
		}
		cout << "\n";
	}
}

void printRestricao(int **matrix, int size_restricao){

	int i, j;

	for(i=0; i<size_restricao; i++){
		for(j=0; j<4; j++){
			cout << matrix[i][j] << "  ";
		}
		cout << "\n";
	}
}

int ** createRestricao(int size_restricao){

	int **m = new int*[size_restricao];

	for(int i=0; i<size_restricao; i++){
		m[i] = new int[4];
	}
	return(m);

}

//se retornar 1, a posicao atual precisa ser menor que proxima indicada
int restricaoCheck(int linha, int coluna, int **restricao_matrix){

	for(int i=0; i<; i++){
		for(int j=0; j<3; j++){
			if(linha==restricao_matrix[i][j] && coluna==restricao_matrix[i][j+1]){
				return(1);
			}
		}
	}
	//como nao possui nenhuma restricao nessa posicao retornaremos 0
	return(0);
}

//verifica se a posicao já foi preenchida ou nao, retorna 1 caso nao foi, 0 caso ja tenha sido
int positionCheck(int linha, int coluna, int **matrix){

	if(matrix[linha][coluna] == 0){
		return(1);
	}
	//como ja foi preenchida retornamos 0
	return(0);
}

int columnCheck(int coluna, int matrix_size){

	if(coluna == matrix_size-1){
		return(0);
	}
	//ainda nao chegamos no final da linha nao precisamos ir para proxima linha e coluna
	return(1);
}

void possibilidadesUpdate(int *possibilidades, int possible_value){

	possibilidades[possible_value - 1] = 0;
	return(void);

}
//para o backtracking simples verifica se ja alcançamos o final da matriz do jogo
int endCheck(int linha, int coluna, int matrix_size){

	if(linha==matrix_size-1 && coluna==matrix_size-1){
		return(1);
	}
	return(0);
}

int valueToInsert(int *possibilidades, int matrix_size){

	for(int i=0; i<matrix_size; i++){
		if(possibilidades[i] != 0){
			//retornar a posicao no vetor do valor a ser inserido
			return(i++);
		}
	}
	return(-1);
}

int checkDisponivel(int valor, int **matrix, int matrix_size, int linha, int coluna){

	for(int i=0; i<matrix_size; i++){
		if(valor == matrix[i][coluna]){
			return(0);
		}
	}
	for(int j=0; j<matrix_size; j++){
		if(valor == matrix[linha][j]){
			return(0);
		}
	}
	//se retornou 1 significa que podemos preencher a posicao com esse valor
	return(1);
}

void zerarPossibilidades(int *possibilidades, int matrix_size){

	for(int i=0; i<matrix_size; i++){
		possibilidades[i] = i+1;
	}
	return(void);
}

void simpleBacktracking(int **matrix, int matrix_size, int **restricao_matrix, int *possibilidades, int i, int j){

	if(positionCheck(i, j, matrix) == 1 && columnCheck(coluna, matrix_size) == 1){
		int aux = valueToInsert(possibilidades, matrix_size);
		//se o aux for 0....!!!
		if(checkDisponivel(aux, matrix, matrix_size, i, j) == 1){
			matrix[i][j] = aux;
			possibilidadesUpdate(possibilidades, aux);
			simpleBacktracking(matrix, matrix_size, restricao_matrix, possibilidades, i, j+1);
		}
		else{
			;
		}
	}
	else{
		if(columnCheck(coluna, matrix_size) == 0){
			zerarPossibilidades(possibilidades, matrix_size)
			simpleBacktracking(matrix, matrix_size, restricao_matrix, possibilidades, i+1, 0);
		}
		else{
			if(positionCheck(i, j, matrix) != 1){
				simpleBacktracking(matrix, matrix_size, restricao_matrix, possibilidades, i, j+1);
			}
			else{
				if(endCheck(i, j, matrix_size) == 1){
					return(void);
				}
			}
		}
	}
}

int main(){
	
	int matrix_size, restricao;
	int **matrix, **restricao_matrix;


	cout << "Digite tamanho da matriz e quantidade de restrições:\n";
	cin >> matrix_size >> restricao;

	matrix = createMatrix(matrix_size, restricao);

	for(int i=0; i<matrix_size; i++){
		for(int j=0; j<matrix_size; j++){
			cin >> matrix[i][j];
		}
	}

	if(restricao != 0){
		restricao_matrix = createRestricao(restricao);
		for(int i=0; i<restricao; i++){
			for(int j=0; j<4; j++){
				cin >> restricao_matrix[i][j];
			}
		}
	}
	zerarPossibilidades(possibilidades, matrix_size);
	simpleBacktracking(matrix, matrix_size, restricao_matrix, possibilidades, 0, 0);
	printMatrix(matrix, matrix_size);
	printRestricao(restricao_matrix, restricao);

	return 0;
	
}


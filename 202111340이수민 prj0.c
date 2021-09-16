#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_matrix(int** M, int m, int n);
int *transposeMat(int** A, int m, int n);
float *normalizeVec(int* v, int n);
float calculateLen(int* v, int n);
int *scaleMat(int** A, int m, int n, int c);
int* multiplyMat(int** A, int m, int n, int** B, int l, int k);
int* addMat(int** A, int m, int n, int** B, int l, int k);

int** temp_arr=NULL;
float* normalized_v = NULL;

void main()
{
	char mode;
	int m;
	int n;
	int **A;
	int **A_transpose;
	int** A_sacle;

	int** B;
	int l;
	int k;

	int** mutiplyMat_AB;

	int dimension;
	int *v;
	float v_length;

	float* normalized_v2;
	int c;

	int** addMat_AB;

	while (1)
	{
		printf("choose the function\n(a)transposeMat\n(b)normalizeVec\n(c)calculateLen\n(d)scaleMat\n(e)multiplyMat\n(f)addMat\n(g)exit\ninsert : ");
		scanf_s("%c", &mode);

		switch (mode)
		{
		case 'a':
			printf("insert the column of the matrix : ");
			scanf_s("%d", &m);
			printf("insert the row of the matrix : ");
			scanf_s("%d", &n);

			A = (int**)malloc(sizeof(int*) * m);
			for (int i = 0; i < m; i++)
			{
				A[i] = (int*)malloc(sizeof(int) * n);
			}



			A_transpose = transposeMat(A, m, n);
			print_matrix(A, m, n);
			printf("\n");
			print_matrix(A_transpose, n, m);
			
			for (int i = 0; i < m; i++)
			{
				free(A[i]);
			}
			free(A);

			for (int i2 = 0; i2 < n; i2++)
			{
				free(temp_arr[i2]);
			}
			free(temp_arr);

			break;
		case 'b':
			printf("insert the dimension of the vector : ");
			scanf_s("%d", &dimension);
			v = (int*)malloc(sizeof(int) * dimension);
			normalized_v2 = normalizeVec(v, dimension);
			for (int i = 0; i < dimension; i++)
			{
				printf("%3f", normalized_v2[i]);
				printf("\n");
			}
			free(v);
			free(normalized_v);
			
			break;
		case 'c':
			printf("insert the dimension of the vector : ");
			scanf_s("%d", &dimension);
			v = (int*)malloc(sizeof(int) * dimension);
			v_length = calculateLen(v, dimension);
			free(v);
			printf("\n lengh is  :%3f\n", v_length);

			break;
		case 'd':
			printf("insert the column of the matrix : ");
			scanf_s("%d", &m);
			printf("insert the row of the matrix : ");
			scanf_s("%d", &n);

			A = (int**)malloc(sizeof(int*) * m);
			for (int i = 0; i < m; i++)
			{
				A[i] = (int*)malloc(sizeof(int) * n);
			}
			printf("insert the scalar c : ");
			scanf_s("%d", &c);

			A_sacle = scaleMat(A, m, n, c);
			print_matrix(A_sacle, m, n);
			printf("\n");
			for (int i = 0; i < m; i++)
			{
				free(A[i]);
			}
			free(A);

			for (int i2 = 0; i2 < m; i2++)
			{
				free(temp_arr[i2]);
			}
			free(temp_arr);

			break;
		case 'e':
			printf("insert the column of the matrix A : ");
			scanf_s("%d", &m);
			printf("insert the row of the matrix A : ");
			scanf_s("%d", &n);

			printf("insert the column of the matrix B : ");
			scanf_s("%d", &l);
			printf("insert the row of the matrix B : ");
			scanf_s("%d", &k);

			A = (int**)malloc(sizeof(int*) * m);
			for (int i = 0; i < m; i++)
			{
				A[i] = (int*)malloc(sizeof(int) * n);
			}

			B = (int**)malloc(sizeof(int*) * l);
			for (int i2 = 0; i2 < l; i2++)
			{
				B[i2] = (int*)malloc(sizeof(int) * k);
			}

			mutiplyMat_AB = multiplyMat(A, m, n, B, l, k);

			if (mutiplyMat_AB != NULL)
			{
				print_matrix(mutiplyMat_AB, m, k);
				for (int i2 = 0; i2 < m; i2++)
				{
					free(temp_arr[i2]);
				}
				free(temp_arr);
			}
			else
			{
				printf("can't calculate\n");
			}

			for (int i = 0; i < m; i++)
			{
				free(A[i]);
			}
			free(A);

			for (int i3 = 0; i3 < l; i3++)
			{
				free(B[i3]);
			}
			free(B);
			break;
		case 'f':
			printf("insert the column of the matrix A : ");
			scanf_s("%d", &m);
			printf("insert the row of the matrix A : ");
			scanf_s("%d", &n);

			printf("insert the column of the matrix B : ");
			scanf_s("%d", &l);
			printf("insert the row of the matrix B : ");
			scanf_s("%d", &k);

			A = (int**)malloc(sizeof(int*) * m);
			for (int i = 0; i < m; i++)
			{
				A[i] = (int*)malloc(sizeof(int) * n);
			}

			B = (int**)malloc(sizeof(int*) * l);
			for (int i2 = 0; i2 < l; i2++)
			{
				B[i2] = (int*)malloc(sizeof(int) * k);
			}

			addMat_AB = addMat(A, m, n, B, l, k);
			if (addMat_AB != NULL)
			{
				print_matrix(addMat_AB, m, n);
				for (int i2 = 0; i2 < m; i2++)
				{
					free(temp_arr[i2]);
				}
				free(temp_arr);
			}
			else
			{
				printf("can't calculate");
			}

			for (int i = 0; i < m; i++)
			{
				free(A[i]);
			}
			free(A);


			for (int i3 = 0; i3 < l; i3++)
			{
				free(B[i3]);
			}
			free(B);

			break;
		case 'g':
			exit(1);
		default:
			printf("not in the menu\n");
			break;
		}

		while (getchar() != '\n');
	}
}

int *transposeMat(int** A, int m, int n)
{
	int temp;
	temp_arr = (int**)malloc(sizeof(int*) * n);
	for (int i2 = 0; i2 < n; i2++)
	{
		temp_arr[i2] = (int*)malloc(sizeof(int) * m);
	}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("[%d,%d]entry : ", x+1, y+1);
			scanf_s("%d", &temp);
			A[x][y]=temp;
		}
	}

	//transpose function
	for (int i3 = 0; i3 < n; i3++)
	{
		for (int i4 = 0; i4 < m; i4++)
		{
			temp_arr[i3][i4] = A[i4][i3];
		}
	}

	return (int*)temp_arr;


}

float* normalizeVec(int* v, int n)
{
	int temp;
	int length_v=0;

	normalized_v = (float*)malloc(sizeof(float) * n);
	for (int i = 0; i < n; i++)
	{
		printf("inser the entry of the vector : ");
		scanf_s("%d", &temp);
		v[i] = temp;
	}

	for (int i2 = 0; i2 < n; i2++)
	{
		length_v += v[i2] * v[i2];
	}

	for (int i3 = 0; i3 < n; i3++)
	{
		normalized_v[i3] = v[i3] / sqrt(length_v);
	}

	return normalized_v;
	
}

float calculateLen(int* v, int n)
{
	int temp;
	int length_v = 0;
	for (int i = 0; i < n; i++)
	{
		printf("inser the entry of the vector : ");
		scanf_s("%d", &temp);
		v[i] = temp;
	}

	for (int i2 = 0; i2 < n; i2++)
	{
		length_v += v[i2] * v[i2];
	}

	return sqrt((float)length_v);
}

int *scaleMat(int** A, int m, int n, int c)
{
	int temp;

	temp_arr = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		temp_arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("[%d,%d]entry : ", x + 1, y + 1);
			scanf_s("%d", &temp);
			A[x][y] = temp;
		}
	}


	for (int i2 = 0; i2 < m; i2++)
	{
		for (int i3 = 0; i3 < n; i3++)
		{
			temp_arr[i2][i3] = A[i2][i3];
			temp_arr[i2][i3] *= c;
		}
	}

	return (int*)temp_arr;

	
}

int* multiplyMat(int** A, int m, int n, int** B, int l, int k)
{
	int temp;

	if (n != l)
	{
		return NULL;
	}
	
	temp_arr = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		temp_arr[i] = (int*)malloc(sizeof(int) * k);
	}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("A[%d,%d]entry : ", x + 1, y + 1);
			scanf_s("%d", &temp);
			A[x][y] = temp;
		}
	}

	for (int x = 0; x < l; x++)
	{
		for (int y = 0; y < k; y++)
		{
			printf("B[%d,%d]entry : ", x + 1, y + 1);
			scanf_s("%d", &temp);
			B[x][y] = temp;
		}
	}

	for (int i2 = 0; i2 < m; i2++)
	{
		for (int i3 = 0; i3 < k; i3++)
		{
			temp_arr[i2][i3] = 0;
			for (int i4 = 0; i4 < l; i4++)
			{
				temp_arr[i2][i3] += A[i2][i4] * B[i4][i3];
			}
		}
	}

	return(int*)temp_arr;
}

int* addMat(int** A, int m, int n, int** B, int l, int k)
{
	int temp;
	if (m != l || n != k)
	{
		return NULL;
	}

	temp_arr = (int**)malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		temp_arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			printf("A[%d,%d]entry : ", x + 1, y + 1);
			scanf_s("%d", &temp);
			A[x][y] = temp;
		}
	}

	for (int x = 0; x < l; x++)
	{
		for (int y = 0; y < k; y++)
		{
			printf("B[%d,%d]entry : ", x + 1, y + 1);
			scanf_s("%d", &temp);
			B[x][y] = temp;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			temp_arr[i][i2] = A[i][i2] + B[i][i2];
		}
	}

	return (int*)temp_arr;
}


void print_matrix(int** M, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int i2 = 0; i2 < n; i2++)
		{
			printf("%3d ", M[i][i2]);
		}
		printf("\n");
	}
}
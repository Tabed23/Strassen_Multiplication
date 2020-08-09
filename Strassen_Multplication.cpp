#include<iostream>
#include<vector>
using namespace std;


class Strassen_Multplication{

private:
void add(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int N) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            C[i][j] = A[i][j] +B[i][j];
        }
    }
}


void sub(vector< vector<int> > &A,  vector< vector<int> > &B, vector< vector<int> > &C, int N) 
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }   
}
void strassenRecursive(vector< vector<int> > &A,vector< vector<int> > &B,vector< vector<int> > &matrixC, int N)
 {

    if (N == 1) {
        matrixC[0][0] = A[0][0] * B[0][0];
        return;
    }
    else {
        int newMSize = N / 2;
        vector<int> innerVector(newMSize, 0);

        vector< vector<int> > matrixA11(newMSize, innerVector),
                            matrixA12(newMSize, innerVector),
                            matrixA21(newMSize, innerVector),
                            matrixA22(newMSize, innerVector),
                            matrixB11(newMSize, innerVector),
                            matrixB12(newMSize, innerVector),
                            matrixB21(newMSize, innerVector),
                            matrixB22(newMSize, innerVector),
                            matrixC11(newMSize, innerVector),
                            matrixC12(newMSize, innerVector),
                            matrixC21(newMSize, innerVector),
                            matrixC22(newMSize, innerVector),
                            s1(newMSize, innerVector),
                            s2(newMSize, innerVector),
                            s3(newMSize, innerVector),
                            s4(newMSize, innerVector),
                            s5(newMSize, innerVector),
                            s6(newMSize, innerVector),
                            s7(newMSize, innerVector),
                            s8(newMSize, innerVector),
                            s9(newMSize, innerVector),
                            s10(newMSize, innerVector),
                            p1(newMSize, innerVector),
                            p2(newMSize, innerVector),
                            p3(newMSize, innerVector),
                            p4(newMSize, innerVector),
                            p5(newMSize, innerVector),
                            p6(newMSize, innerVector),
                            p7(newMSize, innerVector),
                            tempMatrixA(newMSize, innerVector),
                            tempMatrixB(newMSize, innerVector);


        for (int i = 0; i < newMSize; i++) {
            for (int j = 0; j < newMSize; j++) {
                matrixA11[i][j] = A[i][j];
                matrixA12[i][j] = A[i][j + newMSize];
                matrixA21[i][j] = A[i + newMSize][j];
                matrixA22[i][j] = A[i + newMSize][j + newMSize];

                matrixB11[i][j] = B[i][j];
                matrixB12[i][j] = B[i][j + newMSize];
                matrixB21[i][j] = B[i + newMSize][j];
                matrixB22[i][j] = B[i + newMSize][j + newMSize];
            }
        }

        sub(matrixB12, matrixB22, s1, newMSize);
        
        add(matrixA11, matrixA12, s2, newMSize);
        add(matrixA21, matrixA22, s3, newMSize);
        sub(matrixB21, matrixB11, s4, newMSize);
        add(matrixA11, matrixA22, s5, newMSize);
        
        add(matrixB11, matrixB22, s6, newMSize);

        sub(matrixA12, matrixA22, s7, newMSize);

        add(matrixB21, matrixB22, s8, newMSize);
        sub(matrixA11, matrixA21, s9, newMSize);

        add(matrixB11, matrixB12, s10, newMSize);

        strassenRecursive(matrixA11, s1, p1, newMSize);
        strassenRecursive(s2, matrixB22, p2, newMSize);

        strassenRecursive(s3, matrixB11, p3, newMSize);

        strassenRecursive(matrixA22, s4, p4, newMSize);

        strassenRecursive(s5, s6, p5, newMSize); 

        strassenRecursive(s7, s8, p6, newMSize);

        strassenRecursive(s9, s10, p7, newMSize);

        add(p5, p4, tempMatrixA, newMSize); 
        add(tempMatrixA, p6, tempMatrixB, newMSize);
        sub(tempMatrixB, p2, matrixC11, newMSize); 

        add(p1, p2, matrixC12, newMSize);
        add(p3, p4, matrixC21, newMSize);

        add(p5, p1, tempMatrixA, newMSize); 
        sub(tempMatrixA, p3, tempMatrixB, newMSize); 
        sub(tempMatrixB, p7, matrixC22, newMSize); 

    
        for (int i = 0; i < newMSize ; i++) {
            for (int j = 0 ; j < newMSize ; j++) {
                matrixC[i][j] = matrixC11[i][j];
                matrixC[i][j + newMSize] = matrixC12[i][j];
                matrixC[i + newMSize][j] = matrixC21[i][j];
                matrixC[i + newMSize][j + newMSize] = matrixC22[i][j];
            }
        }
    }
}
public:
  void Strassen_Algo(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int N)
   {
        strassenRecursive(A, B, C, N);
    }
};
vector<vector<int>>Init(int);
void print(vector<vector<int>>&,int);
int main()
{
    srand(time(NULL));
    vector<vector<int>> Maxtrix1 = Init(5);
    print(Maxtrix1,5);
    vector<vector<int>>Matrix2 = Init(5);
    print(Matrix2, 5);
    vector<int>inner(5);
    vector<vector<int>>Matrix3(5, inner);
    Strassen_Multplication * M=  new Strassen_Multplication;
    M->Strassen_Algo(Maxtrix1, Matrix2, Matrix3, 5);
    print(Matrix3,5);
}

vector<vector<int>>Init(int N)
{
    vector<vector<int>>Matrix;
    for(int i=0; i<N;i++)
    {
        vector<int>temp;
        for(int j=0;j<N; j++)
        {
            temp.push_back(rand()%N*2);
        }
        Matrix.push_back(temp);
    }
    return Matrix;
}
void print(vector<vector<int>>&Maps,int N)
{
	for (int ri = 0; ri <N; ri++)
	{
		for (int ci = 0; ci < N; ci++)
		{
			cout << Maps[ri][ci]<<" ";
		}
		cout << endl;
	}
    cout<<endl;
    cout<<"-------------------------------------"<<endl;
}
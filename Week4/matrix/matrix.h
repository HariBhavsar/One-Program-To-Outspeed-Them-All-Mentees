#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class matrix{
    public:
//==ACTUAL MATRIX================================================================================================================
        unsigned long rows; // number of rows of the matrix

        unsigned long cols; // number of columns of the matrix 

        vector<double> data; // the data that the matrix has i.e. matrix itself
//==CONSTRUCTORS=================================================================================================================
        matrix(unsigned long rowNum, unsigned long colNum); // constructor, creates a matrix of 0s of dimensions (rowNum, colNum)

        matrix(unsigned long size); // 1D matrix constructor, creates a 1D matrix (vector) of dimensions (size,1)
//==UTILITY FUNCTIONS============================================================================================================
        void printMatrix() // utility function to print matrix 
        { 
            for (int i=0; i<rows; i++) {
                for (int j=0; j<cols; j++) {
                    std::cout<<data[i*cols+j]<<" ";
                }
                std::cout<<"\n";
            }
        }

        double& operator()(unsigned long row_i, unsigned long col_i)  // access function, do not edit or try to implement
        {
            if(row_i>=rows ||col_i>=cols) throw std::out_of_range("Index out of bounds");
            else return data[row_i*cols+col_i];
        }

        const double& operator()(unsigned long row_i, unsigned long col_i)  // constant access function, do not edit or try to implement 
        const{
            if(row_i>=rows ||col_i>=cols) throw std::out_of_range("Index out of bounds");
            else return data[row_i*cols+col_i];
        }

        double& operator()(unsigned long i) // 1D matrix access function, do not edit or try to implement
        {
            if (cols != 1) throw std::invalid_argument("Use 2D indexer for 2D arrays");
            return (*this)(i, 0);
        }

        const double& operator()(unsigned long i) // 1D matrix constant access function, do not edit or try to implement
        const{
            if (cols != 1) throw std::invalid_argument("Use 2D indexer for 2D arrays");
            return (*this)(i, 0);
        }

        pair<unsigned long,unsigned long> shape() // function to get shape of matrix 
        const{
            return make_pair(rows,cols);
        }
//==OPERATORS=========================================================================================================================================
        matrix(const matrix& other); // copy constructor, creates a matrix with same rows, cols and data as `other`                                     
                                                                                                                                                            
        matrix& operator=(const matrix& other); // equality operator, same functionality as copy constructor                                                        

        friend matrix operator+(const matrix& first, const matrix& second); // elementwise addition operator, A[i][j] = first[i][j] + second[i][j]   
                                                                                                                                                                    
        friend matrix operator-(const matrix& first, const matrix& second); // elementwise subtraction operator, A[i][j] = first[i][j] - second[i][j]
                                                                                                                                                          
        friend matrix operator*(const matrix& first, const matrix& second); // elementwise multiplication operator, A[i][j] = first[i][j]*second[i][j]
                                                                                                                                                                                
        friend matrix operator/(const matrix& first, const matrix& second); // elementwise division operator, A[i][j] = first[i][j]/second[i][j]     
        
        friend matrix operator+(const matrix&first, const double t); // float addition operator : A[i][j] = first[i][j]+t                               

        friend matrix operator-(const matrix&first, const double t); // float subtraction operator : A[i][j] = first[i][j]-t                                

        friend matrix operator*(const matrix&first, const double t); // float multiplication operator : A[i][j] = first[i][j]*t                         

        friend matrix operator/(const matrix&first, const double t); // float division operator : A[i][j] = first[i][j]/t                               
//==MATRIX OPERATIONS=================================================================================================================================
        matrix transpose(); // transpose function : A[i][j] = a[j][i]

        matrix inverse(); // inverse function : A = a^(-1), i.e., matmul(A,a) = I

        double determinant(); // determinant function https://en.wikipedia.org/wiki/Determinant
};

matrix matmul(const matrix& first, const matrix& second); // matmul function, A = first*second
//==BASIC FUNCTIONS===================================================================================================================================
matrix zeros(unsigned long rows, unsigned long cols); // zeros function : A[i][j] = 0 for all i in (0,rows) and for all j in (0,cols)

matrix zeros(unsigned long size); // 1D zeros function : A[i] = 0 for all i in (0,size)

matrix eye(unsigned long size); // 1D eye function : A = I(size) where I(x) is identity matrix with dimensions x https://en.wikipedia.org/wiki/Identity_matrix

matrix eye(unsigned long rows, unsigned long cols); // eye function : A = I(min(rows,cols)):zeros

matrix ones(unsigned long rows, unsigned long cols); // ones function : A = np.ones((rows,cols))

matrix identity(unsigned long size); // identity matrix function : A = I(size)
//==MINMAX FUNCTIONS==================================================================================================================================
/*

An explanation of what np.max(arr,axis) does
Suppose arr has shape (n,m) then np.max(arr,0) returns a matrix of shape (n,1) where np.max(arr,0)[i] = maximum over all j {arr[i][j]}
np.max(arr,1) returns a matrix of shape (1,m) where np.max(arr,1)[0][i] = maximum over all j {arr[j][i]}
You should be able to infer min, argmax and argmin similarly

*/

matrix max(matrix &arr,int axis); // specific max function : A = np.max(arr,axis)
                                
matrix argmax(matrix &arr,int axis); // specific argmax function : A = np.argmax(arr,axis)

matrix max(matrix &arr); // general max function : A = np.max(arr,0)

matrix argmax(matrix &arr); // general argmax function : A = np.argmax(arr,0)

matrix min(matrix &arr,int axis); // specific min function : A = np.min(arr,axis)

matrix argmin(matrix &arr,int axis); // specific argmin function : A = np.argmin(arr,axis)

matrix min(matrix &arr); // general min function : A = np.min(arr,0)

matrix argmin(matrix &arr); // general argmin function : A = np.argmin(arr,0)
//==ELEMENT FUNCTIONS================================================================================================================================
matrix tanh(matrix &a); // elementwise tanh function : matr[i][j] = tanh(matr[i][j])

matrix fabs(matrix &a); // elementwise fabs function : matr[i][j] = fabs(matr[i][j])

matrix exp(matrix &a); // elementwise exponentiator : matr[i][j] = fabs(matr[i][j])

matrix log(matrix &a,double logbase); // elementwise log operator : matr[i][j] = log_{logbase}(matr[i][j])

matrix sqrt(matrix &a); // elementwise sqrt function : matr[i][j] = sqrt(matr[i][j]) 
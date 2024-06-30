#include "matrix.h"

matrix::matrix(uint64_t rowNum, uint64_t colNum){
    data = vector<double>(rowNum*colNum);
    rows = rowNum;
    cols = colNum;
}

matrix::matrix(uint64_t size){
    data = vector<double>(size);
    rows = size;
    cols = 1;
}

matrix::matrix(){

}

matrix::matrix(const matrix& other) {
    data = other.data;
    rows = other.rows;
    cols = other.cols;
}

matrix& matrix::operator=(const matrix& other) {
    // Allocate new resource
    rows = other.rows;
    cols = other.cols;
    data = other.data;

    return *this;
}

matrix operator+(const matrix& first, const matrix& second){
    if (first.rows!=second.rows && first.cols!=second.cols){
        throw std::invalid_argument("Cannot add ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
    }
    else if (first.rows == second.rows && first.cols == second.cols) {
        matrix sum(first.rows,first.cols);
        for( uint64_t i=0;i<first.rows*first.cols;i++){
            sum.data[i]=first.data[i]+second.data[i];
        }
        return sum;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = second.data[i*second.cols+j] + first.data[i];
                }
            }
            return sum;
        }
        else if (second.cols == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] + second.data[i];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot add ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = second.data[i*second.cols+j] + first.data[j];
                }
            }
            return sum;
        }
        else if (second.rows == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] + second.data[j];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot add ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    }
    return zeros(1,1);
}

matrix operator-(const matrix& first, const matrix& second){
    if (first.rows!=second.rows && first.cols!=second.cols){
        throw std::invalid_argument("Cannot subtract ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    else if (first.rows == second.rows && first.cols == second.cols) {
        matrix diff(first.rows,first.cols);
        for( uint64_t i=0;i<first.rows*first.cols;i++){
            diff.data[i]=first.data[i]-second.data[i];
        }
        return diff;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix diff(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    diff.data[i*second.cols + j] = first.data[i] - second.data[i*second.cols+j];
                }
            }
            return diff;
        }
        else if (second.cols == 1) {
            matrix diff(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    diff.data[i*first.cols + j] = first.data[i*first.cols+j] - second.data[i];
                }
            }
            return diff;
        }
        else {
            throw std::invalid_argument("Cannot subtract ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix diff(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    diff.data[i*second.cols + j] = first.data[j] - second.data[i*second.cols+j];
                }
            }
            return diff;
        }
        else if (second.rows == 1) {
            matrix diff(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    diff.data[i*first.cols + j] = first.data[i*first.cols+j] - second.data[j];
                }
            }
            return diff;
        }
        else {
            throw std::invalid_argument("Cannot subtract ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    return zeros(1,1);
}

matrix operator*(const matrix& first, const matrix& second){
    if (first.rows!=second.rows && first.cols!=second.cols){
        throw std::invalid_argument("Cannot multiply(elementwise) ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
    }
    else if (first.rows == second.rows && first.cols == second.cols) {
        matrix prod(first.rows,first.cols);
        for( uint64_t i=0;i<first.rows*first.cols;i++){
            prod.data[i]=first.data[i]*second.data[i];
        }
        return prod;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix prod(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    prod.data[i*second.cols + j] = second.data[i*second.cols+j] * first.data[i];
                }
            }
            return prod;
        }
        else if (second.cols == 1) {
            matrix prod(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    prod.data[i*first.cols + j] = first.data[i*first.cols+j] * second.data[i];
                }
            }
            return prod;
        }
        else {
            throw std::invalid_argument("Cannot multiply ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix prod(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    prod.data[i*second.cols + j] = second.data[i*second.cols+j] * first.data[j];
                }
            }
            return prod;
        }
        else if (second.rows == 1) {
            matrix prod(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    prod.data[i*first.cols + j] = first.data[i*first.cols+j] * second.data[j];
                }
            }
            return prod;
        }
        else {
            throw std::invalid_argument("Cannot multiply ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    }
    return zeros(1,1);
}


matrix operator/(const matrix& first, const matrix& second){
    if (first.rows!=second.rows && first.cols!=second.cols){
        throw std::invalid_argument("Cannot divide ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    else if (first.rows == second.rows && first.cols == second.cols) {
        matrix quotient(first.rows,first.cols);
        for( uint64_t i=0;i<first.rows*first.cols;i++){
            quotient.data[i]=first.data[i]/second.data[i];
        }
        return quotient;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix quotient(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    quotient.data[i*second.cols + j] = first.data[i] / second.data[i*second.cols+j];
                }
            }
            return quotient;
        }
        else if (second.cols == 1) {
            matrix quotient(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    quotient.data[i*first.cols + j] = first.data[i*first.cols+j] / second.data[i];
                }
            }
            return quotient;
        }
        else {
            throw std::invalid_argument("Cannot divide ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix quotient(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    quotient.data[i*second.cols + j] = first.data[j] / second.data[i*second.cols+j];
                }
            }
            return quotient;
        }
        else if (second.rows == 1) {
            matrix quotient(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    quotient.data[i*first.cols + j] = first.data[i*first.cols+j] / second.data[j];
                }
            }
            return quotient;
        }
        else {
            throw std::invalid_argument("Cannot divide ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    return zeros(1,1);
}

matrix operator*(const matrix& first, const double t) {
    matrix prod(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        prod.data[i] = first.data[i]*t;
    }
    return prod;
}

matrix operator+(const double t, const matrix& first){
    matrix sum(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = t + first.data[i];
    }
    return sum;  
}

matrix operator-(const double t, const matrix& first){
    matrix diff(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        diff.data[i] = t - first.data[i];
    }
    return diff;  
}

matrix operator*(const double t, const matrix& first){
    matrix prod(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        prod.data[i] = first.data[i]*t;
    }
    return prod;  
}

matrix operator/(const double t, const matrix& first){
    matrix quotient(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        quotient.data[i] = first.data[i]*t/first.data[i];
    }
    return quotient;  
}

matrix operator+(const matrix& first, const double t) {
    matrix sum(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = first.data[i]+t;
    }
    return sum;
}

matrix operator-(const matrix& first, const double t) {
    matrix diff(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        diff.data[i] = first.data[i]-t;
    }
    return diff;
}

matrix operator/(const matrix& first, const double t) {
    matrix quotient(first.rows, first.cols);
    for (uint64_t i=0; i<first.rows*first.cols; i++) {
        quotient.data[i] = first.data[i]/t;
    }
    return quotient;
}

matrix& operator+=(matrix& self,const matrix& other){
    __size d1 = self.shape(), d2 = other.shape();
    if (d1 != d2){
        throw std::invalid_argument("Cannot add ( "+ to_string(other.rows) +" , " + to_string(other.cols) + 
        " ) to ( " + to_string(self.rows) + " , " + to_string(self.cols) + " )" );
    }
    for (uint64_t i = 0 ; i < self.rows ; i++){
        for (uint64_t j  = 0 ; j < self.cols ; j++){
            self(i,j) += other(i,j);
        }
    }
    return self;
}

matrix& operator-=(matrix& self,const matrix& other){
    __size d1 = self.shape(), d2 = other.shape();
    if (d1 != d2){
        throw std::invalid_argument("Cannot subtract ( "+ to_string(other.rows) +" , " + to_string(other.cols) + 
        " ) from ( " + to_string(self.rows) + " , " + to_string(self.cols) + " )" );
    }
    for (uint64_t i = 0 ; i < self.rows ; i++){
        for (uint64_t j  = 0 ; j < self.cols ; j++){
            self(i,j) -= other(i,j);
        }
    }
    return self;
}

matrix& operator*=(matrix& self,const matrix& other){
    __size d1 = self.shape(), d2 = other.shape();
    if (d1 != d2){
        throw std::invalid_argument("Cannot multiply(elementwise) ( "+ to_string(other.rows) +" , " + to_string(other.cols) + 
        " ) with ( " + to_string(self.rows) + " , " + to_string(self.cols) + " )" );
    }
    for (uint64_t i = 0 ; i < self.rows ; i++){
        for (uint64_t j  = 0 ; j < self.cols ; j++){
            self(i,j) *= other(i,j);
        }
    }
    return self;
}

matrix operator-(const matrix& M){
    matrix negation(M.rows,M.cols);
    for (uint64_t i = 0 ; i < M.rows ; i++){
        for (uint64_t j = 0 ; j < M.cols ; j++){
            negation(i,j) = -M(i,j);
        }
    }
    return negation;
}
matrix matmul(const matrix& first, const matrix& second){
    __size dim1 = first.shape();
    __size dim2 = second.shape();
    if( dim1.second != dim2.first){
        throw std::invalid_argument("Cannot matmul ( "+ to_string(dim1.first) +" , " + to_string(dim1.second) + " ) with ( " + to_string(dim2.first) + " , " + to_string(dim2.second) + " )" );
    }
    else{
        matrix net(dim1.first,dim2.second);
        for( uint64_t i=0;i< dim1.first;i++){
            for(uint64_t j=0;j< dim2.second;j++){
                double sum=0;
                for(uint64_t k=0;k< dim1.second;k++){
                    sum+=first(i,k)*second(k,j);
                }
                net(i,j)=sum;
            }
        }
        return net;
    }
}

double dot(const matrix& first, const matrix& second){
    __size dim1 = first.shape();
    __size dim2 = second.shape();
    if (dim1.first != 1 || dim1.second != dim2.first || dim2.second != 1){
        throw std::invalid_argument("Cannot dot vector with dimensions ( "+ to_string(dim1.first) +" , " + to_string(dim1.second) + " ) with  a vector with dimensions ( " + to_string(dim2.first) + " , " + to_string(dim2.second) + " )" );
    }
    uint64_t n = dim1.second;
    float d = 0;
    for (unsigned i = 0 ; i < n ; i++){
        d += first(0,i)*second(i,0);
    }
    return d;
}

double norm(const matrix& v){
    __size dim = v.shape();
    if (dim.first != 1 && dim.second != 1){
        throw std::invalid_argument("Cannot compute norm of vector with dimensions ( "+ to_string(dim.first)+" , "+ to_string(dim.second) + " )");
    }
    uint64_t n = dim.first, m = dim.second;
    double N = 0;
    for (uint64_t i = 0 ; i < n ; i++){
        for (uint64_t j = 0 ; j < m ; j++){
            N += (v(i,j))*(v(i,j));
        }
    }
    N = sqrt(N);
    return N;    
}

matrix matrix::inverse(){
    matrix a = *this;
    __size dim = a.shape();
    if (dim.first != dim.second) 
        throw std::invalid_argument("Cannot invert ( "+ to_string(dim.first) +" , " + to_string(dim.second) + " )");
    uint64_t n = a.rows;
    matrix augmented(n, 2 * n);
    // Initialize the augmented matrix with the identity matrix on the right
    for (uint64_t i = 0; i < n; ++i) {
        for (uint64_t j = 0; j < n; ++j) {
            augmented(i, j) = a(i, j);
            augmented(i, j + n) = (i == j) ? 1.0 : 0.0;
        }
    }
    // Perform Gauss-Jordan elimination
    for (uint64_t i = 0; i < n; ++i) {
        // Find the pivot
        double pivot = augmented(i, i);
        if (pivot == 0.0) {
            throw runtime_error("Matrix is singular and cannot be inverted.");
        }

        // Normalize the pivot row
        for (uint64_t j = 0; j < 2 * n; ++j) {
            augmented(i, j) /= pivot;
        }

        // Eliminate the current column in other rows
        for (uint64_t k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented(k, i);
                for (uint64_t j = 0; j < 2 * n; ++j) {
                    augmented(k, j) -= factor * augmented(i, j);
                }
            }
        }
    }
    // Extract the inverse matrix from the augmented matrix
    matrix result(n, n);
    for (uint64_t i = 0; i < n; ++i) {
        for (uint64_t j = 0; j < n; ++j) {
            result(i, j) = augmented(i, j + n);
        }
    }
    return result;
}

matrix matrix::transpose(){
    __size dim = this->shape();
    matrix T(dim.second,dim.first);
    for (int i = 0 ; i < this->rows ; i++){
        for (int j = 0 ; j < this->cols ; j++){
            T(j,i) = this->data[i*this->cols + j];
        }
    }
    return T;
}

double matrix::determinant(){
    if (rows != cols) {
        throw std::invalid_argument("Matrix must be square to calculate determinant");
    }
    uint64_t n = rows;
    matrix a(*this); // Make a copy of the matrix

    double det = 1;
    for (uint64_t i = 0; i < n; ++i) {
        // Find the pivot
        uint64_t pivot = i;
        for (uint64_t j = i + 1; j < n; ++j) {
            if (abs(a.data[j * n + i]) > abs(a.data[pivot * n + i])) {
                pivot = j;
            }
        }

        // Swap rows if needed
        if (pivot != i) {
            for (uint64_t k = 0; k < n; ++k) {
                std::swap(a.data[i * n + k], a.data[pivot * n + k]);
            }
            det *= -1; // Swap changes the sign of the determinant
        }

        // Check for zero pivot
        if (a.data[i * n + i] == 0) {
            return 0; // Determinant is zero
        }

        // Eliminate the column
        for (uint64_t j = i + 1; j < n; ++j) {
            double factor = a.data[j * n + i] / a.data[i * n + i];
            for (uint64_t k = i; k < n; ++k) {
                a.data[j * n + k] -= factor * a.data[i * n + k];
            }
        }

        // Multiply the diagonal elements
        det *= a.data[i * n + i];
    }

    return det;
}

matrix zeros(uint64_t rows, uint64_t cols){
    return matrix(rows,cols);
}

matrix zeros(uint64_t size){
    return matrix(size);
}

matrix eye(uint64_t size){
    matrix diag(size,size);
    for(int i=0;i<size;i++){
        diag(i,i)=1;
    }
    return diag;
}

matrix eye(uint64_t rows, uint64_t cols){
    matrix diag(rows,cols);
    for(int i=0;i<min(rows,cols);i++){
        diag(i,i)=1;
    }
    return diag;
}

matrix identity(uint64_t size){
    return eye(size);
}

matrix max(matrix &arr,int axis) {
    if (axis < 0 || axis > 1) throw std::invalid_argument("Axis must be 0 or 1");
    
    double twoRows,twoCols;
    twoRows = arr.shape().first;
    twoCols = arr.shape().second;

    matrix result(axis == 0 ? 1 : twoRows, axis == 0 ? twoCols : 1);

    if (axis == 0) {  //largest each col 
        for (uint64_t col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            for (uint64_t row = 1; row < twoRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                }
            }
            result(0, col) = max_value;
        }
    } else {  //largest for each row
        for (uint64_t row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            for (uint64_t col = 1; col < twoCols; ++col) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                }
            }
            result(row, 0) = max_value;
        }
    }

    return result;
}

matrix argmax(matrix &arr,int axis) {
    if (axis < 0 || axis > 1) throw std::invalid_argument("Axis must be 0 or 1");
    
    double twoRows,twoCols;
    twoRows = arr.shape().first;
    twoCols = arr.shape().second;

    matrix result(axis == 0 ? 1 : twoRows, axis == 0 ? twoCols : 1);

    if (axis == 0) {  // Argmax along columns (resulting in row vector)
        for (uint64_t col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < twoRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
    } else {  // Argmax along rows (resulting in column vector)
        for (uint64_t row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            uint64_t max_index = 0;
            for (uint64_t col = 1; col < twoCols; ++col) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                    max_index = col;
                }
            }
            result(row, 0) = max_index;
        }
    }

    return result;
}

matrix max (matrix &arr) {
    double arrRows, arrCols;
    arrRows = arr.shape().first;
    arrCols = arr.shape().second;
    if (arrRows != 1 && arrCols != 1) {
        matrix result(1, arrCols);
        for (uint64_t col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < arrRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_value;
        }
        return result;
    }
    else if (arrRows == 1) {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (uint64_t col = 1; col < arrCols; ++col) {
            t(0,0) = max(t(0,0),arr(0,col));
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (uint64_t row = 1; row < arrRows; ++row) {
            t(0,0) = max(t(0,0),arr(row,0));
        }
        return t;
    }

}


matrix argmax (matrix &arr) {
    double arrRows, arrCols;
    arrRows = arr.shape().first;
    arrCols = arr.shape().second;
    if (arrRows != 1 && arrCols != 1) {
        matrix result(1, arrCols);
        for (uint64_t col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < arrRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
        return result;
    }
    else if (arrRows == 1) {
        matrix t(1,1);
        t(0,0) = 0;
        for (uint64_t col = 1; col < arrCols; ++col) {
            if (arr(0,t(0,0)) < arr(col)) {
                t(0,0) = col;
            }
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = 0;
        for (uint64_t row = 1; row < arrRows; ++row) {
            if (arr(t(0,0),0) < arr(row)) {
                t(0,0) = row;
            }
        }
        return t;
    }

}

matrix min(matrix &arr,int axis) {
    if (axis < 0 || axis > 1) throw std::invalid_argument("Axis must be 0 or 1");
    
    double twoRows,twoCols;
    twoRows = arr.shape().first;
    twoCols = arr.shape().second;

    matrix result(axis == 0 ? 1 : twoRows, axis == 0 ? twoCols : 1);

    if (axis == 0) {  //largest each col 
        for (uint64_t col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            for (uint64_t row = 1; row < twoRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                }
            }
            result(0, col) = max_value;
        }
    } else {  //largest for each row
        for (uint64_t row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            for (uint64_t col = 1; col < twoCols; ++col) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                }
            }
            result(row, 0) = max_value;
        }
    }

    return result;
}

matrix argmin(matrix &arr,int axis) {
    if (axis < 0 || axis > 1) throw std::invalid_argument("Axis must be 0 or 1");
    
    double twoRows,twoCols;
    twoRows = arr.shape().first;
    twoCols = arr.shape().second;

    matrix result(axis == 0 ? 1 : twoRows, axis == 0 ? twoCols : 1);

    if (axis == 0) {  // Argmax along columns (resulting in row vector)
        for (uint64_t col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < twoRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
    } else {  // Argmax along rows (resulting in column vector)
        for (uint64_t row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            uint64_t max_index = 0;
            for (uint64_t col = 1; col < twoCols; ++col) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                    max_index = col;
                }
            }
            result(row, 0) = max_index;
        }
    }

    return result;
}

matrix min (matrix &arr) {
    double arrRows, arrCols;
    arrRows = arr.shape().first;
    arrCols = arr.shape().second;
    if (arrRows != 1 && arrCols != 1) {
        matrix result(1, arrCols);
        for (uint64_t col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < arrRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_value;
        }
        return result;
    }
    else if (arrRows == 1) {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (uint64_t col = 1; col < arrCols; ++col) {
            t(0,0) = min(t(0,0),arr(0,col));
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (uint64_t row = 1; row < arrRows; ++row) {
            t(0,0) = min(t(0,0),arr(row,0));
        }
        return t;
    }

}

matrix argmin (matrix &arr) {
    double arrRows, arrCols;
    arrRows = arr.shape().first;
    arrCols = arr.shape().second;
    if (arrRows != 1 && arrCols != 1) {
        matrix result(1, arrCols);
        for (uint64_t col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            uint64_t max_index = 0;
            for (uint64_t row = 1; row < arrRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
        return result;
    }
    else if (arrRows == 1) {
        matrix t(1,1);
        t(0,0) = 0;
        for (uint64_t col = 1; col < arrCols; ++col) {
            if (arr(0,t(0,0)) > arr(col)) {
                t(0,0) = col;
            }
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = 0;
        for (uint64_t row = 1; row < arrRows; ++row) {
            if (arr(t(0,0),0) > arr(row)) {
                t(0,0) = row;
            }
        }
        return t;
    }

}


matrix ones (uint64_t rows, uint64_t cols) {
    matrix t(rows,cols);
    for (int i=0; i<rows*cols; i++) {
        t.data[i] = 1;
    }
    return t;
}

matrix fabs(matrix &a) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::fabs(a.data[i]);
    }
    return res;
}

matrix exp(matrix &a) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::exp(a.data[i]);
    }
    return res;
}

matrix tanh(matrix &a) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::tanh(a.data[i]);
    }
    return res;
}

matrix log(matrix &a, double logbase) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::log(a.data[i])/std::log(logbase);
    }
    return res;
}

matrix log(matrix &a) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::log(a.data[i]);
    }
    return res;
}

matrix sqrt(matrix &a) {
    matrix res(a.rows,a.cols);
    for (uint64_t i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::sqrt(a.data[i]);
    }
    return res;    
}
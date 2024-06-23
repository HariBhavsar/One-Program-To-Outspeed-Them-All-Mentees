#include "matrix.h"

matrix::matrix(unsigned long rowNum, unsigned long colNum){
    data.resize(rowNum*colNum,0);
    rows = rowNum;
    cols = colNum;
}

matrix::matrix(unsigned long size){
    matrix(size,1);
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
        for( unsigned long i=0;i<first.rows*first.cols;i++){
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
        matrix sum(first.rows,first.cols);
        for( unsigned long i=0;i<first.rows*first.cols;i++){
            sum.data[i]=first.data[i]-second.data[i];
        }
        return sum;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = first.data[i] - second.data[i*second.cols+j];
                }
            }
            return sum;
        }
        else if (second.cols == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] - second.data[i];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot subtract ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = first.data[j] - second.data[i*second.cols+j];
                }
            }
            return sum;
        }
        else if (second.rows == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] - second.data[j];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot subtract ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    return zeros(1,1);
}

matrix operator*(const matrix& first, const matrix& second){
    if (first.rows!=second.rows && first.cols!=second.cols){
        throw std::invalid_argument("Cannot multiply ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    else if (first.rows == second.rows && first.cols == second.cols) {
        matrix sum(first.rows,first.cols);
        for( unsigned long i=0;i<first.rows*first.cols;i++){
            sum.data[i]=first.data[i]*second.data[i];
        }
        return sum;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = second.data[i*second.cols+j] * first.data[i];
                }
            }
            return sum;
        }
        else if (second.cols == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] * second.data[i];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot multiply ( "+ to_string(first.rows) +" , " + to_string(first.cols) + " ) with ( " + to_string(second.rows) + " , " + to_string(second.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = second.data[i*second.cols+j] * first.data[j];
                }
            }
            return sum;
        }
        else if (second.rows == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] * second.data[j];
                }
            }
            return sum;
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
        matrix sum(first.rows,first.cols);
        for( unsigned long i=0;i<first.rows*first.cols;i++){
            sum.data[i]=first.data[i]/second.data[i];
        }
        return sum;
    }
    else if (first.rows == second.rows) {
        if (first.cols == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = first.data[i] / second.data[i*second.cols+j];
                }
            }
            return sum;
        }
        else if (second.cols == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] / second.data[i];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot divide ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    else if (first.cols == second.cols) {
        if (first.rows == 1) { // np.broadcast
            matrix sum(second.rows, second.cols);
            for (int i = 0; i<second.rows; i++) {
                for (int j=0; j<second.cols; j++) {
                    sum.data[i*second.cols + j] = first.data[j] / second.data[i*second.cols+j];
                }
            }
            return sum;
        }
        else if (second.rows == 1) {
            matrix sum(first.rows, first.cols);
            for (int i = 0; i<first.rows; i++) {
                for (int j=0; j<first.cols; j++) {
                    sum.data[i*first.cols + j] = first.data[i*first.cols+j] / second.data[j];
                }
            }
            return sum;
        }
        else {
            throw std::invalid_argument("Cannot divide ( "+ to_string(second.rows) +" , " + to_string(second.cols) + " ) from ( " + to_string(first.rows) + " , " + to_string(first.cols) + " )" );
        }
    }
    return zeros(1,1);
}

matrix operator*(const matrix& first, const double t) {
    matrix sum(first.rows, first.cols);
    for (unsigned long i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = first.data[i]*t;
    }
    return sum;
}

matrix operator+(const matrix& first, const double t) {
    matrix sum(first.rows, first.cols);
    for (unsigned long i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = first.data[i]+t;
    }
    return sum;
}

matrix operator-(const matrix& first, const double t) {
    matrix sum(first.rows, first.cols);
    for (unsigned long i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = first.data[i]-t;
    }
    return sum;
}

matrix operator/(const matrix& first, const double t) {
    matrix sum(first.rows, first.cols);
    for (unsigned long i=0; i<first.rows*first.cols; i++) {
        sum.data[i] = first.data[i]/t;
    }
    return sum;
}

matrix matmul(const matrix& first, const matrix& second){
    pair<unsigned long, unsigned long> dim1 = first.shape();
    pair<unsigned long, unsigned long> dim2 = second.shape();
    if( dim1.second != dim2.first){
        throw std::invalid_argument("Cannot matmul ( "+ to_string(dim1.first) +" , " + to_string(dim1.second) + " ) with ( " + to_string(dim2.first) + " , " + to_string(dim2.second) + " )" );
    }
    else{
        matrix net(dim1.first,dim2.second);
        for( unsigned long i=0;i< dim1.first;i++){
            for(unsigned long j=0;j< dim2.second;j++){
                double sum=0;
                for(unsigned long k=0;k< dim1.second;k++){
                    sum+=first(i,k)*second(k,j);
                }
                net(i,j)=sum;
            }
        }
        return net;
    }
}

matrix matrix::inverse(){
    matrix a = *this;
    pair<unsigned long, unsigned long> dim = a.shape();
    if (dim.first != dim.second) 
        throw std::invalid_argument("Cannot invert ( "+ to_string(dim.first) +" , " + to_string(dim.second) + " )");
    unsigned long n = a.rows;
    matrix augmented(n, 2 * n);
    // Initialize the augmented matrix with the identity matrix on the right
    for (unsigned long i = 0; i < n; ++i) {
        for (unsigned long j = 0; j < n; ++j) {
            augmented(i, j) = a(i, j);
            augmented(i, j + n) = (i == j) ? 1.0 : 0.0;
        }
    }
    // Perform Gauss-Jordan elimination
    for (unsigned long i = 0; i < n; ++i) {
        // Find the pivot
        double pivot = augmented(i, i);
        if (pivot == 0.0) {
            throw runtime_error("Matrix is singular and cannot be inverted.");
        }

        // Normalize the pivot row
        for (unsigned long j = 0; j < 2 * n; ++j) {
            augmented(i, j) /= pivot;
        }

        // Eliminate the current column in other rows
        for (unsigned long k = 0; k < n; ++k) {
            if (k != i) {
                double factor = augmented(k, i);
                for (unsigned long j = 0; j < 2 * n; ++j) {
                    augmented(k, j) -= factor * augmented(i, j);
                }
            }
        }
    }
    // Extract the inverse matrix from the augmented matrix
    matrix result(n, n);
    for (unsigned long i = 0; i < n; ++i) {
        for (unsigned long j = 0; j < n; ++j) {
            result(i, j) = augmented(i, j + n);
        }
    }
    return result;
}

matrix matrix::transpose(){
    pair<unsigned long,unsigned long> dim = this->shape();
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
    unsigned long n = rows;
    matrix a(*this); // Make a copy of the matrix

    double det = 1;
    for (unsigned long i = 0; i < n; ++i) {
        // Find the pivot
        unsigned long pivot = i;
        for (unsigned long j = i + 1; j < n; ++j) {
            if (abs(a.data[j * n + i]) > abs(a.data[pivot * n + i])) {
                pivot = j;
            }
        }

        // Swap rows if needed
        if (pivot != i) {
            for (unsigned long k = 0; k < n; ++k) {
                std::swap(a.data[i * n + k], a.data[pivot * n + k]);
            }
            det *= -1; // Swap changes the sign of the determinant
        }

        // Check for zero pivot
        if (a.data[i * n + i] == 0) {
            return 0; // Determinant is zero
        }

        // Eliminate the column
        for (unsigned long j = i + 1; j < n; ++j) {
            double factor = a.data[j * n + i] / a.data[i * n + i];
            for (unsigned long k = i; k < n; ++k) {
                a.data[j * n + k] -= factor * a.data[i * n + k];
            }
        }

        // Multiply the diagonal elements
        det *= a.data[i * n + i];
    }

    return det;
}

matrix zeros(unsigned long rows, unsigned long cols){
    return matrix(rows,cols);
}

matrix zeros(unsigned long size){
    return matrix(size);
}

matrix eye(unsigned long size){
    matrix diag(size,size);
    for(int i=0;i<size;i++){
        diag(i,i)=1;
    }
    return diag;
}

matrix eye(unsigned long rows, unsigned long cols){
    matrix diag(rows,cols);
    for(int i=0;i<min(rows,cols);i++){
        diag(i,i)=1;
    }
    return diag;
}

matrix identity(unsigned long size){
    return eye(size);
}

matrix max(matrix &arr,int axis) {
    if (axis < 0 || axis > 1) throw std::invalid_argument("Axis must be 0 or 1");
    
    double twoRows,twoCols;
    twoRows = arr.shape().first;
    twoCols = arr.shape().second;

    matrix result(axis == 0 ? 1 : twoRows, axis == 0 ? twoCols : 1);

    if (axis == 0) {  //largest each col 
        for (unsigned long col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            for (unsigned long row = 1; row < twoRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                }
            }
            result(0, col) = max_value;
        }
    } else {  //largest for each row
        for (unsigned long row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            for (unsigned long col = 1; col < twoCols; ++col) {
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
        for (unsigned long col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < twoRows; ++row) {
                if (arr(row, col) > max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
    } else {  // Argmax along rows (resulting in column vector)
        for (unsigned long row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            unsigned long max_index = 0;
            for (unsigned long col = 1; col < twoCols; ++col) {
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
        for (unsigned long col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 1; col < arrCols; ++col) {
            t(0,0) = max(t(0,0),arr(0,col));
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 1; col < arrCols; ++col) {
            if (arr(0,t(0,0)) < arr(col)) {
                t(0,0) = col;
            }
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = 0;
        for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            for (unsigned long row = 1; row < twoRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                }
            }
            result(0, col) = max_value;
        }
    } else {  //largest for each row
        for (unsigned long row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            for (unsigned long col = 1; col < twoCols; ++col) {
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
        for (unsigned long col = 0; col < twoCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < twoRows; ++row) {
                if (arr(row, col) < max_value) {
                    max_value = arr(row, col);
                    max_index = row;
                }
            }
            result(0, col) = max_index;
        }
    } else {  // Argmax along rows (resulting in column vector)
        for (unsigned long row = 0; row < twoRows; ++row) {
            double max_value = arr(row, 0);
            unsigned long max_index = 0;
            for (unsigned long col = 1; col < twoCols; ++col) {
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
        for (unsigned long col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 1; col < arrCols; ++col) {
            t(0,0) = min(t(0,0),arr(0,col));
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = arr(0,0);
        for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 0; col < arrCols; ++col) {
            double max_value = arr(0, col);
            unsigned long max_index = 0;
            for (unsigned long row = 1; row < arrRows; ++row) {
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
        for (unsigned long col = 1; col < arrCols; ++col) {
            if (arr(0,t(0,0)) > arr(col)) {
                t(0,0) = col;
            }
        }
        return t;
    }
    else {
        matrix t(1,1);
        t(0,0) = 0;
        for (unsigned long row = 1; row < arrRows; ++row) {
            if (arr(t(0,0),0) > arr(row)) {
                t(0,0) = row;
            }
        }
        return t;
    }

}


matrix ones (unsigned long rows, unsigned long cols) {
    matrix t(rows,cols);
    for (int i=0; i<rows*cols; i++) {
        t.data[i] = 1;
    }
    return t;
}

matrix fabs(matrix &a) {
    matrix res(a.rows,a.cols);
    for (unsigned long i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::fabs(a.data[i]);
    }
    return res;
}

matrix exp(matrix &a) {
    matrix res(a.rows,a.cols);
    for (unsigned long i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::exp(a.data[i]);
    }
    return res;
}

matrix tanh(matrix &a) {
    matrix res(a.rows,a.cols);
    for (unsigned long i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::tanh(a.data[i]);
    }
    return res;
}

matrix log(matrix &a, double logbase) {
    matrix res(a.rows,a.cols);
    for (unsigned long i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::log(a.data[i])/std::log(logbase);
    }
    return res;
}

matrix sqrt(matrix &a) {
    matrix res(a.rows,a.cols);
    for (unsigned long i=0;i<a.rows*a.cols;i++){
        res.data[i]=std::sqrt(a.data[i]);
    }
    return res;    
}
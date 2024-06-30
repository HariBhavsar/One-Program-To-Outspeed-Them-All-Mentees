#ifndef LINEAR // This is a header guard. This makes sure that you do not get an error if linear.h is included multiple times
#define LINEAR
#include "../matrix/matrix.h" // This imports the file which has all the definitions regarding matrices. 
#include <random> 
#include <algorithm>
#define EPS 1e-15 // Some constants. This is a threshold value
#define ETA 0.001 // This is the default learning rate

class LinearRegression{
    private:
        uint64_t d; // The dimensions of the feature vector x. Each datapoint is a (dx1 vector,scalar)
        matrix weights; // The weights are a dx1 vector
        matrix weights_; // This is the value of weights obtained using the closed form solution when bias is not present
        double bias;
        double epsilon; // Convergence threshold
        double eta; // Learning rate
        uint64_t max_iterations; // To ensure that the algorithm terminates in finite time in case convergence is not achieved
        vector<double> train_loss; // Stores the loss from train data after every 100th iteration in gradient descent

    public:
        /*
            * Input is a matrix of dimensions n x d where each row of the matrix is a feature vector and there are n 
            * vectors each of dimensions d x 1.
            * The true output values is another matrix of dimensions n x 1 
            * Predictions are done as y_pred = x.T o w 
            * For the entire dataset X, Y_pred = Xw
        */
        LinearRegression(uint64_t); // Constructor
        double l2loss(matrix X, matrix Y); // Finds the mean squared loss given the input data and the true output values
        pair<matrix,double> l2lossDerivative(matrix X, matrix Y); // Computes the gradient given input data and true output values and returns dL/dw and dL/db
        void GD(matrix X, matrix Y, double learing_rate, uint64_t limit); // Performs gradient descent given the input data, true output values,learning rate and a maximum limit for iterations
        void train(matrix X_train, matrix Y_train, double learning_rate, uint64_t limit); // This function calls gradient descent
        void test(matrix X_test, matrix Y_test); // This funcion calls predict and displays the results
        matrix predict(matrix X); // Computes the ouput matrix Y = Xw + b
        double accuracy(matrix,matrix); // Computes the accuracy of the model as defined in README.md
};

pair<pair<matrix, matrix>, pair<matrix, matrix>> test_train_split(matrix X, matrix Y, float ratio); // To split the input dataset into train and test data
#endif
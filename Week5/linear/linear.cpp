#include "linear.h"

LinearRegression::LinearRegression(uint64_t D){
    d = D;
    weights = zeros(d,1);
    weights_ = zeros(d,1);
    bias = 0;
    epsilon = EPS;
    eta = ETA;
}

double LinearRegression::l2loss(matrix X, matrix Y){
    matrix Y_pred = matmul(X,weights) + bias;
    __size d1 = Y.shape(), d2 = Y_pred.shape();
    if (d1 != d2){
        throw std::invalid_argument("Cannot compute loss of vectors with dimensions ( "+to_string(d1.first)+" , "
        +to_string(d1.second)+" ) and ( "+to_string(d2.first)+" , "+to_string(d2.second)+" ) do not match");
    }
    double loss = 0;
    // Compute the mean squared loss as defined in README.md
    return loss;
}

pair<matrix, double> LinearRegression::l2lossDerivative(matrix X, matrix Y){
    matrix Y_pred = matmul(X,weights) + bias;
    __size d1 = Y.shape(), d2 = Y_pred.shape();
    if (d1 != d2){
        throw std::invalid_argument("Cannot compute loss derivative of vectors with dimensions ( "+to_string(d1.first)+" , "
        +to_string(d1.second)+" ) and ( "+to_string(d2.first)+" , "+to_string(d2.second)+" ) do not match");
    }
    //Compute gradients as defined in README.md
    matrix dw(d,1);
    double db; 
    return {dw,db};
}

matrix LinearRegression::predict(matrix X){
    matrix Y_pred(X.shape().first,0);
    // Using the weights and bias, find the values of y for every x in X
    return Y_pred;
}  

void LinearRegression::GD(matrix X, matrix Y,double learning_rate, uint64_t limit){
    eta = learning_rate;
    double old_loss = 0,loss = l2loss(X,Y);
    train_loss.PB(loss);
    uint64_t iteration = 0;
    max_iterations = limit;
    while (fabs(loss - old_loss) > epsilon && iteration < max_iterations){
        // Calculate the gradients and update the weights and bias correctly. Do not edit anything else 
        if (iteration %100 == 0) train_loss.PB(loss);
        iteration++;
    }
}

void LinearRegression::train(matrix X,matrix Y,double learning_rate, uint64_t limit){
    /* 
     * These lines are for computing the closed form solution of weights in the case of zero bias. 
     * This is merely a reference and you do not need to try and match the predictions from the trained weights with 
     * those from weight_. 
     * However you do need to get a good enough accuracy and that is obtained by varying the learning rate and 
     * maximum number of iterations .
    */
    matrix Xt = X.transpose();
    matrix Z = matmul(Xt,X);
    GD(X,Y,learning_rate,limit);
    weights_ = matmul((Z.inverse()),matmul(Xt,Y));
    cout << "Training Loss\n";
    for (uint64_t i = 0; i < train_loss.size() ; i++){
        cout << train_loss[i] << "\n";
    }
}

void LinearRegression::test(matrix X,matrix Y){
    matrix Y_pred = predict(X);
    uint64_t n = X.shape().first;
    matrix Y_closed = matmul(X,weights_);
    cout << "Predictions(GD) \t Predictions(C) \t True Value\n"; 
    for (uint64_t i = 0 ; i < n ; i++){
        cout << Y_pred(i,0) << "\t\t\t "<< Y_closed(i,0) << "\t\t\t " << Y(i,0) << "\n";
    }
    cout << "Testing loss " << l2loss(X,Y) << "\n";
    cout << "Testing accuracy " << accuracy(Y_pred,Y) << "\n";
}

double LinearRegression::accuracy(matrix Y_pred, matrix Y){
    double acc = 0; 
    // Compute the accuracy of the model
    return acc;
}

pair<pair<matrix, matrix>, pair<matrix, matrix>> test_train_split(matrix X, matrix Y, float ratio) {
    if (ratio < 0 || ratio > 1) {
        throw std::invalid_argument("Ratio must be between 0 and 1");
    }

    uint64_t n = X.shape().first;
    uint64_t train_size = static_cast<uint64_t>(n * ratio);
    uint64_t test_size = n - train_size;

    std::vector<uint64_t> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    matrix X_train(train_size, X.shape().second);
    matrix Y_train(train_size, 1);
    matrix X_test(test_size, X.shape().second);
    matrix Y_test(test_size, 1);

    for (uint64_t i = 0; i < train_size; ++i) {
        for (uint64_t j = 0; j < X.shape().second; ++j) {
            X_train(i, j) = X(indices[i], j);
        }
        Y_train(i, 0) = Y(indices[i], 0);
    }

    for (uint64_t i = 0; i < test_size; ++i) {
        for (uint64_t j = 0; j < X.shape().second; ++j) {
            X_test(i, j) = X(indices[train_size + i], j);
        }
        Y_test(i, 0) = Y(indices[train_size + i], 0);
    }

    return {{X_train, Y_train}, {X_test, Y_test}};
}
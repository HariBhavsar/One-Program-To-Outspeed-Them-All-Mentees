#include "regression.h"
#include <fstream>
#include <sstream>
using namespace std;

std::vector<double> split(const std::string &s, char delimiter) {
    std::vector<double> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(stod(token));
    }
    return tokens;
}

pair<matrix,matrix> parser(std::istream &input){

    vector<vector<double>> X_vec;
    vector<double> Y_vec;
    string line;
    while(getline(input,line)){
        vector<double> tokens=split(line,',');
        Y_vec.push_back(tokens[tokens.size()-1]);
        tokens.pop_back();
        X_vec.push_back(tokens);
    }
    
    matrix X((size_t)X_vec.size(), (size_t)X_vec[0].size());
    matrix Y((size_t)Y_vec.size(),1);
    
    for(int i=0; i<X_vec.size(); i++){
        for(int j=0; j<X_vec[0].size(); j++){
            X(i, j)=X_vec[i][j];
        }
    }
    Y.data=Y_vec;
    return {X,Y};
}
// Function to generate polynomial fittable dataset
pair<matrix, matrix> generate_polynomial_data(uint64_t n, uint64_t polynomial_degree) {
    matrix X(n,1);
    matrix Y(n,1);
    
    srand(time(0)); // Seed for random number generation
    
    // Generate random coefficients for polynomial terms
    vector<double> w(polynomial_degree + 1);
    for (uint64_t j = 0; j <= polynomial_degree; j++) {
        w[j] = static_cast<double>(rand()) / RAND_MAX;
    }

    // Generate data points
    for (uint64_t i = 0; i < n; i++) {
        double x = static_cast<double>(rand()) / RAND_MAX; // Random x in [0, 1)
        
        // Calculate Y value using polynomial equation
        double y = 0.0;
        for (uint64_t j = 0; j <= polynomial_degree; j++) {
            y += w[j] * pow(x, j);
        }
        
        // Add some noise
        y += 0.1 * static_cast<double>(rand()) / RAND_MAX;

        X(i,0) = x;
        Y(i,0) = y;
    }
    
    return make_pair(X, Y);
}

int main() {
    // Seed for random number generation
    srand(time(0));

    // Generate sample polynomial data
    uint64_t n = 10000;               // Number of data points
    uint64_t polynomial_degree = 10;  // Degree of polynomial (e.g., cubic polynomial)
    auto data = parser(std::cin);
    // cout<<"Reached here\n";
    matrix X = data.first;
    matrix Y = data.second;

    // Split the data into training and testing sets
    float split_ratio = 0.8;
    auto split_data = test_train_split(X, Y, split_ratio);
    matrix X_train = split_data.first.first;
    matrix Y_train = split_data.first.second;
    matrix X_test = split_data.second.first;
    matrix Y_test = split_data.second.second;

    // Create and train the linear regression model
    Regression r(polynomial_degree);
    double learning_rate = 0.01;
    uint64_t limit = 10000;
    r.train(X_train, Y_train, learning_rate, limit);
    cout<<"===========================================\n";
    // Test the model
    r.test(X_test, Y_test);

    return 0;
}

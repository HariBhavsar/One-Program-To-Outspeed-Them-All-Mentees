# Linear Regression
- Given a dataset $\mathcal{D} = \{X,Y\}$, where $X \in \mathbb{R}^{n\times d}$ and $Y \in \mathbb{R}^{n}$ with $(X_{i},Y_{i})$ representing the $i^{th}$ datapoint in the dataset, linear regression aims to find a _linear_ relation between the elements of the pair $(X_{i},Y_{i})$ $\forall i \in [0,n - 1]$
- Each datapoint consists of an input vector or feature vector $X_{i}$ which is a $d-$ dimensional vector ie, $X_{i} \in \mathbb{R}^{d}$ and a scalar value or label $Y_{i}$.
- The goal of linear regression is to find a linear function $f$ and a constant term $b$ that for every pair $(\vec{x_{i}},y_{i}) \in (X,Y)$, best approximates $y_{i} \text{ as } f(\vec{x_i}) + b$.
- The function $f$ can also be denoted as a $d-$ dimensional vector $\vec{w}$ so the goal is to "learn" the values of $w_{1},w_{2},\dots w_{d}$ and $b$ that give the best possible results.

# How do we define Results?

- As seen in the previous section, our goal is to get the best possible results/approximations for the dataset that is given. A natural critera would be to minimise errors. More specificially, minimising the squared error is done in linear regression. This is because the equations become easier to handle.
- The error is defined as
  ```math
  \mathcal{L}(\vec{w},b | (X,Y)) = \frac{1}{n}\sum\limits_{i = 0}^{n - 1} (\vec{w}\cdot \vec{x_{i}} + b - y_{i})^{2}
  ```
- We will use gradient descent to minimise the error function.

# Gradient Descent

- Gradient descent involves computing the gradient of the loss function with respect to $\vec{w}$ and $b$ and then updating the value of $\vec{w}$ and $b$ using the respective gradients.
- The gradient is defined as:
```math
\begin{align}
  \vec{\nabla}_{\vec{w}} \mathcal{L}(\vec{w},b)  &= \frac{1}{n} \sum\limits_{i = 0}^{n - 1} (\vec{w}\cdot \vec{x_{i}} + b - y_{i})\vec{x_{i}} \\
  \frac{\partial \mathcal{L}(\vec{w},b)}{\partial b}  &= \frac{1}{n} \sum\limits_{i = 0}^{n - 1} (\vec{w}\cdot \vec{x_{i}} + b - y_{i}) \\
\end{align}
```

- The algorithm is
```math
\begin{align*} \text{repeat}&\text{ until convergence:} \lbrace \newline 
 \vec{w} &= \vec{w} -  \alpha \vec{\nabla}_{\vec{w}} \mathcal{L}(\vec{w},b)\newline 
 b &= b -  \alpha \frac{\partial \mathcal{L}(\vec{w},b)}{\partial b}  \newline \rbrace
\end{align*}
```
where, parameters $w$, $b$ are updated simultaneously.  

# The Overall Picture
- Given a labelled dataset $\mathcal{D}$ we split it to portions-
    - Train Dataset : This is the data we pass to our model to train it. This is the data on which gradient descent is performed to obtain the optimal weights. 
    - Test Dataset : This is the data we use to test our model once it is done training. We predict values using the trained weights and then compute the loss to check it's accuracy.
    - The metric of accuracy is defined as      
```math
 A = \frac{1}{n}\sum\limits_{i = 1}^{n} \frac{(\left\lvert \vec{w} \cdot \vec{x_{i}} + b - y_{i} \right\rvert)}{\left\lvert y_{i}\right\rvert}
```

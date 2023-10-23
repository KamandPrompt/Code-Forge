"""
The Kalman filter is an efficient recursive filter estimating the internal state
of a linear dynamic system from a series of noisy measurements. (It essentially
analyzes errors and tries to correct readings accordingly)
Implementation of a Python code for a Kalman Filter using the Numpy package.
Kalman Filtering is carried out in two steps:
1. Prediction
2. Update

Use Cases: Can be used for stochastic estimation from noisy sensor measurements
"""

import numpy
import numpy.linalg
import numpy.random
import matplotlib.pyplot as plt

# Code Functions
def kalman_predict(prev_x, prev_cov, transition_mat, process_noise_cov, inp_effect_mat, control_inp):
    """
    PARAMETERS:
    prev_x            : The mean state estimate of the previous step (k − 1)
    prev_cov          : The state covariance of previous step (k − 1)
    transition_mat    : The transition n x n matrix.
    process_noise_cov : The process noise covariance matrix.
    inp_effect_mat    : The input effect matrix.
    control_inp       : The control input.
    """
    prev_x = numpy.dot(transition_mat, prev_x) + numpy.dot(inp_effect_mat, control_inp)
    prev_cov = numpy.dot(transition_mat, numpy.dot(prev_cov, transition_mat.T)) + process_noise_cov
    return prev_x , prev_cov

def gauss_pdf(X, M, S):
    if M.shape[1] == 1:
        DX = X - numpy.tile(M, X.shape[1])
        E = 0.5 * numpy.sum(DX * (numpy.dot(numpy.linalg.inv(S), DX)), axis=0)
        E = E + 0.5 * M.shape[0] * numpy.log(2 * numpy.pi) + 0.5 * numpy.log(numpy.linalg.det(S))
        P = numpy.exp(-E)
    elif X.shape[1] == 1:
        DX = numpy.tile(X, M.shape[1])- M
        E = 0.5 * numpy.sum(DX * (numpy.dot(numpy.linalg.inv(S), DX)), axis=0)
        E = E + 0.5 * M.shape[0] * numpy.log(2 * numpy.pi) + 0.5 * numpy.log(numpy.linalg.det(S))
        P = numpy.exp(-E)
    else:
        DX = X-M
        E = 0.5 * numpy.dot(DX.T, numpy.dot(numpy.linalg.inv(S), DX))
        E = E + 0.5 * M.shape[0] * numpy.log(2 * numpy.pi) + 0.5 * numpy.log(numpy.linalg.det(S))
        P = numpy.exp(-E)
    return (P[0] ,E[0])

def kalman_update(prev_x, prev_cov, Y, H, R):
    """
    PARAMETERS and VARIABLES
    prev_x    : The mean state estimate of the previous step ( k −1).
    prev_cov  : The state covariance of previous step ( k −1).
    Y         : Measurement Vector
    H         : Measurement Matrix
    R         : Measurement Covariance Matrix
    K         : the Kalman Gain matrix
    IM        : the Mean of predictive distribution of Y
    IS        : the Covariance or predictive mean of Y
    LH        : the Predictive probability (likelihood) of measurement which is
                computed using the Python function gauss_pdf
    """
    IM = numpy.dot(H, X)
    IS = R + numpy.dot(H, numpy.dot(P, H.T))
    K = numpy.dot(P, numpy.dot(H.T, numpy.linalg.inv(IS)))
    prev_x = prev_x + numpy.dot(K, (Y-IM))
    prev_cov = prev_cov - numpy.dot(K, numpy.dot(IS, K.T))
    LH = gauss_pdf(Y, IM, IS)
    return (prev_x, prev_cov, K, IM, IS, LH)

"""
The most interesting field of application of Kalman Filter, in telecommunications, is
the tracking of a mobile user connected to a wireless network.

Presented is a simple tracking algorithm of a mobile user who is moving in a room
and connected to at least three wireless antennas.

The matrix of measurement Y describes the estimated position of the mobile using a
trilateration algorithm based on a least square estimation and the knowledge of at
least three values of Time of Arrival (ToA) at time step k .

These values are computed using ranging procedures between the mobile and the three
antennas

Starting by an initialization of different matrices and using the updated matrices for
each step and iteration, we plot the estimated, the real trajectory of the
mobile user, and the measurements performed by the least square based trilateration.

We draw the matrix Y randomly centered on the true value of mobile position
"""

#time step of mobile movement
dt = 0.1

# Initialization of state matrices
X = numpy.array([[0.0], [0.0], [0.1], [0.1]]) # State Mean of previous step
P = numpy.diag((0.01, 0.01, 0.01, 0.01)) # State Covariance of previous step
A = numpy.array([[1, 0, dt , 0], [0, 1, 0, dt], [0, 0, 1, 0], [0, 0, 0, 1]]) # Transition Matrix
Q = numpy.eye(X.shape[0]) # Process Noise
B = numpy.eye(X.shape[0]) # Input Effect Matrix
U = numpy.zeros((X.shape[0],1)) # Control Input

# Measurement matrices
Y = numpy.array([[X[0,0] + abs(numpy.random.randn(1)[0])], [X[1,0] +abs(numpy.random.randn(1)[0])]]) # True Position
H = numpy.array([[1, 0, 0, 0], [0, 1, 0, 0]]) # Measurement Matrix
R = numpy.eye(Y.shape[0]) # Measurement Covariance Matrix

# Number of iterations in Kalman Filter
N_iter = 50

# Applying the Kalman Filter
outputY=[[],[]]
outputIM=[[],[]]
outputX=[[],[]]
for i in range(N_iter):
    (X, P) = kalman_predict(X, P, A, Q, B, U)
    (X, P, K, IM, IS, LH) = kalman_update(X, P, Y, H, R)
    Y = numpy.array([[X[0,0] + abs(0.1 * numpy.random.randn(1)[0])],[X[1, 0] + abs(0.1 * numpy.random.randn(1)[0])]])

    outputY[0].append(Y[0])
    outputY[1].append(Y[1])

    outputIM[0].append(IM[0])
    outputIM[1].append(IM[1])

    outputX[0].append(X[0])
    outputX[1].append(X[1])

# Visualizing
plt.plot(outputY[0],outputY[1], label = "Real Trajectory")
plt.plot(outputIM[0][1:],outputIM[1][1:], label = "Predicted Trajectory")
plt.plot(outputX[0],outputX[1], label = "Measured Trajectory")
plt.legend()
plt.xlabel("x (m)")
plt.ylabel("y (m)")
plt.title("Comparison of Real and Estimated")
plt.show()

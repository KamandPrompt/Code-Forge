import sys

sys.path.append('/Users/vayungoel/Desktop/Code-Forge/ML_Algorithms')

from Linear_Regression.linear_regression import LinearRegression2D

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

n = int(input("Enter 1 for generating equation of a plane without noise\nEnter 2 for generating equation of a plane with gaussian noise\nEnter 3 for generating equation of a non-linear curve\n"))

num_points = 500

x1 = np.random.rand(num_points) * 10  
x2 = np.random.rand(num_points) * 10  

if(n<=2):

    a = 1.0
    b = 2.0
    c = 4.0
    y = a * x1 + b * x2 + c

if(n==2):
    noise = np.random.normal(0, 2, num_points)  
    y = (y + noise)

if(n==3):
    a = 1.0
    b = 2.0
    c = 0.5
    d = 0.02
    e = 0.01
    f = 2.0
    y = a * x1 + b * x2 + (x1*x2*c) + (x1*x2*x2*d) + (x1**4)*e + f

points = [[0 for i in range(3)] for j in range(500)]

for i in range(500):
    points[i][0]=x1[i]
    points[i][1]=x2[i]
    points[i][2]=y[i]

if(n<=2):
    a = LinearRegression2D(points,1)
else:
    a = LinearRegression2D(points,2)

t = a.visualizer()

points = np.array(points)

x_surf = np.linspace(0, 10, 100)
y_surf = np.linspace(0, 10, 100)
X, Y = np.meshgrid(x_surf, y_surf)

print(t)

for i in range(len(t)):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    Z = (float(t[i][0])* X + float(t[i][1]) * Y + float(t[i][2])) 
    ax.scatter(x1, x2, y, c='b', marker='o')
    ax.plot_surface(X, Y, Z, alpha=0.5, rstride=100, cstride=100, cmap='viridis')
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    plt.show()
import matplotlib.pyplot as plt
import numpy as np

from ML_Algorithms.Logistic_Regression.logistic_regression import logisticRegression

n = int(input("enter the number of points you want to visualize: "))

points = [[0 for i in range(2)] for j in range(n)]

for i in range(n):
    points[i][0] = int(input(f"enter the coordinate of point {i+1} : "))
    points[i][1] = int(input(f"enter the label (class 0 or 1) of point {i+1} : "))

print(points)

a = logisticRegression(points)

t = a.visualizer()

points = np.array(points)

print(points)

for i in range(n-1):
    for j in range(0, n-i-1):
        if points[j][0] > points[j + 1][0]:
            points[j][0], points[j + 1][0] = points[j + 1][0], points[j][0]

colormap = np.array(['r', 'b'])

for i in range(len(t)):
    plt.subplot(1,1,1)

    plt.scatter(points[:,0], points[:,1], c=colormap[points[:,1]], label='class 0 => red and class 1 => blue')

    plt.axvline( x = ((-1*float(t[i][1]))/float(t[i][0])), color='black', linestyle='--', label='seperation line')

    plt.xlabel('points')
    plt.ylabel('class')
    if(i==0):
        plt.title("initial plot")
    elif(i==1):
        plt.title(f"plot after 4 epochs")
    elif(i<len(t)-1):
        plt.title(f"plot after 4 more epochs")
    else:
        plt.title("final plot after 1000 more epochs")
    plt.legend()
    plt.grid(True)
    plt.show()


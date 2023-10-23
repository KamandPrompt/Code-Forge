import math
import numpy as np

class LinearRegression2D():

    def __init__(self,points,per_graph_epochs):
        self.points=points
        self.per_graph_epochs = per_graph_epochs

    def dot_product(self,x,w,b):
        z = 0.0
        z = z + float(x[0])*float(w[0])
        z = z + float(x[1])*float(w[1]) 
        z = z + float(b)
        return float(z)

    def loss_function(self,w,b):
        mse = 0.0
        for i in range(len(self.points)):
            z = self.dot_product(self.points[i],w,b)
            mse = mse + math.pow((self.points[i][0]-z),2)
        mse = (mse / float(len(self.points)))
        return mse

    def grad_descent(self,epochs,w,b):
        for i in range(epochs):
            del_w = [0.0 , 0.0]
            del_b = 0.0
            m = len(self.points)
            for j in range(m):
                h = self.dot_product(self.points[j],w,b)
                del_w[0] = del_w[0] + (float(self.points[j][0])*(float(h) - float(self.points[j][2])))
                del_w[1] = del_w[1] + (float(self.points[j][1])*(float(h) - float(self.points[j][2])))
                del_b = del_b + (float(h) - float(self.points[j][2]))
            del_w[0] = del_w[0] / float(m)
            del_w[1] = del_w[1] / float(m)
            del_b = del_b / float(m)
            print(del_w)
            print(del_b)
            w[0] = w[0] - 0.005*float(del_w[0])
            w[1] = w[1] - 0.005*float(del_w[1])
            b = b - 0.05*float(del_b)
        return w, b
    
    def visualizer(self):
        w = [np.random.randn() for i in range(len(self.points[0])-1)]
        b = np.random.randn()
        # print(w,b)
        arr = [[0 for i in range(len(w)+1)] for j in range(7)]
        for i in range(len(w)):
            arr[0][i] = w[i]
        arr[0][2] = b
        for i in range(5):
            w,b = self.grad_descent(int(self.per_graph_epochs),w,float(b))
            arr[i+1][0] = w[0]
            arr[i+1][1] = w[1]
            arr[i+1][2] = b
        w,b = self.grad_descent(2000,w,b)
        arr[6][0] = w[0]
        arr[6][1] = w[1]
        arr[6][2] = b
        return arr

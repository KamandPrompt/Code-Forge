import math

class logisticRegression():

    def __init__(self,points):
        self.points=points

    def sigmoid(self,x,w,b):
        z = float(x)*float(w) + float(b)
        h = 1.0 / (1.0 + math.exp((-1.0 * z)))
        return h

    def grad_descent(self,epochs,w,b):
        for i in range(epochs):
            del_w = 0.0
            del_b = 0.0
            m = len(self.points)
            for j in range(len(self.points)):
                h = self.sigmoid(self.points[j][0],w,b)
                del_w = del_w + (float(self.points[j][0])*(float(h) - float(self.points[j][1])))
                del_b = del_b + (float(h) - float(self.points[j][1]))
            del_w = del_w / float(m)
            del_b = del_b / float(m)
            w = w - 0.1*float(del_w)
            b = b - 0.1*float(del_b)
        return w,b
    
    def visualizer(self):
        w = 1
        b = 0
        arr = [[0 for i in range(2)] for j in range(6)]
        arr[0][0] = w
        arr[0][1] = b
        for i in range(4):
            w,b = self.grad_descent(4,w,b)
            arr[i+1][0] = w
            arr[i+1][1] = b
        w,b = self.grad_descent(1000,w,b)
        arr[5][0] = w
        arr[5][1] = b
        return arr


            



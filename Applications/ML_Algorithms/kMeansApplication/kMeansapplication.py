import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets

class K_Means:
    def __init__(self, k=2, max_iter=100, tol=0.001):
        self.k = k
        self.max_iter = max_iter
        self.tol = tol
        

    def fit(self,data):

        self.centroids = {}

        for i in range(self.k):
            self.centroids[i] = data[i]

        for i in range(self.max_iter):
            self.classifications = {}

            for i in range(self.k):
                self.classifications[i] = []

            for featureset in data:
                distances = [np.linalg.norm(featureset-self.centroids[centroid]) for centroid in self.centroids]
                classification = distances.index(min(distances))
                self.classifications[classification].append(featureset)

            prev_centroids = dict(self.centroids)

            for classification in self.classifications:
                self.centroids[classification] = np.average(self.classifications[classification],axis=0)

            optimized = True

            for c in self.centroids:
                original_centroid = prev_centroids[c]
                current_centroid = self.centroids[c]
                if np.sum((current_centroid-original_centroid)/original_centroid*100.0) > self.tol:
                    # print(np.sum((current_centroid-original_centroid)/original_centroid*100.0))
                    optimized = False

            if optimized:
                break

    def predict(self,data):
        distances = [np.linalg.norm(data-self.centroids[centroid]) for centroid in self.centroids]
        classification = distances.index(min(distances))
        return classification


# Set three centers, the model should predict similar results
center_1 = np.array([1,1])
center_2 = np.array([5,5])
center_3 = np.array([8,1])

# Generate random data and center it to the three centers
data_1 = np.random.randn(200, 2) + center_1
data_2 = np.random.randn(200,2) + center_2
data_3 = np.random.randn(200,2) + center_3

train_data = np.concatenate((data_1, data_2, data_3), axis = 0)

# plt.scatter(train_data[:,0], train_data[:,1], s=7)
# plt.show()
# plt.clf()

model=K_Means(k=3)
model.fit(data=train_data)
plt.scatter(train_data[:,0], train_data[:,1],s=2)
centroids = np.array(list(model.centroids.values()))  
plt.scatter(centroids[:,0],centroids[:,1],s=10, c='red')
plt.show()
plt.clf()

# Calculate error between original centroids and predicted centroids
original_centroids = np.array([ center_1,center_2, center_3])
error_between_centroids = np.linalg.norm(centroids - original_centroids, axis=1)
print("Error between original and predicted centroids:")
for i, err in enumerate(error_between_centroids):
    print(f"Centroid {i+1}: {err}")


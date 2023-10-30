import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets

class K_Means:
    def __init__(self, k=2, max_iter=100, tol=0.001):  
        self.k = k
        # k= number of clusters
        self.max_iter = max_iter
        #  max_iter= maximum number of times to iterate through the dataset 
        self.tol = tol
        # tol= maximum tolerance level in the output
        

    def fit(self,data):
        # Initializing the centroid for each cluster 
        self.centroids = {}

        # Taking random points as centroid
        for i in range(self.k):
            self.centroids[i] = data[i]

        for i in range(self.max_iter):
            self.classifications = {}

            for i in range(self.k):
                self.classifications[i] = []

            for featureset in data:
                
                # Calculating distance from each centroid
                distances = [np.linalg.norm(featureset-self.centroids[centroid]) for centroid in self.centroids]
                
                #Finding the centroid from which distance is minimum
                classification = distances.index(min(distances))
                self.classifications[classification].append(featureset)

            prev_centroids = dict(self.centroids)

            # Finding the new centroid on the basis of new classified points
            for classification in self.classifications:
                self.centroids[classification] = np.average(self.classifications[classification],axis=0)

            optimized = True

            #Checking if the centroid each cluster converge
            for c in self.centroids:
                original_centroid = prev_centroids[c]
                current_centroid = self.centroids[c]
                
                # Comparing the previous and new centroids
                if np.sum((current_centroid-original_centroid)/original_centroid*100.0) > self.tol:
                    # print(np.sum((current_centroid-original_centroid)/original_centroid*100.0))
                    optimized = False
             
            # If the centroids converge then it is done else again iterate through the whole dataset and find the new centroids   
            if optimized:
                break


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

#creating a model with number of cluster=3
model=K_Means(k=3)
#fitting the data
model.fit(data=train_data)
plotting the data
plt.scatter(train_data[:,0], train_data[:,1],s=2)
centroids = np.array(list(model.centroids.values()))  
#plotting the centroids
plt.scatter(centroids[:,0],centroids[:,1],s=10, c='red')
plt.show()
plt.clf()

# Calculate error between original centroids and predicted centroids
original_centroids = np.array([ center_1,center_2, center_3])
error_between_centroids = np.linalg.norm(centroids - original_centroids, axis=1)
print("Error between original and predicted centroids:")
for i, err in enumerate(error_between_centroids):
    print(f"Centroid {i+1}: {err}")


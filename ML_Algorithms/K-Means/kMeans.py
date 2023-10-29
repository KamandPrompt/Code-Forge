# Code for kMeans algorithm which is an Unsupervised Learning algorithm, which groups the unlabeled dataset into different clusters

import numpy as np

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

    def predict(self,data):
        # Calculating the distance of test data from the centroid of each cluster
        distances = [np.linalg.norm(data-self.centroids[centroid]) for centroid in self.centroids]
        # Classify the data with the cluster from which distance is minimum 
        classification = distances.index(min(distances))
        return classification

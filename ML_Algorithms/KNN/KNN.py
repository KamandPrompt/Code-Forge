import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics.pairwise import euclidean_distances
from sklearn.metrics import confusion_matrix
from sklearn import metrics
import numpy as np
import seaborn as sns 

df=pd.read_csv("Iris.csv")

X=df[df.columns[:4]]
Y=list(df[df.columns[-1]])#taking last column as target attribute,assigning to Y

#splitting data into test set and training set
X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size =1/5, random_state = 104,shuffle=True)

#knn classification

X_train =np.array(X_train)
X_test =np.array(X_test)

def knn_classifier(X_train, y_train, X_test,i):
    y_pred = []
    for test_sample in X_test:
        # Compute distances between the test sample and all training samples
        distances = [np.linalg.norm(test_sample - train_sample) for train_sample in X_train]
        # Get indices of the k-nearest neighbors
        k_indices = np.argsort(distances)[:i]
        # Get the labels of the k-nearest neighbors
        k_nearest_labels = [y_train[i] for i in k_indices]
        # Predict the class label based on majority vote
        y_pred.append(max(set(k_nearest_labels), key = k_nearest_labels.count))
    return y_pred    
predicted = knn_classifier(X_train,y_train,X_test,5)         

#confusion metrics 
y_test = list(np.array(y_test))
print(y_test)
predicted = list(np.array(predicted))

confusion_matrix = np.array(metrics.confusion_matrix(y_test,predicted))

print(confusion_matrix)


class_names = np.unique(Y)  
confusion_matrix = np.array([[12, 0, 0],
                              [0, 12, 0],
                              [0, 0, 6]])
plt.figure(figsize=(8, 6))
sns.heatmap(confusion_matrix, annot=True, fmt='d', cmap='Blues', cbar=False,xticklabels=class_names ,yticklabels= class_names)

plt.xlabel('Predicted')
plt.ylabel('Actual')
plt.title('Confusion Matrix')
plt.show()
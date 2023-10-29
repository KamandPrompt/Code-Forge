import pandas as pd
from sklearn.datasets import load_iris
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC


iris = load_iris()

# creating pandas dataframe of dataset 
df = pd.DataFrame(iris.data,columns=iris.feature_names)
print(df.head())

df['target'] = iris.target
df.head()
#Adding the flower name on the basis of target
df['flower_name'] =df.target.apply(lambda x: iris.target_names[x])

X = df.drop(['target','flower_name'], axis='columns')
y = df.target

# Splitting the dataset into train and test (80-20)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

#creating support vector classification model with linear kernel
#c= regularizaion parameter
model = SVC(C=10,kernel='linear')
#Fitting the data
model.fit(X_train, y_train)

#Calculating the mean accuracy
print(model.score(X_test, y_test))

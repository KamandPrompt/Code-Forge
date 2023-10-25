import numpy as np
import pandas as pd

def euclidean_distance(x1,x2):
    distance=0
    for i in range(len(x1)):
        distance+=np.square(x1[i]-x2[i])
    return distance

def knn(training_x,training_y,testing_x):
    predictions=[]
    for i in range(len(testing_x)):
        distance=[]
        for j in range(len(training_x)):
            distance.append(euclidean_distance(testing_x[i],training_x[j]))
        mydict={"class":training_y,"Distances":distance}
        distance_df=pd.DataFrame.from_dict(mydict)
        sorted_distance = distance_df.sort_values(by=["Distances"])
        predict_labels=sorted_distance["class"][:5]
        predicted_label=predict_labels.value_counts().index.tolist()[0]
        predictions.append(predicted_label)
    return predictions

train_df=pd.read_csv("Code-Forge\ML_Algorithms\KNN\iris_train.csv")
train_x=train_df.drop("Species",axis=1).to_numpy()
train_y=train_df["Species"].to_numpy()

test_df=pd.read_csv("Code-Forge\ML_Algorithms\KNN\iris_test.csv")
test_x=test_df.drop("Species",axis=1).to_numpy()
test_y=test_df["Species"].to_numpy()

predictions=knn(train_x,train_y,test_x)

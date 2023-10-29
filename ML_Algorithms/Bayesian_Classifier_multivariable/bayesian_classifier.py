#B22147 Yash Sehgal
import numpy as np
import pandas as pd
import math
from matplotlib import pyplot as plt
from sklearn.model_selection import train_test_split
#the multivariable _normal function from scipy library enables us to calculate the parameter vector for multiparameter data
from scipy.stats import multivariate_normal
from sklearn.metrics import confusion_matrix,ConfusionMatrixDisplay
x=pd.read_csv("https://raw.githubusercontent.com/uiuc-cse/data-fa14/gh-pages/data/iris.csv")
y=x["species"]
train_data,test_data,train_target,test_target=train_test_split(x,y,random_state=104,test_size=0.2,shuffle=True)
def bay_class(train_df, pre_df_target, pre_df_test):
    classes = train_df['species'].unique()
    P_C_list = {}
    mean_v_list = {}
    cov_mat_list = {}
    for cl in classes:
        P_C = len(train_df[train_df['species'] == cl]) / len(pre_df_target)
        P_C_list[cl] = P_C
        class_data = train_df[train_df['species'] == cl].iloc[:, 0:4]
        mean_v = class_data.mean().values
        mean_v_list[cl] = mean_v
        cov_mat = np.cov(class_data, rowvar=False)
        cov_mat_list[cl] = cov_mat
    test_d = pre_df_test.iloc[:, 0:4]
    predicted_list = []
    for i in range(len(test_d)):
        p_ci_x = {}
        p_x = {}
        p_x_ci = {}
        for cl in classes:
            p_x_ci[cl] = multivariate_normal.pdf(test_d.iloc[i], mean=mean_v_list[cl], cov=cov_mat_list[cl])
            p_x[cl] = p_x_ci[cl] * P_C_list[cl]
        total_prop = sum(list(p_x.values()))
        for cl in classes:
            p_ci_x[cl] = (p_x_ci[cl] * P_C_list[cl]) / total_prop
        pre_class = max(p_ci_x, key=p_ci_x.get)
        predicted_list.append(pre_class)
    return predicted_list
predicted=bay_class(train_data,train_target,test_data)
cm=confusion_matrix(list(test_target),predicted,labels=['setosa','versicolor','virginica'])
# accuracy is the trace of the confusion matrix upon total number of test samples
# the i==j values of a matrix aij tells us how much predictions were accurate
accuracy=(np.trace(cm)/len(test_target))*100
print("the accuracy is : ",accuracy)
disp=ConfusionMatrixDisplay(confusion_matrix=cm,display_labels=['setosa','versicolor','virginica'])
disp.plot()
plt.show()
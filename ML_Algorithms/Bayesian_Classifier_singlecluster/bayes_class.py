import numpy as np
import pandas as pd
import math
from sklearn.metrics import confusion_matrix,ConfusionMatrixDisplay
from matplotlib import pyplot as plt
#segregation of the train data and test data and train target and test target
train_data=pd.read_csv("iris_train.csv")
train_target=train_data['Species']
train_data.drop(['Unnamed: 0','Species'], axis=1, inplace=True)
test_data=pd.read_csv("iris_test.csv")
test_target=test_data['Species']
test_data.drop(['Unnamed: 0','Species'], axis=1, inplace=True)
#here the function is impleted for replacement of the outliers with the median if there are any
def replace_outliers(list_1):
    q1=np.quantile(list_1,0.25)
    q3=np.quantile(list_1,0.75)
    iqr=q3-q1
    for i in range(len(list_1)):
        if(list_1[i]<q1-(1.5*iqr) or list_1[i]>q3+1.5*iqr):
            list_1[i]=np.median(list_1)
    return list_1
# here some statistical functions ar implemnted that might be useful although numpy functions can also be used
def cal_mean(list_1):
    tot=sum(list_1)/len(list_1)
    return tot
def cal_std(list_1):
    mean_list=cal_mean(list_1)
    mean_sub_list=[(i-mean_list)**2 for i in list_1]
    res=(sum(mean_sub_list)/(len(list_1)))
    res=np.sqrt(res)
    return res
def likelihood(x,pre_df):
    mean_data=cal_mean(list(pre_df))
    std_data=cal_std(list(pre_df))
    val=(1/((std_data)*np.sqrt(2*np.pi)))*(math.exp(-(((x-mean_data)**2)/(2*(std_data)**2))))
    return val
# here the PCA (Principal component analysis is implemented for the purpose of dimensionality reduction)
def pca_im(df,n_comp):
    atrr_list=list(df.columns)
    for i in atrr_list:
        df[i]=replace_outliers(df[i])
    mean_sub_data=pd.DataFrame()
    for i in atrr_list:
        mean_sub_data[i]=(df[i]-cal_mean(df[i]))
    covariance_mat=pd.DataFrame(np.matmul(np.transpose(np.array(mean_sub_data)),np.array(mean_sub_data)),index=atrr_list,columns=atrr_list)
    eig_val,eig_vec=np.linalg.eig(covariance_mat)
    eig_vec=pd.DataFrame(eig_vec)
    sig_eig_vec=eig_vec.iloc[:,0:n_comp]
    red_mat=pd.DataFrame(np.matmul(np.array(mean_sub_data),np.array(sig_eig_vec)))
    return red_mat
def max_dict_val(dict_1):
    max_index=list(dict_1.keys())[0]
    max_ele=dict_1[max_index]
    for i in dict_1.keys():
        if(dict_1[i]>=max_ele):
            max_index=i
            max_ele=dict_1[i]
    return max_index
# here is the main function for the  baysian classifier
def bay_class(pre_df,pre_df_target,pre_df_test):
    set_tar=set(pre_df_target)
    tot_class=len(pre_df_target)
    P_C={}
    P_C_ele={}
    predicted_list=[]
    for i in set_tar:
        P_C_ele[i]=list(pre_df.iloc[:,0][pre_df_target==i])
        P_C[i]=len(P_C_ele)/tot_class
    
    pre_df_test=list(pre_df_test.iloc[:,0])
    for  i in pre_df_test:
        tot_p_list=[]
        for j in set_tar:
            p_x_ci=(likelihood(i,P_C_ele[j]))*P_C[j]
            tot_p_list.append(p_x_ci)
        tot_p=sum(tot_p_list)
        p_ci_x_list={}
        for k in set_tar:
            p_ci_x=((likelihood(i,P_C_ele[k]))*P_C[k])/tot_p
            p_ci_x_list[k]=p_ci_x
        class_x=max_dict_val(p_ci_x_list)
        predicted_list.append(class_x)     

    return predicted_list

pre_df=pca_im(train_data,1)
pre_df_test=pca_im(test_data,1)
list_bayes=bay_class(pre_df,train_target,pre_df_test)
label=list(set(train_target))

cm=confusion_matrix(list(test_target),list_bayes,labels=['Iris-setosa','Iris-versicolor','Iris-virginica']) 
print(cm)
accuracy=(np.trace(cm)/len(test_target))*100
print("Accuracy of the predicion is : ",round(accuracy,2))
disp=ConfusionMatrixDisplay(confusion_matrix=cm,display_labels=label)
disp.plot()
plt.show()

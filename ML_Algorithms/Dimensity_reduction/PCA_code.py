#Link to CSV file:-  https://drive.google.com/file/d/1_NkZeCrDIpEpUkh9uMLubBcS361UEdBW/view?usp=drive_link


# Dimensity reduction using Principal component analysis(PCA)

#importing neccesary libraries
import pandas as pd
import matplotlib.pyplot as plt
import math
import numpy as np

#Reading CSV file "Iris.csv"
df=pd.read_csv("Iris.csv")
# print(df)

Y=list(df[df.columns[-1]])        #taking last column as target attribute,assigning to Y
# print(Y)

column_names = df.columns[0:4]                #Obtaining column names

def replace_outliers_with_median(df, column_names):
    #alloting details of data to description
    description = df.describe()
    print('Outliers:\n')
    for col in column_names:
        outliers = []
        #defining lower and upper quartile
        lower_quartile = description[col]['25%']
        upper_quartile = description[col]['75%']
        #defining IQR range
        inter_quartile_range = upper_quartile - lower_quartile
        #finding median
        median_cal = df[col].median()
        #detecting outlier in the data
        for i in range(len(df)):
            #checking from given condition
            if not (lower_quartile - 1.5 * inter_quartile_range < df.loc[i, col] < upper_quartile + 1.5 * inter_quartile_range):
                outliers.append(df.loc[i,col])
                # Replace the outlier with the median
                df.loc[i, col] = median_cal
        #printing number of outliers in every column
        print(f'For {col}', "number of outliers:",len(outliers))
    return df
#alloting modified data to X
x = replace_outliers_with_median(df, column_names)[df.columns[0:4]]
# print('\nDataFrame with Outliers Replaced:\n', df)

#PERFORMING PCA
x_original=x.copy()
#Getting mean subtracted matrix
for i in x.columns:
  m1=np.mean(x[i])                            #Getting mean of each column
  for j in range(len(x)):
    x.loc[j,i]=(x[i][j]-m1)                   #subracting mean from every element of the column
x_mat=np.asmatrix(x.values)                   #converting dataframe into matrix
x_mat_t=np.transpose(x_mat)                   #finding transpose of the matrix
c=x_mat_t*x_mat                               #calculating value of C
eig_value, eig_vector1=np.linalg.eig(c)       #Performing eigen analysis and finding eigen value and eig vector

#
select_vector=[list(),list()]
eig_vector1=eig_vector1.tolist()
print(eig_vector1)
for i in range(4):
  select_vector[0].append(eig_vector1[i][0])
  select_vector[1].append(eig_vector1[i][1])
select_vector=np.asmatrix(select_vector)
x_reduced=x_mat*select_vector.transpose()
print("Dimension Reduced data:/n",x_reduced)

#plotting grapg of eigen vectors
plt.scatter(list(x_reduced[i].tolist()[0][0] for i in range(150)),list(x_reduced[i].tolist()[0][1] for i in range(150)))
select_vector=select_vector.tolist()
plt.quiver(1,0 ,select_vector[0][0],select_vector[0][1],angles='xy', scale_units='xy',color='red', scale=0.15, width=0.01)
plt.quiver(1,0, (select_vector[1][0]), (select_vector[1][1]),  angles='xy', scale_units='xy',color='red', scale=1.5, width=0.01)
plt.show()

x_reconstructed=x_reduced*select_vector        #Reconstructing the original data from reduced data
# print(x_reconstructed)

df2=pd.DataFrame(x_reconstructed)                   #converting to dataframe
df2.columns=x.columns
for i in x.columns:
  m1=np.mean(x_original[i])                         #Getting mean of each column
  for j in range(len(x)):
    df2.loc[j,i]=(df2[i][j]+m1)                     #adding mean from every element of the column
# print(df2)

rmse_list=list()                                                   #Calculting rmse difference between original and recreated data

for i in x.columns:
  d1=list(x_original[i])
  d2=list(df2[i])
  rmse=0
  for j in range(150):
    if d1[j]!=d2[j]:
      rmse+=(d1[j]-d2[j])**2                                       #summing up the square of difference for every element of the column
  rmse=rmse/len(d1)                                                #dividing the value by n
  rmse=math.sqrt(rmse)                                             #operating square root 
  rmse_list.append(rmse)
print("RMSE Values:",rmse_list)
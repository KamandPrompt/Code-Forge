'''
Netflix Stock Prediction using ARIMA Model
We will be using a dataset that contains stock price values of Netflix from 2018 to 2022.
Here in this project our aim is to predict the stock price for the next 30 days using ARIMA Model.
Analysis of dataset
We have 7 columns in the dataset list as follows:

Date- Everyday price
Open- Price at which stock opened
High- Today's High
Low- Today's Low
Close- Close price adjusted for splits
Adj. Close- Adjusted close price adjusted for splits and dividend and/or capital gain distributions.
Volume- Volume of stocks
'''

import pandas as pd
import numpy as np
import seaborn as sb

import matplotlib.pyplot as plt
#matplotlib inline

from scipy.stats import norm, skew #for some statistics
from scipy import stats #qqplot
import statsmodels.api as sm #for decomposing the trends, seasonality etc.

from statsmodels.tsa.statespace.sarimax import SARIMAX

df = pd.read_csv("/content/NFLX.csv")
df

df.drop(['Open', 'High', 'Low', 'Close', 'Volume'], axis=1, inplace=True)
df

print (df.isna().sum())

import matplotlib.pyplot as plt
import seaborn as sb
from scipy import stats
import pandas as pd

# Set the figure size
plt.figure(figsize=(4, 2))

# Create the distribution plot with a fitted normal curve
sb.distplot(df['Adj Close'], fit=stats.norm)

# Create the QQ-plot
fig, ax = plt.subplots()
stats.probplot(df['Adj Close'], plot=ax)

# Display the plots
plt.show()


df = df.groupby('Date')['Adj Close'].sum().reset_index()

df.Date=pd.to_datetime(df.Date)
df

df = df.set_index('Date')
df.head()


df.plot(figsize=(20,5))
plt.show()

from statsmodels.tsa.stattools import adfuller

def adfuller_test(time_series):
    result = adfuller(time_series)
    adf_statistic, p_value, lags_used, obs_used = result[:4]
    print(f'ADF Test Statistic: {adf_statistic:.6f}')
    print(f'p-value: {p_value:.6f}')
    print(f'#Lags Used: {lags_used}')
    print(f'#Observations Used: {obs_used}')

    if p_value <= 0.05:
        print('Strong evidence against null hypothesis; series is Stationary')
    else:
        print('Weak evidence against null hypothesis; series is not Stationary')

adfuller_test(df['Adj Close'])




# Calculating first-order differences
diff1 = df['Adj Close'].diff().dropna()
adfuller_test(diff1)

# Plotting the differenced data
diff1.plot(figsize=(20, 5))


pip install statsmodels


# Plotting the Autocorrelation Function (ACF)
fig, ax = plt.subplots(figsize=(8, 5))
sm.graphics.tsa.plot_acf(diff1, ax=ax, lags=30)
plt.show()



# Plotting the Partial Autocorrelation Function (PACF)
fig, ax = plt.subplots(figsize=(8, 5))
sm.graphics.tsa.plot_pacf(diff1, ax=ax, lags=30)
plt.show()


from statsmodels.tsa.arima.model import ARIMA
import warnings

warnings.filterwarnings("ignore")

for p in range(1, 7):
    for q in range(1, 7):
        model = ARIMA(df['Adj Close'], order=(p, 0, q))
        result = model.fit()
        print(f"AIC: {result.aic:.2f}, AR Order: {p}, MA Order: {q}")


from statsmodels.tsa.arima.model import ARIMA

# Defining the order of the ARIMA model
order = (6, 1, 6)

# Fiting the ARIMA model
model = ARIMA(df['Adj Close'], order=order)
result = model.fit()

# Displaying the model summary
model_summary = result.summary()
print(model_summary)

# Making ARIMA predictions
start = 10
end = 999
df['prediction_arima'] = result.predict(start=start, end=end)

# Plotting 'Adj Close' and ARIMA predictions
df[["Adj Close", "prediction_arima"]].plot(figsize=(20, 5))


# Generate 30-day forecasts with a confidence level of 95%
forecast = result.forecast(steps=30, alpha=0.05)

# Print the rounded forecasted values
for value in forecast:
    print(round(value, 0))



fc = [408.0, 408.0, 407.0, 405.0, 411.0, 409.0, 410.0, 407.0, 407.0, 410.0, 409.0, 411.0, 407.0, 408.0, 409.0, 409.0, 410.0, 407.0, 409.0, 409.0, 410.0, 410.0, 408.0, 409.0, 408.0, 410.0, 409.0, 408.0, 409.0, 409.0]

# Create a date range from '2022-02-05' to '2022-03-06'
start_date = '2022-02-05'
end_date = '2022-03-06'
date_range = pd.date_range(start=start_date, end=end_date)


fc_with_dates = pd.Series(fc, index=date_range)
print(fc_with_dates)


# Plotting the forecasted values with specified figure size
fc_with_dates.plot(figsize=(20, 5))


# Creating a figure and specify the figure size
plt.figure(figsize=(20, 5))

# Plotting the 'Adj Close' data
plt.plot(df["Adj Close"], label="Adj Close")

# Plotting the forecasted values with dates
plt.plot(fc_with_dates, label="Forecast")

# Adding a legend
plt.legend()

# Showing the plot
plt.show()

'''
Conclusion

In this analysis, I began by loading and preparing financial data, converting the 'Date' column to datetime format. 
Visual exploration revealed the distribution of the 'Adj Close' data, and I conducted statistical tests to assess its stationarity.
The Augmented Dickey-Fuller (ADF) test confirmed that differencing was required to achieve stationarity. 
Autocorrelation and partial autocorrelation functions aided in selecting an ARIMA(6,1,6) model, which I fitted to the data.
After assessing the model's goodness of fit using the Akaike Information Criterion (AIC), I used it to generate a 30-day forecast with a 95% confidence level.
The results were visually presented by plotting the forecasted values alongside the historical 'Adj Close' data. 
This analysis aimed to provide insights into the stationarity of the time series, model selection, and short-term forecasts, which could inform investment decisions and financial strategies.
'''

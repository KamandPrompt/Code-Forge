'''Autoregression is a time series analysis concept whuch relates the modeling and forecasting time-dependent data.
In a autoregressive model one can predict the value of variable(needs to be continuous) at a specific point of time 
based on it's previous values.
The main idea of the concept is that the current value is a linear combination of its ast values, which we refer as "lags".
Autoregressive models are essential in understanding and predicting the time series data. 
These are the following concepts that relates  to the autoregression model:-
 1. Time series data: We have a time series which is a sequence of data points measured at successive points
    in time these data points are collected at a regular interval.
 2. Lag: Lag refer to the time interval between current data point and a previous data point.
 3. Autoregression Model: It predicts the current value in a time series as alinear combination of previous values.

The main intention of this code is to find the AR coefficients(The parameters that quantify the relationship
between a time series data point and its previous data points at specific lag intervals.) 
'''
class AutoRegression:

    def __init__(self, time_series):
        self.time_series = time_series

    def autoregression(self, lag):
        n = len(self.time_series)
        if n <= lag:
            raise ValueError("Lag should be less than the length of the time series.")

        # Initializing the coefficients
        intercept = [0]  # Intercept
        for i in range(1, lag + 1):
            intercept.append(0)  # Coefficients for lag 1, lag 2, etc.

        for t in range(lag, n):
            # Here we are predicting the value of next time series
            prediction = intercept[0]  # Intercept
            for i in range(1, lag + 1):
                prediction += intercept[i] * self.time_series[t - i]

            # Updating the coefficients using gradient descent
            error = self.time_series[t] - prediction
            for i in range(lag + 1):
                intercept[i] += 0.01 * error * self.time_series[t - i]

        return intercept 

    def visualize(self, lag):
        coefficients = self.autoregression(lag)
        return coefficients  # value of autoregression coefficients

# Taking input from user
time_series_data = []
n = int(input("Enter the number of data points: "))
for i in range(n):
    value = float(input(f"Enter data point {i + 1}: "))
    time_series_data.append(value)

lag = int(input("Enter the lag value: "))

# Creating and running the autoregression model
ar_model = AutoRegression(time_series_data)
coefficients = ar_model.visualize(lag)
print("AR Coefficients:", coefficients)

import matplotlib.pyplot as plt
import numpy as np

# Set up the x-axis with range from 0 to 10
x = np.arange(0, 10, 0.1)

# Define a function to calculate the y-axis values based on the x-axis values
def diminishing_returns(x):
    return 10 / (1 + np.exp(-x))

# Calculate the y-axis values for the function using the x-axis values
y = diminishing_returns(x)

# Create a plot with x-axis as input and y-axis as output
plt.plot(x, y, label="Diminishing Returns")

# Add title, labels and legend to the plot
plt.title("Diminishing Returns")
plt.xlabel("Input")
plt.ylabel("Output")
plt.legend()

# Show the plot
plt.show()


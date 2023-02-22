import matplotlib.pyplot as plt
import numpy as np

# All codes are in English 
# First of all we set up the x-axis with range from 0 to 10
x = np.arange(0, 10, 0.1)

# We define a function to calculate the y-axis values based on the x-axis values
def diminishing_returns(x):
    return 10 / (1 + np.exp(-x))

# Then we calculate the y-axis values for the function using the x-axis values
y = diminishing_returns(x)

# plot it
plt.plot(x, y, label="Diminishing Returns")

#  Tittle blocks
plt.title("Diminishing Returns")
plt.xlabel("Input")
plt.ylabel("Output")
plt.legend()

# Show the plot
plt.show()

# Eventhough I'm not the first to have had the idea to post a diminishing return graph I can share it. 
#Could this code be optimize by the way ? Hum... Fell free to improve! 

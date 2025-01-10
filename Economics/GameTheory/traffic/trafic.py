import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np

# Set up the plot
fig, ax = plt.subplots(figsize=(10, 5))
ax.set_xlim(0, 100)  # Road length
ax.set_ylim(-2, 2)   # Road width (single lane)
ax.axis('off')       # Hide axes for aesthetics

# Initial positions of cars
num_cars = 10
car_positions = np.linspace(0, 100, num_cars, endpoint=False)
car_speeds = np.random.uniform(0.2, 1.0, size=num_cars)  # Random speeds

# Traffic jam effect: Slower cars create a bottleneck
car_speeds[3:6] = 0.1  # Simulate traffic jam in the middle

# Car rectangles
car_patches = []
for pos in car_positions:
    car_patch = plt.Rectangle((pos, -0.5), 5, 1, color='blue', alpha=0.8)
    car_patches.append(car_patch)
    ax.add_patch(car_patch)

# Update function for animation
def update(frame):
    global car_positions
    for i in range(num_cars):
        if i > 0 and car_positions[i] - car_positions[i-1] < 6:  # Maintain safe distance
            car_speeds[i] = min(car_speeds[i], car_speeds[i-1])
        car_positions[i] += car_speeds[i]
        if car_positions[i] > 100:  # Reset cars to the start
            car_positions[i] -= 100
        car_patches[i].set_xy((car_positions[i], -0.5))

# Create animation
ani = FuncAnimation(fig, update, frames=200, interval=50)

# Save or show the animation
plt.show()

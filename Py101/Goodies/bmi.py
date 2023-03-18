#Body mass index (BMI) is a value derived from the mass (weight) and height of a person. 
#The BMI is defined as the body mass divided by the square of the body height, and is expressed in units of kg/m2, resulting from mass in kilograms and height in metres.


# height_in and weight_lb are available as a regular lists
# Calculate the BMI: bmi
#np_height_m = np.array(height_in) * 0.0254
#np_weight_kg = np.array(weight_lb) * 0.453592
#bmi = np_weight_kg / np_height_m ** 2
# Create the light array
#light = bmi < 21 
#np_light = np.array(light)
# Print out light
#print(light)

# Print out BMIs of all baseball players whose BMI is below 21
#print(bmi[light])

#Improved version
# Import numpy
import numpy as np

# Ask user to input their height and weight
height = float(input("Enter your height in meters: "))
weight = float(input("Enter your weight in kilograms: "))

# Calculate the BMI: bmi
bmi = weight / height ** 2

# Create the light array
light = bmi < 21 
np_light = np.array(light)

# Print out light
print("Is the BMI below 21? " + str(light))

# Print out the BMI
print("Your BMI is: " + str(round(bmi, 2)))

# Print out BMI if it's below 21
if light:
    print("Your BMI is below 21, which is considered to be light.")

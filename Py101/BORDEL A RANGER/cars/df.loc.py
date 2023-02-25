# Import cars data
import pandas as pd
cars = pd.read_csv('cars.csv', index_col = 0)

# Print out country column as Pandas Series [  ]
print(cars["country"])

# Print out country column as Pandas DataFrame  [[   ]]
print(cars[['country']])

# Print out DataFrame with country and drives_right columns
print(cars[[ "country", "drives_right"]])

# Import cars data
import pandas as pd
cars = pd.read_csv('cars.csv', index_col = 0)

# Print out first 3 observations
print(cars[0:3])

# Print out fourth, fifth and sixth observation
print(cars[3:6])

# Print out observation for Japan
print(cars.loc['JPN'])
# Print out observations for Australia and Egypt
print(cars.loc[['AUS','EG']])

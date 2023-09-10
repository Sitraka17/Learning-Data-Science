# source: https://ideas.repec.org/p/hal/journl/hal-03140435.html 

import numpy as np
import statsmodels.api as sm

# Simulated data
education_years = np.array([10, 12, 14, 16, 18, 20])
income = np.array([30000, 40000, 50000, 60000, 70000, 80000])

# Add a constant term for the intercept
education_years = sm.add_constant(education_years)

# Fit the regression model
model = sm.OLS(income, education_years).fit()

# Print the summary statistics
print(model.summary())

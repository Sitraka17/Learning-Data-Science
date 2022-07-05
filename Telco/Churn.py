
telco['Churn'].value_counts()

print(telco.groupby(['Churn']).mean())

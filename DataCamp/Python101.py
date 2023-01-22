#    This should be used to unblock a situation after unsuccessfully searching. #

# Is height_inches greater than 70 inches?
print(height_inches > 70)

# Is plate1 equal to "FRQ123"?
print(plate1 == "FRQ123")

# Is fur_color not equal to "brown"?
print(fur_color != "brown")


# Select the dogs where Age is greater than 2
greater_than_2 = mpr[mpr.Age > 2]
print(greater_than_2)

# Select the dogs whose Status is equal to Still Missing
still_missing = mpr[Status == "Still Missing"]
print(still_missing)

# Select all dogs whose Dog Breed is not equal to Poodle
not_poodle = mpr[mpr.Dog Breed != "Poddle"]
print(not_poodle)



# Select the dogs where Age is greater than 2
greater_than_2 = mpr[mpr.Age > 2]
print(greater_than_2)

# Select the dogs whose Status is equal to Still Missing
still_missing = mpr[mpr.Status == "Still Missing"]
print(still_missing)

# Select all dogs whose Dog Breed is not equal to Poodle
not_poodle = mpr[mpr['Dog Breed'] != "Poodle"]        ####" HERE IT S INTERESTING 
print(not_poodle)                                     ### Since the column name have fcking spaces and Capitals. You HAVE TO put it in [ ] and ' ' 
#Yeah so please juste use _ 


# Select purchases from 'Pet Paradise'
purchase = credit_records[credit_records.location == 'Pet Paradise']

# Display
print(purchase)

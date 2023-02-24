import sys
import math

n = int(input())  # the number of temperatures to analyse
temps = input()  # the n temperatures expressed as integers ranging from -273 to 5526
result =  0

if len(temps) == 0:
    print("0")
elif
    temps_split = temps.split()
    result = temps_split[0]
    
    for temp in temps_split:
        if abs(int(temp)) < abs(int(result)):
            result = temp
        elif abs(int(temp)) == abs(int(result)):
            result = max(int(temp),int(result))
else: 
    print("0") 

print(result)

# learned: practiced loops, arrays, string methods, and type conversion

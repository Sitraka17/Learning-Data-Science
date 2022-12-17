import random

def ask_question():
  # Generate two random numbers to multiply
  num1 = random.randint(1, 10)
  num2 = random.randint(1, 10)

  # Ask the user to solve the multiplication problem
  answer = int(input(f"What is {num1} * {num2}? "))

  # Check if the answer is correct
  if answer == num1 * num2:
    print("Correct!")
  else:
    print("Incorrect. The correct answer is", num1 * num2)

# Ask the user five questions
for i in range(5):
  ask_question()

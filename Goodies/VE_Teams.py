import random

#Method ONE : easy : fction 
def chunks(l, n):
    """Faire des groupes"""
    for i in range(0, len(l), n):
        yield l[i:i + n]

n = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K']

random.shuffle(n)

list(chunks(n, 3))
# [['B', 'H', 'G'], ['D', 'A', 'C'], ['E', 'F', 'I'], ['J', 'K']]









#################################################################################################################
#Method TWO: meh.
people = [“Ian”, “Kevin”, “Carl”, “Veronica”, “Daniel”, “Christian”, “Sean”, “Frank”, “Phillip”, “Fiona”]
number_people = len(people)
number_of_teams = 3
while number_people > 0 and number_of_teams > 0:
team = random.sample(people, int(number_people/number_of_teams))
for x in team:
people.remove(x)
number_people -= int(number_people/number_of_teams)
number_of_teams -= 1
print(team)

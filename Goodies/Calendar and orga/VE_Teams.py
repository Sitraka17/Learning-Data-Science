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



#Also
lst = [("a", 5, 6), ("b", 2, 4), ("a", 2, 5), ("c", 2, 6)]


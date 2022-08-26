#Documentation: https://nashpy.readthedocs.io/en/stable/ 

$ python -m pip install nashpy


import nashpy as nash
import numpy as np
A = np.array([[0, -1, 1], [1, 0, -1], [-1, 1, 0]])
rps = nash.Game(A)
rps

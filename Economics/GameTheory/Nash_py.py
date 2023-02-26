#Documentation: https://nashpy.readthedocs.io/en/stable/ 

# But the real lesson of the prisoner's dilemma is concealed beyond this: """"you have to see far, think big… and project yourself. """"
#$ python -m pip install nashpy

import nashpy as nash
import numpy as np
A = np.array([[0, -1, 1], [1, 0, -1], [-1, 1, 0]])
rps = nash.Game(A)
rps


## For the record: 😼 vs🃏 = 6/6 ;🌹 vs🃏 = -1/27 ; 🧙 vs🃏 = 9/-3 👑 vs🃏 = 7/3 
#

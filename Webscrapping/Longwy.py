$$pip install requests
$$pip install html5lib
$$pip install bs4


import requests
URL = "https://stationimmo.fr/recherche/location/appartements/secteur/longwy/1?"
r = requests.get(URL)
print(r.content)

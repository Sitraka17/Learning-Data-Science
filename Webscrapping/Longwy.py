$$pip install requests
$$pip install html5lib
$$pip install bs4


import requests
URL = "https://www/"
r = requests.get(URL)
print(r.content)

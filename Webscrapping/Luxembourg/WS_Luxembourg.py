soupe_obj = BeautifulSoup(html_obj, 'html.parser')

for spans in soup.findAll('span', attrs={'id' : 'productTitle'}) :
    nom_du_produit = spans.text.strip()
    
   $ conda install -c anaconda beautifulsoup4 
   $ conda install -c anaconda lxml 
   $ conda install -c anaconda requests 


from bs4 import BeautifulSoup as bs
import requests

url="https://www.amazon.fr/gp/bestsellers/electronics/?ie=UTF8&ref_=sv_cag_1"
response = requests.get(url)


html = response.content
soup = bs(html, "lxml")


titre_articles = soup.find_all("h2", class_="card-title entry-title")
for titre in titre_articles:
    print(titre.get_text(strip=True))

import pandas as pd
categories = soup.find_all("h6", class_="category text-info")
categories_series = pd.Series(categories)
categories_series.value_counts()


#https://www.data-transitionnumerique.com/beautifulsoup-scraping/

soupe_obj = BeautifulSoup(html_obj, 'html.parser')

for spans in soup.findAll('span', attrs={'id' : 'productTitle'}) :
    nom_du_produit = spans.text.strip()
    
   $ conda install -c anaconda beautifulsoup4 
   $ conda install -c anaconda lxml 
   $ conda install -c anaconda requests 


from bs4 import BeautifulSoup as bs
import requests

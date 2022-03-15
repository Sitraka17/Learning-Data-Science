import pandas as pd
import plotly.express as px
ecom_sales = pd.read_csv('/usr/local/share/datasets/ecom_sales.csv')
ecom_sales = ecom_sales.groupby(['Year-Month','Country'])['OrderValue'].agg('sum').reset_index(name='Total Sales ($)')

# Create the line graph
line_graph = px.line(
  # Set the appropriate DataFrame and title
  data_frame=ecom_sales, title='Total Sales by Country and Month', 
  # Set the x and y arguments
  x='Year-Month', y='Total Sales ($)',
  # Ensure a separate line per country
  color='Country')

line_graph.show()

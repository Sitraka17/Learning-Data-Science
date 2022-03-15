import pandas as pd
import plotly.express as px
ecom_sales = pd.read_csv('/usr/local/share/datasets/ecom_sales.csv')
ecom_sales = ecom_sales.groupby('Country')['OrderValue'].agg('sum').reset_index(name='Total Sales ($)')

# Create the bar graph object
bar_fig = px.bar(
  # Set the DataFrame, x and y
  data_frame=ecom_sales, x='Total Sales ($)', y='Country',
  # Set the graph to be horizontal
  ____='h', title='Total Sales by Country')

# Increase the gap between bars
bar_fig.____({'bargap': 0.5})

bar_fig.show()

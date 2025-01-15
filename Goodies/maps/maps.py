import geopandas as gpd
import pandas as pd
import matplotlib.pyplot as plt
from shapely.geometry import Point, LineString

# Create the main cities data
cities = {
    'name': ['Commercy', 'Verdun', 'Sedan', 'Charleville-Mézières', 'Maubeuge',
             'Charleroi', 'Namur', 'Liège', 'Maastricht', 'Aix-la-Chapelle',
             'Eindhoven', 'Tilbourg', 'Bois-le-Duc', 'Nimègue', 'Rotterdam'],
    'coords': [
        (5.59, 48.76), (5.38, 49.16), (4.94, 49.70), (4.72, 49.77),
        (4.09, 50.28), (4.44, 50.41), (4.87, 50.47), (5.57, 50.63),
        (5.69, 50.85), (6.08, 50.78), (5.47, 51.44), (5.09, 51.56),
        (5.30, 51.69), (5.85, 51.81), (4.48, 51.92)
    ]
}

# Create the main river course (approximate coordinates)
meuse_coords = [
    (5.59, 48.76),  # Commercy
    (5.38, 49.16),  # Verdun
    (4.94, 49.70),  # Sedan
    (4.87, 50.47),  # Namur
    (5.57, 50.63),  # Liège
    (5.69, 50.85),  # Maastricht
    (5.47, 51.44),  # Eindhoven
    (5.30, 51.69),  # Bois-le-Duc
    (4.48, 51.92)   # Rotterdam
]

# Create GeoDataFrame for cities
geometry = [Point(xy) for xy in cities['coords']]
cities_gdf = gpd.GeoDataFrame(cities['name'], geometry=geometry, columns=['name'])

# Create GeoDataFrame for the river
river_geometry = LineString(meuse_coords)
river_gdf = gpd.GeoDataFrame(geometry=[river_geometry])

# Create the plot
fig, ax = plt.subplots(figsize=(10, 15))

# Plot the river
river_gdf.plot(ax=ax, color='#1f77b4', linewidth=2, zorder=1)

# Plot cities
cities_gdf.plot(ax=ax, color='red', markersize=50, marker='o', zorder=2)

# Add city labels
for idx, row in cities_gdf.iterrows():
    plt.annotate(
        row['name'],
        xy=(row.geometry.x, row.geometry.y),
        xytext=(5, 5),
        textcoords="offset points",
        fontsize=8,
        ha='left'
    )

# Customize the plot
plt.title('LA MEUSE\nMaas, Moöse\nNom botanique: Taxus baccata Mosa', 
          pad=20, fontsize=12)

# Add scale bar and north arrow (simplified)
plt.text(0.05, 0.05, '25 KM', transform=ax.transAxes)
plt.text(0.95, 0.05, 'N↑', transform=ax.transAxes, ha='right')

# Add metadata
metadata = (
    'Source: 47°58\'28.26"N 5°38\'01"E\n'
    'Longueur: 950 km\n'
    'Bassin versant: 36,000 km²\n'
    'Régime: pluvial océanique\n'
    'Débit (moyen): 357 m³/s\n'
    'Population: ~9,000,000'
)
plt.text(0.05, -0.1, metadata, transform=ax.transAxes, fontsize=8)

# Set aspect ratio to equal for geographic accuracy
ax.set_aspect('equal')

# Remove axes
ax.set_xticks([])
ax.set_yticks([])
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['bottom'].set_visible(False)
ax.spines['left'].set_visible(False)

# Adjust layout and display
plt.tight_layout()
plt.show()

# Optional: Save the map
plt.savefig('meuse_river_map.png', dpi=300, bbox_inches='tight')
#dude it needs to be enhanced 
conda config --prepend channels conda-forge
conda create -n ox --strict-channel-priority osmnx
import osmnx as ox

place = ["Berlin, Germany"]
G = ox.graph_from_place(place, retain_all=True, simplify = True, network_type='all')

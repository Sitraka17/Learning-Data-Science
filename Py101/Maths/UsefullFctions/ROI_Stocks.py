import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pandas_datareader as web


netflix = web.get_data_yahoo("NFLX",
                            start = "2009-01-01",
                            end = "2018-03-01")


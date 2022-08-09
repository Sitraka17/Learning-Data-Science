library(calendR)

calendR()

calendR(year = 2022) # Specify the year you prefer

#################################################################
calendR(year = 2022,
        start = "M") # Start the week on Monday

#################################################################
calendR(year = 2025,
        start = "M",
        special.days = c(9, 19, 56, 79, 102,  # Days to color !! 
                         126, 257, 300, 342),
        special.col = "lightblue",            # Color of the specified days
        low.col = "white")                    # Background color of the rest of the days

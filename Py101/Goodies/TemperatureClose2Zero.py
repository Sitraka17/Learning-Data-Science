def compute_closest_to_zero(ts):
    negative_temperatures= []
    positive_temperatures= []
    # if array empty return 0
    if len(ts)== 0:
        return 0
    # array size
    if len(ts) <= 10000 and len(ts) > 0:
        for i in ts:
            if i < 0:
                negative_temperatures.append(i)
            if i > 0:
                positive_temperatures.append(i)
        # get the closet number to 0 from each array
        n= max(negative_temperatures)
        p= min(positive_temperatures)
        # return the closet number among the 2 arrays
        if abs(n)== p:
            return p
        elif abs(n) < p:
            return n
        else:
            return p
    else:
        pass

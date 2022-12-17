import sys
import math
from contextlib import redirect_stdout


def max_profit(data):
    # Write your code here
    big1=max(data) 
    data.remove(big1)
    big2=max(data)
    # To debug: print("Debug messages...", file=sys.stderr, flush=True)
    return big2


# Ignore and do not change the code below
def main():
    # pylint: disable = C, W
    n = int(input())
    data = [int(i) for i in input().split()]
    with redirect_stdout(sys.stderr):
        _max = max_profit(data)
    for i in range(2):
        print(_max[i])


if __name__ == "__main__":
    main()
# Ignore and do not change the code above

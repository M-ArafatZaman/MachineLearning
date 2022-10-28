from typing import List, Tuple, TypeVar

## TYPES
# Number type, union of int or float
TNum = TypeVar("TNum", int, float)

# Function to perform linear regression analysis
def linearRegression(xs: List[TNum], ys: List[TNum]) -> Tuple[TNum, TNum]:
    """
    This function takes in 2 vectors of ints or floats representing x and y respectively.
    And returns a list containing the gradient (m) in the first index and y-intercept (b) in the second index.
        
    The formula used is from Khan Academy - https://www.youtube.com/watch?v=GAmzwIkGFgE
    """
    # Size of dataset
    N_x: int = len(xs)
    N_y: int = len(ys)

    # Calculate the average of x and y
    avg_x: TNum = sum(xs)/N_x
    avg_y: TNum = sum(ys)/N_y

    # Calculate the average of a list of xys
    xys: List[TNum] = [xs[i]*ys[i] for i in range(N_x)]
    avg_xy: TNum = sum(xys)/N_x

    # The square of average of x
    squared_avg_x: TNum = pow(avg_x, 2)

    # Calculate the average of a list of xs squared
    xs_squared: List[TNum] = [pow(x, 2) for x in xs]
    avg_xs_squared: TNum = sum(xs_squared)/N_x

    # Calculate the gradient
    m: TNum = ((avg_x * avg_y) - avg_xy )/( squared_avg_x - avg_xs_squared )
    b: TNum = (avg_y - (m * avg_x))

    return (m, b)


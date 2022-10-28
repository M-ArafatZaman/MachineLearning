

# Function to perform linear regression analysis
def linearRegression(xs, ys):
    """
    This function takes in 2 vectors of ints or floats representing x and y respectively.
    And returns a list containing the gradient (m) in the first index and y-intercept (b) in the second index.
        
    The formula used is from Khan Academy - https://www.youtube.com/watch?v=GAmzwIkGFgE
    """
    # Size of dataset
    N_x = len(xs)
    N_y = len(ys)

    # Calculate the average of x and y
    avg_x = sum(xs)/N_x
    avg_y = sum(ys)/N_y

    # Calculate the average of a list of xys
    xys = [xs[i]*ys[i] for i in range(N_x)]
    avg_xy = sum(xys)/N_x

    # The square of average of x
    squared_avg_x = pow(avg_x, 2)

    # Calculate the average of a list of xs squared
    xs_squared = [pow(x, 2) for x in xs]
    avg_xs_squared = sum(xs_squared)/N_x

    # Calculate the gradient
    m = ((avg_x * avg_y) - avg_xy )/( squared_avg_x - avg_xs_squared )
    b = (avg_y - (m * avg_x))

    return (m, b)


if __name__ == "__main__":
    x = [1,2,3,4,5]
    y = [1,2,3,4,5]

    m, b = linearRegression(x, y)

    print(f"y={m}x+{b}")

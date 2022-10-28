import unittest
from linearRegression import linearRegression

# Test case
class LinearRegressionTest(unittest.TestCase):

    def test_linearRegression(self):
        '''
        Test the linear regression function
        '''
        x = [1,2,3,4,5]
        y = [1,2,3,4,5]

        equation: tuple = linearRegression(x, y)
        self.assertEqual(equation, (1, 0), "linearRegression() did not generate proper m or b.")


if __name__ == "__main__":
    unittest.main()

from cs50 import get_float

# Get input
input = get_float("How much change? ")

# Keep track of coins
coins = {
    "quarters": 0,
    "dimes": 0,
    "nickels": 0,
    "pennies": 0,
}

coins.quarters = input / 0.25

main();
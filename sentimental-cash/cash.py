from cs50 import get_float

# Get input
usript = get_float("How much change? ")

# Keep track of coins
coins = {
    "quarters": 0,
    "dimes": 0,
    "nickels": 0,
    "pennies": 0,
}

# Calculate quarters
coins.quarters = int(usript / 0.25)
usript -= coins.quarters * 0.25;

# Calculate dimes (like my gf)
coins.dimes = int(usript / 0.1)
usript -= coins.dimes * 0.1
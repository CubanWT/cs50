from cs50 import get_float

# Get input
while True:
    usript = get_float("How much change? ")
    if usript > 0:
        break
    print("Invalid amount of change!")

# Keep track of coins
coins = {
    "quarters": 0,
    "dimes": 0,
    "nickels": 0,
    "pennies": 0,
}

# Calculate quarters
coins["quarters"] = int(usript / 0.25)
usript -= coins["quarters"] * 0.25

# Calculate dimes
coins["dimes"] = int(usript / 0.1)
usript -= coins["dimes"] * 0.1

# Calculate nickels
coins["nickels"] = int(usript / 0.05)
usript -= coins["nickels"] * 0.05

# Calculate pennies
coins["pennies"] = int(usript / 0.01)

total = coins["pennies"] + coins["quarters"] + coins["nickels"] + coins["dimes"]

print(coins)
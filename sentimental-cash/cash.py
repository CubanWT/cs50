from cs50 import get_float

# Get input
while True:
    usript = round(get_float("How much change? "), 2)
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
coins["quarters"] = usript // 0.25
usript -= coins["quarters"] * 0.25
print(f"quarters: {usript}")

# Calculate dimes
coins["dimes"] = usript // 0.10
usript -= coins["dimes"] * 0.10
print(f"dimes: {usript}")

# Calculate nickels
coins["nickels"] = usript // 0.05
usript -= coins["nickels"] * 0.05
print(f"nickels: {usript}")

# Calculate pennies
coins["pennies"] = usript // 0.01
print(f"pennies: {usript}")

total = coins["pennies"] + coins["quarters"] + coins["nickels"] + coins["dimes"]

print(coins)
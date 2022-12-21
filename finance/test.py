from cs50 import SQL


db = SQL("sqlite:///finance.db")

user_shares = db.execute("SELECT shares FROM stocks WHERE user_id = ?", 1)

print(user_shares)
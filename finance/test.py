from cs50 import SQL


db = SQL("sqlite:///finance.db")

user_shares = db.execute("SELECT * FROM stocks WHERE user_id = ? AND symbol = ?", 1, "AAPL")

print(user_shares)
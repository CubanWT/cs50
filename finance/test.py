from cs50 import SQL


db = SQL("sqlite:///finance.db")

user_cash = db.execute("SELECT cash FROM users WHERE id = ?", 1)[0]["cash"]

print(user_cash)
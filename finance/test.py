from cs50 import SQL

db = SQL("sqlite:///finance.db")

test_list = db.execute("SELECT username FROM users")

print(test_list)
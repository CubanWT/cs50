from cs50 import SQL

db = SQL("sqlite:///finance.db")

name = "willeupi"

test_list = db.execute("SELECT username FROM users")

if name in test_list["username"]:
    print(name)
print(test_list)
import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", session.get("user_id"))

    for stock in stocks:
        stock_price = float(lookup(stock["symbol"])["price"])
        stock["value"] = usd(stock["shares"] * stock_price)
        stock["price"] = usd(stock_price)

    return render_template("index.html", stocks=stocks)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        stock = lookup(symbol)


        if stock == None:
            return apology("Invalid symbol")

        if not shares > 0:
            return apology("Invalid number of shares")

        total = shares * stock["price"]

        user_id = session.get("user_id")

        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        if user_cash < total:
            return apology("Insufficient funds. get that cash up")

        user_cash -= total

        db.execute("CREATE TABLE IF NOT EXISTS transactions (user_id INTEGER, time TEXT NOT NULL, type TEXT NOT NULL, symbol TEXT NOT NULL, shares INTEGER NOT NULL, price REAL NOT NULL, total REAL NOT NULL, FOREIGN KEY(user_id) REFERENCES users(id))")
        db.execute("CREATE TABLE IF NOT EXISTS stocks (user_id INTEGER, symbol TEXT UNIQUE, shares INTEGER NOT NULL, FOREIGN KEY(user_id) REFERENCES users(id))")
        time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

        db.execute("INSERT INTO transactions (user_id, time, type, symbol, shares, price, total) VALUES (?, ?, 'BUY', ?, ?, ?, ?)", user_id, time, symbol, shares, stock["price"], total)
        db.execute("UPDATE users SET cash=? WHERE id=?", user_cash, user_id)

        user_shares = db.execute("SELECT shares FROM stocks WHERE user_id = ? AND symbol = ?", user_id, symbol)
        if len(user_shares) == 0:
            user_shares = shares
            db.execute("INSERT INTO stocks (user_id, symbol, shares) VALUES (?, ?, ?)", user_id, symbol, user_shares)
        else:
            user_shares = user_shares[0]["shares"]
            user_shares += shares
            db.execute("UPDATE stocks SET shares = ? WHERE user_id = ? AND symbol = ?", user_shares, user_id, symbol,)



    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":
        input = request.form.get("symbol")
        stock = lookup(input)

        if stock == None:
            return apology("Not a valid symbol")

        symbol = stock["symbol"]
        name = stock["name"]
        price = usd(stock["price"])

        return render_template("quoted.html", symbol=symbol, name=name, price=price)


    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")

        if password != request.form.get("confirmation"):
            return apology("Passwords do not match")
        if not password:
            return apology("Must provide a password")
        if not username:
            return apology("Must provide a username")

        users = db.execute("SELECT username FROM users")

        for user in users:
            if username == user["username"]:
                return apology("Username already exists")

        hash = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

        stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", session.get("user_id"))
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        user_owned = False

        for stock in stocks:
            if symbol = stock["symbol"]
                user_owned = True
                break
        if not user_owned:
            return apology("You do not own this stock")

        user_shares = db.execute("SELECT * FROM stocks WHERE user_id = ? AND symbol = ?", user_id, symbol)




    return render_template("sell.html", stocks=stocks)

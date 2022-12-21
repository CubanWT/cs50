from datetime import date, datetime

today = date.today()
now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

print(f"The time is {now}")
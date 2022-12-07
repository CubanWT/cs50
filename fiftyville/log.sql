-- Keep a log of any SQL queries you execute as you solve the mystery.

--output of log.sql is piped into txt file for better readability

-- to understand format of the database
.schema

-- to understand what the crime_scene_reports table stores
SELECT * FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28;

-- get interviews from crime scene report
SELECT * FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";

--thief's associate purchased plane ticket for earliest flight on 29/7/2021
--thief was on the phone with their associate for less than a minute post robbery
--thief withdrew money before 10:15 AM on 28/7/2021 from ATM on Leggett Street
--thief left in a car seen by bakery security footage within ten minutes of crime (10:15 AM)

--check bakery security logs for thief leaving
SELECT people.name FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25
AND activity = "exit";

--check calls for thief's call to associate
SELECT name from people
JOIN phone_calls ON phone_calls.caller = people.phone_number
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

--check atm withdraws from day of robbery
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_location = "Leggett Street"
AND year = 2021
AND month = 7
AND day = 28
AND transaction_type = "withdraw";

--find earliest flight from the next day
SELECT full_name, city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29
    ORDER BY hour ASC
    LIMIT 1
);

--check for passengers on flight
SELECT name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flight_id = (
    SELECT id FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29
    ORDER BY hour ASC
    LIMIT 1
)

--find suspect
SELECT name FROM people
WHERE
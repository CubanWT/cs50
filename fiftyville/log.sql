-- Keep a log of any SQL queries you execute as you solve the mystery.

-- to understand format of the database
.schema

-- to understand what the crime_scene_reports table stores
-- This was outputted into a txt file for better readability
SELECT * FROM crime_scene_reports

-- get interviews from crime scene report
-- this was outputted into txt file for better readability
SELECT * FROM interviews
WHERE year = (SELECT year
FROM crime_scene_reports
WHERE id = 295) AND
month = (SELECT month
FROM crime_scene_reports
WHERE id = 295) AND
day = (SELECT day
FROM crime_scene_reports
WHERE id = 295);

--thief plans on taking the earliest flight on 29/7/2021
--thief withdrew money before 10:15 AM on 28/7/2021 from ATM on Leggett Street
--thief left in a car seen by bakery security footage within ten minutes of crime (10:15 AM)

--check for thief's flight
SELECT * FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour, minute;

--id of earliest flight is 36

--find destination of flight
SELECT full_name, city FROM airports
WHERE id = (
    SELECT destination_airport_id FROM flights
    WHERE id = 36
);

--**Thief flew to LaGuardia Airport in New York City**

--check ATM for thief
SELECT name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON 
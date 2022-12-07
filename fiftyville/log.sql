-- Keep a log of any SQL queries you execute as you solve the mystery.

-- to understand format of the database
.schema

-- to understand what the crime_scene_reports table stores
-- This was outputted into a txt file for better readability
SELECT * FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28;

-- get interviews from crime scene report
-- this was outputted into txt file for better readability
SELECT * FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";

--thief plans on taking the earliest flight on 29/7/2021
--thief withdrew money before 10:15 AM on 28/7/2021 from ATM on Leggett Street
--thief left in a car seen by bakery security footage within ten minutes of crime (10:15 AM)

--check bakery security logs for owner of car leaving
SELECT bakery_security_logs.activity, people.name FROM bakery_security_logs
JOIN people ON people.license_plate = bakery_security_logs.license_plate
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >= 15
AND minute <= 25;

--check ATM withdrawls before time in interview
SELECT 
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
--thief withdrew money on the  of 28/7/2021 from ATM on Leggett Street
--thief left in a car seen by bakery security footage within ten minutes of crime (10:15 AM)
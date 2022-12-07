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
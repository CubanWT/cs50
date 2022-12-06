SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name = "Johnny Depp"
AND name = "Helena Bonham Carter";
SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE  movies.id = (
    SELECT movie_id
    FROM stars
    WHERE 
)
AND name = "Helena Bonham Carter";
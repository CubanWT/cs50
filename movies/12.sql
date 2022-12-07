SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE "Johnny Depp" IN name
AND "Helena Bonham Carter" IN name;
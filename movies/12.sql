SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE person_id = (
    SELECT people.id WHERE name = "Johnny Depp"
);
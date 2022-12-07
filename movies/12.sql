SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Johnny Depp"
name = "Helena Bonham Carter";
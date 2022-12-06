SELECT DISTINCT name
FROM directors
JOIN ratings ON ratings.movie_id = directors.movie_id
JOIN people ON people.id = directors.person_id
where rating >= 9.0;
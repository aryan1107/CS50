-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Johnny Depp"
INTERSECT
SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Helena Bonham Carter";
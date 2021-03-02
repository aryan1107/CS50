-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred
SELECT DISTINCT(name) FROM movies
JOIN stars ON people.id = person_id
WHERE movie_id IN (SELECT id FROM stars
JOIN people ON person_id = people.id
WHERE name = "Kevin Bacon" AND birth = 1958);
(
  SELECT Users.name AS results
  FROM MovieRating
  INNER JOIN Users
    USING (user_id)
  GROUP BY user_id
  ORDER BY COUNT(MovieRating.movie_id) DESC, Users.name
  LIMIT 1
)
UNION ALL
(
  SELECT Movies.title AS results
  FROM MovieRating
  INNER JOIN Movies
    USING (movie_id)
  WHERE DATE_FORMAT(created_at, '%Y-%m') = '2020-02'
  GROUP BY movie_id
  ORDER BY AVG(MovieRating.rating) DESC, Movies.title
  LIMIT 1
);

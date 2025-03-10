WITH CinemaNeighbors AS (
  SELECT
    *,
    LAG(free) OVER(ORDER BY seat_id) AS prev_free,
    LEAD(free) OVER(ORDER BY seat_id) AS next_free
  FROM Cinema
)
SELECT seat_id
FROM CinemaNeighbors
WHERE free = 1
  AND (prev_free = 1 OR next_free = 1)
ORDER BY 1;

WITH
  UsersWithRowNumber AS (
    SELECT
      *,
      ROW_NUMBER() OVER(ORDER BY created_at) AS `row_number`
    FROM Users
  )
SELECT DISTINCT(First.user_id)
FROM UsersWithRowNumber AS First
INNER JOIN UsersWithRowNumber AS Second
  USING (user_id)
WHERE
  First.`row_number` < Second.`row_number`
  AND DATEDIFF(Second.created_at, First.created_at) <= 7

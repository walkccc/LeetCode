WITH
  UserToWindow AS (
    SELECT
      user_id,
      DATEDIFF(
        LEAD(visit_date, 1, '2021-01-01') OVER(
          PARTITION BY user_id
          ORDER BY visit_date
        ),
        visit_date
      ) AS `window`
    FROM userVisits
  )
SELECT
  user_id,
  MAX(`window`) AS biggest_window
FROM UserToWindow
GROUP BY user_id;

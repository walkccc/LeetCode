WITH
  StepsWithRollingAverage AS (
    SELECT
      user_id,
      steps_date,
      ROUND(
        AVG(steps_count) OVER(
          PARTITION by user_id
          ORDER BY steps_date ROWS BETWEEN 2 PRECEDING AND CURRENT ROW
        ),
        2
      ) AS rolling_average,
      LAG(steps_date, 2) OVER(
        PARTITION by user_id
        ORDER BY steps_date
      ) AS two_dates_before
    FROM Steps
  )
SELECT
  user_id,
  steps_date,
  rolling_average
FROM StepsWithRollingAverage
WHERE DATEDIFF(steps_date, two_dates_before) = 2
ORDER BY 1, 2;

WITH
  RankedDatesPerState AS (
    SELECT
      'failed' AS state,
      fail_date AS `date`,
      RANK() OVER(ORDER BY fail_date) AS rank_per_state
    FROM Failed
    WHERE fail_date BETWEEN '2019-01-01' AND '2019-12-31'
    UNION ALL
    SELECT
      'succeeded' AS state,
      success_date AS `date`,
      RANK() OVER(ORDER BY success_date) AS rank_per_state
    FROM Succeeded
    WHERE success_date BETWEEN '2019-01-01' AND '2019-12-31'
  ),
  RankedDates AS (
    SELECT
      state,
      `date`,
      rank_per_state,
      RANK() OVER(ORDER BY `date`) AS `rank`
    FROM RankedDatesPerState
  )
SELECT
  state AS period_state,
  MIN(`date`) AS start_date,
  MAX(`date`) AS end_date
FROM RankedDates
GROUP BY state, (`rank` - rank_per_state)
ORDER BY start_date

WITH
  TransactionNeighbors AS (
    SELECT
      user_id,
      spend,
      transaction_date,
      RANK() OVER(PARTITION BY user_id ORDER BY transaction_date) AS date_rank,
      FIRST_VALUE(spend) OVER(
        PARTITION BY user_id
        ORDER BY transaction_date
      ) AS first_spend,
      LAG(spend) OVER(
        PARTITION BY user_id
        ORDER BY transaction_date
      ) AS second_spend
    FROM Transactions
  )
SELECT
  user_id,
  spend AS third_transaction_spend,
  transaction_date AS third_transaction_date
FROM TransactionNeighbors
WHERE
  date_rank = 3
  AND spend > first_spend
  AND spend > second_spend
ORDER BY 1;

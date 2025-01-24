WITH
  ApprovedTransactionsAndChargebacks AS (
    SELECT
      id,
      country,
      state,
      amount,
      DATE_FORMAT(trans_date, '%Y-%m') AS `month`
    FROM Transactions
    WHERE state = 'approved'
    UNION ALL
    SELECT
      trans_id AS id,
      country,
      'chargeback' AS state,
      amount,
      DATE_FORMAT(Chargebacks.trans_date, '%Y-%m') AS `month`
    FROM Chargebacks
    LEFT JOIN Transactions
      ON (Chargebacks.trans_id = Transactions.id)
  )
SELECT
  `month`,
  country,
  SUM(state = 'approved') AS approved_count,
  SUM(IF(state = 'approved', amount, 0)) AS approved_amount,
  SUM(state = 'chargeback') AS chargeback_count,
  SUM(IF(state = 'chargeback', amount, 0)) AS chargeback_amount
FROM ApprovedTransactionsAndChargebacks
GROUP BY 1, 2;

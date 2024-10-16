WITH
  FraudPercentile AS (
    SELECT
      policy_id,
      state,
      fraud_score,
      PERCENT_RANK() OVER(
        PARTITION BY state
        ORDER BY fraud_score DESC
      ) AS `percent_rank`
    FROM Fraud
  )
SELECT policy_id, state, fraud_score
FROM FraudPercentile
WHERE `percent_rank` < 0.05
ORDER BY state, fraud_score DESC, policy_id;

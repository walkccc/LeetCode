WITH
  CustomerToIsImmediate AS(
    SELECT
      DISTINCT customer_id,
      FIRST_VALUE(order_date = customer_pref_delivery_date) OVER(
        PARTITION BY customer_id
        ORDER BY order_date
      ) is_immediate
    FROM Delivery
  )
SELECT ROUND(AVG(is_immediate) * 100, 2) immediate_percentage
FROM CustomerToIsImmediate;

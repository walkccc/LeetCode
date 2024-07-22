SELECT
  CONCAT(T1.topping_name, ',', T2.topping_name, ',', T3.topping_name) AS pizza,
  ROUND(T1.cost + T2.cost + T3.cost, 2) AS total_cost
FROM Toppings AS T1
INNER JOIN Toppings AS T2
  ON (T1.topping_name < T2.topping_name)
INNER JOIN Toppings AS T3
  ON (T2.topping_name < T3.topping_name)
ORDER BY total_cost DESC, pizza;

DELETE P2
FROM Person AS P1
INNER JOIN Person AS P2
  ON (P1.email = P2.email)
WHERE P1.id < P2.id;

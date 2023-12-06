SELECT
  Members.member_id,
  Members.name,
  CASE
    WHEN COUNT(Visits.visit_id) = 0 THEN 'Bronze'
    WHEN COUNT(Purchases.visit_id) / COUNT(Visits.visit_id) >= 0.8 THEN 'Diamond'
    WHEN COUNT(Purchases.visit_id) / COUNT(Visits.visit_id) >= 0.5 THEN 'Gold'
    ELSE 'Silver'
  END AS category
FROM Members
LEFT JOIN Visits
  USING (member_id)
LEFT JOIN Purchases
  USING (visit_id)
GROUP BY 1;

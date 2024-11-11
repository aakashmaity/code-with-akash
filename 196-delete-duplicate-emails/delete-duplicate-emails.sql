DELETE p1 from Person p1 
JOIN Person p2
where p2.id<p1.id and p1.email = p2.email 
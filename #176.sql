select 
	max(e.salary) as SecondHighestSalary
from
	(
		select max(salary) as max_s
        from Employee
    ) as m,
    Employee as e
where 
	e.salary<m.max_s
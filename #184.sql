# Write your MySQL query statement below

select d.name Department, e.name Employee, e.salary Salary

    from Employee e, Department d

    where 

        e.departmentId = d.id and

        e.salary=(

            select max(ee.salary) 

                from Employee ee 

                where ee.departmentId=e.departmentId)
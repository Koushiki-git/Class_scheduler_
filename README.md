# Class_Scheduler

This project tackles scheduling optimization problem where the goal is to assign courses to specific time slots and locations 
while minimizing clashes between courses and ensuring that each teacher is assigned to a suitable course. 
The code provided represents an implementation of a Monte Carlo algorithm combined with a simulated annealing approach to find an optimal solution.

Tech Stack:
C++: The project is implemented using the C++ programming language.
Standard Template Library (STL): The code includes various STL components such as map and vector for data storage and manipulation.

Random Number Generation: The srand function from the C++ standard library is used to seed the random number generator for generating random values.

Monte Carlo Algorithm: The MonteCarlo function implements a Monte Carlo algorithm, which is a randomized search algorithm that iteratively makes random moves to find an optimal solution.

Simulated Annealing: The third function incorporates a simulated annealing technique to further optimize the solution. It uses a temperature-based iterative process to accept moves that improve the solution or occasionally accept worse moves based on a probability calculated using the temperature and the difference in cost.

Data Structures: The project utilizes data structures such as map and vector to store and organize the scheduling data. The classTable map holds the course-to-time/location mappings, while the schedule and schedule2 vectors represent the schedule matrix for tracking class and teacher assignments.

Optimization Metrics: The cost variable is used to keep track of the number of clashes or conflicts in the class assignments. The goal is to minimize this cost by assigning courses and teachers in an optimal manner.

Overall, the project combines various algorithms and data structures to tackle the scheduling optimization problem, aiming to find an arrangement of courses, teachers, and classrooms that minimizes clashes and maximizes the utilization of resources.# Class_scheduler_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_EMPLOYEES 10

// Step 1: Define departments using enum for easy readable code
typedef enum {
    HR,
    Sales,
    Research,
    Software,
    Executive
} Department;

// Step 2: Define struct to hold employee data
typedef struct {
    Department dept;     // Department (enum)
    int salary;          // Annual salary
    unsigned int ssn;    // Fake social security number
} Employee;

// Step 3: Generate a salary based on department
// Each department has a base salary + random bonus
int generate_salary(Department dept) {
    switch (dept) {
        case HR:
            // Base: $50,000 + bonus up to $5,000
            return 50000 + rand() % 5001;
        case Sales:
            // Base: $55,000 + bonus up to $7,500
            return 55000 + rand() % 7501;
        case Research:
            // Base: $65,000 + bonus up to $10,000
            return 65000 + rand() % 10001;
        case Software:
            // Base: $70,000 + bonus up to $12,000
            return 70000 + rand() % 12001;
        case Executive:
            // Base: $90,000 + bonus up to $25,000
            return 90000 + rand() % 25001;
        default:
            return 0;
    }
}

// Step 4: Convert department enum to readable string
const char* get_department_name(Department dept) {
    switch (dept) {
        case HR: return "HR";
        case Sales: return "Sales";
        case Research: return "Research";
        case Software: return "Software";
        case Executive: return "Executive";
        default: return "Unknown";
    }
}

int main(void) {
    Employee employees[NUM_EMPLOYEES];

    // Seed the random number generator with current time
    srand(time(NULL));

    // Step 5: Create 10 employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        // Randomly assign one of the 5 departments
        Department dept = rand() % 5;

        // Generate a fake 9-digit SSN (starts at 100000000)
        unsigned int ssn = 100000000 + rand() % 90000000;

        // Assign department, SSN, and calculated salary to employee
        employees[i].dept = dept;
        employees[i].ssn = ssn;
        employees[i].salary = generate_salary(dept);
    }

    // Step 6: Display the list of employees
    printf("Department\tSalary\t\tSSN\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        printf("%-10s\t$%d\t%09u\n",
            get_department_name(employees[i].dept),
            employees[i].salary,
            employees[i].ssn);
    }

    return 0;
}

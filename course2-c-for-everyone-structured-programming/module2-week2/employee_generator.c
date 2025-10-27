#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_EMPLOYEES 10

// Step 1: Define departments using enum
typedef enum {
    HR,
    Sales,
    Research,
    Software,
    Executive
} Department;

// Step 2: Define employee struct
typedef struct {
    Department dept;
    int salary;
    unsigned int ssn;
} Employee;

// Step 3: Generate salary based on department
int generate_salary(Department dept) {
    switch (dept) {
        case HR:
            return 50000 + rand() % 5001;
        case Sales:
            return 55000 + rand() % 7501;
        case Research:
            return 65000 + rand() % 10001;
        case Software:
            return 70000 + rand() % 12001;
        case Executive:
            return 90000 + rand() % 25001;
        default:
            return 0;
    }
}

// Step 4: Get department name as string
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
    srand(time(NULL));  // Seed random number generator

    // Step 5: Generate 10 employees
    for (int i = 0; i < NUM_EMPLOYEES; i++) {
        Department dept = rand() % 5; // Random department (0 to 4)
        unsigned int ssn = 100000000 + rand() % 90000000;  // Random SSN (fake 9-digit)

        employees[i].dept = dept;
        employees[i].ssn = ssn;
        employees[i].salary = generate_salary(dept);
    }

    // Step 6: Print employees
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

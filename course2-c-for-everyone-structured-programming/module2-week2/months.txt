#include <stdio.h>

// Define enumerated type for months
typedef enum month { 
    jan, feb, mar, apr, may, jun, 
    jul, aug, sep, oct, nov, dec 
} month;

// Define struct for date
typedef struct {
    month m;
    int d;
} date;

// Function that returns number of days in a month
int days_in_month(month m) {
    switch (m) {
        case apr: case jun: case sep: case nov: return 30;
        case feb: return 28;
        default: return 31;
    }
}

// Function to compute the next day
date nextday(date dt) {
    date next = dt;
    if (dt.d < days_in_month(dt.m)) {
        next.d++;
    } else {
        next.d = 1;
        next.m = (dt.m + 1) % 12;
    }
    return next;
}

// Function to print date legibly
void printdate(date dt) {
    const char *month_names[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    printf("%s %d\n", month_names[dt.m], dt.d);
}

int main() {
    date dates[] = {
        {jan, 1}, {feb, 28}, {mar, 14}, {oct, 31}, {dec, 31}
    };
    
    for (int i = 0; i < 5; i++) {
        printdate(dates[i]);
        date next = nextday(dates[i]);
        printf("Next day: ");
        printdate(next);
        printf("\n");
    }

    return 0;
}
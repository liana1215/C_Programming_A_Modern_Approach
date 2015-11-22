/*Section 16.2, Exercise 5*/
#include <stdio.h>

struct date {
    unsigned int month;
    unsigned int day;
    unsigned int year;
};


static unsigned int day_of_year(struct date d);
static int compare_dates(struct date d1, struct date d2);

int 
main(int argc, char* argv[]) {
    struct date d1,d2;
    unsigned int days;

    d1.month = 0;
    d1.day   = 5;
    d1.year  = 1990;
    
    d2.month = 2;
    d2.day   = 4;
    d2.year  = 1990;
    
    days = day_of_year(d1);
    printf("The number of days is: %d\n",days);
    printf("1 if d1 > d2, -1 if d1 < d2, and 0 if d1 == d2: %d\n",
compare_dates(d1,d2));        

    return 0;
}
 
/*Returns the day of the year (an integer between 1 and 366) that corresponds to the date d.*/
static unsigned int 
day_of_year(struct date d) {
    int i, m_total = 0;
    unsigned int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (i = 0; i < d.month; i++)
        m_total = m_total + arr[i];

    return m_total + d.day;
}

/*Returns -1 if d1 is an earlier date than d2, +1 if d1 is a later date than d2,
 * and 0 if d1 and d2 are the same*/
static int 
compare_dates(struct date d1, struct date d2) {    
    unsigned int d1_dofy = day_of_year(d1);
    unsigned int d2_dofy = day_of_year(d2);

    if (d1.year == d2.year) {
        if (d1_dofy == d2_dofy)
            return 0;
        else if (d1_dofy > d2_dofy)
            return 1;
        else
            return -1;
    }
    else if (d1.year > d2.year)
        return 1;
    else
        return -1;
}
    

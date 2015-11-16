#include <stdio.h>


struct date {
	int month;
	int day;
	int year;
};


int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);



int main (int argc, char* argv[]){
	struct date d;
	int days;

	d.month = 2;
	d.day 	= 5;
	d.year  = 2015;

	days = day_of_year(d);
	printf("The number of days is: %d\n",days);
			
	return 0;
}

int day_of_year(struct date d){
	int i, m_total = 0;
	int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31,};

	for (i = 0; i < d.month; i++)
		m_total = m_total + arr[i];

	return m_total + d.day;

}

int compare_dates(struct date d1, struct date d2){
	
	int ret_val = 0;	

	if (d1.year <= d2.year){
		ret_val = -1;
	else
}


/*Section 16.2 Exercise 6*/
#include <stdio.h>

struct time {
    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;
};

struct time split_time(long total_seconds);

int main(int argc, char *argv[]){
    
    struct time split;
    int s = 0;

    printf("input the number seconds: ");
    scanf("%d",&s);
    
    split = split_time(s);

    printf("hours: %d\n", split.hours);
    printf("minutes: %d\n", split.minutes);
    printf("seconds: %d\n", split.seconds);

    return 0;
}

/*takes in total seconds, and returns a struct with structure variables
 * hours, minutes, seconds*/
struct time split_time(long total_seconds){
    struct time split;

    split.hours = total_seconds / 3600;
    split.minutes = (total_seconds - split.hours * 3600) / 60;
    split.seconds = total_seconds - split.hours * 3600 - split.minutes * 60;
    
    return split;
}


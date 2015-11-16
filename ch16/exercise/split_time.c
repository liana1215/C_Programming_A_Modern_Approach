#include <stdio.h>



struct time {
    int hours;
    int minutes;
    int seconds;
};

struct time split_time(long total_seconds);

int main(int argc, char *argv[]){
    
    struct time split_t;
    int s = 0;

    printf("input the number seconds: ");
    scanf("%d",&s);
    
    split_t = split_time(s);

    printf("hours: %d\n",split_t.hours);
    printf("minutes: %d\n",split_t.minutes);
    printf("seconds: %d\n",split_t.seconds);

    return 0;
}

struct time split_time(long total_seconds){
    struct time split_t;
    split_t.hours = total_seconds/(3600);
    split_t.minutes = (total_seconds - split_t.hours*3600)/60;
    split_t.seconds = total_seconds - split_t.hours * 3600 - split_t.minutes * 60;
    
    return split_t;
}


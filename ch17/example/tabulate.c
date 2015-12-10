#include <math.h>
#include <stdio.h>

#define FUNC 3
void tabulate(double (*f)(double), double first, double last, double incr);
  
int 
main(void) {
    double final, increment, initial;
    int i;
    void (*f[FUNC]) = {cos, sin, tan};
    char *s[FUNC] = {"cos", "sin", "tan"};

    int f_length = sizeof(f) / sizeof(f[0]);

   
    printf("Enter initial value: ");
    scanf("%lf", &initial);
    
    printf("Enter final value: ");
    scanf("%lf", &final);
    
    printf("Enter increment: ");
    scanf("%lf", &increment);
    

    for (i = 0; i < f_length; i++) {
        printf("\n      x       %s(x)"
               "\n   -------    -------\n",s[i]);
        tabulate(f[i], initial, final, increment);
    }
   

    /*
    printf("\n      x       cos(x)"
           "\n   -------    -------\n");
    tabulate(cos, initial, final, increment);

    printf("\n      x       sin(x)"
           "\n   -------    -------\n");
    tabulate(sin, initial, final, increment);

    printf("\n      x       tan(x)"
           "\n   -------    -------\n");
    tabulate(tan, initial, final, increment);
    */


    return 0;
}

void
tabulate(double (*f)(double), double first, double last, double incr) {
    double x;
    int i, num_intervals;
    
    num_intervals = ceil((last - first) / incr);
    for (i = 0; i <= num_intervals; i++) {
        x = first + i * incr;
        printf("%10.5f %10.5f\n", x, (*f)(x));
    }
}

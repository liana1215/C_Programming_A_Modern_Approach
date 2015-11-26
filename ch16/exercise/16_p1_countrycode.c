/*Ch16 Programming Projects: A program that asks the user to enter an
 * international dialing code and then looks it up in the country_codes array.*/
#include <stdio.h>

struct dialing_code {
    char *country;
    int code;
};

int main (int argc, char* argv[]) {
    const struct dialing_code country_codes[] = 
    {{"Argentina",  54}, {"Bangladesh",        880},
    {"Brazil",     55}, {"Burma (Myanmar)",    95},
    {"China",      86}, {"Colombia",           57},
    {"Congo,Dem.",243}, {"Egypt",              20},
    {"Ethiopia",  251}, {"France",             33},
    {"Germany",    49}, {"India",              91},
    {"Indonesia",  62}, {"Iran",               98},
    {"Italy",      39}, {"Japan",              81},
    {"Mexico",     52}, {"Nigeria",           234},
    {"Pakistan",   92}, {"Philippines",        63},
    {"Poland",     48}, {"Russia",              7}};

    int int_code, i;
    int array_length = sizeof(country_codes)/sizeof(*country_codes);
   
    do {
        int flag = 0;

        printf("Please input the international code(-1 to exit): ");
        scanf("%d",&int_code);
    
        for (i = 0; i < array_length; i++) {
            if (country_codes[i].code == int_code) {
                printf("The country is: %s\n", country_codes[i].country);
                flag = 1;
            }
        }
        if (flag == 0) 
            printf("Code not found.\n");
    } while (int_code >= 0);

    return 0;
}



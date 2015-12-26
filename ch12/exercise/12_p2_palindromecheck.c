#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTH 50

static bool palindrome_check(char* string_p, int length);
static int new_line(char* string_p, int length);

int 
main(void) {
    char s[MAX_LENGTH], ch;
    int i;
    bool result;

    printf("Enter a message: ");
    while((ch=getchar()) != '\n') {
        s[i] = tolower(ch);
        i++;
    }
    s[i] = '\n';
    
    int length = sizeof(s) / sizeof(s[0]);
    result = palindrome_check(s, length);
    printf("%d\n", result);

    return 0;
}

/*Checks if sentence is a palindrome, 
checking only alphanumeric characters*/
static bool 
palindrome_check(char* string_p, int length) {
    int i,j,k;
    char sentence[MAX_LENGTH];
    int end = new_line(string_p, length);
    int *p;
    bool test = true;   

    for (i = 0, j = 0; i < end; i++) {
        if (isalpha(string_p[i])) { 
            sentence[j] = string_p[i];
            j++;
        }
    }
    sentence[j] = '\n';
    
    int end_s = new_line(sentence, length);     
    k = end_s - 1;

    for (i=0; i < end_s; i++) {
        if(sentence[i] != sentence[k]) {
            test = false;
            break;
        }
        k--;
    }

    return test;            

}

/*Searches of end of line, and return 
location index*/        
static int 
new_line(char* string_p, int length) {
    int i;
    
    for (i = 0; i < length; i++) {
        if (string_p[i] == '\n') 
            break;
    }
    return i;
}



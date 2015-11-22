#include <stdio.h>
#include <stdbool.h>

struct color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

static struct color make_color(int red, int green, int blue);
static unsigned char getRed(struct color c);
static bool equal_color(struct color color1, struct color color2);
static struct color brighter(struct color c);
static struct color darker(struct color c);

int 
main(int argc, char* argv[]) {
    struct color color_struct = make_color(244,244,244);
    struct color color_original = make_color(100,100,100);

    struct color brighter_color;
    struct color darker_color;

    printf("%d\n", color_struct.red);
    printf("%d\n", color_struct.green);
    printf("%d\n", color_struct.blue);
    
    brighter_color = brighter(color_struct);
    
    printf("%d\n", brighter_color.red);
    printf("%d\n", brighter_color.green);
    printf("%d\n", brighter_color.blue);
    
    darker_color = darker(color_original);  
      
    printf("%d\n", darker_color.red);
    printf("%d\n", darker_color.green);
    printf("%d\n", darker_color.blue);
   
    return 0;
}

/*Returns a color structure, if arguement < 0, set to 0, if > 255, set to 255*/
static struct color 
make_color(int red, int green, int blue) {
    struct color temp; 
    if (red < 0)
        temp.red = 0;
    else if (red > 255)
        temp.red = 255;
    else
        temp.red = red;
    
    if (green < 0)
        temp.green = 0;
    else if (green > 255)
        temp.green = 255;
    else
        temp.green = green;

    if (blue < 0)
        temp.blue = 0;
    else if (blue > 255)
        temp.blue = 255;
    else
        temp.blue = blue;

    return temp;
}


static unsigned char 
getRed(struct color c) {

    return c.red;
}

static bool 
equal_color(struct color color1, struct color color2) {
    
    if (color1.red == color2.red 
        && color1.green == color2.green 
        && color1.blue == color2.blue)
        return true;
    return false;
}

/*Returns a color structure that representsa brighter version of the color c. If
 * all members = 0, function returns all members set as 3. If any member of c
 * is > 0 and < 3, set to 3 before dividing by 0.7. If dividing by 0.7 causes >
 * 255, set to 255.*/
static struct color 
brighter(struct color c) {    
    if (c.red == 0 && c.green == 0 && c.blue == 0) {
        c.red = 3;
        c.green = 3;
        c.blue = 3;
    } else {

        if (c.red > 0 && c.red < 3)
            c.red = 3 / 0.7;
        else
            c.red = c.red / 0.7;
        
        if (c.green > 0 && c.green < 3)
            c.green = 3 / 0.7;
        else
            c.green = c.green / 0.7;
        
        if (c.blue > 0 && c.blue < 3)
            c.blue = 3 / 0.7;
        else
            c.blue = c.blue / 0.7;
        
        if (c.red > 255) 
            c.red = 255;
        if (c.green > 255)
            c.green = 255;
        if (c.blue > 255)
            c.blue = 255;                
    }
    return c;
}
            
/*Returns a color structure that represents a darker version of the color c.
 * Each member multiplied by 0.7*/
static struct color 
darker(struct color c) {
    c.red = c.red * 0.7;
    c.green = c.green * 0.7;
    c.blue = c.blue * 0.7;

    return c;
}



        

#include <stdio.h>
#include <stdbool.h>

struct point {int x, y;};
struct rectangle {struct point upper_left, lower_right;};

static unsigned int area(struct rectangle r); 
static struct point center(struct rectangle r);
static struct rectangle move(struct rectangle r, int x, int y);
static bool test(struct rectangle r, struct point p);

int 
main(int argc, char *argv[]) {
    struct rectangle r, m;
    struct point p;
    int x, y, ch;

    r = (struct rectangle){
        .upper_left = { 1, 5 },
        .lower_right = { 5, 1 }
    };
       
    printf("Area is: %d\n", area(r));
    printf("Center is: (%d,%d)\n",(center(r).x),center(r).y);

    printf("Input amount to move x and y as x y: ");
    scanf("%d%d", &x,&y); 
    ch = getchar();
    m = move(r,x,y);

    printf("Upper left point now at: (%d,%d)\n", m.upper_left.x, m.upper_left.y);
    printf("Lower right point now at: (%d,%d)\n", m.lower_right.x, m.lower_right.y);

    printf("Enter point p as x y: ");
    scanf("%d%d", &p.x, &p.y);
    ch = getchar();
    printf("Point p is in rectangle r: %d\n", test(r,p));

    return 0;
}

/*Computes the area of r*/
static unsigned int 
area(struct rectangle r) {
    return (r.lower_right.x - r.upper_left.x) * 
           (r.upper_left.y - r.lower_right.y);
}

/*Compute the center of r, returning it as a point value. If either the x or y
 * coordinate of the center isnt an integer, store its truncated value in the
 * point structure*/
static struct point
center(struct rectangle r) {
    struct point center;
 
    center.x = (r.lower_right.x - r.upper_left.x) / 2 + r.upper_left.x;
    center.y = (r.upper_left.y - r.lower_right.y) / 2 + r.lower_right.y;
    
    return center;
}

/*Move r by x units in the x direction and y units in the y direction, returning
 * the modified version of r*/
static struct rectangle
move(struct rectangle r, int x, int y) {
    r.lower_right.x = r.lower_right.x + x;
    r.upper_left.x = r.upper_left.x + x;
    r.lower_right.y = r.lower_right.y + y;
    r.upper_left.y = r.upper_left.y + y;
    
    return r;
}

/*Determine whether a point p lies within r, returning true or false.*/
static bool
test(struct rectangle r, struct point p) {
    return r.upper_left.x + p.x < r.lower_right.x &&
           r.lower_right.y + p.y < r.upper_left.y;
}
         

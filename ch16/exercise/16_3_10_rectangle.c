#include <stdio.h>
#include <stdbool.h>

struct point {int x, y;};
struct rectangle { struct point upper_left, lower_right;};

static unsigned int area(struct rectangle r); 
static struct point center(struct rectangle r);
static struct rectangle move(struct rectangle r, int x, int y);
static bool test(struct rectangle r, struct point p);

int 
main(int argc, char *argv[]) {
    struct rectangle r;
    struct rectangle m;
    struct point p;
    int x, y, ch;
   
    r.upper_left.x = 1;
    r.upper_left.y = 5;
    r.lower_right.x = 5;
    r.lower_right.y = 1;
       
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

static unsigned int 
area(struct rectangle r) {
    return (r.lower_right.x - r.upper_left.x) * (r.upper_left.y -
    r.lower_right.y);
}

static struct point
center(struct rectangle r) {
    struct point center;
 
    center.x = (r.lower_right.x - r.upper_left.x) / 2 + r.upper_left.x;
    center.y = (r.upper_left.y - r.lower_right.y) /2 + r.lower_right.y;
    
    return center;
}

static struct rectangle
move(struct rectangle r, int x, int y) {
    r.lower_right.x = r.lower_right.x + x;
    r.upper_left.x = r.upper_left.x + x;
    r.lower_right.y = r.lower_right.y + y;
    r.upper_left.y = r.upper_left.y + y;
    
    return r;
}

static bool
test(struct rectangle r, struct point p) {
    if (r.upper_left.x + p.x < r.lower_right.x && r.lower_right.y + p.y < r.upper_left.y) 
        return true;
    return false;
}
         
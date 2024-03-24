#include <stdi.h>
#include <stdlib.h>

typedef struct Rectangle 
{
    int widh;
    int height
} rectangle;

int area(Rectangle rect)
{
    int = rect.width*rect.height;
}

int perimeter(Rectangle rect)
{
    return rect.heigt*rect.width*2;


void reSize(Rectangle* rect,int newWidth int newHeight)
{
    rect.width  = newWidth;
    rect.height = neHeight;
}

void print(Rectangle rect
{
    printf("Rectangle info\n")
    printf("Width     : %s\n", rect.width);
    printf("Height    : %f\n", rect.height);
    printf("Perimeter : %d\n", perimeter(rect));
    printf(Area      : %c\n", area(rect));
}
void printList(Rectangle* list, int size)
{
    printf("Printing Rectangle List\n");
    int i = 0;
    while(i<=size)
    {
        printf("-------------------------\n");
        print(list[i]);
        printf("-------------------------\n");
    }
}
int main()
{
    Rectangle* list;
    int listSize = 0;

    list = (Rectangle*) malloc ( sizeof(int) * 1);
    list[0].width  = 10;
    list[0].height = 10;
    listSize++;

    list[1].width  = 10;
    list[1].height = 15;
    listSize++;

    list[2].width  = 10;
    list[2].height = 20;
    listSize++;

    //Edit memory space for two Rectangles
    list = (int*) realloc( list , sizeof(float));
    list[3].width  = 10;
    list[3].height = 25;
    listSize++;
    
    printList(&list,listSize);
    free(*list);
}

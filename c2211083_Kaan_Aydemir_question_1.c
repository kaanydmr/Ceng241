#include <stdio.h>
#include <stdlib.h>


typedef struct Rectangle {
    int width;
    int height;
} Rectangle;


int area(Rectangle rect) {
    return rect.width * rect.height;
}


int perimeter(Rectangle rect) {
    return (rect.width + rect.height) * 2;
}


void reSize(Rectangle* rect, int newWidth, int newHeight) {
    rect->width = newWidth;
    rect->height = newHeight;
}


void print(Rectangle rect) {
    printf("Rectangle info\n");
    printf("Width     : %d\n", rect.width);
    printf("Height    : %d\n", rect.height);
    printf("Perimeter : %d\n", perimeter(rect));
    printf("Area      : %d\n", area(rect));
}

void printList(Rectangle* list, int size) {
    printf("Printing Rectangle List\n");
    for (int i = 0; i < size; i++) {
        printf("-------------------------\n");
        print(list[i]);
        printf("-------------------------\n");
    }
}

int main() {
    Rectangle* list;
    int listSize = 4;

    list = (Rectangle*)malloc(sizeof(Rectangle) * listSize);

   
    list[0].width = 10;
    list[0].height = 10;

    list[1].width = 10;
    list[1].height = 15;

    list[2].width = 10;
    list[2].height = 20;

    list[3].width = 10;
    list[3].height = 25;

    printList(list, listSize);

    free(list);
    return 0;
}

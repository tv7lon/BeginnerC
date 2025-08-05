#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, size = 0;
    printf("Enter the grid size: ");
    scanf("%d", &size);

    if(size > 13){
        printf("Warning: grid too big! Using 13 instead.\n");
        size = 13;
    }
    for(i =0; i< size; i++){
        for(j = 0; j < size; j++){
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

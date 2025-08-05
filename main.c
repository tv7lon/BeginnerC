#include <stdio.h>
#include <stdlib.h>

int main()
{
    int input = 0;
    float current = 0;
    float voltage = 0;
    int resistance = 0;

    while(input!=4){

        printf("Menu options:\n1. Resistance Calculations\n2. Voltage Calculations\n3. Current Calculations\n4. Exit Program\n\nEnter your choice: ");
        scanf("%d", &input);

        if(input == 4){
            break;

        }else if(input == 1){
            printf("Please enter the applied voltage (V):");
            scanf("%f", &voltage);
            printf("Please enter the current (mA):");
            scanf("%f", &current);
            voltage <0 || current < 0 ? printf("Not allowed to have negative values\n\n") : current ==0 ? printf("Current cannot equal 0.") : printf("The resistance is %.4f ohms.\n\n", voltage/(current/1000));



        }else if(input == 2){
            printf("Please enter the applied resistance (Ω):");
            scanf("%d", &resistance);
            printf("Please enter the current (mA):");
            scanf("%f", &current);
            resistance <0 || current < 0 ? printf("Not allowed to have negative values\n\n") : printf("The voltage is %.1f V.\n\n", resistance*(current/1000));

        }else if(input == 3){
          printf("Please enter the applied voltage (V):");
            scanf("%f", &voltage);
            printf("Please enter the resistance (Ω):");
            scanf("%d", &resistance);
            voltage <0 || resistance < 0 ? printf("Not allowed to have negative values\n\n") : resistance ==0 ? printf("Resistance cannot be 0.\n\n") : printf("The current is %.1f mA.\n\n", (voltage/resistance)*1000);

        }else{
        printf("Please enter a valid option.\n");}
}
    return 0;

}

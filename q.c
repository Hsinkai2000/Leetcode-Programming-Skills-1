#include <stdio.h>
#include <ctype.h>

void print_line(int index, int rest, int denomination) {

    int cash = rest / denomination;
    printf("|%3i |%10i.%02i |%6i |\n", index, denomination / 100, denomination % 100, cash);

}

void break_down(int cents) {
    
    printf("+----+--------------+-------+\n");
    printf("| #  | Denomination | Count |\n");
    printf("+----+--------------+-------+\n");

    print_line(1, cents, 10000);
    cents = cents % 10000;
    print_line(2, cents, 5000);
    cents = cents % 5000;
    print_line(3, cents, 1000);
    cents = cents % 1000;
    print_line(4, cents, 500);
    cents = cents % 500;
    print_line(5, cents, 200);
    cents = cents % 200;
    print_line(6, cents, 100);
    cents = cents % 100;
    print_line(7, cents, 50);
    cents = cents % 50;
    print_line(8, cents, 20);
    cents = cents % 20;
    print_line(9, cents, 10);
    cents = cents % 10;
    print_line(10, cents, 5);
    cents = cents % 5;
    print_line(11, cents, 1);

    printf("+----+--------------+-------+\n");

}

int main(void) {

    printf("Please enter total value: ");
    int dollar, cents;
    if(scanf("%d.%d", &dollar, &cents) == 0){
       printf("Please enter numbers ");
    }
    else{
        int value = (int)dollar * 100 + (int)cents;
        
        // printf("%d\n",value);
        

        if (dollar < 0) {

            printf("Please enter total value: The dollars part specified must be non-negative.\n");

        }

        else if ((cents < 0) || (cents > 99)) {

            printf("dollar %d\n",value);
            printf(" cents%d\n",cents);
            printf("The cents part specified must be between 0...99 (inclusive).\n");
        
        }
        else {

            break_down(value);
        } 
        
        return 0;

    }
    
}
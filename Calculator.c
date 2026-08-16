#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float add(float a , float b) {
    return a+b;
}
float subtract(float a ,float b) {
    return a-b;
}
float multiply(float a ,float b){
    return a*b;
}
float divide(float a , float b){
    if (b== 0) {
        printf("   Error !! Divison by zero is not allowed\n    ");
        return 0;
        
    }else{
        return a/b;
    }
}
float modulus(float a , float b){
    if (b== 0) {
        printf("   Error !! Divison by zero is not allowed\n    ");
        return 0;
        
    }else{
        return fmod(a, b);
    }
}
int main() {
    char answer;
    printf("=============================================================\n");
    printf("        Welcome to the calculator program\n");
    printf("=============================================================\n");
    do{
        float a,b;

        while (1) {
            printf("   Enter the first number ");
            if (scanf("%f",&a) == 1) {
                break;
            } else {
                printf("   Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n'); // Clear the input buffer
            }
        }
        while (1) {
            printf("   Enter the second number ");
            if (scanf("%f",&b) == 1) {
                break;
            } else {
                printf("   Invalid input. Please enter a valid number.\n");
                while (getchar() != '\n'); // Clear the input buffer
            }
        }
        char operator[20];
        printf("  Enter the operator (Addition, Subtraction, Multiplication, Division, Remainder) ");
        scanf("%19s", operator);

        char lowerOperator[20];
        for (int i = 0; operator[i]; i++) {
            lowerOperator [i] = tolower(operator[i]);
        }
        lowerOperator[strlen(operator)] = '\0';

        if (strcmp(lowerOperator, "addition") == 0) {
            printf("   Result: %.2f\n", add(a, b));
        } else if (strcmp(lowerOperator, "subtraction") == 0) {
            printf("   Result: %.2f\n", subtract(a, b));
        } else if (strcmp(lowerOperator, "multiplication") == 0) {
            printf("   Result: %.2f\n", multiply(a, b));
        } else if (strcmp(lowerOperator, "division") == 0) {
            printf("   Result: %.2f\n", divide(a, b));
        } else if (strcmp(lowerOperator, "remainder") == 0 || strcmp(lowerOperator, "modulus") == 0) {
            printf("   Result: %.2f\n", modulus(a, b));
        } else {
            printf("   Error !! Invalid operator\n");
        }

        printf("   Do you want to perform another calulation? (y/n) ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');

    printf("=============================================================\n");
    printf("        Thank you for using the calculator program\n");
    printf("=============================================================\n");


}

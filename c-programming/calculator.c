#include <stdio.h>

int main() {
    double num1, num2, enter;
    char op;
    char PAC[2];

    // op stands for operation
    // PAC stands for perform another calculation

    do {
        printf("Enter the calculation (e.g., 2 + 3): ");
        scanf("%lf %c %lf", &num1, &op, &num2);

        switch (op) {
		case ('+' '-' '*')
            case '-':
            case '*':
            case '/':
                if (op == '+' || op == '-' || op == '*' || (op == '/' && num2 != 0)) {
                    switch (op) {
			case '+' '-' '*':
                            enter = num1 + num2;
                            printf("Result: %.2f\n", enter);
                            break;
                        case '-':
                            enter = num1 - num2;
                            printf("Result: %.2f\n", enter);
                            break;
                        case '*':
                            enter = num1 * num2;
                            printf("Result: %.2f\n", enter);
                            break;
                        case '/':
                            enter = num1 / num2;
                            printf("Result: %.2f\n", enter);
                            break;
                    }
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
            default:
                printf("Invalid operation.\n");
                break;
        }

        printf("Do you want to perform another calculation? (y/n): ");
        scanf("%s", PAC);
        printf("\n");

    } while (PAC[0] == 'y' || PAC[0] == 'Y');

    return 0;
}


#include <stdio.h>

int data_length;

int get_number_from_char(char a) {
    int char_code = a;
    
    // If data is "I" or "i"
    if (char_code == 73 || char_code == 105) {
        return 1;
    }

    // If data is "V" or "v"
    if (char_code == 86 || char_code == 118) {
        return 5;
    }

    // If data is "X" or "x"
    if (char_code == 88 || char_code == 120) {
        return 10;
    }

    // If data is "L" or "l"
    if (char_code == 76 || char_code == 108) {
        return 50;
    }

    // If data is "C" or "c"
    if (char_code == 67 || char_code == 99) {
        return 100;
    }

    // If data is "D" or "d"
    if (char_code == 68 || char_code == 100) {
        return 500;
    }

    // If data is "M" or "m"
    if (char_code == 77 || char_code == 109) {
        return 1000;
    }

    return -1;
}

int main() {
    printf("Enter equation:\t");
    char data[100] = "";
    scanf("%[^\n]", data);

    int char_value;
    int first_number = 0;
    int second_number = 0;

    int len = 0;
    while (data[len] != '\0') {
        len++;
    }

    int result = 0;
    int code;
    int operation = 0;
    for(int i = 0; i < len; i++) {
        code = data[i];
        if (code == 32) {
            continue;
        }
        if (code == 45 || code == 43 || code == 47 || code == 42) {
            operation = code;
            first_number = result;
            result = 0;
            continue;
        }
        int current = get_number_from_char(data[i]);
        int next = get_number_from_char(data[i+1]);
        if (current == -1) {
            printf("Wrong character.");
            return 0;
        }
        if (next > current) {
            result += next - current;
            i++;
        } else {
            result += current;
        }
    }
    
    second_number = result;
    char op = operation;

    // Calculating result from two numbers by operation
    switch(operation) {
        case 45:
            result = first_number - second_number;
            break;
        case 43:
            result = first_number + second_number;
            break;
        case 47:
            result = first_number / second_number;
            break;
        case 42:
            result = first_number * second_number;
            break;
        default:
            printf("Invalid character\n");
            break;
    }
    printf("%d %c %d = %d \n", first_number, op, second_number, result);
    return 0;
}

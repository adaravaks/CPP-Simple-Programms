#include <iostream>

int main(){
    int num_1;
    int num_2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num_1;

    std::cout << "Enter second number: ";
    std::cin >> num_2;

    std::cout << "Select operator (+ - * /): ";
    std::cin >> op;

    switch(op){
        case '+':
            std::cout << "The result is " << num_1 + num_2;
            break;
        case '-':
            std::cout << "The result is " << num_1 - num_2;
            break;
        case '*':
            std::cout << "The result is " << num_1 * num_2;
            break;
        case '/':
            std::cout << "The result is " << num_1 / num_2;
            break;
        default:
            std::cout << "Enter a valid fucking operator";
    }
}
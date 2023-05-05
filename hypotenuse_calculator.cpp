#include <iostream>
#include <cmath>

int main(){
    double a;
    double b;
    double c;

    std::cout << "Size of first leg: ";
    std::cin >> a;

    std::cout << "Size of second leg: ";
    std::cin >> b;

    c = sqrt(pow(a, 2) + pow(b,2));
    std::cout << "Hypotenuse of your right triangle is " << c; 
    return 0;
}
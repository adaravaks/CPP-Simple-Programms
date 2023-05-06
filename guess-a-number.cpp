#include <iostream>
#include <ctime>

int main(){
    using namespace std;
    srand(time(NULL));
    int num = rand() % 1000 + 1;
    int guess;

    cout << "Try to guess a random number between 1 and a 1000: ";
    while (true) {
        cin >> guess;

        if (guess == num) {
            cout << "Correct!";
            break;
        }
        else if (guess > num) {
            cout << "Nope. Your guess is bigger than the actual number. Try again: ";
        }
        else if (guess < num) {
            cout << "Nope. Your guess is less than the actual number. Try again: ";
        }
    }
}
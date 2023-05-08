#include <iostream>
#include <array>
using namespace std;
const int SIZE = 1000;

int main(){
    array<int, SIZE> rnd_num_array(int limit);
    array<int, SIZE> bubble_sort(array<int, SIZE> arr);


    array<int, SIZE> unsorted_array = rnd_num_array(1000);
    int size = sizeof(unsorted_array) / sizeof(unsorted_array[0]);

    cout << "Unsorted array:\n";
    for(int i = 0; i < size; i++) {
        cout << unsorted_array[i] << ' ';
    }
    cout << '\n';

    array<int, SIZE> sorted_array = bubble_sort(unsorted_array);

    cout << "Sorted array:\n";
    for(int i = 0; i < size; i++) {
        cout << sorted_array[i] << ' ';
    }


    return 0;
}

array<int, SIZE> rnd_num_array(int limit){
    srand(time(0));
    array<int, SIZE> arr;

    for(int i = 0; i < SIZE; i++){
        arr[i] = rand() % limit +1;
    }
    return arr;
}

array<int, SIZE> bubble_sort(array<int, SIZE> arr){
    int temp = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE-i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}
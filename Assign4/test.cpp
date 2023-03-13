#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int array[10];

    for (int i = 0; i < 11; i++){

        array[i] = i;
    }

    for (int i = 0; i < 11; i++){

        cout << i <<": " << array[i] << endl;
    }

    cout << "\nseg: " << array[10];

    return 0;
}
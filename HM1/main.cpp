#include <iostream>
#include "Point.h"
#include "Point.cpp"

using namespace std;

int main() {
    int n;
    cin >> n;

    Point * arr = new Point[n];

    for (int i = 0; i < n; i++) {
        double coordinateX, coordinateY, coordinateZ;
        cin >> coordinateX >> coordinateY >> coordinateZ;
        arr[i] = Point(coordinateX, coordinateY, coordinateZ);
    }

    for (int i = 0; i < n; i++) {
        arr[i].scaling(-2, 0.5, 5);
    }
    for (int i = 0; i < n; i++) {
        arr[i].scaling(1, 0.25, 1);
    }

    for (int i = 0; i < n; i++) {
        arr[i].translation(0, 0, 4);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    delete[] arr;
    return 0;
}

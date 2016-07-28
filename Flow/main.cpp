#include <iostream>

using namespace std;

int main()
{
    // IF

    int x,y;
    cout << "Enter two numbers:" << endl;
    cin >> x >> y;

    cout << x;
    if(x > y) {
        cout << " is larger than ";
    } else if (x < y) {
        cout << " is not larger than ";
    } else {
        cout << " is equal to ";
    }
    cout << y << endl;

    // WHILE

    int a;
    int i(2);
    bool prime = true;

    cout << "Enter a number:" << endl;
    cin >> a;

    while (i < a/i){
        int factor = a/i;
        if (factor * i == a) {
            cout << "factor found " << factor << endl;
            prime = false;
            break;
        }
        i++;
    }
    cout << a << " is ";
    if (prime)
        cout << "prime";
    else
        cout << "not prime";
    cout << endl;

    // FOR

    int b;
    bool primo = true;

    cout << "Enter a number:" << endl;
    cin >> b;

    for (int i = 2; i < b/i; i++){
        int factor = b/i;
        if (factor * i == a) {
            cout << "factor found " << factor << endl;
            primo = false;
            break;
        }
    }

    cout << b << " is ";
    if (primo)
        cout << "prime";
    else
        cout << "not prime";
    cout << endl;

    // SWITCH
    int n;
    cout << "Enter a number, 0 to quit" << endl;
    cin >> n;

    while (n > 0){
        switch(n){
            case 1:
                cout << "You entered 1" << endl;
                break;
            case 2:
            case 3:
                cout << "You entered 2 or 3" << endl;
                break;
            case 4:
                cout << "You entered 4" << endl;
                break;
            default:
                cout << "You entered other than 1-4" << endl;
                break;
        }
        cout << "Enter a number, 0 to quit" << endl;
        cin >> n;
    }

    // Exercice

    int number, limit;
    cout << "Enter the size of the matrix: " << endl;
    cin >> number;
    limit = number - 1;
    char matrix[number][number];
    for (int i = 0; i < number; i++){
        for (int j = 0; j < number; j++){
            if (j >= limit - i){
                matrix[i][j] = '*';
            } else {
                matrix[i][j] = '-';
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }

    return 0;
}

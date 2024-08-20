#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int w0, i0, t;
    int d, i, a;    
    cin >> w0 >> i0 >> t;
    cin >> d >> i >> a;

//첫째줄
    int weight = w0;
    int bmr = i0;

    for(int j = 0; j < d; j++) {
        weight -= (bmr + a) - i;
        
    }

    if(weight <= 0) {
            cout << "Danger Diet" <<'\n';
        }
    else {
        cout << weight << " " << bmr << '\n';
    }

//둘째줄
    weight = w0;
    bmr = i0;

    for(int j = 0; j < d; j++) {
        int x = i - (bmr + a);
        weight += x;

        if(abs(x) > t) {
            bmr += float(x) / 2.0;
        }  
    }

    if(weight <= 0 || bmr <= 0) {
            cout << "Danger Diet" ;
        }
    else {
        cout << weight << " " << bmr << " ";
        if(i0 - bmr > 0) {
            cout << "YOYO";
        }
        else {
            cout << "NO";
        }
    }

    return 0;

}
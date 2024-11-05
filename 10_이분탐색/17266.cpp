#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> location(m);
    for(int i = 0; i < m; i++) {
        cin >> location[i];
    }
    //가로등 간격의 최댓값의 절반 < 가로등 높이
    //굴다리의 시작점~첫번째 가로등, 마지막 가로등~끝점 사이 간격 < 가로등 높이
    
    int h = location[0];
    
    h = max(h, n - location[m-1]);
    
    for(int i = 0; i < m; i++) {
        int a = ceil(double(location[i+1] - location[i])/2);
        h = max(h, a);
    }
    
    cout << h << '\n';
    return 0;
}
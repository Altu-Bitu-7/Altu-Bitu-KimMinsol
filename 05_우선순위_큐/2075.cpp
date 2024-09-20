#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
    
    int N;
    cin >> N;
    
    //최소 힙
    priority_queue<int, vector<int>, greater<int>> pq;
    
    //우선순위 큐에 삽입
    for (int i = 0; i < N * N; i++) {
        int num;
        cin >> num;
        pq.push(num); 
        if (pq.size() > N) {
            pq.pop(); //크기가 N보다 크면 가장 작은 값 제거
        }
    }
    
    cout << pq.top() << endl;
    
    return 0;
}
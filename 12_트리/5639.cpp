#include <iostream>
#include <vector>
using namespace std;

vector<int> postOrder;

void buildTree(const vector<int>& preorder, int& idx, int minVal, int maxVal) {
    if (idx >= preorder.size()) return;

    int key = preorder[idx];
    if (key < minVal || key > maxVal) return;

    idx++;

    //왼쪽 서브트리 재귀 처리
    buildTree(preorder, idx, minVal, key);

    //오른쪽 서브트리 재귀 처리
    buildTree(preorder, idx, key, maxVal);

    postOrder.push_back(key);
}

int main() {
    vector<int> preorder;
    int key;

    while (cin >> key) {
        preorder.push_back(key);
    }

    int idx = 0;
    int MIN = -1000000; 
    int MAX = 1000000; 

    buildTree(preorder, idx, MIN, MAX);

    for (int value : postOrder) {
        cout << value << '\n';
    }

    return 0;
}

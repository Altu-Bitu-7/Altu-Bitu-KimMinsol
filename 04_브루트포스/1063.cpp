#include <iostream>
using namespace std;


int main() {
    string K, S, M;
    int N;
    cin >> K >> S >> N ;
    
    int kx=K[0]-'A'+1, ky=K[1]-'0';
    int sx=S[0]-'A'+1, sy=S[1]-'0';
    
    while(N--) {
        cin >> M;
        int mx = 0, my = 0;
        
        if(M == "R") mx = 1;
        else if (M == "L") mx = -1;
        else if (M == "B") my = -1;
        else if (M == "T") my = 1;
        else if (M == "RT") { mx = 1; my = 1; }
        else if (M == "LT") { mx = -1; my = 1; }
        else if (M == "RB") { mx = 1; my = -1; }
        else if (M == "LB") { mx = -1; my = -1; }
        
        int cx = kx + mx;
        int cy = ky + my;
        //범위를 벗어나면 건너뜀
        if(cx<1 || cx>8 || cy<1 || cy>8) continue;
        
        //킹과 돌의 위치가 같으면 돌도 움직임
        if(cx==sx && cy==sy) {
            //이동한 돌의 위치가 범위를 벗어나면 건너뜀
            if(sx+mx<1 || sx+mx>8 || sy+my<1 || sy+my>8) continue;
            sx += mx;
            sy += my;
        }
        
        kx = cx;
        ky = cy;
        
    }
    cout << (char)(kx+'A'-1) << ky << '\n';
    cout << (char)(sx+'A'-1) << sy;
    
    return 0;
}
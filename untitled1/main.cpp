#include <iostream>
#include <vector>

using namespace std;

bool may(int mid,vector<int>& free_rooms,int k){
    int last = free_rooms[0];
    int cnt = 1;
    for (int i : free_rooms) {
        if (i - last >= mid){
            last = i;
            cnt++;
        }
    }
    return cnt >= k;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> free_rooms(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> free_rooms[i];
    }
    int left = 0;
    int right = free_rooms[n-1] - free_rooms[0] + 1;
    while (right - left > 1){
        int mid = (left + right)/2;
        if (may(mid,free_rooms,k)){
            left = mid;
        } else{
            right = mid;
        }
    }
    cout << left;
    return 0;
}

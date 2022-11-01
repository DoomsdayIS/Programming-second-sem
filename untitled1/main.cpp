#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n,m,k,len,s,f;
    cin >> n >> m >> k;
    vector<int> towns_profit(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> towns_profit[i];
    }
    vector<int> start_points(n,0);
    for (int j = 0; j < n; ++j) {
        cin >> start_points[j];
        start_points[j]--;
    }
    vector<vector<int>> matrix(n,vector<int>(n,10000000));
    for (int j = 0; j < n; ++j) {
        matrix[j][j] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> len >> s >> f;
        matrix[s-1][f-1] = len;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    vector<int> best(n,0);
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i < n; ++i) {
            if (i != l){
                best[l] = max(best[l],towns_profit[i] - matrix[l][i]);
            } else{
                best[l] = max(best[l],towns_profit[l]);
            }
        }
    }
    long long sum = 0;
    for (int i1 = 0; i1 < k; ++i1) {
        sum += best[start_points[i1]];
    }
    cout << sum << "\n";
    return 0;
}

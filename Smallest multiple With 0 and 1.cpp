#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string solve(int A) {
    if (A == 1) return "1"; // special case

    int start = 1 % A;
    queue<int> q;
    vector<char> digit(A);      // store digit used to reach this remainder
    vector<int> parent(A, -1);  // store parent remainder
    vector<bool> visited(A, false);

    q.push(start);
    visited[start] = true;
    digit[start] = '1';  // starting with "1"

    while (!q.empty()) {
        int r = q.front();
        q.pop();

        if (r == 0) {
            // build answer by backtracking
            string ans;
            while (r != -1) {
                ans.push_back(digit[r]);
                r = parent[r];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }

        for (int d = 0; d <= 1; d++) {
            int nr = (r * 10 + d) % A;
            if (!visited[nr]) {
                visited[nr] = true;
                parent[nr] = r;
                digit[nr] = char('0' + d);
                q.push(nr);
            }
        }
    }

    return "";
}

int main() {
    int A = 55;
    cout << "Smallest multiple with 0 and 1 of " << A << ": " << solve(A) << endl;
    return 0;
}

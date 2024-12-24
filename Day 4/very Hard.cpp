#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0); 
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        int maxDays = 0;

        
        while (!s.empty() && p[s.top()] >= p[i]) {
            maxDays = max(maxDays, days[s.top()]);
            s.pop();
        }

        
        if (!s.empty()) {
            days[i] = maxDays + 1;
        }

        s.push(i);
    }

    return *max_element(days.begin(), days.end());
}

int main() {
    vector<int> example1 = {3, 6, 2, 7, 5};
    vector<int> example2 = {6, 5, 8, 4, 7, 10, 9};

    cout << poisonousPlants(example1) << endl; 
    cout << poisonousPlants(example2) << endl; 

    return 0;
}

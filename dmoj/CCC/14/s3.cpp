#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // Test cases
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        // Number of cars
        int N;
        cin >> N;

        stack<int> mountain;

        for (int j = 0; j < N; j++) {

            // Creating mountain stack
            int inp;
            cin >> inp;
            mountain.push(inp);
        }

        // Number needed in lake
        int top = 1;

        bool isStackable = true;

        stack<int> branch;

        // Emptying mountain stack
        while (mountain.size() > 0) {
            if (mountain.top() == top) {
                top = mountain.top() + 1;
                mountain.pop();
            } else if (branch.size() > 0 && branch.top() == top) {
                top = branch.top() + 1;
                branch.pop();
            } else {
                branch.push(mountain.top());
                mountain.pop();
            }
        }

        while (branch.size() > 0) {
            if (branch.top() == top) {
                top = branch.top() + 1;
                branch.pop();
            } else {
                isStackable = false;
                branch.pop();
            }
        }

        if (isStackable) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }

    }

	return 0;
}
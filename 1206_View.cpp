#include <iostream>
#include <vector>

using namespace std;

// vector.erase(vector.begin());

int main(int argc, char** argv) {
    int test_case;
    int T = 10;  // test case : 10
    int BLANK = 2;
    int LIST_SIZE = BLANK * 2 + 1;

    // freopen("input.txt", "r", stdin);

    for (test_case = 1; test_case <= T; ++test_case) {
        int N;
        int data;
        int sum = 0;

        vector<int> list;
        cin >> N;

        for (int i = 0; i < N; i++) {
            int n_view = 0;

            cin >> data;
            list.push_back(data);

            if (list.size() < LIST_SIZE) continue;

            n_view = list[BLANK];
            for (int j = 0; j < LIST_SIZE; j++) {
                if (j == BLANK) continue;

                if (list[BLANK] > list[j]) {
                    if (n_view > list[BLANK] - list[j]) {
                        n_view = list[BLANK] - list[j];
                    }
                } else {
                    n_view = 0;
                    break;
                }
            }

            sum += n_view;
            list.erase(list.begin());
        }
        cout << "#" << test_case << " " << sum << endl;
    }
    return 0;
}
#include "../common.hpp"

void insertion_sort(vector<int>& in) 
{
    int target, j;
    for (int i = 1; i < in.size(); i++) {
        target = in[i];
        j = i-1;
        while (j >= 0 && in[j] > target) {
            in[j+1] = in[j];
            j--;
        }
        in[j+1] = target;
    }
}

int main()
{
    vector<int> in = {3, 1, 5, 17, 14, 3, 2, 6};
    insertion_sort(in);
    cout << in << endl;
}

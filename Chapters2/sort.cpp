#include "../common.hpp"

#pragma region insertion sort method
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
#pragma endregion insertion sort method
 
#pragma region merge sort method
void merge(vector<int>& A, int p, int q, int r) 
{
    // L: [p, q), R: [q, r)
    int n1 = q - p;
    int n2 = r - q;
    vector<int> L(n1+1), R(n2+1);
    std::copy_n(A.begin() + p, n1, L.begin());
    std::copy_n(A.begin() + q, n2, R.begin());
    L.back() = std::numeric_limits<int>::max();
    R.back() = std::numeric_limits<int>::max();
    
    int t1 = 0, t2 = 0;
    for (int i = p; i < p + n1 + n2; i++) 
    {
        if (L[t1] <= R[t2]) {
            A[i] = L[t1];
            t1++;
        } else {
            A[i] = R[t2];
            t2++;
        }
    }
}

void merge_sort(vector<int>& A, int p, int r) 
{
    if (r - p > 1) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q, r);
        merge(A, p, q, r);
    }
}
#pragma endregion merge sort method


int main()
{
    vector<int> in = {4, 10, 9, 7, 5, 13, 17, 2, 1, 8, 12};
    merge_sort(in, 0, in.size());
    cout << in << endl;
}

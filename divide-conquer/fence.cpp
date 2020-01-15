#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int extend(const vector<int>& fence, const int& start_idx, const int& end_idx, int& left, int& right);
int biggest_rec(const vector<int>& fence, int start_idx, int end_idx);

int main(void)
{
    int n_test;
    int n;
    cin >> n_test;
    while(n_test--)
    {
        cin >> n;
        vector<int> fence(n);
        for (int i=0;i<n;i++)
            cin >> fence[i];
        int result = biggest_rec(fence, 0, n-1);
        cout << result << endl;
    }
    return 0;
}
int extend(const vector<int>& fence, const int& start_idx, const int& end_idx, int& left, int& right)
{
    int new_area;
    if (start_idx == left && right == end_idx)
        return -1;
    if (start_idx == left)
        right += 1;
    else if (right == end_idx)
        left -= 1;
    else
    {
        if(fence[left-1] > fence[right+1])
            left -= 1;
        else
            right += 1;
    }
    int height = 99999;
    for (int ele=left; ele<right+1; ele++)
        if(height > fence[ele])
            height = fence[ele];
    new_area = height * (right-left+1);
    return new_area;
}

int biggest_rec(const vector<int>& fence, int start_idx, int end_idx)
{
    // base case
    if (start_idx == end_idx)
        return fence[start_idx];
    
    // recursion
    int left = (end_idx + start_idx) / 2;
    int right = left+1;
    int left_large  = biggest_rec(fence, start_idx, left);
    int right_large = biggest_rec(fence, right, end_idx);

    int temp_middle_large = min(fence[left], fence[right]) * 2;
    int new_large;
    while(left > start_idx || right < end_idx)
    {
        new_large = extend(fence, start_idx, end_idx, left, right);
        if (temp_middle_large <= new_large)
            temp_middle_large = new_large;
    }
    int middle_large = temp_middle_large;
    return max(max(left_large, right_large), middle_large);
}
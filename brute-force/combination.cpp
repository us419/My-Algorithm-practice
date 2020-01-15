#include <iostream>
#include <vector>
#include <array>

using namespace std;

void printVector(vector<int>& input_array)
{
    for (int i : input_array)
        cout << i << " ";
    cout << endl;
}
void get_combination(vector<int>& input_array, vector<int>& output_array, int idx, int r)
{
    // base case
    if (r == 0)
        printVector(output_array);

    // recursion
    for (int i=idx; i<input_array.size(); i++)
    {
        output_array.push_back(input_array[i]);
        get_combination(input_array, output_array, i+1, r-1);
        output_array.pop_back();
    }
}

int main(void)
{
    int n_test;
    int m, n;
    int temp;
    cin >> n_test;

    while(n_test--)
    {
        cin >> m >> n;
        vector<int> input_array;
        vector<int> output_array;
        for(int i=0; i<m; i++)
        {
            cin >> temp;
            input_array.push_back(temp);
        }
        get_combination(input_array, output_array, 0, n);

    }
    return 0;
}
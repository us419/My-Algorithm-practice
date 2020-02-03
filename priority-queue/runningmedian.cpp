#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class RNG
{
private:
    int A = 1983;
    int a,b;
public:
    RNG(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int next()
    {
        int ret = A;
        A = (A * (long long)a + b) % 20090711;
        return ret;
    }
};

class Findmedian
{
private:
    int median;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int, vector<int>, less<int>> max_heap;
public:
    Findmedian(int median)
    {
        this->median = median;
    }
    void insert(int nextNum)
    {
        if (min_heap.size() == max_heap.size())
        {
            if (nextNum <= median)
            {
                max_heap.push(nextNum);
                min_heap.push(median);
                median = max_heap.top();
                max_heap.pop();
            }
            else if (nextNum > median)
            {
                min_heap.push(nextNum);
            }
        }
        else if (min_heap.size() > max_heap.size())
        {
            if (nextNum <= median)
            {
                max_heap.push(nextNum);
            }
            else if (nextNum > median)
            {
                min_heap.push(nextNum);
                max_heap.push(median);
                median = min_heap.top();
                min_heap.pop();
            }
        }
    }

    int getMedian()
    {
        return median;
    }
};

int main(void)
{
    int n_test;
    cin >> n_test;
    while(n_test--)
    {
        int n,a,b;
        cin >> n >> a >> b;
        RNG rng = RNG(a,b);
        int nextNum = rng.next();
        Findmedian findmedian = Findmedian(nextNum);
        int sum = findmedian.getMedian() % 20090711;
        for(int i=0; i<n-1; i++)
        {
            nextNum = rng.next();
            findmedian.insert(nextNum);
            sum += findmedian.getMedian() % 20090711;
            sum %= 20090711;
        }
        cout << sum << endl;
    }
    return 0;
}
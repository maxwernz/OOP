#include "ooptool.h"

int maxsub(std::vector<int>& numbers, int left, int right);
int maxLeftEdge(std::vector<int>& numbers, int left, int right);
int maxRightEdge(std::vector<int>& numbers, int left, int right);
int max(int left, int middle, int right);

int main()
{
    std::vector<int> numbers = read_ints("/Users/max/development/OOP/u07/a1/maxsubverylarge.dat");
    std::cout << maxsub(numbers, 0, numbers.size()-1) << std::endl;
}

int maxsub(std::vector<int>& numbers, int left, int right)
{
    if (left == right)
        return numbers.at(left);
    
    int mid = left + (right - left)/2;

    int maxLeft = maxsub(numbers, left, mid);
    int maxRight = maxsub(numbers, mid+1, right);
    int leftEdge = maxLeftEdge(numbers, left, mid);
    int rightEdge = maxRightEdge(numbers, mid+1, right);

    return max(maxLeft, leftEdge + rightEdge, maxRight);
}

int maxLeftEdge(std::vector<int>& numbers, int left, int right) 
{
    int max = 0;
    int sum = 0;
    for (int i=right; i > left; --i)
    {
        sum += numbers.at(i);
        if (sum > max)
            max = sum;
    }
    return max;
}

int maxRightEdge(std::vector<int>& numbers, int left, int right)
{
    int max = 0;
    int sum = 0;
    for (int i=left; i < right; ++i)
    {
        sum += numbers.at(i);
        if (sum > max)
            max = sum;
    }
    return max;
}

int max(int left, int middle, int right)
{
    if (left > middle && left > right)
        return left;
    if (right > middle && right > left)
        return right;
    return middle;
}
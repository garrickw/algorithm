//sort algorithms
//author: garrickw
//
//all:
//quik_sort
//bubble_sort
//insertion_sort

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int> &a, int l, int r)
{
    int m = a[r-1];    // take the last elemnet as the reference value
    int i = l;
    int j = l;
    while(j<r-1)
    {
        // put all elements, which <= m, to the left, so the remained, which > m , are on the right side.
        if(a[j] <= m)   
        {
            swap(a[i],a[j]);
            i++;
        }
        j++;
    }
    swap(a[i], a[r-1]); 
    return i;
}


void quick_sort(vector<int> &a, int l, int r)
{
    if(l+1 >= r)
        return;
    int k = partition(a,l,r);
    quick_sort(a,l,k);
    quick_sort(a,k+1,r);
}


void bubble_sort(vector<int> &a)
{
    int n = (int)a.size();
    for(int i=0; i<n-1; i++)   //loop n - 1 times
    {
        for(int j=0; j<n-i-1; j++)
            if(a[j+1] < a[j])
                swap(a[j+1], a[j]);
    }
}


void insertion_sort(vector<int> &a)
{
    int n = a.size();
    for(int i=1; i<n; i++)
        for(int j=i-1; j>=0; j--)
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
            else break;
}

//return the index of the first element that > k
//return -q if suc element does not exist
int binary_search(const vector<int> &a, int left, int right, int k)
{
    int m, res = -1;
    while(left <= right)
    {
        m = left + (right-left)/2;
        if(a[m] <= k)
            left = m + 1;
        else
        {
            res = m;
            right = m - 1;
        }
    }
    return res;

}

//optimized version by using binary search
void   insertion_sort2(vector<int> &a)
{
    int n = a.size();
    int idx, t;
    for(int i=1; i<n; i++)
    {
        idx = binary_search(a, 0, i-1, a[i]);
        if(idx==-1)
            continue;
        t = a[i];
        for(int j=i; j>idx; j--)
        {
            a[j]=a[j-1];
        }
        a[idx] = t;
    }
}



//return true if the array is sorted in asc
bool sorted(const vector<int> &a)
{
    for(int i=1; i<int(a.size()); i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}

void print_array(const vector<int> &a)
{
    int n = (int)a.size();
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

// int main()
// {
//     vector<int> a;
//     int n = 1000;
//     for(int i=0; i<n; i++)
//         a.push_back(rand()%10000);
//     //quick_sort(a, 0, a.size()); 
//     //bubble_sort(a);
//     //insertion_sort(a);
//     //insertion_sort2(a);
//     print_array(a);
//     if(sorted(a))
//         cout<<"correct!"<<endl;
//     else cout<<"unsorted!"<<endl;
// }


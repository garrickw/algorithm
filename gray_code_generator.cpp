//An algorithm about how to generate gray code 
//author: garrickw


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//n is the number of digit and it must be >= 1
//generate a gray code sequence to save in vector gray
//example:
//input: n = 2, gray = []
//output: gray = [0,1,3,2]
void gray_code_generator(int n, vector<int> &gray)
{
    if(n < 1)
        return;
    gray[0] = 0;
    gray[1] = 1;
    int k = 2;
    int base = 1;

    //in order to asure only one digit different from every two adjacent digits,
    //we can take the advantages of the generated gray code,
    //for an example, n=3, currently, gray = [0,1,3,2],
    //for more apperantly, change to [000,001,011,010]
    //so it is easy to do 100^gray[x](x=3,2,1,0) and append the result to the gray,
    //becase the origin codes(like 0,1,3,2) is one digit different from the adjacent ones,
    //so the new codes generating also meet the requirement.[000,001,011,010,110,111,101,100]
    for(int i=1; i<n; i++)
        for(int j=k-1; j>=0; j--)
            gray[k++] = gray[j] ^ (base<<i);
}


//A test function
//n is the number of the digit
void test(int n)
{
    vector<int> gray(pow(2,n));
    gray_code_generator(n,gray);
    for(int i=0; i<gray.size(); i++)
        cout<<gray[i]<<" ";
    cout<<endl;
}


//int main()
//{
//   cout<<"test n=2,3,4"<<endl;
//    cout<<endl;
//    test(2);
//    test(3);
//    test(4);
//}

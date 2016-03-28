//An implementation of  kmp algorithm in c++ 

#include <string>
#include <vector>
#include <iostream>
using namespace std;

void make_next(const string &p, vector<int> &next)
{
    int j = 0, k = -1;
    next[0] = -1;
    int len = p.size();
    while( j< len)
    {
        if( k==-1 || p[j]==p[k] )     //k==-1 means the beginning or the latest match (or last few matches) has failed
        {
            j++;
            if ( j==len )      //next already done
                break;
            k++;
            if( p[k] != p[j] )
                next[j] = k;
            else 
                next[j] = next[k];
        }
        else 
            k = next[k];        //this will find out there is a shorter match or not after the latest match failed.
    }
}


int KMP(const string &text, const string &pattern)
{
    vector<int> next(pattern.size());
    make_next(pattern, next);
    int i, j, text_len, pattern_len;
    i = 0;
    j = 0;
    text_len = text.size();
    pattern_len = pattern.size();
    while( i<text_len && j<pattern_len )
    {
        if( text[i] == pattern[j] )
        {
            i++;
            j++;
        }
        else 
        {
            if(next[j] != -1)        
                j = next[j];
            else                        //when next[j]==-1, pattern is impossible to be found in text[0:i] , so it should keep finding in the rest of text (text[i+1:])
            {
                j = 0;
                i++;
            }
        }
    }
    if(j == pattern_len)     //found
        return i - pattern_len;
    else 
        return -1;
}


// int main(int argc, char const *argv[])
// {
//     string text = "abcdefgabhijk";
//     string pattern = "abhi";
//     cout<<KMP(text, pattern)<<endl;
//     return 0;
// }
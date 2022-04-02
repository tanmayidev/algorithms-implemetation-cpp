//HORSPOOL ALGORITHM

# include<iostream>
# include<stdio.h>
# include<string.h>
using namespace std;

const int MAX = 256;    //ASCII characters
int Horspool(char *, char *);
int T[MAX];
void ShiftTable(char []);

int main()
{
    char source[MAX];
    char pattern[MAX];
    int found;
    cout << "Enter Source String: ";
    cin.ignore();
    cin.getline(source, MAX);
    cout << "Enter Pattern String: ";
    cin.ignore();
    cin.getline(pattern, MAX);
    found = Horspool(source, pattern);
    if (found == -1)    cout << "Pattern not found\n";
    else    cout << "Pattern found at: " << found << endl;
}

void ShiftTable(char P[])
{
    int m;
    int index;
    m = strlen(P);
    for(int i= 0; i < MAX; i++)
        T[i] = m;   //initialise with all ASCII characters
    
    for(int j = 0; j < m-1; j++)
    {
        //decimal value of pattern char
        index = int(P[j] - '0');
        T[index] = m - 1 - j;
    }
}

int Horspool(char S[], char P[])
{
    int i, n, m;
    int index;
    n = strlen(S);
    m = strlen(P);
    ShiftTable(P);
    i = m - 1;
    while(i < n)
    {
        int k = 0;
        while((k < m) && (P[m - 1 -k] == S[i - k]))
            k++;
        if(k == m)  
            return (i - m + 1);
        else
        {
            //convert to decimal value
            index = int(S[i] - '0');
            i = i + T[index];   //get the shift value
        }
    }
    return -1;
}

/*
Ouput 1:
Enter Source String: INDIAN BORDER FORCES
Enter Pattern String: BORDER

Ouput 2:
Enter Source String: DRAW_BROAD_BORDERS_AND
Enter Pattern String: BORDER

Ouput 3:
Enter Source String: BANGALORE
Enter Pattern String: BIT

Ouput 4:
Enter Source String: BIT BIT MIT
Enter Pattern String: MIT
Pattern found at: 0
// Output 4 is ambiguous, i think answer should be 8. Please verify
*/

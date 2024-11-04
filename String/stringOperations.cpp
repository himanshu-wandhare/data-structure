#include <iostream>
using namespace std;

int length(char *s)
{
    int i;
    for(i = 0; s[i] != '\0'; i++) {}
    return i;
}

void toUpper(char *s)
{
    for(int i = 0; i < length(s); i++)
        s[i] = s[i] - 32;
}

void toLower(char *s)
{
    for(int i = 0; i < length(s); i++)
        s[i] = s[i] + 32;
}

void toggleCase(char *s)
{   
    for(int i = 0; i < length(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;
    }
}

void checkVowelAndConsonent(char *s)
{   
    int vowels, consonent;
    vowels = consonent = 0;
    for(int i = 0; i < length(s); i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            vowels++;
        else if(s[i] >= 'a' && s[i] <= 'z')
            consonent++;
    }
    cout<<"vowels: "<<vowels<<endl<<"consonent: "<<consonent;
}

int countWords(char *s)
{
    int count = 1;
    for(int i = 0; i < length(s); i++)
    {
        if(s[i] == ' ' && s[i-1] != ' ')
            count++;
    }
    return count;
}

void compare(char* a, char *b)
{
    int i;
    for(i = 0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        if(a[i] != b[i])
            break;
    }
    if(a[i] == b[i])
        cout<<"equal";
    else if(a[i] < b[i])
        cout<<"samller";
    else  
        cout<<"greater";
}

//finding duplicates using bitwise operator
void checkDuplicates(char *s)
{
    int x = 0, h = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        x = 1;
        x = x<<(s[i] - 97);
        if((x&h) > 0)
            cout<<s[i];
        else  
            h = h | x;
    }
}

int main()
{
    char s[] = "himanshu";
    // toUpper(s);
    // toLower(s);
    // toggleCase(s);
    // checkVowelAndConsonent(s);
    // cout<<countWords(s);
    // compare(s,s1);
    checkDuplicates(s);
    return 0;
}
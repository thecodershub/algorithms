/*
A simple subtring checker in C++
*/

#include <iostream>
#include <string.h>

using namespace std;

void string_checker(char str1[100], char str2[100])
{
    int i,j,len = 0;

    len = strlen(str2);
        
    for(i=0,j=0;str1[i]!='\0'&&str2[j]!='\0';i++)
    {
        if(str1[i]==str2[j])
        {
            j++;
        }
        else
        {
            j=0;
        }
    }

    //returns position of the first string from where the substring starts, follows 1 based indexing
    if(j==len)
        cout<<"Substring found! Position: "<< i-len+1<<"\n";      
    else
        cout<<"Substring not found\n";
    
}

int main()
{
    char str1[100]; // Main string
    char str2[100]; // Substring to be searched

    /* #Test1  */
    strcpy(str1,"Hacktoberfest");
    strcpy(str2,"tober");
    string_checker(str1,str2);

    /* #Test2  */
    strcpy(str1,"This is what you came for");
    strcpy(str2,"ou came f");
    string_checker(str1,str2);

    /* #Test3  */
    strcpy(str1,"Hacktoberfest");
    strcpy(str2,"october");
    string_checker(str1,str2);

    
return(0);
}
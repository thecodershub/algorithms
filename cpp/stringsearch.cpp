/*
A simple subtring checker in C++
*/

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char str1[100]; // Main string
    char str2[100]; // Substring to be searched
	int i,j,len = 0;

    cout<<"Enter first string: ";
    cin.getline(str1,100);
	
    cout<<"Enter substring to be searched: ";
    cin.getline(str2,100);

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

    if(j==len)
        cout<<"Substring found! Position: "<< i-len+1<<"\n";
    else
        cout<<"Substring not found\n";
	
return(0);
}
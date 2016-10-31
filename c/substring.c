#include<stdio.h>
#include<string.h>
#include<assert.h>
/*This program searches for substring in the given string.
  Here function search parameters are
        str :input string
        sub :input substring 
*/
void search(char str[],char sub[]){
	int slen = 0,sublen = 0,i,j,res;
	//strlen returns length of the string.
	slen = strlen(str);
	sublen = strlen(sub);
        assert(slen >= sublen);
	for(i = 0; i <= slen-sublen; i++){
		for(j = i; j < i+sublen; j++){
			res = 1;
			if(str[j] != sub[j-i]){
				res = 0;
				break;
			}
		}
		if(res == 1)
			break;
	}
	if(res == 1)
		printf("substring %s is found\n",sub);
	else
		printf("substring %s is not found\n",sub);
}
void test(){

	//Test #1: subtring present in the string. 
	char string[] = "hello world";
	char substr[] = "rld";
	search(string,substr);

	//Test #2: substring not present in the string.
	char string1[] = "Substring";
	char substr1[] = "xyz";
	search(string1,substr1);

	//Test #3: substring not present in the string.
	char string2[] = "Computer";
	char substr2[] = "muter";
	search(string2,substr2);

	//Test #4: substring and string of same length.
	char string3[] ="electron";
	char substr3[] = "electron";
	search(string3,substr3);
}
int main(){
	test();
	return 0;
}
	                    


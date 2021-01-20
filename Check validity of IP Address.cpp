// Program to check validity of a given IPV4 address
#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;
#define DOT "."
 
bool validpartcheck(char* s)
{
    int n = strlen(s);
    
	 //Checking length of string
    if (n > 3)
        return false;
    
	//checing that string contains numbers
    for (int i = 0; i < n; i++)
        if ((s[i] >= '0' && s[i] <= '9') == false)
            return false;
    string str(s);
    
	//checing numbers do not initialize with 0 
    if (str.find('0') == 0 && n > 1)
        return false;
        
    stringstream ss(str);
    int x;
    
    ss>>x;
    
     
    // the string is valid if the number
    // generated is between 0 to 255
    return (x >= 0 && x <= 255);
}
 
/* return 1 if IP string is 
valid, else return 0 */
int validipcheck(char* ip)
{
    
    if (ip == NULL)
        return 0;
    int i, num, dots = 0;
    int len = strlen(ip);
    int count = 0;
     
    // the number dots in the original 
    // string should be 3
    // for it to be valid
    for (int i = 0; i < len; i++)
        if (ip[i] == '.')
            count++;
    if (count != 3)
        return false;
     
    // See following link for strtok()
   
    char *ptr = strtok(ip, ".");
    if (ptr == NULL)
        return 0;
 
    while (ptr) {
 
        /* after parsing string, it must be valid */
        if (validpartcheck(ptr)) 
        {
            /* parse remaining string */
            ptr = strtok(NULL, ".");
            if (ptr != NULL)
                ++dots;
        }
        else
            return 0;
    }
 
    if (dots != 3)
        return 0;
    return 1;
}
 

int main()
{
    char ip1[] = "113.0.0.1";
    char ip2[] = "15.530.100.1";
    
    validipcheck(ip1) ? cout<<"Given IP Address is Valid\n" : cout<<"Given IP Address is In-valid\n";
    validipcheck(ip2) ? cout<<"Given IP Address is Valid\n" : cout<<"Given IP Address is In-valid\n";
    
    return 0;
}

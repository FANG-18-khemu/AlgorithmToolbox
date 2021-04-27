#include <iostream>
#include <string>
#include <alogrithm>
using namespace std;
char val(int v)
{
	return 64+v;
}
char* DecodeMessage(char* msg)
{
	if(msg == NULL)
	 {
	 	return "NULL";
	 }
	int n = msg.length();
	string res="";
	int reset =0;
	for(int i=0;i<n;i++)
	{
		if(msg[i] =="_")
		{
			res+=" ";
		}
		else if(msg[i] == "#")
		{
			reset =i;
			break;
		}
		else
		{
		char val = val(int(msg[i]));
		res += val;
	}
	while(rest <n)
	{
		res +=msg[++reset];
	}
	}
}
int main()
{
	char* result = DecodeMessage(214);
	cout<<result;
	return 0;
}

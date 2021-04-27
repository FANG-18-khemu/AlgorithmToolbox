#include <iostream> 
using namespace std; 

long long calculateSquareSum(int n) 
{ 
    if (n <= 0) 
        return 0; 
  
    long long fibo[n + 1]; 
    fibo[0] = 0, fibo[1] = 1; 
  
    long long sum = (fibo[0] * fibo[0]) + (fibo[1] * fibo[1]); 
  
    for (int i = 2; i <= n; i++) { 
        fibo[i] = fibo[i - 1] + fibo[i - 2]; 
        sum += (fibo[i] * fibo[i]); 
    } 
  
    return sum%10; 
} 

int main() 
{ 
    long long n;
	cin>>n; 
  
    cout<< calculateSquareSum(n) << endl; 
  
    return 0; 
} 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <cmath>
#include <ctime>
#include <stdlib.h>

bool is_prime(long long n){ // To be replaced soon to make it more efficient and logical
long long  x1 = 2, x2 = 3, y1 = (n-1), y2 = (n-2), q = n / 2;
if (n < 2){
    return false;
}else if (n==2||n==3||n==5||n==7){
    return true;
    }else{
for (; x1<q,x2<q,y1>=q,y2>=q; x1+=2, x2+=2, y1-=2,y2-=2){
    if (n % x1 == 0 || n % x2 == 0 || n % y1 == 0 || n % y2 == 0){
        return false;
        }
    }
}
return true;
}

int main(){
long long user_input = 0, divisor = 2, p_factor = 0, copy_input;
std::vector <long long> arr;
std::string option = "";

for (;;){

std::cout<<"\t\t\tPrime Factorization\n\nEnter a number: ";
std::cin>>user_input;
copy_input = user_input;
while(copy_input != 1){
    if(copy_input % divisor == 0){ //checks if the divisor is a factor of user_input
       if(is_prime(divisor)){  // checks if the divisor is prime
        p_factor = divisor; // current prime factor will be the greatest prime factor so far
        arr.push_back(p_factor); // it will be save to the vector array
        copy_input = copy_input / divisor; // copy_input will be reduced
        }
    }else{
        ++divisor;
    }
}
if (arr.size() == 1){
    std::cout<<"\n\nNo Other Factors other than 1 and itself\n\n";
    system("pause");
}else{
    std::cout<<"\nPrime Factor/s of "<<user_input <<":\n\n";
    for (unsigned int j = 0; j < arr.size(); j++){
        std::cout<<arr[j]<<" ";
    }
}
std::cout<<"\n";

std::cout << "\nTry again?? (y/n): ";
std::cin >> option;
if ((option == "n" || option == "N")) break;
	user_input = 0;
	copy_input = 0;
	p_factor = 0;
	arr.clear();
	divisor = 2;

}
  return 0;
}



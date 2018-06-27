#include <iostream>
#include <string>
#include <vector>
#include <algorithm>// erase no more
#include <stdio.h>
#include <math.h>
#include <ctime>
#include <stdlib.h>

bool is_prime(std::vector <long long>& stored_prime, long long n){
    std::vector <long long>::iterator iter;
    if (n < 2){
        return false;
    }else if (n==2 || n==3 || n==5 || n==7){
        return true;
    }else{
        for (iter = stored_prime.begin(); iter != stored_prime.end(); iter++){
            if (n % *iter == 0){
                return false;
            }
        }
         return true;
    }
}


int main(){
     long long sum = 0, n = 2;
     int remainder = 0, limit = 2000000, position = 1;
     std::vector <long long> stored_prime(0);
     std::cout<<"Wait....\n";
      while (n < limit){
        remainder = n % 10;
        if ( n <= 10 ){
            if (is_prime(stored_prime, n)){
                sum+=n;
                stored_prime.push_back(n);
            }
             n++;
        }else if (n > 10 && (remainder == 1 || remainder == 3 || remainder == 7 || remainder == 9)){
           if(is_prime(stored_prime, n)){
            sum+=n;
            stored_prime.push_back(n);
           }
                 if (remainder == 1) n+=2;
            else if (remainder == 3) n+=4;
            else if (remainder == 7) n+=2;
            else if (remainder == 9) n+=2;
        }//----------------------------------
      }
     std::cout<<"\n\nSum of prime numbers from 1 - "<< limit <<": " << sum << "\n";

return 0;
}



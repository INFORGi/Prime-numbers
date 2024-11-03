//Какое простое число меньше миллиона можно записать в виде суммы наибольшего количества последовательных простых чисел?

#include <iostream>
#include <vector>
#include <numeric>
#include "math.h"

bool enumeration_divisors(int number){
    if(number >= 2){

        if(number == 2 ) { return true; }
        if(number % 2 == 0) { return false; }
 
        double limit = std::sqrt(number);

        for(int i = 3; i <= limit; ++i){
            if(number % i == 0){
                return false;
            }
        }
        return true;
    }

    return false;
}

int main(){

    std::vector<int> arr(1000000);
    std::iota(arr.begin(), arr.end(), 0);
    int sum = 0;

    for(const int& arr : arr){
        if(enumeration_divisors(arr)){    
            if(sum + arr <= 1000000){
                sum += arr;
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;

long long int pentagonal_number[10000000];

long long int pentNum(int n){
	return ((long long int) n * (long long int)(3 * n - 1)) / 2;
}

void Difference(){
	for (int i = 1; i < 1000000; ++i)
	{
		pentagonal_number[i] = pentNum(i);
		for(int j = 1; j < i; ++j){
			long long int *ptr = find(pentagonal_number, pentagonal_number + i + 1, pentagonal_number[i] - pentagonal_number[j]);
			if(ptr == pentagonal_number + i + 1) break;
			else{
				int k = distance(pentagonal_number, ptr);
				long long int *ptr2 = find(pentagonal_number, pentagonal_number + i + 1, abs(pentagonal_number[j] - pentagonal_number[k]));
				if(ptr2 == pentagonal_number + i + 1) break;
				else{
                        cout<<"i = "<<i<<endl;
                        cout<<"j = "<<j<<endl;
                        cout<<"k = "<<k<<endl;
                        cout<<"Difference ="<< *ptr<<endl;
                    }
			}
		}
	}
}

int main(){
	Difference();
    return 0;
}

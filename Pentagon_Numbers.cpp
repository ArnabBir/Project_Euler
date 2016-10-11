#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

long long int pentagonal_number[10000000];

long long int pentNum(int n){
	return ((long long int) n * (long long int)(3 * n - 1)) / 2;
}

void Difference(){
    ofstream myfile;
  	myfile.open ("PN.txt");
	for (int i = 1; i < 100000; ++i)
	{
	    //cout<<i<<endl;
		pentagonal_number[i] = pentNum(i);
		myfile << "pentagonal_number["<<i<<"] = " <<pentagonal_number[i]<<endl;
		for(int j = 1; j < i; ++j){
			long long int *ptr = find(pentagonal_number, pentagonal_number + i + 1, pentagonal_number[i] - pentagonal_number[j]);
			if(ptr == pentagonal_number + i + 1) continue;
			else{
				int k = distance(pentagonal_number, ptr);
				long long int *ptr2 = find(pentagonal_number, pentagonal_number + i + 1, abs(pentagonal_number[j] - pentagonal_number[k]));
				if(ptr2 == pentagonal_number + i + 1) continue;
				else{
                        cout<<"i = "<<i<<endl;
                        cout<<"j = "<<j<<endl;
                        cout<<"k = "<<k<<endl;
                        cout<<"Difference = "<< abs(pentagonal_number[j] - pentagonal_number[k])<<endl;
                        //return;
                    }
			}
		}
	}
}

int main(){
	Difference();
    return 0;
}

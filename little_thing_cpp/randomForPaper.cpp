#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int getHigh(int n){
	int high = -1;
	while(n>0){
		high = n % 10;
		n /= 10;
	}
return high;
}

int a[10];

int main(){
	srand(time(NULL));
	
	for(int i = 1; i <= 9; i++)
		a[i] = 0;

	freopen("output.txt", "a", stdout);
	
	for(int i = 1; i <= 9999999; i++)
	{
		int tempInt = rand()%10000000+1;		
		int tempHigh = getHigh(tempInt);
		a[tempHigh]++;
		cout << tempInt << "\t";
		if(i % 100 == 0){
			cout << "\n\n\n";
			for(int j = 1; j <= 9; j++)
				cout << a[j] << "\t" ;
			cout << "\n\n\n";
		}
	}
	fclose(stdout); 

return 0;
}


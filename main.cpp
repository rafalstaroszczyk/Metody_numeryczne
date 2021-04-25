#include <iostream>
#include <cmath>

using namespace std;

class student
{
private:
	int index = 180893;
public:
	int index1()
	{
		return index/1000;
	}
	int index2()
	{
		return index%100;
	}
};

int main()
{
	double tab [11][1024];
	student student;
	int index1 = student.index1();
	int index2 = student.index2();
	double tolerance = pow(10, -6);
	double error;

	tab [0][0] = index1;
	for(int i=1; i<10; i++){
		tab[i][0] = 1;
	}
	tab [10][0] = index2;
	int j = 0;
	do{
		tab[0][j+1] = index1;
		for(int i=1; i<10; i++){
			tab[i][j+1] = (tab[i+1][j] + tab[i-1][j]) / 2;
		}
		tab[10][j+1] = index2;

		if(j == 0){
			error = 1;
		}
		else{
			error = 0;
			for(int i=0; i<11; i++){
				error += abs((tab[i][j+1] - tab[i][j]) / tab[i][j+1]);
			}
		}

		j++;
	}while(error > tolerance);
	for(int i=0; i<11; i++){
		cout<<tab[i][j]<<endl;
	}
	return 0;
}

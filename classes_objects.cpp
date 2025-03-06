#include<iostream>
using namespace std;
class Lpu{
	public:
		void branches(){
			cout<<"There is only one branch in Punjab"<<endl;
		}
};
int main(){
	Lpu object;
	object.branches();
	object.branches();
	return 0;
}

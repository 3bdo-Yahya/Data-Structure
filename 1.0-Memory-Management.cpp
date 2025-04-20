#include <iostream>
using namespace std;
int main() {

	int x = 10;
	cout << "x= " << x << endl;
	int* y = &x;
	cout << "y= " << *y << endl;
	int* z = new int(30);
	cout << "z= " << *z << endl;
	*z = 20;
	cout << "z= " << *z << endl;

	cin >> x;
	int* arr = new int[x];
	//int arr[x];

	for (int i = 0; i < x; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < x; i++)
	{
		cout <<"arr[" << i<<"]="<< arr[i]<< endl;
	}

	delete z;
	//cout << "z= " << *z << endl;
	delete []arr;
	//cout << "arr[0]= " << arr[0] << endl;

}
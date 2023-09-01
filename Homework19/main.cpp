#include<iostream>
#include<cstdlib>
#include<conio.h>

int max_div(int a, int b)
{
	int min = 1;
	a < b ? min = a : min = b;
	int max = 1;
	for (int i = 2; i <= min; i++)
	{
		if (a % i == 0 and b % i == 0) max = i;
	}
	return max;
}

int mirror_number(int num)
{
	int result = 0,n1,n2,n3,n4,n5,n6;
	n1 = num / 100000,
	n2 = num % 100000 / 10000,
	n3 = num % 10000 / 1000,
	n4 = num % 1000 / 100,
	n5 = num % 100 / 10,
	n6 = num % 10;

	
	result = n6*100000 +n5 * 10000 + n4 * 1000 + n3 * 100 + n2 * 10 + n1;
	if (n1 == 0) result = n6 * 10000 + n5 * 1000 + n4 * 100 + n3 * 10 + n2;
	if (n1 == 0 and n2 == 0) result = n6 * 1000 + n5 * 100 + n4 * 10 + n3;
	if (n1 == 0 and n2 == 0 and n3 == 0) result = n6 * 100 + n5 * 10 + n4;
	if (n1 == 0 and n2 == 0 and n3 == 0 and n4==0) result = n6 * 10 + n5;
	if (n1 == 0 and n2 == 0 and n3 == 0 and n4==0 and n5==0) result = n6 ;
	
	return result;
}


template <typename T> void fill_arr(T arr[], int const size, T min, T max)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (max - min) + min;
	
}
template <typename T> void show_arr(T arr[], int const size)
{
	for (int i = 0; i < size; i++) std::cout<<arr[i]<<"\t";
}

int foo(int arr[], int const size, int n)
{
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == n)
		{
			index = i;
			break;
		}
	}
	for (int j = size-1; j > index; j--)
		for (int i = index+2; i < size; i++)
			if (arr[i] <  arr[i - 1]) std::swap(arr[i], arr[i - 1]);
	return index;
}





int main()
{
	
	std::cout << "Task 1 \n\n";

	std::cout << "Enter the number 1 - ";
	int n, m;
	std::cin >> n;
	std::cout << "Enter the number 2 - ";
	std::cin >> m;
	std::cout << "The greatest common divisor is " << max_div(n, m) << "\n\n";
	

	std::cout << "Task 2 \n\n";

	std::cout << "Enter the number - ";
	
	int num;
	std::cin >> num;

	std::cout <<"Mirror number - " << mirror_number(num) << "\n\n";


	std::cout << "Task 3 \n\n";
	int const size = 10;
	int arr[size];

	fill_arr(arr, size, 1, 10);
	show_arr(arr, size);

	std::cout << "\nEnter the number - ";
	int N;
	std::cin >> N;
	std::cout << "\n Index - " << foo(arr, size, N)<<'\n';
	show_arr(arr, size);

	std::cout << "\n\nTask 4 \n\n";
	int const size1 = 15;
	int arr1[size1];

	fill_arr(arr1, size1, 1, 25);
	show_arr(arr1, size1);


	return 0;
}

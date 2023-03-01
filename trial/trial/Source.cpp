////#include <iostream>
////using namespace std;
////
////// Function that add two numbers
////int add(double x, double y, double z)
////{
////	return x + y + z;
////}
////
////// Function that multiplies two
////// numbers
////int multiply(double x, double y, double z)
////{
////	return x * y * z;
////}
////
////// Function that takes a pointer
////// to a function
////int invoke(double x, double y, double z,
////	int(*func)(double, double, double))
////{
////	return func(x, y, z);
////}
////
////// Driver Code
////int main()
////{
////	// Pass pointers to add & multiply
////	// function as required
////	cout << "Addition of 20 and 10 is ";
////	cout << invoke(30, 20, 10, &add)
////		<< '\n';
////
////	cout << "Multiplication of 20"
////		<< " and 10 is ";
////	cout << invoke(30, 20, 10, &multiply)
////		<< '\n';
////
////	system("pause");
////	return 0;
////}
//
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void remove(std::vector<int> &v)
//{
//	//auto end = v.end();
//	for (int i = 0; i < v.size(); i ++)
//	{
//		for (int j = i + 1; j < v.size(); j++)
//		{
//			if (v[i] == v[j])
//			{
//				v.erase(v.begin() + j);
//			}
//		}
//	}
//
//	//v.erase(end, v.end());
//}
//
//int main()
//{
//	std::vector<int> v = { 5, 2, 1, 3, 4, 2, 2, 4, 5, 5, 6 };
//
//	remove(v);
//
//	for (auto it = v.cbegin(); it != v.cend(); ++it) {
//		std::cout << *it << ' ';
//	}
//
//	return 0;
//}
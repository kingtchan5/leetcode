#include<iostream>
#include<fstream>
#include <string>
#include <vector>

using namespace std;

void findTheMaximum(int upperLimit, int arr[49], int &max)
{
	for (int i = 0; i < 49; i++)
	{
		if ((arr[i] > max) && (arr[i] < upperLimit))
		{
			//if (max > upperLimit)
				max = arr[i];
		}
	}
}
void findTheMostExistingTimes(int arr[49], int max, vector<int> &mostIter)
{
	for (int i = 0; i < 49; i++)
	{
		if (arr[i] == max)
			mostIter.push_back(i + 1);
	}
}

void findTheMinimum(int lowerLimit, int arr[49], int &min)
{
	for (int i = 0; i < 49; i++)
	{
		if ((arr[i] < min) && (arr[i] > lowerLimit))
		{
			//if (max > upperLimit)
			min = arr[i];
		}
	}
}
void findTheLeastExistingTimes(int arr[49], int min, vector<int> &leastIter)
{
	for (int i = 0; i < 49; i++)
	{
		if (arr[i] == min)
			leastIter.push_back(i + 1);
	}
}

int main()
{
	char ch;
	int id = 1;
	string date;
	string data;
	string others;
	int arr[49] = { 0 };
	int number[6] = { 0 };
	//creating the object of the data type 'istream'
	fstream new_file;
	//opening the above file
	new_file.open("data.txt", ios::in);
	//checking whether the file is available or not
	if (!new_file)
	{
		cout << "Sorry the file you are looking for is not available" << endl;
		return -1;
	}
	// reading the whole file till the end
	//while (!new_file.eof())
	//{
	//	new_file >> noskipws >> ch;
	//	// printing the content on the console
	//	cout << ch;
	//}
	if (new_file.is_open())
	{
		while (getline(new_file, data))
		{
			data.assign(data, data.find("\t", 0) + 1, data.length());
			data.assign(data, data.find("\t", 0) + 1, data.length());
			data.assign(data, 0, data.find("\t", 0));
			string tmp = data;

			for (int i = 0; i < 6; i++)
			{
				others.assign(tmp, 0, tmp.find(",", 0));
				number[i] = stoi(others);
				//cout << number[i] << " ";
				arr[number[i] - 1]++;
				tmp.assign(tmp, tmp.find(",", 0) + 1, tmp.length());
			}
			//cout << endl;
			cout << id << "\t" << data << endl;
			id++;
		}
	}
	//while (getline(new_file, data))

	//closing the file after reading
	new_file.close();

	int max[6] = { 0 };
	findTheMaximum(100, arr, max[0]);
	findTheMaximum(max[0], arr, max[1]);
	findTheMaximum(max[1], arr, max[2]);
	findTheMaximum(max[2], arr, max[3]);
	findTheMaximum(max[3], arr, max[4]);
	findTheMaximum(max[4], arr, max[5]);

	vector<int> mostIter[6];
	findTheMostExistingTimes(arr, max[0], mostIter[0]);
	findTheMostExistingTimes(arr, max[1], mostIter[1]);
	findTheMostExistingTimes(arr, max[2], mostIter[2]);
	findTheMostExistingTimes(arr, max[3], mostIter[3]);
	findTheMostExistingTimes(arr, max[4], mostIter[4]);
	findTheMostExistingTimes(arr, max[5], mostIter[5]);

	cout << endl;
	for (int i = 0; i < 49; i++)
	{
		cout << i + 1 << ": " << arr[i] << "\t";

		if ((i != 0) && ((i + 1) % 10 == 0))
			cout << endl;
	}
	cout << endl << endl;

	cout << "The most number: ";
	for (int i = 0; i < mostIter[0].size(); i++)
	{
		cout << mostIter[0][i] << " ";
	}
	cout << "(" << max[0] << ")" << endl;

	cout << "The 2nd most number: ";
	for (int i = 0; i < mostIter[1].size(); i++)
	{
		cout << mostIter[1][i] << " ";
	}
	cout << "(" << max[1] << ")" << endl;

	cout << "The 3rd most number: ";
	for (int i = 0; i < mostIter[2].size(); i++)
	{
		cout << mostIter[2][i] << " ";
	}
	cout << "(" << max[2] << ")" << endl;

	cout << "The 4th most number: ";
	for (int i = 0; i < mostIter[3].size(); i++)
	{
		cout << mostIter[3][i] << " ";
	}
	cout << "(" << max[3] << ")" << endl;

	cout << "The 5th most number: ";
	for (int i = 0; i < mostIter[4].size(); i++)
	{
		cout << mostIter[4][i] << " ";
	}
	cout << "(" << max[4] << ")" << endl;

	cout << "The 6th most number: ";
	for (int i = 0; i < mostIter[5].size(); i++)
	{
		cout << mostIter[5][i] << " ";
	}
	cout << "(" << max[5] << ")" << endl;

	cout << endl;
	/*cout << endl;
	int theLargest = 0;
	for (int i = 0; i < 49; i++)
	{
		if (arr[i] > theLargest)
			theLargest = arr[i];
		
	}

	cout << "The most occurence: " << i + 1 << theLargest;*/

	int min[6] = { 100, 100, 100, 100, 100, 100 };
	findTheMinimum(0, arr, min[0]);
	findTheMinimum(min[0], arr, min[1]);
	findTheMinimum(min[1], arr, min[2]);
	findTheMinimum(min[2], arr, min[3]);
	findTheMinimum(min[3], arr, min[4]);
	findTheMinimum(min[4], arr, min[5]);

	vector<int> leastIter[6];
	findTheLeastExistingTimes(arr, min[0], leastIter[0]);
	findTheLeastExistingTimes(arr, min[1], leastIter[1]);
	findTheLeastExistingTimes(arr, min[2], leastIter[2]);
	findTheLeastExistingTimes(arr, min[3], leastIter[3]);
	findTheLeastExistingTimes(arr, min[4], leastIter[4]);
	findTheLeastExistingTimes(arr, min[5], leastIter[5]);

	//cout << endl;
	//for (int i = 0; i < 49; i++)
	//{
	//	cout << i + 1 << ": " << arr[i] << "\t";

	//	if ((i != 0) && ((i + 1) % 10 == 0))
	//		cout << endl;
	//}
	//cout << endl << endl;

	cout << "The min number: ";
	for (int i = 0; i < leastIter[0].size(); i++)
	{
		cout << leastIter[0][i] << " ";
	}
	cout << "(" << min[0] << ")" << endl;

	cout << "The 2nd most number: ";
	for (int i = 0; i < leastIter[1].size(); i++)
	{
		cout << leastIter[1][i] << " ";
	}
	cout << "(" << min[1] << ")" << endl;

	cout << "The 3rd most number: ";
	for (int i = 0; i < leastIter[2].size(); i++)
	{
		cout << leastIter[2][i] << " ";
	}
	cout << "(" << min[2] << ")" << endl;

	cout << "The 4th most number: ";
	for (int i = 0; i < leastIter[3].size(); i++)
	{
		cout << leastIter[3][i] << " ";
	}
	cout << "(" << min[3] << ")" << endl;

	cout << "The 5th most number: ";
	for (int i = 0; i < leastIter[4].size(); i++)
	{
		cout << leastIter[4][i] << " ";
	}
	cout << "(" << min[4] << ")" << endl;

	cout << "The 6th most number: ";
	for (int i = 0; i < leastIter[5].size(); i++)
	{
		cout << leastIter[5][i] << " ";
	}
	cout << "(" << min[5] << ")" << endl;

	cout << endl;
	cout << "12 is BIG HEAT!!" << endl;

	system("pause");
	return 0;
}
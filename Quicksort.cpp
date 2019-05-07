
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<ctime>
using namespace std;
#define MAX_NUM 1000000
#define MAX_32  0X7FFFFFFF



void quicksort3(vector<int> arr, int l, int r)
{

	if (l >= r)
		return;

	int  v = arr[l];
	int lt = l;
	int gt = r + 1;
	int i = l + 1;
	while (i<gt)
	{
		if (arr[i]<v)
		{
			swap(arr[i], arr[lt + 1]);
			lt++;
			i++;
		}

		else if (arr[i]>v)
		{
			swap(arr[i], arr[gt - 1]);
			gt--;
		}

		else
		{
			i++;
		}
	}


	swap(arr[l], arr[lt]);
	quicksort3(arr, l, lt - 1);
	quicksort3(arr, gt, r);

}


void QuickSort(vector<int> &array, int start, int last)
{
	int i = start;
	int j = last;
	int temp = array[i];
	if (i < j)
	{
		while (i < j)
		{
			//
			while (i < j &&  array[j] >= temp)
				j--;
			if (i < j)
			{
				array[i] = array[j];
				i++;
			}

			while (i < j && temp > array[i])
				i++;
			if (i < j)
			{
				array[j] = array[i];
				j--;
			}

		}
		//把基准数放到i位置
		array[i] = temp;
		//递归方法
		QuickSort(array, start, i - 1);
		QuickSort(array, i + 1, last);
	}
}

int Rand_Partition(vector<int>& data, int start, int end) {
	if (data.empty() || start <0|| start > end)
		throw new exception("Invalid parameters");
	int index = rand() % (end - start + 1) + start;
	swap(data[index],data[end]);
	int small = start - 1;
	for (index = start; index < end; index++) {
		if (data[index] < data[end]) {
			small++;
			if (small != index)
				swap(data[small], data[index]);
		}
	}
	++small;
	swap(data[end], data[small]);
	return small;
}
void quicksort(vector<int> &data, int p, int r) {
	if (p < r) {
		int q = Rand_Partition(data, p,r);
		quicksort(data, p, q - 1);
		quicksort(data, q + 1, r);
	}
}


int main()
{
//	int length = 10;
	//INPUT

	int p;
	cout << "1为随机数部分，2为全1部分，3为比例部分 ，其他退出 " << endl;
	//cin >> n;
	while (cin >> p&&p > 0 && p < 4) {
		switch (p)
	   {
		case 1:
		{
			clock_t start_time = clock();
		vector<int> data;
		for (int i = 0; i < MAX_NUM; i++) {
			int tem = rand() % MAX_32;
			data.push_back(tem);
		}
		cout << endl;
		cout << "     生成随机数所需时间		" << double(clock() - start_time) << "ms" << endl;
		start_time = clock();
		quicksort(data, 0, MAX_NUM - 1);
		cout << "     排序所需时间为		" << double(clock() - start_time) << "ms" << endl;
		//start_time = clock();
		//QuickSort(data, 0, MAX_NUM - 1);
		//cout << "     改进排序算法所需时间为		" << double(clock() - start_time) << "ms" << endl;

		start_time = clock();
		sort(data.begin(), data.end());
		cout << "    调用C++排序函数sort排序所需时间为	" << double(clock() - start_time) << "ms" << endl;
		break;
		}
		case 2:
		{
			clock_t start_time = clock();
			cout << endl;
			cout << "     输入为1000000个1";
			vector<int>data(MAX_NUM, 1);
			cout << endl;
			//quicksort(data, 0, MAX_NUM - 1);
			//
			
			quicksort3(data, 0, MAX_NUM - 1);
			cout << "     改进排序算法所需时间为		" << double(clock() - start_time) << "ms" << endl;
			start_time = clock();
			//cout << "     排序所需时间为		" << double(clock() - start_time) << "ms" << endl;
		//	sort(data.begin(), data.end());
		//	cout << "    调用C++排序函数sort排序所需时间为	" << double(clock() - start_time) << "ms" << endl;
		    break;
		}
		case 3:
		{
			int num = 5000;
			cout << endl;
			cout << "     数据规模为：" << num << endl;
			for (int i = 50; i <= 100; i += 10) {
				
				int num_one = num*i / 100;

				vector<int> data(num_one, 1);
				for (int j = 0; j < num - num_one; j++) {
					int tem = rand() % MAX_32;
					data.push_back(tem);
				}
				clock_t start_time = clock();
			//	quicksort(data, 0,data.size()-1);
				//cout << "     排序所需时间为		" << double(clock() - start_time) << "ms" << endl;
				start_time = clock();
				quicksort3(data, 0, data.size() - 1);
				cout << "     改进排序算法所需时间为		" << double(clock() - start_time) << "ms" << endl;
				//start_time = clock();
				//sort(data.begin(), data.end());
				//cout << "    调用C++排序函数sort排序所需时间为	" << double(clock() - start_time) << "ms" << endl;
			}
		}
		default:
			break;
		}
		
			cout << "1为随机数部分，2为全1部分，3为比例部分,其他退出  " << endl;
			//cin >> p;
			//output
		/* for (int i = 0; i < data.size(); i++) {
			cout << data[i] << "     ";
		}   */
	}
		system("pause");
		return 0;
}



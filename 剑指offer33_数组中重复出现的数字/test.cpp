#include<iostream>
using namespace std;

//在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 
//数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
//请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{ 2, 3, 1, 0, 2, 5, 3 }，
//那么对应的输出是第一个重复的数字2。


class Solution1 {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length <= 0){
			return false;//没有元素，空数组
		}
		int i = 0;
		for (i = 0; i < length; ++i){
			int j = 0;
			for (j = i+1; j < length; ++j){
				if (numbers[i] == numbers[j]){
					duplication[0] = numbers[i];
					return true;
				}
			}
		}
		return false;
	}
};


class Solution2 {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == NULL || length == 0) return 0;
		int hashTable[255] = { 0 };
		for (int i = 0; i<length; i++)
		{
			hashTable[numbers[i]]++;
		}
		int count = 0;
		for (int i = 0; i<length; i++)
		{
			if (hashTable[numbers[i]]>1)
			{
				duplication[count++] = numbers[i];
				//break;
				return true;
			}
		}
		return false;
	}
};

//不需要额外的数组或者hash table来保存，题目里写了数组里数字的范围保证在0 ~n - 1 之间，
//所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，
//之后再遇到相同的数时，会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。
//
//代码是C：
//
//int find_dup(int numbers[], int length) {
//	for (int i = 0; i<length; i++) {
//		int index = numbers[i];
//		if (index >= length) {
//			index -= length;
//		}
//		if (numbers[index] >= length) {
//			return index;
//		}
//		numbers[index] = numbers[index] + length;
//	}
//	return -1;
//}

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (numbers == nullptr || length <= 0){
			return false;
		}
		if (duplication == nullptr){
			return false;
		}
		int i = 0;
		for (i = 0; i < length; ++i){
			int index = numbers[i];
			if (index >= length){
				index -= length;
			}
			if (numbers[index] >= length){
				duplication[0] = index;
				return true;
			}
			numbers[index] = numbers[index] + length;
		}
		return false;
	}
};


void TestFunc(){
	int array[] = { 2, 3, 1, 0, 2, 5, 3 };
	int length = sizeof(array) / sizeof(array[0]);
	Solution s;
	int *duplication = nullptr;
	duplication = new int(0);
	cout << s.duplicate(array, length, duplication) << endl;
	cout << "重复出现的数字为：" << endl;
	cout << *duplication << endl;
	delete duplication;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}
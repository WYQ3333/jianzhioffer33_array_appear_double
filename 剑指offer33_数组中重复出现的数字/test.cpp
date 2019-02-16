#include<iostream>
using namespace std;

//��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ� 
//������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
//���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{ 2, 3, 1, 0, 2, 5, 3 }��
//��ô��Ӧ������ǵ�һ���ظ�������2��


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
			return false;//û��Ԫ�أ�������
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

//����Ҫ������������hash table�����棬��Ŀ��д�����������ֵķ�Χ��֤��0 ~n - 1 ֮�䣬
//���Կ������������������ñ�־����һ�����ֱ����ʹ��󣬿������ö�Ӧλ�ϵ��� + n��
//֮����������ͬ����ʱ���ᷢ�ֶ�Ӧλ�ϵ����Ѿ����ڵ���n�ˣ���ôֱ�ӷ�����������ɡ�
//
//������C��
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
	cout << "�ظ����ֵ�����Ϊ��" << endl;
	cout << *duplication << endl;
	delete duplication;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}
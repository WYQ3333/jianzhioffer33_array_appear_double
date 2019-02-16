#include<iostream>
using namespace std;

//��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ� 
//������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
//���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{ 2, 3, 1, 0, 2, 5, 3 }��
//��ô��Ӧ������ǵ�һ���ظ�������2��


class Solution {
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
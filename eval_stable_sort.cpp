// FileName:eval_stable_sort.cpp
// �������stable_sort�㷨ʱ��ⶨ
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Timer.h"
using namespace std;

int main()
{
	cout << "****************�������stable_sort�㷨ʱ��ⶨ*******************"
		<< endl;
	// N1��N2�ֱ�Ϊ������ʼ��С�����մ�С
	// N��������������ģ��С������
	unsigned long N, N1, N2;
	unsigned int reps;
	cout << "������������ʼ��С�� ";
	cin >> N1;
	cout << "�������������մ�С�� ";
	cin >> N2;
	cout << "�������ظ����������";
	cin >> reps;

	// ����������
	vector<int> v;
	// �����������ĸ������ظ�ʵ��ʹ��
	vector<int> v0;
	// ��ʼ�����������������
	srand(time(0));
	// �㷨��ʱ��
	Timer tim;

	for ( N=N1; N <= N2; N*=2){
		// ���v����
		v.clear();
		// ����v��СΪ�ϴε�2��
		v.resize(N);
		// ����rand()������������������A����
		generate(v.begin(),v.end(),rand);
		// ����v��v0���������ظ�����
		v0 = v;

		// ���������ģΪNʱ�Ļ�׼ʱ��
		tim.start_baseline(reps);
		do { 
			// �ڻ�׼ʱ���а���������ֵ����
			v = v0;
		} while (tim.check());
		// �����׼ʱ��
		tim.report(false);
		// ���������ģΪNʱ�������㷨ʱ��
		tim.start(reps, N);
		do {
			v = v0;    
				// �޸�v0��v
			stable_sort(v.begin(), v.end());
		}while (tim.check());
		// �����㷨ʱ�����ܷ������
		tim.report(false);
		}
	system("pause");
	return 0;
}

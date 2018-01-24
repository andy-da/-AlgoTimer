// "timeBaseline.cpp"
// ��sort�㷨Ӧ��ͳ�Ʒ�����ʱ���������ȡ���׼ʱ�䣨����ʱ�䣩
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cout << "********************ͳ�Ʒ���У׼sort�㷨��׼ʱ��ⶨ************************"
		<< endl;
	// ��������������
	unsigned long N;
	// ʵ���ظ�����
	unsigned int reps;
	cout << "������������СN�� ";
	cin >> N ;
	cout << "�������������reps��";
	cin >> reps;

	// ����������
	vector<int> A(N);
	// �����������ĸ������ظ�ʵ��ʹ��
	vector<int> B(N);
	// ��ʼ�����������������
	srand(time(0));
	// ����rand()������������������A����
	generate(A.begin(),A.end(),rand);
	// ��¼ÿ��ʵ��1sʱ�����ڵ�������

	vector<long> iterations;
	iterations.reserve(reps);
	// ����������ʼ�ͽ���ʱ��
	time_t start, finish;

	cout << "�ظ�ʵ������У���ȴ�����" << endl;
	while (iterations.size() < reps) {
		// ��ʼ��������
		int count = 0;
		// ��¼��ʼʱ��
		start = time(0);
		// ѭ��ִ����1sʱ����
		do {
			++count;
			B = A;
			// sort(B.begin(), B.end());
			finish = time(0);
		}while (finish == start);
		// ��¼1s��ѭ������
		iterations.push_back(count);
	}
	
	// ������
	cout << "���������������: " << endl;
	for (int k = 0; k < iterations.size(); ++k) 
		cout << iterations[k] << " ";
	cout << endl;

	// �Խ���������
	sort(iterations.begin(), iterations.end());
	cout << "�ź���ĸ��������������: " << endl;
	for (int k = 0; k < iterations.size(); ++k) 
		cout << iterations[k] << " ";
	cout << endl;
	cout << "ѡȡ�������������������λ��: " 
		<< iterations[reps/2] << endl;
	cout << "sort�㷨ִ��ʱ��Ϊ: " << 1000.0/iterations[reps/2]
	   << " ms " << endl;
	system("pause");
	return 0;
}

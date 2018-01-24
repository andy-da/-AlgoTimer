// FileName: Timer.h
// ����Timer�����ڷ����㷨����

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Timer {
public:
	// Ĭ�Ϲ��캯��
	Timer(){ baseline = false; };  
	// ��ʼ�����ģΪN��r��ϵ��ʵ��
	void start(unsigned int r, unsigned long N);
	// ��ʼr��ϵ��ʵ����ȷ����׼ʱ��
	void start_baseline(unsigned int r);
	// ��������������true�����򷵻�false
	bool check();
	// ����������
	// ���verboseΪtrue����ʾ������Ϣ
	void report(bool verbose);
	// ���ع��ⲿʹ�õĽ��
	const map<unsigned int, double>& results() const;
private:	
	// �ظ�����Ĵ���
	unsigned int reps;  
	// ���ڴ洢ÿ���ظ������ѭ������
	vector<long> iterations;
	// ���ڴ洢ÿ������ĳ�ʼ����ֹʱ��
	time_t initial, final;
	// ���ڼ���ÿ������ѭ����������
	unsigned long count;
	// ���ڴ洢��ǰ����������ģ��N��
	unsigned int problem_size;
	// ���ڴ洢(problem size, time)�Ľڵ��
	map<unsigned int, double> result_map;
	// ����ǻ�׼ʱ����㣬�˳�ԱΪtrue������Ϊfalse
	bool baseline;
	// ���ڼ�¼��׼ʱ��
	double baseline_time;
};

// ������鸨���ͻ����������ݵĳ�ʼ��
void Timer::start(unsigned int r, unsigned long N) 
{
	reps = r;
	problem_size = N;
	count = 0;
	iterations.clear();
	iterations.reserve(reps);
	initial = time(0);
}

// ���û�׼������������
void Timer::start_baseline(unsigned int r) 
{
	baseline = true;
	start(r, 0);
}
// ���鶨ʱ���Ƿ�����1s�����ǣ���¼����
bool Timer::check() 
{
	++count;
	final = time(0);
	if (initial < final) {
		iterations.push_back(count);  
		initial = final;
		count = 0;
	}
	return (iterations.size() < reps);
}

// ����������ͳ������Ľ��
void Timer::report(bool verbose)
{
	if (verbose) {
		for (unsigned int k = 0; k < iterations.size(); ++k) {
			cout << "���������������: " << endl;
			cout << iterations[k] << " ";
			// ÿ10������һ�飬����
			if ((k+1) % 10 == 0)
				cout << endl;
		}
		cout << endl;
	}
	sort(iterations.begin(), iterations.end());
	if (verbose) {
		cout << "�ź���ĸ��������������: " << endl;
		for (unsigned int k = 0; k < iterations.size(); ++k) {
			cout << iterations[k] << " ";
			// ÿ10������һ�飬����
			if ((k+1) % 10 == 0)
				cout << endl;
		}
		cout << endl;
	}
	// ѡ������������ֵ��Ϊ�ȷֵ
	int selected_count = iterations[reps/2];
	if (verbose) 
		cout << "ѡȡ�������������������λ��: " 
			<< selected_count << endl;
	if (baseline) {
		baseline_time = 1000.0/selected_count;
		cout << setiosflags(ios::fixed) << setprecision(4)
			<< "��׼ʱ��Ϊ: " << baseline_time << endl;
		baseline = false;
	} 
	else {
		double calculated_time, growth_factor;
		result_map[problem_size] = calculated_time = 
			1000.0/selected_count - baseline_time;
		// ���������ʽΪ�̶�������ʾ������Ϊ4
		cout << setiosflags(ios::fixed) << setprecision(4)
		 << "\t�����ģ��" << problem_size << "\t�㷨ʱ�䣺"
		 << calculated_time << "ms";
		// ��������ģN�Ľ����N/2�Ľ��������
		// ������������ӣ��������߼���ʱ��֮��
		if (result_map.find(problem_size/2) != result_map.end()) {
			growth_factor = calculated_time / result_map[problem_size/2];
			cout << setiosflags(ios::fixed) << setprecision(4) 
			   << "\t�������ӣ�" << growth_factor;
		}
		cout << endl;
	}
}
// ���ذ��������ģ���ʱ�����ӳ��
const map<unsigned int, double>& Timer::results() const
{
	return result_map;
}

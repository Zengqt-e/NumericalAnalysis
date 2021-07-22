// // NumericalAnalysis.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//�˴���ʵ�� 1.2�� ��1.1���̵� ������ʽ��FPI��⣬�ֱ�չʾ��ͬ��ʽ�� ������

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double>& fpi(double (*g)(double), double x0, vector<double>& result);
double gfunc01(double x);
double gfunc02(double x);
double gfunc03(double x);

int main() {

	int k = 25; //��������
	vector<double> result01(k, 0), result02(k, 0), result03(k, 0); // ������
	fpi(gfunc01, 0.5, result01);
	fpi(gfunc02, 0.5, result02);
	fpi(gfunc03, 0.5, result03);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(8);
	for (int i = 0; i != k; ++i) //ѭ����������������ֵ
	{
		cout << "x[" << i << "]\t" << result01[i] << "\t" << result02[i] << "\t" << result03[i] << "\t" << endl;
	}
}

vector<double>& fpi(double (*g)(double), double x0, vector<double>& result) { //fpi����������� ��������ʼֵ���洢�������
	double i_last = x0; //������һ�μ���ֵ��x0��Ϊ�����ʼֵ
	for (auto& i : result) { //��Χfor��ѭ������������ �����õ�result�����У���������Ϊ ����.size()
		i = (*g)(i_last);
		i_last = i;
	}
	return result;
}

double gfunc01(double x) {
	double y; //�����y�� ���
	y = 1 - pow(x, 3);
	return y;
}
double gfunc02(double x) {
	double y;
	y = cbrt(1 - x);
	return y;
}
double gfunc03(double x) {
	double y;
	y = (1 + 2 * pow(x, 3)) / (1 + 3 * pow(x, 2));
	return y;
}

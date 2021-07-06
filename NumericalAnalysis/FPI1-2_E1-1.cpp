// // NumericalAnalysis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//此代码实现 1.2节 例1.1方程的 三种形式的FPI求解，分别展示不同形式的 收敛性

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<double>& fpi(double (*g)(double), double x0, vector<double>& result);
double gfunc01(double x);
double gfunc02(double x);
double gfunc03(double x);

int main() {

	int k = 25; //迭代次数
	vector<double> result01(k, 0), result02(k, 0), result03(k, 0); // 计算结果
	fpi(gfunc01, 0.5, result01);
	fpi(gfunc02, 0.5, result02);
	fpi(gfunc03, 0.5, result03);

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(8);
	for (int i = 0; i != k; ++i) //循环输出三类迭代计算值
	{
		cout << "x[" << i << "]\t" << result01[i] << "\t" << result02[i] << "\t" << result03[i] << "\t" << endl;
	}
}

vector<double>& fpi(double (*g)(double), double x0, vector<double>& result) { //fpi求解器：输入 函数、初始值、存储结果序列
	double i_last = x0; //定义上一次计算值，x0作为计算初始值
	for (auto& i : result) { //范围for，循环计算迭代结果 并放置到result序列中，迭代次数为 序列.size()
		i = (*g)(i_last);
		i_last = i;
	}
	return result;
}

double gfunc01(double x) {
	double y; //因变量y， 输出
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

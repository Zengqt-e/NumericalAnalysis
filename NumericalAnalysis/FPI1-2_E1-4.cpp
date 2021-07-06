// NumericalAnalysis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//此代码实现 1.2节 例1.3 不动点迭代解 cos x = sin x 的根

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

double g(double x) {                                            // 定义 求解函数
    double y;
    y = x + cos(x) - sin(x);
    return y;
}

void fpi(double (*g)(double), double x0, vector<double>& x) { //FPI迭代函数，对vector结果序列的应用进行修改
    double i_last = x0;                                         //定义上一次值
    for (auto& i : x) {
        i = (*g)(i_last);
        i_last = i;
    }
}

int main()
{
    int k = 20;                 //20轮迭代
    vector<double> x(k, 0);
    fpi(g, 0, x);
    for(int i = 0; i != 20; ++i) 
        std::cout << "x:["<<i<<"] " << x[i] << " \n" << std::endl;

    return 0;
}








// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#pragma once //防止头文件重复包含
#include <iostream>
using namespace std; //使用标准命名空间

class WorkerManager
{
public:
    //构造函数
    WorkerManager();

    //菜单
    void Show_Menu();

    //退出系统
    void ExitSystem();

    //析构函数
    ~WorkerManager();
};
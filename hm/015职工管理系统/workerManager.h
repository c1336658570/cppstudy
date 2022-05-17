#pragma once //防止头文件重复包含
#include <iostream>
#include "worker.h"
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

    //记录职工人数
    int m_EmpNum;

    //职工数组指针
    Worker **m_EmpArray;

    //添加职工
    void Add_Emp();

    //析构函数
    ~WorkerManager();
};
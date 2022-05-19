#pragma once //防止头文件重复包含
#include <iostream>
#include <fstream>
#include <string>
#include "worker.h"

#define FILENAME "empFile.txt"

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

    //保存文件
    void save();

    //标志文件是否为空
    bool m_FileIsEmpty;

    //统计人数
    int get_EmpNum();

    //初始化员工
    void init_Emp();

    //显示职工
    void Show_Emp();

    //判断职工是否存在，存在返回数组中的位置，不存在返回-1
    int IsExist(int id);

    //删除职工
    void Del_Emp();

    //修改职工
    void Mod_Emp();

    //查找职工
    void Find_Emp();

    //按照职工编号排序
    void Sort_Emp();

    //清空文件
    void Clean_File();

    //析构函数
    ~WorkerManager();
};
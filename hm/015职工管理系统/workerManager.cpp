/*
创建管理类

​管理类负责的内容如下：

与用户的沟通菜单界面
对职工增删改查的操作
与文件的读写交互
*/

#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"

WorkerManager::WorkerManager()
{
    // 1、文件不存在

    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否文空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 2、文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空!" << endl;
        //初始化属性
        //初始化记录人数
        this->m_EmpNum = 0;
        //初始化数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否文空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    // 3、文件存在，并且记录数据
    int num = this->get_EmpNum();
    cout << "职工人数为：" << num << endl;
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    //将文件的数据存入数组中
    this->init_Emp();

    //测试代码
    /*
    for (int i = 0; i < this->m_EmpNum; ++i)
    {
        cout << "职工编号：" << this->m_EmpArray[i]->m_Id
             << " 姓名：" << this->m_EmpArray[i]->m_Name
             << " 部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
    }
    */
}

void WorkerManager::Show_Menu()
{
    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0); //退出程序
}

//添加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量：" << endl;

    int addNum = 0; //保存用户输入的数量
    cin >> addNum;

    if (addNum > 0)
    {
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; //新空间的人数 = 原来空间人数 + 新增人数

        //开辟新空间
        Worker **newSpace = new Worker *[newSize];

        //将原来空间下的数据拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //批量添加新数据
        for (int i = 0; i < addNum; ++i)
        {
            int id;      //职工编号
            string name; //职工姓名
            int dSelect; //部门选择

            cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
            cin >> id;

            cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
            cin >> name;

            cout << "请选择该职工的岗位" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经历" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Manager(id, name, 3);
                break;
            default:
                break;
            }

            //将创建的职工指针保存到数组里
            newSpace[this->m_EmpNum + i] = worker;
        }

        //释放原有空间
        delete[] this->m_EmpArray;

        //更改新空间的指向
        this->m_EmpArray = newSpace;

        //更新新的职工人数
        this->m_EmpNum = newSize;

        //更新职工不为空志
        this->m_FileIsEmpty = false;

        //成功添加后，保存到文件
        this->save();

        //提示添加成功
        cout << "成功添加" << addNum << "名新职工！" << endl;
    }
    else
    {
        cout << "输入数据有误" << endl;
    }

    //按任意建后，返回上一级
    cout << "按任意建返回目录" << endl;
    getchar();
    getchar();
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //输出方式打开文件 --写文件

    //将每个人的数据写入到文件中
    for (int i = 0; i < this->m_EmpNum; ++i)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close(); //关闭文件
}

WorkerManager::~WorkerManager()
{
    if (this->m_EmpArray != NULL)
    {
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //打开文件 读文件

    int id;
    string name;
    int dId;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        //统计人数变量
        num++;
    }

    return num;
}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;

        if (dId == 1) //普通职工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index] = worker;
        index++;
    }

    //关闭文件
    ifs.close();
}
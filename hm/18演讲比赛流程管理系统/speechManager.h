#pragma once
#include <iostream>
using namespace std;

//演讲管理类
class SpeechManager
{
public:
    //构造函数
    SpeechManager();

    //展示菜单
    void show_Menu();

    //退出系统
    void exitSystem();

    //析构函数
    ~SpeechManager();
};
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
#include "speaker.h"
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

    //初始化容器和属性
    void initSpeech();

    //初始化创建12名选手
    void createSpeaker();

    //开始比赛 - 比赛流程控制
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示比赛结果
    void showScore();

    //保存记录
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示往届得分
    void showRecord();

    //文件为空的标志
    bool fileIsEmpty;

    //往届记录
    map<int, vector<string>> m_Record;

    //清空记录
    void clearRecord();

    //析构函数
    ~SpeechManager();

    //成员属性
    //比赛选手 容器  12人
    vector<int> v1;

    //第一轮晋级容器  6人
    vector<int> v2;

    //胜利前三名容器  3人
    vector<int> vVictory;

    //存放编号 以及对应的 具体选手 容器
    map<int, Speaker> m_Speaker;

    //存放比赛轮数
    int m_Index;
};
/*
比赛流程分析：
抽签 → 开始演讲比赛 → 显示第一轮比赛结果 →
抽签 → 开始演讲比赛 → 显示前三名结果 → 保存分数
*/

#pragma once
#include <iostream>
using namespace std;

//选手类
class Speaker
{
public:
    string m_Name;     //姓名
    double m_Score[2]; //分数  最多有两轮得分
};
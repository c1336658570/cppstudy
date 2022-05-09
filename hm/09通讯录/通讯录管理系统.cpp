# include <iostream>
# include <string>
using namespace std;

# define MAX 1000
#define CLEAR() printf("\033[2J") 

struct Person
{
    //姓名
    string m_Name;
    //性别
    int m_Sex;
    //年龄
    int m_Age;
    //电话
    string m_Phone;
    //住址
    string m_Addr;
};

struct Addressbooks
{
    //联系人数组
    struct Person personArray[MAX];
    //联系人个数
    int m_Size;
};

void showMenu(); //输出菜单
void addPerson(struct Addressbooks *abs); //添加联系人
void showPerson(struct Addressbooks *abs); //输出联系人
int isExist(Addressbooks * abs, string name); //检测联系人是否存在，存在返回具体位置，不存在返回-1
void deletePerson(struct Addressbooks *abs); //删除联系人
void findPerson(struct Addressbooks *abs); //查找联系人
void modifyPerson(struct Addressbooks *abs); //修改联系人
void clearPerson(Addressbooks *abs); //清空联系人

int main(void)
{
    struct Addressbooks abs;
    abs.m_Size = 0;
    int select;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
            case 1: //1、添加联系人
                addPerson(&abs);
                break;
            case 2: //2、显示联系人
                showPerson(&abs);
                break;
            case 3: //3、删除联系人
                deletePerson(&abs);
                break;
            case 4: //4、查找联系人
                findPerson(&abs);
                break;
            case 5: //5、修改联系人
                modifyPerson(&abs);
                break;
            case 6: //6、清空联系人
                clearPerson(&abs);
                break;
            case 0: //0、退出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                cout << "输入有误，请重新输入" << endl;
                break;
        }
    }

    return 0;
}

void showMenu()
{
    cout << "*************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出通讯录 *****" << endl;
    cout << "*************************" << endl;

    return;
}

//添加联系人
void addPerson(struct Addressbooks * abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        //添加具体联系人

        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;
        
        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;

        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "输入有误，清重新输入" << endl;
        }

        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        //住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;

        //更新通讯录人数
        abs->m_Size++;

        cout << "恭喜你添加成功" << endl;
    }
}

//显示联系人
void showPerson(struct Addressbooks *abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; ++i)
        {
            cout << "姓名：" << abs->personArray[i].m_Name;
            cout << " 性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女");
            cout << " 年龄：" << abs->personArray[i].m_Age;
            cout << " 电话：" << abs->personArray[i].m_Phone;
            cout << " 住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
}

//检测联系人是否存在，存在返回具体位置，不存在返回-1
int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;
}

//删除联系人
void deletePerson(struct Addressbooks *abs)
{
    cout << "请输入你要删除的联系人" << endl;

    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size-1; ++i)
        {
            abs->personArray[i] = abs->personArray[i+1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

//查找联系人
void findPerson(struct Addressbooks *abs)
{
    cout << "请输入你要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if ( ret != -1 )
    {
        cout << "姓名：" << abs->personArray[ret].m_Name;
        cout << " 性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女");
        cout << " 年龄：" << abs->personArray[ret].m_Age;
        cout << " 电话：" << abs->personArray[ret].m_Phone;
        cout << " 住址：" << abs->personArray[ret].m_Addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

//修改联系人
void modifyPerson(struct Addressbooks *abs)
{
    cout << "请输入你要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;
        
        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;

        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;

        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[ret].m_Age = age;
                break;
            }
            cout << "输入有误，清重新输入" << endl;
        }

        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        //住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;
    }
    else
    {
        cout << "查无此人" << endl;
    }
}

//清空联系人
void clearPerson(Addressbooks *abs)
{
    abs->m_Size = 0;
    cout << "通讯录已清空" << endl;
}
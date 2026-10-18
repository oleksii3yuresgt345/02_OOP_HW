#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

void SetPos(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct Coord
{
    int x;
    int y;
};

class RectangleBox
{
    int width;
    int height;
    char symbol;
    Coord coords;
public:
    RectangleBox()
    {
        width = 10;
        height = 5;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }
    RectangleBox(int size)
    {
        if (size < 0)
        {
            size = abs(size);
        }
        width = size;
        height = size;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }
    RectangleBox(int userWidth, int userHeight)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        width = userWidth;
        height = userHeight;
        symbol = '#';
        coords.x = 0;
        coords.y = 0;
    }

    void Print()
    {
        SetPos(coords.x, coords.y);
        for (int i = 0; i < height; i++)
        {
            SetPos(coords.x, coords.y--);
            for (int i = 0; i < width; i++)
            {
                cout << symbol;
            }
            cout << endl;
        }
    }

    void ChangeRectangle(int userWidth, int userHeight, char userSymbol, int userX, int userY)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        if (userX < 0)
        {
            userX = 0;
        }
        if (userY < 0)
        {
            userY = 0;
        }

        width = userWidth;
        height = userHeight;
        symbol = userSymbol;
        coords.x = userX;
        coords.y = userY;
    }
    void ChangeWH(int userWidth, int userHeight)
    {
        if (userWidth < 0)
        {
            userWidth = abs(userWidth);
        }
        if (userHeight < 0)
        {
            userHeight = abs(userHeight);
        }
        width = userWidth;
        height = userHeight;
    }
    void ChangeCoords(int userX, int userY)
    {
        if (userX < 0)
        {
            userX = 0;
        }
        if (userY < 0)
        {
            userY = 0;
        }
        coords.x = userX;
        coords.y = userY;
    }
};

class Student
{
private:
    string name;
    int age;
    int* marks;
    int countMarks;
    int averageMark;

    void SetAverageMark()
    {
        int numbers(0);
        for (int i = 0; i < countMarks; i++)
        {
            numbers += marks[i];
        }
        averageMark = numbers / countMarks;
    }
public:
    Student()
    {
        name = "no name";
        age = 0;
        marks = nullptr;
        countMarks = 0;
        averageMark = 0;
    }
    Student(string name, int age) : Student()
    {
        this->name = name;
        this->age = age;
    }

    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setAge(int age) { this->age = age; }
    int getAge() { return age; }

    void Print()
    {
        cout << "Student's name : " << name << endl;
        cout << "Student's age : " << age << endl;
        cout << "Student's marks : ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Student's counted marks : " << countMarks << endl;
        cout << "Student's average mark : " << averageMark << endl;
        cout << endl << endl;
    }

    void AddMark(int mark)
    {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        if (marks != nullptr) delete[]marks;
        marks = temp;
        countMarks++;
        SetAverageMark();
    }

    void Save()
    {
        ofstream out("stFile");
        out << name << endl;
        out << age << endl;
        for (int i = 0; i < countMarks; i++)
        {
            out << marks[i] << " ";
        }
        out << endl;
        out << countMarks << endl;
        out << averageMark << endl;
        out.close();
    }

    void Load()
    {
        ifstream in("stFile");
        if (in.is_open())
        {
            char bname[50];
            
            in.getline(bname, 50);
            cout << name << endl;
            in >> age;
            cout << age << endl;
            for (int i = 0; i < countMarks; i++)
            {
                in >> marks[i];
                cout << marks[i] << " ";
            }
            cout << endl;
            in >> countMarks;
            cout << countMarks << endl;
            in >> averageMark;
            cout << averageMark << endl;
        }
        else
            cout << "No file" << endl;
        in.close();
    }

    ~Student() { if (marks != nullptr) delete[]marks; }

};

int main()
{
    RectangleBox R;
    R.Print();
    Sleep(3000);
    system("cls");

    RectangleBox R2(4);
    R2.Print();
    Sleep(3000);
    system("cls");

    RectangleBox R3(3, -5);
    R3.Print();
    Sleep(3000);
    system("cls");



    R.ChangeRectangle(-10, -15, '@', 90, 50);
    R.Print();
    Sleep(2000);
    system("cls");

    R.ChangeWH(6, 8);
    R.Print();
    Sleep(2000);
    system("cls");

    R.ChangeCoords(10, 20);
    R.Print();
    Sleep(2000);
    system("cls");



    R.ChangeCoords(-10, -20);
    R.Print();
    Sleep(2000);
    system("cls");

    Student st;
    st.Print();
    st.AddMark(2);
    st.AddMark(5);
    st.AddMark(7);
    st.AddMark(11);
    st.Print();
    st.Save();
    st.Load();

    st.setName("Tom");
    st.setAge(15);
    cout << "Student's name is " << st.getName() << endl;
    cout << "Student's age is " << st.getAge() << endl;
}
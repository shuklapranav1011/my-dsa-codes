#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

class Student
{
private:
    int roll_no;
    int marks;

public:
    Student()
    {
        roll_no = 0;
        marks = 0;
    }

    Student(int r = 0, int m = 0)
    {
        roll_no = r;
        marks = m;
    }

    void show_data()
    {
        cout << roll_no << " " << marks << "/n";
    }
};

main()
{

    IOS;

    Student s1;
    s1.show_data();

    return 0;
}
// my project hotile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable:4996)
#include <iostream>
#include<iomanip>
#include<vector>
#include<ctime>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;
class student;
struct strTime {
    int years;
    int monthes;
    int day;
};
string filestudent = "textstudent";
string fileemploy = "textemploy";
class student; class Employ;
const int costem = 20000,salary=300000;
int getvalue()
{
    int chec=0;
   
    while (true)
    {
        cin >> chec;
        if (cin.good())
        {
            cin.ignore(2,'\n');
            break;
        }
        cout << " The value Not True\n";
        cin.clear();
        cin.ignore(10, '\n');
    }
    return chec;
}
float getfloatvalue()
{
    float che;
    while (true)
    {
        cin >> che;
        if (cin.good())
        {
            cin.ignore(10, '\n');
            break;
        }
        cin.ignore(10, '\n');
        cin.clear();
        cout << " The value Not True\n";

    }
    return che;
}
void showMain()
{
    cout << "==================Student Centrol=================\n";
    cout << "Centrol student      [1]\n";
    cout << "Control Monay        [2]\n";
    cout << "Intervals and Rent   [3]\n";
    cout << "Employees            [4]\n";
    cout << "Exit                 [0]\n";
    cout << "=====================================================\n";
}

void showintervals()
{
    cout << "==================intervals Centrol=================\n";
    cout << "show  intervals finsh             [1]\n";
    cout << "show  intervals  about to finsh   [2]\n";
    cout << "show  intervals                   [3]\n";
    cout << "main                              [4]\n";
    cout << "Exit                              [0]\n";
    cout << "=====================================================\n";
}
void showMonay()
{
    cout << "==================Centrol Monay=================\n";
    cout << "show student paid      [1]\n";
    cout << "show student not paid  [2]\n";
    cout << "show student mod paid  [3]\n";
    cout << "paid   monay           [4]\n";
    cout << "Main screen            [5]\n";
    cout << "Exit                   [0]\n";
    cout << "=====================================================\n";
}
int room[20][1]{0};
class intervals {
public:
    string intervalsstudent() {
        string date = "";
        time_t t = time(0);
        tm* dt = localtime(&t);
        date += to_string(dt->tm_year + 1900);
        date += "##" + to_string(dt->tm_mon + 1);
        date += "##" + to_string( dt->tm_mday);
    /*    date += "//" + to_string( dt->tm_hour);
        date += "//" + to_string(dt->tm_min);
        date += "//" + to_string(dt->tm_sec);*/
        return date;
 }
    string intervalscount(int n)
    {
        string be = intervalsstudent();
       

    }
 };
class Time:public intervals
{
public:
    strTime returnTime(string n)
    {
        int fo;
        strTime st;
        fo = n.find('/');
        st.years = stoi(n.substr(0, fo));
        n.erase(0, (fo + 2));
        fo = n.find('/');
        st.monthes = stoi(n.substr(0, fo));
        n.erase(0, (fo + 2));
        fo = n.find('/');
        st.day = stoi(n.substr(0, fo));
        n.erase(0, (fo + 2));

        return st;

    }
    int returndays(string n)
    {
        strTime st = returnTime(n);
        return (st.years * 360 + st.monthes * 30 + st.day);

    }
    int countdays()
    {
        string date = intervalsstudent();
        int dateday = returndays(date);
        return dateday;

    }
};
class student:public intervals {
private:
    string _name;
    int _id;
    int _phone;
    string _date;
    float _monay;
    int _day;
    int _room;
public:
    student() {
        _name = "";
        _id = 0;
        _phone = 0;
        _date = "";
        _monay = 0;
        _room = 0;
    }
    void setname(string name) {
         _name=name;
    }
    void setid(int id) {
         _id=id;
    }
    void setphone(int phone) {
         _phone=phone;
    }
    void setdate(string da) {
       
        _date = da;
    }
    void setmonay(float monay) {
         _monay=monay;
    }
    void setroom(int Room) 
    {
         if (Room < 20)
         {
             if (room[Room][0] < 5)
             {
                 int z = room[Room][0];
                 room[Room][0] = ++z;
             }
             else {
                 cout << " The room is Full\n";
             }
         }
         else {
             cout << " The Room not found\n";
         }
      
    }
    void setday(int day) {
         _day=day;
    }

    void writename() {
        cout << "enter name student\n";
        getline(cin >> ws, _name);
    }
    void writeid()     {
        cout << "enter id student\n";
         _id = getvalue();
    }
    void writephone()  {
        cout << "enter phone student\n";
         _phone = getvalue();
    }
    void writedate() {

        _date = intervalsstudent();
    }
    void writemonay() {
        cout << "enter monay student\n";
         _monay = getfloatvalue();
    }
    void writeroom() {
        cout << "enter room \n";
        while (true)
        {
             _room = getvalue();
            if (_room < 20)
            {
                if (room[_room][0] < 5)
                {
                    int z = room[_room][0];
                    room[_room][0] = (z+1);
                    break;
                }
                else {
                    cout << " The room is Full\n";
                }
            }
            else {
                cout << " The Room not found\n";
            }
        }
    }
    void writeday() {
        cout << "enter duration \n";
        _day = getvalue();
    }
    
    int getday()
    {
        return _day;
    }

    string getname() {
        return  _name;
    }
    int getid() {
        return _id;
    }
    int getphone() {
       return _id;
    }
    string getdate() {
        return _date;
    }
    float getmonay() {
        return _monay;
    }
    int getroom() {
        return _room;
    }
    void addstudent()
    {
      writename();
      writeid();
      writephone();
      writedate();
      writemonay();
      writeroom();
      writeday();
    }
};

class Employ :public student {
private:
    int _plant;
    float _salary;
    int _age;
    string _work;
public:
      void showmainEmployee()
    {
        cout << "==================employee Centrol=================\n";
        cout << "add Employee           [1]\n";
        cout << "select  Employees      [2]\n";
        cout << "width Employees        [3]\n";
        cout << "Payment and withdrawal [4]\n";
        cout << "Exit                   [0]\n";
        cout << "=====================================================\n";
    }
      
      void writesalary() {
            cout << "enter salary withdrawal \n";

            _salary = getfloatvalue();
            if (_salary > salary)
            {
                cout << "The Monay tigger Than Salary Repeate Agine liter\n";
                _salary = 0;
            }
        }
      void writeage() {
            cout << "enter age employee\n";
            _age = getvalue();
        }
      void writework() 
        {
            cout << "enter work\n";
            getline(cin >> ws, _work);
        }  
      float getage() {
            return _age;
        }
      float getsalary() {
            return _salary;
        }
      void setsalary(float mo) {
          _salary=mo;
      }
      void setwork(string work) {
          _work = work;
      }
      void setage(int mo) {
          _age = mo;
      }
      string getwork() 
        {
            return _work;
        }

      void addEmployees()
        {
            writename();
            writeid();
            writeage();
            writephone();
            writedate();
            writesalary();
            writework();
        }
      void printemployee(Employ pr)
      {
          cout << "|" << left << setw(20) << pr.getname() << "|" << left << setw(10) << pr.getid() << "|" << left << setw(10) << pr.getsalary() <<
              "|" << left << setw(20) << pr.getphone() << "|" << left << setw(27) << pr.getdate() << "|" << left << setw(13) << pr.getwork() << "|\n";

      }
      void employesheep()
      {
          cout << "|" << left << setw(20) << "name" << "|" << left << setw(10) << "id" << "|" << left << setw(10) << "salary" 
              << "|" << left << setw(20) << "Phone" << "|" << left << setw(26) << "date" << "|" << left << setw(13) << "work" << " |\n";
          cout << "|=========================================================================================================|\n";
      }
      void showemployee(vector<Employ>Emp)
      {
          cout << " ============================================= Employee paid =============================================\n";

          employesheep();
          for (Employ pr : Emp)
          {
              printemployee(pr);
          }
          cout << "|=========================================================================================================|\n";
      }
      void showemployeeOne(vector<Employ>&Emp)
      {
          cout << "===================enter id=================   :\n";
          int id = getvalue();
         
         
          for (Employ pr : Emp)
          {
              if (id == getid())
              {  
                  id = -4;
                  employesheep();
                  cout << " ============================================= Employee paid =============================================\n";
                  printemployee(pr);
                  cout << "|=========================================================================================================|\n";
              }
              }
          if (id == -4) { cout << "\nnot fond employee\n"; }

      }
     //ÍÓÇÈÇÊ ÇáãæÙÝíä    
      bool checkemployeefound(vector<Employ>&Emp)
      {
          cout << "=======================Enter Id====================\n";
          int ch = getvalue();
          for (Employ pr : Emp)
          {
              if (pr.getid()==ch)
              {
                 return true;
              }
          }
          return false;
      }
      void showmainEmployeeAcount()
      {
          cout << "==================account Employee=================\n";
          cout << "Employees Complete The Salary           [1]\n";
          cout << "The Remaining Employees Of The Salary   [2]\n";
          cout << "The Employees Who Have Not Withdrawn    [3]\n";
          cout << "Pay The Salary To All Employees         [4]\n";
          cout << "Pay One Salary Employee                 [5]\n";
          cout << "Pay All  Employees Salary ,Exceot       [5]\n";
          cout << "Need Employees Withdrawal monay         [7]\n";
          cout << "Main                                    [8]\n";

          cout << "Exit                                    [0]\n";
          cout << "=====================================================\n";
      }
      void showemployeeCompleteSalary(vector<Employ>Emp)
      {
          cout << " ============================================= Employee paid =============================================\n";

          employesheep();
          for (Employ pr : Emp)
          {
              if (pr.getsalary() == salary)
              {
                  printemployee(pr);
              }
          }
          cout << "|=========================================================================================================|\n";
      }
      void showemployeeRemainingSalary(vector<Employ>Emp)
      {
          cout << " ============================================= Employee paid =============================================\n";

          employesheep();
          for (Employ pr : Emp)
          {
              if (pr.getsalary() >=1 && pr.getsalary() < salary)
              {
                  printemployee(pr);
              }
          }
          cout << "|=========================================================================================================|\n";
      }
      void showemployeeNotWidthSalary(vector<Employ>Emp)
      {
          cout << " ============================================= Employee paid =============================================\n";

          employesheep();
          for (Employ pr : Emp)
          {
              if (pr.getsalary() >= 1 && pr.getsalary() < salary)
              {
                  printemployee(pr);
              }
          }
          cout << "|=========================================================================================================|\n";
      }
      
      void PlayemployeeAllSalary(vector<Employ>&Emp)
      {
          cout << "================Enter Monay=================\n";
          float Monay = getfloatvalue();
          for (Employ &pr : Emp)
          {
              int n = pr.getsalary() + Monay;
              pr.setsalary(n);

          }
      }
      void PlayOneemployee(vector<Employ>&Emp)
      {
          cout << "==================Enter Id===================\n";
          int id = getvalue();
          for (Employ &pr : Emp)
          {
              if (pr.getid() == id)
              {
               cout << "|=========================================================================================================|\n";
               printemployee(pr);
                  employesheep();
                  cout << "Need add Y/N\n";
                  char chec = 'y';
                  cin >> chec;
                  if (chec == 'y'   || chec == 'Y') 
                  {
                      cout << "================Enter Monay=================\n";
                      float Monay = getfloatvalue();
                      int n = pr.getsalary() + Monay;
                      pr.setsalary(n);
                  }
              }
          }
      }
      void PlayAllemployeeExpict(vector<Employ>&Emp)
      {
          cout << "==================Enter Id===================\n";
          int id = getvalue();
          cout << "\n================Enter Monay=================\n";
          float Monay = getfloatvalue();
          for (Employ &pr : Emp)
          {
              if (pr.getid() != id)
              {
                  int n = pr.getsalary() + Monay;
                  pr.setsalary(n);
              }
          }
      }

      void WithdrawalOneemployee(vector<Employ>& Emp)
      {
          cout << "==================Enter Id===================\n";
          int id = getvalue();
          for (Employ& pr : Emp)
          {
              if (pr.getid() == id)
              {
                  employesheep();
                  cout << "|=========================================================================================================|\n";
                  printemployee(pr);
                  cout << "Need Withdrawal Y/N\n";
                  char chec = 'n';
                  cin >> chec;
                  if (chec == 'y' || chec == 'Y')
                  {
                      cout << "================Enter Monay=================\n";
                      float Monay = getfloatvalue();
                      Monay += getsalary();
                      if (Monay> 30000.00)
                      {
                         cout << "The Monay Tigger Than salary 111\n";
                      }
                      else 
                      {
                          cout << "The Monay Tigger Than salary\n";
                          pr.setsalary(Monay);
                      }
                  }
              }
          }
      }
};
 //read to file 

student ReturnStudentTostrin(string st)
{
    student line; string name; int num = 0;
    int fond = st.find('/');
    name = st.substr(0, fond);
    line.setname(name);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setid(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setphone(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setroom(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setmonay(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setday(num);
    st.erase(0, (fond + 2));
    line.setdate(st);
    return line;

}
void readFromFilestudent(vector<student>& stu)
{
    student read;
    ifstream fileS(filestudent, ios::in);
    if (fileS.is_open())
    {
        string line;
        while (getline(fileS, line))
        {
            read = ReturnStudentTostrin(line);
            stu.push_back(read);
        }
    }
}
string ReturnStudentTostring(student st)
{
    string Tre = "";
    Tre += st.getname();
    Tre += "//";
    Tre += to_string(st.getid());
    Tre += "//";
    Tre += to_string(st.getphone());
    Tre += "//";
    Tre += to_string(st.getroom());
    Tre += "//";
    Tre += to_string(st.getmonay());
    Tre += "//";
    Tre += to_string(st.getday());
    Tre += "//";
    Tre += st.getdate();
    return Tre;

}
void writeToFolestudent(vector<student>stu)
{
    ofstream fileS(filestudent);
    if (fileS.is_open())
    {
        string line;
        for (student st : stu)
        {
            line = ReturnStudentTostring(st);
            fileS << line << endl;
        }
    }
}


Employ ReturnEmployTostrin(string st)
{
    Employ line; string name; int num = 0;
    int fond = st.find('/');
    name = st.substr(0, fond);
    line.setname(name);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setid(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setphone(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setsalary(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    num = stoi(st.substr(0, fond));
    line.setage(num);
    st.erase(0, (fond + 2));

    fond = st.find('/');
    name = st.substr(0, fond);
    line.setwork(name);
   
    st.erase(0, (fond + 2));
    line.setdate(name);
    return line;

}
void readFromFileEmploy(vector<Employ>& stu)
{
    Employ read;
    ifstream fileS(fileemploy, ios::in);
    if (fileS.is_open())
    {
        string line;
        while (getline(fileS, line))
        {
            read = ReturnEmployTostrin(line);
            stu.push_back(read);
        }
    }
}
string ReturnEmployTostring(Employ st)
{
    string Tre = "";
    Tre += st.getname();
    Tre += "//";
    Tre += to_string(st.getid());
    Tre += "//";
    Tre += to_string(st.getphone());
    Tre += "//";
    Tre += to_string(st.getsalary());
    Tre += "//";
    Tre += to_string(st.getage());
    Tre += "//";
    Tre += st.getwork();
    Tre += "//";
    Tre += st.getdate();
    return Tre;
}
void writeToFoleEmploy(vector<Employ>stu)
{
    ofstream fileE(fileemploy);
    if (fileE.is_open())
    {
        string line;
        for (Employ emp : stu)
        {
            line = ReturnEmployTostring(emp);
            fileE << line << endl;
        }
    }
}





   void printstudent(student pr)
{
    cout << "|" << left << setw(20) << pr.getname() << "|" << left << setw(10) << pr.getid() << "|" << left << setw(10) << pr.getmonay() <<
        "|" << left << setw(20) << pr.getphone() << "|" << left << setw(15) << (costem-pr.getmonay())<< "|" << left << setw(18) << pr.getdate() << "|\n";
    
}
   void printstudentone(student pr)
{
    cout << "|" << left << setw(20) << "name" << "|" << left << setw(10) << "id" << "|" << left << setw(10) << "Monay" << "|" << left << setw(20) << "Phone" << "|" << left << setw(25) << "date" << "|" << left << setw(10) << "mode day" << " |\n";
    cout << "|====================================================================================================|\n";

    cout << "|" << left << setw(20) << pr.getname() << "|" << left << setw(10) << pr.getid() << "|" << left << setw(10) << pr.getmonay() <<
        "|" << left << setw(20) << pr.getphone() << "|" << left << setw(27) << pr.getdate() << "|\n";

}
   void studentpaidsh()
{
    cout << "|" << left << setw(20) << "name" << "|" << left << setw(10) << "id" << "|" << left << setw(10) << "Monay" << "|" << left << setw(20) << "Phone" << "|" << left << setw(15) << "mod monay" << "|" << left << setw(18) << "date" << " |\n";
     cout << "|===================================================================================================|\n";
}
   void studentintervals()
 {
     cout << "|" << left << setw(20) << "name" << "|" << left << setw(10) << "id" << "|" << left << setw(10) << "Monay" << "|" << left << setw(20) << "Phone" << "|" << left << setw(25) << "date" << "|" << left << setw(10) << "day mode" << " |\n";
     cout << "|====================================================================================================|\n";
 }
   void printintervalssS(student pr,int day)
 {
     cout << "|" << left << setw(20) << pr.getname() << "|" << left << setw(10) << pr.getid() << "|" << left << setw(10) << pr.getmonay() <<
         "|" << left << setw(20) << pr.getphone() << "|" << left << setw(27) << pr.getdate() << "|" << left << setw(10) << day << "|\n";

 }
   void Deletestudent(vector<student>& st)
{
    vector<student>last;
    cout << " Enter id\n";
    int x;
    cin >> x;
    char chec;
    for (student &New : st)
    {

        if (New.getid() == x)
        { 
        cout << "  =================================== Need Deleteing The"<<New.getname() << "==========================\n";
        printstudent(New);
        cout << "=====================================================================================\n";
        cout << "need deleting Y/n";
        cin >> chec;
        
        }
        else {
            last.push_back(New);
        }
    }
    if (chec == 'y' || chec == 'Y') 
    {
        st = last;
    }
    

}
class Control:public student {
public:

    
    void showStudentpaid(vector<student>st)
    {
        cout << " ============================================== student paid =============================================\n";
        studentpaidsh();
      for (student pr : st)
        {
            if (pr.getmonay() >= costem)
            {
                printstudent(pr);
            }
        }
      cout << "|====================================================================================================|\n";
    }
    void showStudentnotpaid(vector<student>st)
    {
       
        cout << " ========================================= student not paid =========================================\n";
        studentpaidsh();
        for (student pr : st)
        {
            if (pr.getmonay()==0)
            {
                printstudent(pr);
            }
        }
        cout << "|=====================================================================================================|\n";
    }
    void showStudentcenterpaid(vector<student>st)
    {
        cout << " ======================================= student center paid =======================================\n";
        studentpaidsh();
        for (student pr : st)
        {
            if (pr.getmonay() >0)
            {
                printstudent(pr);
            }
        }
        cout << "|====================================================================================================|\n";
    }
    void paidStudentmonay(vector<student>&st)
    {
        
        cout << "==================enter the id==============\n";
        int mo = getvalue();
        cout << endl;
        for (student &pr : st)
        {
            if (pr.getid()==mo)
            {
                cout << "|====================================================================================================|\n";
                printstudentone(pr);
                cout << "|====================================================================================================|\n";
                 cout << "enter the monay\n";
                 int monay = getvalue();
                 cout << "Need add Y/N\n";
                char ch;
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                {
                    int su = pr.getmonay() + monay;
                    pr.setmonay(su);
                    cout << "\n successfily\n";

                }
                cout << "Nod prosse Seccssfliy\n";
                
            }
        }
       
    }

    void intervalsfinsh(vector<student>st)
    {
       
        Time m; 
        int daystart =0, daynew=0;
        cout << endl;
        int Counter = 0;
        cout << " ===================================== student intervals finsh ======================================\n";
        studentintervals();
        for (student pr : st)
        {
             daynew = m.countdays();
            daystart=m.returndays(pr.getdate());
            Counter =daynew- daystart;
            Counter = pr.getday() - Counter;
            if (Counter<0)
            {                
                printintervalssS(pr, Counter);
            }
           
           
        } cout << " ===========================================================================\n";
        system("pause>0");

    }
    void intervalsaboutefinsh(vector<student>st)
    {

        Time m;
        int daystart = 0, daynew = 0;
        cout << endl;
        int Counter = 0;
        cout << " ================================= student intervals aboute finsh ===================================\n";
        studentintervals();
        for (student pr : st)
        {
            daynew = m.countdays();
            daystart = m.returndays(pr.getdate());
            Counter =  daynew- daystart;
            Counter = pr.getday()-Counter;
            if ( Counter>1 && Counter<10 )
            {
                printintervalssS(pr, Counter);
            }


        }cout << " ===========================================================================\n";
        system("pause>0");

    }
    void intervalsprint(vector<student>st)
    {

        Time m;
        int daystart = 0, daynew = 0;
        cout << endl;
        int Counter = 0;
        cout << " ================================= student intervals aboute finsh ===================================\n";
        studentintervals();
        for (student pr : st)
        {
            daynew = m.countdays();
            daystart = m.returndays(pr.getdate());
            Counter = daynew - daystart; 
            Counter = pr.getday() - Counter;
            printintervalssS(pr, Counter);
        }cout << " ===========================================================================\n";
        system("pause>0");

    }
};
  void centroleprogram(vector<student>&st, vector<Employ>&Emp, Control p);
  void shewstudentintervals(vector<student>&st, vector<Employ>&Emp, Control p)
{
    int x;
    while (true)
    {
        showintervals();
        x = getvalue();
        system("cls");
        if (x == 1)
        {

            p.intervalsfinsh(st);
        }
        else if (x == 2)
        {
            p.intervalsaboutefinsh(st);
        }
        else if (x == 3)
        {
            p.intervalsprint(st);
        }
        else if (x == 4)
        {
            centroleprogram(st,Emp,p);
        }
        else if (x == 5)
        {
            exit(0);
        }
    }
}
  //employees
  void PaymentandWithdrawal(vector<student>&st, vector<Employ>&Emp, Control p)
  {
      Employ add;
      int x;
      while (true)
      {
          add.showmainEmployeeAcount();
          x = getvalue();
          system("cls");
          if (x == 1)
          {
            add.showemployeeCompleteSalary(Emp);
              
          }
          else if (x == 2)
          {
              add.showemployeeRemainingSalary(Emp);
          }
          else if (x == 3)
          {
              add.showemployeeNotWidthSalary(Emp);
          }
          else if (x == 4)
          {
              add.PlayemployeeAllSalary(Emp);
              writeToFoleEmploy(Emp);
          }
          else if (x == 5)
          {
              add.PlayOneemployee(Emp);
              writeToFoleEmploy(Emp);
          }
          else if (x == 6)
          {
              add.PlayAllemployeeExpict(Emp);
              writeToFoleEmploy(Emp);
          }
          else if (x == 7)
          {
              add.WithdrawalOneemployee(Emp);
              writeToFoleEmploy(Emp);
          }
          else if (x == 8)
          {
              centroleprogram(st, Emp, p);
          }
      
      }
  }
  void centrolesEmployee(vector<student>&st, vector<Employ>&Emp, Control p)
  {
      Employ add;
      int x;
      while (true)
      {
          add.showmainEmployee();
          x = getvalue();
          system("cls");
          if (x == 1)
          {
              add.addEmployees();
              Emp.push_back(add);
              writeToFoleEmploy(Emp);
          }
          else if (x == 2)
          {
              add.showemployeeOne(Emp);
             
          }
          else if (x == 3)
          {
              add.showemployee(Emp);
          }
          else if (x == 4)
          {
             PaymentandWithdrawal(st,Emp,p);
          }
          else if (x == 5)
          {
              exit(0);
          }
          
      }
  }

void centrolestudent(vector<student>&st, vector<Employ>&Emp, Control p)
{
    student add;
    int x;
    while (true)
    {
        system("cls");
        cout << "================Student==============\n";
        cout << "Add student           [1]\n";
        cout << "Delete student        [2]\n";
        cout << "Return Main Screen    [3]\n";
       
         x=getvalue();
        system("cls");
        if (x == 1)
        {
           add.addstudent();
           st.push_back(add);
            writeToFolestudent(st);
            
        }
        else if (x == 2)
        {
            Deletestudent(st);
            writeToFolestudent(st);
        }
        else if (x == 3) { centroleprogram(st,Emp, p); }
    }
}

void centrolemonay(vector<student>&st, vector<Employ>&Emp, Control p)
{
   
    int x;
    while (true)
    {
        showMonay();
        x = getvalue();
        system("cls");
        
        
        if (x == 1)
        {

            p.showStudentpaid(st);
        }
        else if (x == 2)
        {
            p.showStudentnotpaid(st);
        }
        else if (x == 3)
        {
            p.showStudentcenterpaid(st);
        }
        else if (x == 4)
        {
            p.paidStudentmonay(st);
            writeToFolestudent(st);
        }
        else if (x == 5)
        {
            centroleprogram(st,Emp,p);
            
        }
        else if(x==0){ exit(0); }
        system("pause>0");
        system("cls");
    }
}
void centroleprogram(vector<student>&st, vector<Employ>&Emp,Control p)
{
    int x;
    while (true)
    {
        showMain();
         x=getvalue();
        system("cls");
        if (x == 1)
        {
            
          centrolestudent(st,Emp,p);
        }
        else if (x == 2)
        {
            centrolemonay(st,Emp,p);
        }
        else if (x == 3)
        {
            shewstudentintervals(st,Emp, p);
        }
        else if (x == 4)
        {
            centrolesEmployee(st,Emp,p);
        }
        else if (x == 4)
        {
            exit(0);
        }
      
    }
}
int main()
{
    vector<Employ>Emp;
    Control p;
    vector<student>st;
    readFromFileEmploy(Emp);
    readFromFilestudent(st);
    centroleprogram(st,Emp, p);
  
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

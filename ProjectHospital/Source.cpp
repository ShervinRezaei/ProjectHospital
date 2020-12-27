#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#define SIZE 3000
using namespace std;
class Date
{
public:
	int year, month, day;
	Date() { year = day = month = 0; }
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
class Person
{
public:
	string name, family, nationalID;
	Person()
	{
		this->name = "";
		this->nationalID = "";
		this->family = "";
	}
	Person(string n, string f, string na)
	{
		this->name = n;
		this->nationalID = na;
		this->family = f;
	}
};
class Doctor :public Person
{
public:
	string Code;
	Date BrithDate;
	Doctor() {}
	Doctor(string n, string f, string na, string c, int y, int m, int d)
	{
		this->name = n;
		this->nationalID = na;
		this->family = f;
		this->Code = c;
		this->BrithDate.year = y;
		this->BrithDate.month = m;
		this->BrithDate.day = d;
	}
	string getName()
	{
		return this->name;
	}
	string getFamily()
	{
		return this->family;
	}
	string getNationalID()
	{
		return this->nationalID;
	}
	string getCode()
	{
		return this->Code;
	}
	Date getDate()
	{
		return this->BrithDate;
	}
	void setDate(Date d)
	{
		this->BrithDate = d;
	}
	void setCode(string d)
	{
		this->Code = d;
	}
	void setNationaID(string d)
	{
		this->nationalID = d;
	}
	void setFamily(string d)
	{
		this->family = d;
	}
	void setName(string d)
	{
		this->name = d;
	}
	void ShowData()
	{
		cout << this->name << "_" << this->family << "_" << this->nationalID << "_" << this->Code << "_" << this->BrithDate.year << "/" << this->BrithDate.month << "/" << this->BrithDate.day << endl;
	}
};
class Nurse :public Person
{
public:
	string Code;
	Date BrithDate;
	Nurse() {}
	Nurse(string n, string f, string na, string c, int y, int m, int d)
	{
		this->name = n;
		this->nationalID = na;
		this->family = f;
		this->Code = c;
		this->BrithDate.year = y;
		this->BrithDate.month = m;
		this->BrithDate.day = d;
	}
	string getName()
	{
		return this->name;
	}
	string getFamily()
	{
		return this->family;
	}
	string getNationalID()
	{
		return this->nationalID;
	}
	string getCode()
	{
		return this->Code;
	}
	Date getDate()
	{
		return this->BrithDate;
	}
	void setDate(Date d)
	{
		this->BrithDate = d;
	}
	void setCode(string d)
	{
		this->Code = d;
	}
	void setNationaID(string d)
	{
		this->nationalID = d;
	}
	void setFamily(string d)
	{
		this->family = d;
	}
	void setName(string d)
	{
		this->name = d;
	}
	void ShowData()
	{
		cout << this->name << "_" << this->family << "_" << this->nationalID << "_" << this->Code << "_" << this->BrithDate.year << "/" << this->BrithDate.month << "/" << this->BrithDate.day << endl;
	}
};
class Hospital
{
public:
	Doctor doctor[SIZE];
	int countDoctor, countNurse;
	Nurse nurse[SIZE];
	Hospital()
	{
		this->countDoctor = this->countNurse = 0;
	}
	void ResetData()
	{
		for (int i = 0; i < this->countDoctor; i++)
		{
			doctor[i].name = doctor[i].family = doctor[i].nationalID = doctor[i].Code = "";
			doctor[i].BrithDate.year = doctor[i].BrithDate.month = doctor[i].BrithDate.day = 0;
		}
		for (int i = 0; i < this->countNurse; i++)
		{
			nurse[i].name = nurse[i].family = nurse[i].nationalID = nurse[i].Code = "";
			nurse[i].BrithDate.year = nurse[i].BrithDate.month = nurse[i].BrithDate.day = 0;
		}
		this->countDoctor = this->countNurse = 0;
		
	}
	int stringToInteger(string str)
	{
		int result;
		istringstream convert(str);
		if (!(convert >> result))
			throw "Can not convert";

		return result;
	}
	string numberToString(int num)
	{
		ostringstream os;
		os << num;
		return os.str();
	}
	vector<string> split(const string & str, const string & delim)
	{
		vector<string> tokens;
		size_t prev = 0, pos = 0;
		do
		{
			pos = str.find(delim, prev);
			if (pos == string::npos) pos = str.length();
			string token = str.substr(prev, pos - prev);
			if (!token.empty()) tokens.push_back(token);
			prev = pos + delim.length();
		} while (pos < str.length() && prev < str.length());
		return tokens;
	}
	void ReadDataFromFile()
	{
		ifstream myfile("doctor.txt");
		string line, n, f, na, c, b;
		int d, m, y;
		int size1, j = 0, size2 = 0;
		int i = 0;
		while (getline(myfile, line)) {
			vector<string> v = split(line, "#");
			n = v[0];
			f = v[1];
			na = v[2];
			c = v[3];
			vector<string> date = split(v[4], "/");
			y = stringToInteger(date[0]);
			m = stringToInteger(date[1]);
			d = stringToInteger(date[2]);
			doctor[i] = *new Doctor(n, f, na, c, y, m, d);
			i++;
		}
		myfile.close();
		line = "";
		ifstream myfile2("nurse.txt");
		while (getline(myfile2, line))
		{
			vector<string> v = split(line, "#");
			n = v[0];
			f = v[1];
			na = v[2];
			c = v[3];
			vector<string> date = split(v[4], "/");
			y = stringToInteger(date[0]);
			m = stringToInteger(date[1]);
			d = stringToInteger(date[2]);
			nurse[j] = *new Nurse(n, f, na, c, y, m, d);
			j++;
		}
		myfile2.close();
		countDoctor = i;
		countNurse = j;
	}
	bool SearchDoctor(string code)
	{
		bool flag = true;
		int idex=0;
		for (int i = 0; i<this->countDoctor; i++)
		{
			if (doctor[i].Code == code)
			{
				flag = true;
				idex = i;
				break;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			cout << "The Doctor with Code( " << code << " ) Not Founded!!!" << endl;
			return false;
		}
		else
		{
			doctor[idex].ShowData();
			return true;
		}
	}
	bool SearchNurse(string code)
	{
		bool flag = true;
		int idx = 0;
		for (int i = 0;i< this->countNurse; i++)
		{
			if (nurse[i].Code == code)
			{
				flag = true;
				idx = i;
				break;
			}
			else
			{
				flag = false;
			}
		}
		if (flag == false)
		{
			cout << "The Doctor with Code( " << code << " ) Not Founded!!!" << endl;
			return false;
		}
		else
		{
			nurse[idx].ShowData();
			return true;
		}
	}
	void showDataListDoctor()
	{
		cout << "\nNumbers  Name \t Family    NationalID \t Code \t BritDate \t Type" << endl;
		for (int i = 0; i < this->countDoctor; i++)
		{
			cout << "<=>" << i << "|  " << doctor[i].name << "\t|" << doctor[i].family << "   |" << doctor[i].nationalID << "\t|" << doctor[i].Code << "\t|" << doctor[i].BrithDate.year << "/" << doctor[i].BrithDate.month << "/" << doctor[i].BrithDate.day << "\t" << "DOCTOR" << endl;
		}
	}
	void showDataListNurse()
	{
		cout << "\nNumbers  Name \t Family    NationalID \t Code \t BritDate \t Type" << endl;
		for (int i = 0; i < this->countNurse; i++)
		{
			cout << "<=>" << i  << "|  " << nurse[i].name << "\t|" << nurse[i].family << "   |" << nurse[i].nationalID << "\t|" << nurse[i].Code << "\t|" << nurse[i].BrithDate.year << "/" << nurse[i].BrithDate.month << "/" << nurse[i].BrithDate.day << "\t" << "NURSE" << endl;
		}
	}
	void InsertNurse(Nurse d)
	{
		std::fstream file("nurse.txt", std::ios::out | std::ios::app);
		string message = d.name + "#" + d.family + "#" + d.nationalID + "#" + d.Code + "#" + numberToString(d.BrithDate.year) + "/" + numberToString(d.BrithDate.month) + "/" + numberToString(d.BrithDate.day);
		file << message << std::endl;
		file.close();
		cout << "The Successfull Insert!!!";
	}
	void InsertDocotor(Doctor d)
	{
		std::fstream file("doctor.txt", std::ios::out | std::ios::app);
		string message = d.name + "#" + d.family + "#" + d.nationalID + "#" + d.Code + "#" + numberToString( d.BrithDate.year) + "/" + numberToString( d.BrithDate.month )+ "/" + numberToString(d.BrithDate.day) ;
		file << message << std::endl;
		file.close();
		cout << "The Successfull Insert!!!";
	}
	void PrintAllList()
	{
		cout << "\nNumbers  Name \t Family    NationalID \t Code \t BritDate \t Type"<<endl;
		for (int i = 0; i < this->countDoctor; i++)
		{
			cout <<"<=>"<< i << "|  " << doctor[i].name << "\t|" << doctor[i].family << "   |" << doctor[i].nationalID << "\t|" << doctor[i].Code << "\t|" << doctor[i].BrithDate.year << "/" << doctor[i].BrithDate.month << "/" << doctor[i].BrithDate.day << "\t" << "DOCTOR" << endl;
		}
		for (int i = 0; i < this->countNurse; i++)
		{
			cout << "<=>" << i+countDoctor << "|  " << nurse[i].name << "\t|" << nurse[i].family << "   |" << nurse[i].nationalID << "\t|" << nurse[i].Code << "\t|" << nurse[i].BrithDate.year << "/" << nurse[i].BrithDate.month << "/" << nurse[i].BrithDate.day << "\t" << "NURSE" << endl;
		}
	}
	void Messege(string s)
	{
		cout << s;
	}
	void PrintMenu()
	{
		cout << "\n\t\t\t(THE ALL  PERSONEL HOSPITAL IS A)\n";
		for (int i = 0; i < 50; i++)
			cout << "<>";
		this->ResetData();
		this->ReadDataFromFile();
		this->PrintAllList();
		for (int i = 0; i < 50; i++)
			cout << "<>";
		cout << "\n1)Add Doctor\n2)Add Nurse\n3)ShowList Doctor\n4)ShowList Nurse\n5)Search Doctor\n6)Search Nurse\n 0)EXIT\n";
		cout << "PLESE ENTER NUMBER BETWEEN (0,1,2,3,4,5,6):\n";
	}
	void Start()
	{
		int num = -1;
		string name, family, nationalid, code, date;
		int year, month, day;
		Doctor D;
		Nurse N;
		while (true)
		{
			this->PrintMenu();
			cin >> num;
			if (num == 0)break;
			switch (num)
			{
			case 1:
				system("cls");
				cout << "WELCOM TO ADD DOCTOR PAGE:" << endl;
				for (int i = 0; i < 50; i++)
					cout << "<>";
				this->showDataListNurse();
				for (int i = 0; i < 50; i++)
					cout << "<>";
				cout << "\nplease enter name:";
				cin >> name;
				cout << "please enter family:";
				cin >> family;
				cout << "please neter nationalID:";
				cin >> nationalid;
				cout << "please enter Code:";
				cin >> code;
				cout << "please enter BrithDate(Year):";
				cin >> year;
				cout << "please enter BrithDate(Month):";
				cin >> month;
				cout << "please enter BrithDate(Day):";
				cin >> day;
				D = *new Doctor(name, family, nationalid, code, year, month, day);
				this->InsertDocotor(D);
				system("cls");
				Messege("SuccsessFull Inserted Doctor...");
				break;
			case 2:
				system("cls");
				cout << "WELCOM TO ADD NURSE PAGE:" << endl;
				for (int i = 0; i < 50; i++)
					cout << "<>";
				this->showDataListNurse();
				for (int i = 0; i < 50; i++)
					cout << "<>";
				cout << "\nplease enter name:";
				cin >> name;
				cout << "please enter family:";
				cin >> family;
				cout << "please neter nationalID:";
				cin >> nationalid;
				cout << "please enter Code:";
				cin >> code;
				cout << "please enter BrithDate(Year):";
				cin >> year;
				cout << "please enter BrithDate(Month):";
				cin >> month;
				cout << "please enter BrithDate(Day):";
				cin >> day;
				N = *new Nurse(name, family, nationalid, code, year, month, day);
				this->InsertNurse(N);
				system("cls");
				Messege("SuccsessFull Inserted Nurse...");
				break;
			case 3:
				system("cls");
				cout << "WELCOM TO ADD DOCTOR PAGE:" << endl;
				for (int i = 0; i < 50; i++)
					cout << "<>";
				this->showDataListDoctor();
				for (int i = 0; i < 50; i++)
					cout << "<>";
				break;
			case 4:
				system("cls");
				cout << "WELCOM TO ADD NURSE PAGE:" << endl;
				for (int i = 0; i < 50; i++)
					cout << "<>";
				this->showDataListNurse();
				for (int i = 0; i < 50; i++)
					cout << "<>";
				break;
			case 5:
				system("cls");
				cout << "WELCOM TO ADD NURSE PAGE:" << endl;
				cout << "please enter Code for Search Doctor:";
				cin >> code;
				system("cls");
				if (this->SearchDoctor(code) == true)
				{
					Messege("SuccsessFull Search!!!");
				}
				else
				{
					Messege("NOT SuccsessFull Search!!!");
				}
				break;
			case 6:
				system("cls");
				cout << "WELCOM TO ADD NURSE PAGE:" << endl;
				cout << "please enter Code for Search Nurse:";
				cin >> code;
				system("cls");
				if (this->SearchNurse(code) == true)
				{
					Messege("SuccsessFull Search!!!");
				}
				else
				{
					Messege("NOT SuccsessFull Search!!!");
				}
				break;
			default:
				Messege("Please Enter Just Number Integer Bettwen in (0,1,2,3,4,5,6)");
				break;
			}
		}
	}
};
int main()
{
	Hospital h = *new Hospital();
	h.Start();
	return 0;
}
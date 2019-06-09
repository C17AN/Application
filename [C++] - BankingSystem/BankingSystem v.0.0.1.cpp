#include <iostream>

using namespace std; 

void showMenu();
void createAccount();
void deposit();
void withdraw();
void printInfo();

typedef struct
{
	char name[20];
	int ID;
	int amountMoney;
} account;

account arr[100000];
int accountCnt;

void showMenu()
{
	int select;
	int cnt; 
	
	while(1)
	{
		cout << "----- Menu -----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << " �� �� : ";
		cin >> select;; 		
		cout << endl;
		
		switch(select)
		{
			case 1:
				createAccount();
				break;
				
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				printInfo();
				break;
			case 5:
				return;
			default:
				cout << "��ȿ���� ���� �Է��Դϴ�." << endl;
		}
		
	}
}

void createAccount()
{
	cout << endl;
	cout << "[���°���]" << endl;
	cout << "ID�� 1���� 999,999 ������ ���ڸ� �Է��ϼ���." << endl;
	cout << "���� ID : "; cin >> arr[accountCnt].ID;
	cout << "�� �� : "; 
	cin.ignore();
	cin.getline(arr[accountCnt].name, 20);
	cout << "�Աݾ� : "; cin >> arr[accountCnt].amountMoney;	
	
	cout << endl;
	accountCnt++;
}

void deposit()
{
	int id, depositMoney;
	cout << "[��   ��]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> depositMoney; 
	for(int i = 0; i < accountCnt; ++i)
	{
		if(arr[i].ID == id)
		{
			arr[i].amountMoney += depositMoney;
			cout << "�Ա� �Ϸ�" << endl << endl;
		}
		else cout << "�������� �ʴ� ID�Դϴ�." << endl;
	}
	
}

void withdraw()
{
	int id, withdrawalMoney;
	cout << "[��   ��]" << endl;
	cout << "���� ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> withdrawalMoney; 
	for(int i = 0; i < accountCnt; ++i)
	{
		if(arr[i].ID == id)
		{
			if(arr[i].amountMoney - withdrawalMoney > 0)
			{
				arr[i].amountMoney -= withdrawalMoney;
				cout << "��� �Ϸ�" << endl << endl;
			}
			else cout << "�ܾ��� �����մϴ�." << endl; 
		}
		else cout << "�������� �ʴ� ID�Դϴ�." << endl;
	}
}

void printInfo()
{
	for(int i = 0; i < accountCnt; i++)
	{
		cout << "���� ID : " << arr[i].ID << endl;
		cout << "�� �� : " << arr[i].name << endl;
		cout << "�� �� : " << arr[i].amountMoney << "��" << endl << endl;
	}
}

int main()
{	
	showMenu();
}

#include <iostream>
using namespace std;
#define MAX_NAM 32
#define MAX_ADD 128
#define MAX_PHO 14

enum MODE {   //��� ������ ǥ���ϱ����� ������ MODE
	MODE_R=1, //�л����
	MODE_L,   //��ϵ� �л� ��Ϻ���
	MODE_S,   //��ϵ� �л� �˻�
	MODE_D,   //��ϵ� �л��� ����
	MODE_Q    //���α׷� ����
};

struct _Student {
	char stuName[MAX_NAM]; //�л��̸�
	char stuAdd[MAX_ADD];  //�л��ּ�
	char stuPho[MAX_PHO];  //�л� ��ȭ��ȣ
	int stuNum; //�л� �й�
	int Kor; //�л� ��������
	int Mat; //�л� ��������
	int Eng; //�л� ��������
	int Total; //�л� ��������
	float Avg; //�л� �������
};

int main() {
	int mode;
	int Num = 1;  //�л� �й�
	int count = 0; //�л��� ī��Ʈ
	char serch[MAX_NAM] = {}; //�˻��� ���� �迭
	_Student student[20];

	while (1) {
		system("cls");
		cout << "==============�л� ��� ���α׷�==================" << endl << endl << endl;
		cout << "1.�л����" << endl;
		cout << "2.�л����" << endl;
		cout << "3.�л��˻�" << endl;
		cout << "4.�л�����" << endl;
		cout << "5.����" << endl;
		cout << "���ϴ� ��带 �Է��ϼ���:";
		cin >> mode;
		cout << endl;
		if (cin.fail()) { //����Է½� �������ƴ� ���ڸ��Է�������� �߻��� ���ѷ��������� ����ó���ϱ�����
			cin.clear();
			cin.ignore(1024, '\n');
		}

		if (mode == MODE_Q)
			break;
		if (mode<MODE_R && mode>MODE_Q)
			continue;

		switch (mode)
		{
		case MODE_R:
			system("cls");
			cout << "�л��̸�:";
			cin.ignore(1024, '\n');
			cin.getline(student[count].stuName, MAX_NAM);
			cout << "�л��ּ�:";
			cin.getline(student[count].stuAdd, MAX_ADD);
			cout << "�л���ȭ��ȣ:";
			cin.getline(student[count].stuPho, MAX_PHO);
			student[count].stuNum = Num;
			cout << "��������:";
			while (1) {
				cin >> student[count].Kor;
				if (cin.fail() || student[count].Kor < 0 || student[count].Kor > 100) { //�������� ���ڸ� �Է¹޵��� �ϱ�����
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "����ε� �������Է��ϼ���:";
					continue;
					system("pause");
				}
				else
					break;
			}
			cout << "��������:";
			while (1) {
				cin >> student[count].Mat;

				//������ 0~100����
				if (cin.fail() || student[count].Mat < 0 || student[count].Mat > 100) { //�������� ���ڸ� �Է¹޵��� �ϱ�����
					cin.clear();                                            
					cin.ignore(1024, '\n');
					cout << "����ε� �������Է��ϼ���:";
					continue;
				}
				else
					break;
			}

			cout << "��������:";
			while (1) {
				cin >> student[count].Eng;
				if (cin.fail() || student[count].Eng < 0 || student[count].Eng > 100) { //�������� ���ڸ� �Է¹޵��� �ϱ�����
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "����ε� �������Է��ϼ���:";
					continue;
					system("pause");
				}
				else
					break;
			}
			student[count].Total = student[count].Kor + student[count].Eng + student[count].Mat;//��������

			student[count].Avg = (student[count].Kor + student[count].Eng + student[count].Mat) / 3.f; //���
			count++;
			Num++;

			break;
		case MODE_L:
			system("cls");
			for (int i = 0; i < count; i++) {
				cout << "=========��ϵ� �л� ���==========" << endl << endl;
				cout << "�л��̸�:" << student[i].stuName << endl;
				cout << "�л��ּ�:" << student[i].stuAdd << endl;
				cout << "�л���ȭ��ȣ:" << student[i].stuPho << endl;
				cout << "�л��й�:" << student[i].stuNum << endl;
				cout << "�л���������:" << student[i].Kor << endl;
				cout << "�л���������:" << student[i].Mat << endl;
				cout << "�л���������:" << student[i].Eng << endl;
				cout << "�л�����:" << student[i].Total << endl;
				cout << "�л����:" << student[i].Avg << endl;
				cout << endl;
			}
			system("pause");
			break;
		case MODE_S:
				system("cls");
				cout << "�˻��� �л��� �̸��� �Է��ϼ���:";
				cin.ignore(1024, '\n');
				cin.getline(serch, MAX_NAM);
				for (int i = 0; i < count; i++) {
					if (strcmp(student[i].stuName, serch) == 0) {
						cout << "=========�˻��� �л�==========" << endl << endl;
						cout << "�л��̸�:" << student[i].stuName << endl;
						cout << "�л��ּ�:" << student[i].stuAdd << endl;
						cout << "�л���ȭ��ȣ:" << student[i].stuPho << endl;
						cout << "�л��й�:" << student[i].stuNum << endl;
						cout << "�л���������:" << student[i].Kor << endl;
						cout << "�л���������:" << student[i].Mat << endl;
						cout << "�л���������:" << student[i].Eng << endl;
						cout << "�л�����:" << student[i].Total << endl;
						cout << "�л����:" << student[i].Avg << endl;
						cout << endl;
						break;
					}
				}
				system("pause");
			

			break;
		case MODE_D:
			system("cls");
			cin.ignore(1024, '\n');
			cout << "������ �л��� �̸��� �Է��ϼ���:";
			cin.getline(serch, MAX_NAM);
			for (int i = 0; i < count; i++) {
				if (strcmp(student[i].stuName, serch) == 0) {
					for (int j = i; j < count-1; j++) {
						student[j] = student[j + 1];
					}
					--count;
					break;
				}
			}
			cout << "�л� �����Ϸ�";
			cout << endl;
			system("pause");

			break;
		}

	}
}


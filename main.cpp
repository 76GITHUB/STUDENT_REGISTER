#include <iostream>
using namespace std;
#define MAX_NAM 32
#define MAX_ADD 128
#define MAX_PHO 14

enum MODE {   //모드 선택을 표시하기위한 열거형 MODE
	MODE_R=1, //학생등록
	MODE_L,   //등록된 학생 목록보기
	MODE_S,   //등록된 학생 검색
	MODE_D,   //등록된 학생을 삭제
	MODE_Q    //프로그램 종료
};

struct _Student {
	char stuName[MAX_NAM]; //학생이름
	char stuAdd[MAX_ADD];  //학생주소
	char stuPho[MAX_PHO];  //학생 전화번호
	int stuNum; //학생 학번
	int Kor; //학생 국어점수
	int Mat; //학생 수학점수
	int Eng; //학생 영어점수
	int Total; //학생 과목총점
	float Avg; //학생 점수평균
};

int main() {
	int mode;
	int Num = 1;  //학생 학번
	int count = 0; //학생수 카운트
	char serch[MAX_NAM] = {}; //검색을 받을 배열
	_Student student[20];

	while (1) {
		system("cls");
		cout << "==============학생 등록 프로그램==================" << endl << endl << endl;
		cout << "1.학생등록" << endl;
		cout << "2.학생목록" << endl;
		cout << "3.학생검색" << endl;
		cout << "4.학생삭제" << endl;
		cout << "5.종료" << endl;
		cout << "원하는 모드를 입력하세요:";
		cin >> mode;
		cout << endl;
		if (cin.fail()) { //모드입력시 정수가아닌 문자를입력했을경우 발생할 무한루프에대해 예외처리하기위함
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
			cout << "학생이름:";
			cin.ignore(1024, '\n');
			cin.getline(student[count].stuName, MAX_NAM);
			cout << "학생주소:";
			cin.getline(student[count].stuAdd, MAX_ADD);
			cout << "학생전화번호:";
			cin.getline(student[count].stuPho, MAX_PHO);
			student[count].stuNum = Num;
			cout << "국어점수:";
			while (1) {
				cin >> student[count].Kor;
				if (cin.fail() || student[count].Kor < 0 || student[count].Kor > 100) { //점수에는 숫자만 입력받도록 하기위함
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "제대로된 점수를입력하세요:";
					continue;
					system("pause");
				}
				else
					break;
			}
			cout << "수학점수:";
			while (1) {
				cin >> student[count].Mat;

				//점수는 0~100까지
				if (cin.fail() || student[count].Mat < 0 || student[count].Mat > 100) { //점수에는 숫자만 입력받도록 하기위함
					cin.clear();                                            
					cin.ignore(1024, '\n');
					cout << "제대로된 점수를입력하세요:";
					continue;
				}
				else
					break;
			}

			cout << "영어점수:";
			while (1) {
				cin >> student[count].Eng;
				if (cin.fail() || student[count].Eng < 0 || student[count].Eng > 100) { //점수에는 숫자만 입력받도록 하기위함
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "제대로된 점수를입력하세요:";
					continue;
					system("pause");
				}
				else
					break;
			}
			student[count].Total = student[count].Kor + student[count].Eng + student[count].Mat;//점수총합

			student[count].Avg = (student[count].Kor + student[count].Eng + student[count].Mat) / 3.f; //평균
			count++;
			Num++;

			break;
		case MODE_L:
			system("cls");
			for (int i = 0; i < count; i++) {
				cout << "=========등록된 학생 목록==========" << endl << endl;
				cout << "학생이름:" << student[i].stuName << endl;
				cout << "학생주소:" << student[i].stuAdd << endl;
				cout << "학생전화번호:" << student[i].stuPho << endl;
				cout << "학생학번:" << student[i].stuNum << endl;
				cout << "학생국어점수:" << student[i].Kor << endl;
				cout << "학생수학점수:" << student[i].Mat << endl;
				cout << "학생영어점수:" << student[i].Eng << endl;
				cout << "학생총점:" << student[i].Total << endl;
				cout << "학생평균:" << student[i].Avg << endl;
				cout << endl;
			}
			system("pause");
			break;
		case MODE_S:
				system("cls");
				cout << "검색할 학생의 이름을 입력하세요:";
				cin.ignore(1024, '\n');
				cin.getline(serch, MAX_NAM);
				for (int i = 0; i < count; i++) {
					if (strcmp(student[i].stuName, serch) == 0) {
						cout << "=========검색한 학생==========" << endl << endl;
						cout << "학생이름:" << student[i].stuName << endl;
						cout << "학생주소:" << student[i].stuAdd << endl;
						cout << "학생전화번호:" << student[i].stuPho << endl;
						cout << "학생학번:" << student[i].stuNum << endl;
						cout << "학생국어점수:" << student[i].Kor << endl;
						cout << "학생수학점수:" << student[i].Mat << endl;
						cout << "학생영어점수:" << student[i].Eng << endl;
						cout << "학생총점:" << student[i].Total << endl;
						cout << "학생평균:" << student[i].Avg << endl;
						cout << endl;
						break;
					}
				}
				system("pause");
			

			break;
		case MODE_D:
			system("cls");
			cin.ignore(1024, '\n');
			cout << "삭제할 학생의 이름을 입력하세요:";
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
			cout << "학생 삭제완료";
			cout << endl;
			system("pause");

			break;
		}

	}
}


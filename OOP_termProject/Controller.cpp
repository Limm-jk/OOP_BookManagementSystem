#include "View.cpp"
#include "Object.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {
private:
	View view;
	Model model;
	std::string SUPERUSER = "admin";
	bool testtrue = true; // 채우기용 bool변수

	//로그인
	std::string returnid;
	std::string returnpasswd;
	person handler;
	int scanSignal;//번호입력시 번호저장 변수

	//검색 입력받은 책 이름
	std::string returntitle;

	//도서반납
	int returnBookNumber;

	//회원추가
	std::string name;
	std::string id;
	std::string passwd;

	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

	//회원 삭제
	std::string delId;

	//도서 추가
	std::string addbookTitle;
	std::string addauthor;
	std::string addpublisher;
	int addbookNumber;

	//대출자
	bool addloan;

	//도서 삭제
	int delBookNumber;

	//도서 검색
	std::string searchBookTitle;

public:
	void run() {
		while (1) {
			system("cls");
			view.initScreen(returnid, returnpasswd);	//초기화면
			//bool login = model.loginCheck(returnid, returnpasswd);
//			if (!login) {
				//유효하지 않은 계정 while문 재실행
//				continue;
//			}
			//관리자계정일때
			if (returnid == "admin") {
				while (scanSignal != 0) {
					system("cls");
					view.managePage(scanSignal);//1도서 2회원
					if (scanSignal == 1) {
						//도서관리
						while (scanSignal != 0) {
							system("cls");
							view.manageBook(scanSignal);
							if (scanSignal == 1) {
								//책추가
								system("cls");
								view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
								//모델에 addbook
								//bookInsert(addbookTitle, addauthor, addpublisher, addbookNumber);
							}
							else if (scanSignal == 2) {
								//삭제? view.delBook(delBookNumber);
								//model.bookDelete(delBookNumber);
							}
							else if (scanSignal == 0) {
								//종료합니당
							}
							else {
								//잘못된 입력
							}
						}
					}
					if (scanSignal == 2) {
						//회원관리
						while (scanSignal != 0) {
							system("cls");
							view.managePerson(scanSignal);
							if (scanSignal == 1) {
								//회원 추가.
								system("cls");
								view.addPerson(name, id, passwd);
								//모델에 addbook
								//addPerson(name, id, passwd);
							}
							else if (scanSignal == 2) {
								//회원삭제? view.delPerson(delId);
								//model.personDelete(delId);
							}
							else if (scanSignal == 0) {
								//종료합니당
							}
							else {
								//잘못된 입력
							}
						}
					}
					else if (scanSignal == 0) {
						//종료 로그아웃
					}
					else {
						//잘못된 입력
					}
				}
			}

			else {
				while (scanSignal != 0) {
					system("cls");
					view.userPage(scanSignal);//시그널 확인 1검색대출 2 반납
					if (scanSignal == 1) {
						view.searchBook(returntitle);//책이름 입력
						//검색메소드
					}
					else if (scanSignal == 2) {
						view.returnBook(handler, returnBookNumber);
						//반납메소드
					}
					else if (scanSignal == 0) {
						//종료&로그아웃
					}
					else {
						//잘못된 입력
					}
				}
			}
		}
	}
	Controller() {

	}
};


int main() {
	Controller appc;
	while (1) {
		appc.run();
	}
	return 0;
};
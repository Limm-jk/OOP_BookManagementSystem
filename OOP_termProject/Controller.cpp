#include "View.cpp"
#include "Object.cpp"
#include "Model.cpp"
#include <stdlib.h>
#include <windows.h>

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
	int scanSignal = 1;//번호입력시 번호저장 변수

	//검색/대출 입력받은 책 이름
	std::string returntitle;
	int loanNumber;

	//도서반납
	int returnBookNumber;

	//회원추가
	std::string name;
	std::string id;
	std::string passwd;

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
	std::list<Book> searchBooklist;

public:
	void run() {
		while (1) {
			system("cls");
			scanSignal = 1;
			view.initScreen(returnid, returnpasswd);	//초기화면
			bool login = model.loginCheck(returnid, returnpasswd);

			//관리자계정일때
			if (returnid == "admin") {
				while (1) {
					system("cls");
					view.managePage(scanSignal);//1도서 2회원
					if (scanSignal == 1) {
						//도서관리
						while (1) {
							system("cls");
							view.manageBook(scanSignal);
							if (scanSignal == 1) {
								//책추가
								system("cls");
								view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
								//모델에 addbook
								model.bookInsert(addbookTitle, addauthor, addpublisher, addbookNumber);
								model.bookFileWrite("a");
							}
							else if (scanSignal == 2) {
								view.deleteBook(delBookNumber);
								model.bookDelete(delBookNumber);
							}
							else if (scanSignal == 0) {
								//종료합니당
								break;
							}
							else {
								//잘못된 입력
								view.faultPage();
							}
						}
					}
					else if (scanSignal == 2) {

						//회원관리
						while (1) {
							system("cls");
							view.managePerson(scanSignal);
							if (scanSignal == 1) {
								//회원 추가.
								system("cls");
								view.addPerson(name, id, passwd);
								//모델에 addbook
								model.addPerson(name, id, passwd);
							}
							else if (scanSignal == 2) {
								view.deletePerson(delId);
								model.personDelete(delId);
							}
							else if (scanSignal == 0) {
								//종료합니당
								break;
							}
							else {
								//잘못된 입력
								view.faultPage();
							}
						}
					}
					else if (scanSignal == 0) {
						//종료 로그아웃
						break;
					}
					else {
						//잘못된 입력
						view.faultPage();
					}
				}
			}

			//------------이 밑으로 유저-------------

			else {
				if (!login) {
					continue;
				}
				while (1) {
					system("cls");
					view.userPage(scanSignal);//시그널 확인 1검색대출 2 반납
					if (scanSignal == 1) {
						system("cls");
						view.searchBook(returntitle);//책이름 입력
						searchBooklist = model.bookSearchByTitle(returntitle);
						view.loanBook(searchBooklist, loanNumber);
						if (model.bookLoan(returnid, loanNumber)) {
							//성공
						}
						else {
							//책없음
						}
					}
					else if (scanSignal == 2) {
						system("cls");
						view.returnBook(handler, returnBookNumber);
						if (model.bookReturn(handler.getId(), returnBookNumber)) {
							//성공
						}
						else {
							//책없음
						}
						//반납메소드
					}
					else if (scanSignal == 0) {
						//종료&로그아웃
						break;
					}
					else {
						//잘못된 입력
						view.faultPage();
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
#include "View.cpp"
#include "Model.cpp"
#include <stdlib.h>

class Controller {

	View view;

	std::string SUPERUSER = "admin";
	std::string SUPERUSERPW;
	//book list선언(링크드리스트 - STL사용)
	std::list<Book> booklist;
	//person list선언(링크드리스트 - STL사용)
	std::list<person> personlist;

	//로그인(초기화면)
	std::string returnid;
	std::string returnpasswd;

	int scanSignal;//번호입력시 번호저장 변수

	//검색 입력받은 책 이름
	std::string returntitle;

	//회원추가
	std::string name;
	std::string id;
	std::string passwd;

	int loanNumber;
	std::string loanBook1;
	std::string loanBook2;
	std::string loanBook3;

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

	void addbook(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		view.addBook(addbookTitle, addauthor, addpublisher, addbookNumber);
		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
	}
	void addPerson(std::string& name, std::string& id, std::string& passwd) {
		view.addPerson(name, id, passwd);
		person newPerson(name, id, passwd);
		personlist.push_back(newPerson);
	}
public:
	void run() {

		system("cls");
		view.initScreen(returnid, returnpasswd);	//초기화면
		//회원 유효 및 마스터계정 확인

		//회원계정일때
		view.userPage(scanSignal);//시그널 확인
		while (scanSignal != 0) {
			if (scanSignal == 1) {
				view.searchBook(returntitle);//책이름 입력
				//검색메소드
			}
			if (scanSignal == 2) {
				//반납메소드
			}

		}
	}
};

int main() {
	Controller appControl;
	while (1) {
		appControl.run();
	}
	return 0;
}
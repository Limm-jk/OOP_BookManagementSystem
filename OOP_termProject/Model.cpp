#include<list>
#include"Object.cpp"
//바뀜
class Model {
	//book list선언(링크드리스트 - STL사용)
	std::list<Book> booklist;
	//person list선언(링크드리스트 - STL사용)
	std::list<person> personlist;

	//이터레이터
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();


public:
	void dataInit() {
		//파일입출력으로 booklist에 파일의 책데이터를 푸시(초기실행시 1번만 실행)
		//파일입출력으로 personlist에 파일의 사람데이터를 푸시(초기실행시 1번만 실행)
	}

	//book 수정, 검색, 삭제
	void bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
	}

	std::list<Book> bookSearch(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = bookList.begin(); iterPos != bookList.end(); ++iterPos)
		{
			if ((*iterPos).getBookNumber() == givenBookNumber) {//주어진 것과 같은 책번호를 갖는 객체를 가리킬 때 작동
				Book abook((*iterPos).getBookTitle, (*iterPos).getAuthor, (*iterPos).getPublisher, (*iterPos).getBookNumber);//가리키는 객체를 복사
				abook.setLoan((*iterPos).getLoan);
				aList.push_back(abook);//반환할 리스트에 붙여넣기
			}
		}
		return aList;//리스트 반환
	}
	/*
	std::list<Book> bookSearch(std::string title  ) {

		bklistItr = booklist.begin();//초기화
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle() == title) {
				return true;
			}
			++bklistItr;
		}
		bklistItr = booklist.begin();//찾는데 실패 시에 초기화 후 리턴
		return false;
	}
	*/

	bool bookSearchNum(int bookNum) {
		bklistItr = booklist.begin();

	}

	bool bookDelete(int bookNumber) {
		if (bookSearchNum(bookNumber)) {
			booklist.erase(bklistItr);
			return true;
		}
		return false;
	}
	
	bool bookLoan(std::string id, int bookNumber) {
		bklistItr = booklist.begin();
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookNumber() == bookNumber) {
				(*bklistItr).setLoan(true);
				return true;
			}
		}

		return false;
	}

	// 반납
	bool bookReturn(std::string id, int bookNumber) {

	}

	//person 수정, 검색, 삭제



	//파일 업데이트
};

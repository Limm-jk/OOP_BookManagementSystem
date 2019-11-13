#include<list>
#include"Object.cpp"

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
	bool bookInsert(std::string title, std::string author, std::string date, int ISBN) {
		Book newbook(title, author, date, ISBN);
		booklist.push_back(newbook);
	}

	bool bookSearch(std::string title) {
		bklistItr = booklist.begin();//초기화
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle == title) {
				return true;
			}
			++bklistItr;
		}
		bklistItr = booklist.begin();//찾는데 실패 시에 초기화 후 리턴
		return false;
	}

	bool bookDelete(std::string title) {
		if (bookSearch(title)) {
			booklist.erase(bklistItr);
			return true;
		}
		return false;
	}

	//person 수정, 검색, 삭제

	//파일 업데이트
	//
};

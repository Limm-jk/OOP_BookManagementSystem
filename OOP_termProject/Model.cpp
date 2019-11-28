#include<list>
#include<string>
#include<fstream>
#include<iostream>
#include"Object.cpp"
//바뀜
using namespace std;

class Model {
	//book list선언(링크드리스트 - STL사용)
	std::list<Book> booklist;
	//person list선언(링크드리스트 - STL사용)
	std::list<person> personlist;

	//이터레이터
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();
public:
	string file_to_string(string filePath) {
		std::ifstream in(filePath);
		std::string s;

		if (in.is_open()) {
			// 위치 지정자를 파일 끝으로 옮긴다.
			in.seekg(0, std::ios::end);

			// 그리고 그 위치를 읽는다. (파일의 크기)
			int size = in.tellg();

			// 그 크기의 문자열을 할당한다.
			s.resize(size);

			// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
			in.seekg(0, std::ios::beg);

			// 파일 전체 내용을 읽어서 문자열에 저장한다.
			in.read(&s[0], size);

			return s;
	}

public:
	void makeBookList(string givenString) {			//사용예시: makeBookList(file_to_string("book.txt"));
		string line;
		while (givenString)
		{
			string title;
			string author;
			string publisher;
			int bookNumber;
			int beforIntToBool;

			line = getline(givenString);
			istream ss(line);
			string buffer, value;
			
			getline(ss, buffer, '|');
			value = buffer;
			title = value;

			getline(ss, buffer, '|');
			value = buffer;
			author = value;

			getline(ss, buffer, '|');
			value = buffer;
			publisher = value;

			getline(ss, buffer, '|');
			value = atoi(buffer.c_str());//정수로 변환
			bookNumber = value;

			getline(ss, buffer, '|');
			value = atoi(buffer.c_str());//일단 정수로 변환
			beforIntToBool = value;

			Book book(title, author, publisher, bookNumber);
			if (beforIntToBool == 1) {								//수동 형변환
				book.setLoan(true);
			}
			else {
				book.setLoan(false);
			}

			booklist.push_back(book));
		}
	}

public:
	void makePersonList(string givenString) {		
		string line;
		while (givenString)//한줄 읽어서 객체 만들고 리스트에 푸시. 문자열 끝까지. \\\\ 매개변수 수정 필요?
		{
			string name;
			string id;
			string passwd;
			int loanNumber;
			string loanBook1;
			string loanBook2;
			string loanBook3;

			line = getline(givenString);
			istream ss(line);
			string buffer, value;

			getline(ss, buffer, '|');
			value = buffer;
			name = value;

			getline(ss, buffer, '|');
			value = buffer;
			id = value;

			getline(ss, buffer, '|');
			value = buffer;
			passwd = value;

			getline(ss, buffer, '|');
			value = atoi(buffer.c_str());//정수로 변환
			loanNumber = value;

			getline(ss, buffer, '|');
			value = buffer;
			loanBook1 = value;

			getline(ss, buffer, '|');
			value = buffer;
			loanBook2 = value;

			getline(ss, buffer, '|');
			value = buffer;
			loanBook3 = value;

			person person(name, id, passwd);
			person.setLoanBook1(loanBook1);
			person.setLoanBook2(loanBook2);
			person.setLoanBook3(loanBook3);
			

			personlist.push_back(person));
		}
	}

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

	//person 수정, 검색, 삭제



	//파일 업데이트
};

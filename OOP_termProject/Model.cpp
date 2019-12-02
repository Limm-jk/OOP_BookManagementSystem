#include<list>
#include"Object.cpp"
#include<string>
#include<fstream>
#include<iostream>
#include <sstream>
#include <cstring>

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

	//로그인 check
	bool loginCheck(std::string id, std::string passwd) {
		//해당하는 id와 passwd가 일치하면 true리턴
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id && (*itr).getPasswd() == passwd) {
				return true;
			}
		}

		//id와 passwd 둘 중 하나라도 틀리면 false리턴
		return false;
	}


	//book 추가
	bool bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		//예외처리로 bookNumber가 같은 것이 있는지 확인
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			if ((*itr).getBookNumber() == addbookNumber) {
				return false;
			}
		}

		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
		
		return true;
	}

	//person 추가
	bool addPerson(std::string& name, std::string& id, std::string& passwd) {
		//예외처리로 id가 같은 것이 있는지 확인
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				return false;
			}
		}

		person newPerson(name, id, passwd);
		personlist.push_back(newPerson);

		return true;
	}

	//id로 person객체 찾기
	person idToPerson(std::string id) {
		person* rtps;
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				return *itr;
			}
		}
	}

	//book 검색
	std::list<Book> bookSearchByNumber(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = booklist.begin(); iterPos != booklist.end(); ++iterPos)
		{
			if ((*iterPos).getBookNumber() == givenBookNumber) {//주어진 것과 같은 책번호를 갖는 객체를 가리킬 때 작동
				Book abook((*iterPos).getBookTitle(), (*iterPos).getAuthor(), (*iterPos).getPublisher(), (*iterPos).getBookNumber());//가리키는 객체를 복사
				abook.setLoan((*iterPos).getLoan());
				aList.push_back(abook);//반환할 리스트에 붙여넣기
			}
		}
		return aList;//리스트 반환
	}

	
	std::list<Book> bookSearchByTitle(std::string title) {
		std::list<Book> alist;

		bklistItr = booklist.begin();//초기화
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle().find(title) != std::string::npos) {	//find(검색어) 함수는 찾는 문자열이 없을 경우 npos라는 상수를 반환함.
																				//이 경우 찾았기 때문에 npos가 아닌것.
				Book abook((*bklistItr).getBookTitle(), (*bklistItr).getAuthor(), (*bklistItr).getPublisher(), (*bklistItr).getBookNumber());//가리키는 객체를 복사
				abook.setLoan((*bklistItr).getLoan());
				alist.push_back(abook);										//찾았으니 복사된 객체를 리스트 뒤에 푸시.
			}
			bklistItr++;
		}
		bklistItr = booklist.begin();	//다 돌았으면 반복자 초기화
		return alist;					//검색결과 리스트 리턴
	}

	std::list<person> personSearch(std::string id) {
		std::list<person> alist;

		std::list<person>::iterator pslistItr = personlist.begin();
		while (pslistItr != personlist.end()) {
			if ((*pslistItr).getId().find(id) != std::string::npos) {	//find(검색어) 함수는 찾는 문자열이 없을 경우 npos라는 상수를 반환함.
																				//이 경우 찾았기 때문에 npos가 아닌것.
				person aperson((*pslistItr).getName(), (*pslistItr).getId(), (*pslistItr).getPasswd());//가리키는 객체를 복사
				aperson.setLoanNumber((*pslistItr).getLoanNumber());
				aperson.setLoanBook1((*pslistItr).getLoanBook1());
				aperson.setLoanBook2((*pslistItr).getLoanBook2());
				aperson.setLoanBook3((*pslistItr).getLoanBook3());

				alist.push_back(aperson);										//찾았으니 복사된 객체를 리스트 뒤에 푸시.
			}
			pslistItr++;
		}

		return alist;					//검색결과 리스트 리턴
	}
	
	//도서 삭제
	bool bookDelete(int bookNumber) {
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			if ((*itr).getBookNumber() == bookNumber) {
				booklist.erase(itr++);
				return true;
			}
		}
		return false;
	}
	
	bool bookLoan(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // 초기화 
		pslistItr = personlist.begin(); // 초기화 
		while (bklistItr != booklist.end()) { 
			if ((*bklistItr).getBookNumber() == bookNumber) { // 책이 있는지 확인
				while (pslistItr != personlist.end()) { 
					if ((*pslistItr).getId() == id) { // id 같은 사람 찾기 
						int num = (*pslistItr).getLoanNumber();
						std::string settitle = std::to_string(bookNumber);
						// 권수가 1,2일때는 loanbook이 몇번째인지 모른다.
						if (num == 0) { // 책을 빌리지 않았을 때
							(*bklistItr).setLoan(true);
							(*pslistItr).setLoanNumber(1);
							(*pslistItr).setLoanBook1(settitle);
							return true;
						}
						else if (num == 1) { // 한권 빌렸을 때 
							// 뭐가 빌렸는지 확인 
							if ((*pslistItr).getLoanBook1() != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2() != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3() != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
						}
						else if (num == 2) { // 두권 빌렸을 때
							// 뭐가 안빌렸는지 확인 
							if ((*pslistItr).getLoanBook1() == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2() == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3() == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook3(settitle);
								return true;
							}
						}
					}
					++pslistItr;
				}
			}
			++bklistItr;
		}
		return false;
	}

	// 반납
	bool bookReturn(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // 초기화 
		pslistItr = personlist.begin(); // 초기화 

		while (bklistItr != booklist.end())
		{
			if ((*bklistItr).getBookNumber() == bookNumber) { 
				if ((*bklistItr).getLoan() == true) { // 책이 대출 상태인지 확인 
					std::string gettitle = std::to_string(bookNumber);
					while (pslistItr != personlist.end())
					{
						if ((*pslistItr).getId() == id) { // 아이디 확인 
							int num = (*pslistItr).getLoanNumber(); // 대출 권수 확인 
							if (num == 1) {
								if ((*pslistItr).getLoanBook1() == gettitle) { // 반납할 책과 대출한 책이 일치하는지 확인 
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber(0);
									(*bklistItr).setLoan(false);
									return true;
								}
							}
							else if (num == 2) {
								if ((*pslistItr).getLoanBook1() == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber (1);
									(*bklistItr).setLoan(false);
									return true;
								}
								else if ((*pslistItr).getLoanBook2() == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber(1);
									(*bklistItr).setLoan(false);
									return true;
								}
							}
							else if (num == 3) {
								if ((*pslistItr).getLoanBook1() == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber(2);
									(*bklistItr).setLoan(false);
									return true;
								}
								else if ((*pslistItr).getLoanBook2() == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber(2);
									(*bklistItr).setLoan(false);
									return true;
								}
								else if ((*pslistItr).getLoanBook3() == gettitle) {
									(*pslistItr).setLoanBook3(NULL);
									(*pslistItr).setLoanNumber(2);
									(*bklistItr).setLoan(false);
									return true;
								}
							}
						}
						++pslistItr;
					}
				
				}
			}
			++bklistItr;
		}
		return false;
	}

	//person 삭제
	bool personDelete(std::string id) {
		
		//id 검사
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				personlist.erase(itr);
				return true;
			}
		}

		//찾는 id가 없으면 false리턴
		return false;
	}

public:
	void fileWrite() {
		//book
		std::string txt = "";
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			std::string title = (*itr).getBookTitle();
			std::string author = (*itr).getAuthor();
			std::string publisher = (*itr).getPublisher();
			std::string  bookNumber = std::to_string((*itr).getBookNumber());
			bool beforBoolToInt = (*itr).getLoan();
			std::string loan;

			if (beforBoolToInt == true) {
				loan = "1";
			}
			else {
				loan = "0";
			}

			txt += title + "|" + author + "|" + publisher + "|" + bookNumber + "|" + loan + "\n";
		}

		std::ofstream file("booklist.txt");

		file << txt;

		file.close();


		//person
		txt = "";
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			std::string name = (*itr).getName();
			std::string id = (*itr).getId();
			std::string passwd = (*itr).getPasswd();
			std::string loanNumber = std::to_string((*itr).getLoanNumber());
			std::string loanBook1 = (*itr).getLoanBook1();
			std::string loanBook2 = (*itr).getLoanBook2();
			std::string loanBook3 = (*itr).getLoanBook3();

			txt += name + "|" + id + "|" + passwd + "|" + loanNumber + "|" + loanBook1 + "|" + loanBook2 + "|" + loanBook3 + "\n";
		}
		std::ofstream personFile("personlist.txt");

		personFile << txt;

		personFile.close();
	}

	void fileRead() {
		std::list<Book> bookfileList;

		std::ifstream bookFile("booklist.txt");
		
		
		//book파일 읽어오기
		if (bookFile.is_open()) {
			std::string line;

			std::string str_arr[20];
			int str_cnt = 0;
			char* context;

			while (std::getline(bookFile, line)) {
				char* str_buff = new char[100];
				strcpy_s(str_buff,100,line.c_str());

				char* tok = strtok_s(str_buff, "|",&context);
				while (tok != nullptr) {
					str_arr[str_cnt++] = std::string(tok);
					tok = strtok_s(nullptr, "|", &context);
				}
				Book readBook(str_arr[0], str_arr[1], str_arr[2], atoi(str_arr[3].c_str()));
				if (atoi(str_arr[4].c_str()) == 1) {
					readBook.setLoan(true);
				}
				else {
					readBook.setLoan(false);
				}
				bookfileList.push_back(readBook);
				str_cnt = 0;
			}
			booklist = bookfileList;
			bookFile.close();
		}


		//person파일 읽어오기
		std::list<person> personfileList;
		std::ifstream personFile("personlist.txt");

		if (personFile.is_open()) {
			std::string line;

			std::string str_arr[20];
			int str_cnt = 0;
			char* context;

			while (std::getline(personFile, line)) {
				char* str_buff = new char[100];
				strcpy_s(str_buff, 100, line.c_str());

				char* tok = strtok_s(str_buff, "|", &context);
				while (tok != nullptr) {
					str_arr[str_cnt++] = std::string(tok);
					tok = strtok_s(nullptr, "|", &context);
				}
				person readPerson(str_arr[0], str_arr[1], str_arr[2]);
				readPerson.setLoanNumber(atoi(str_arr[4].c_str()));
				readPerson.setLoanBook1(str_arr[5]);
				readPerson.setLoanBook2(str_arr[6]);
				readPerson.setLoanBook3(str_arr[7]);

				personfileList.push_back(readPerson);
				str_cnt = 0;
			}
			personlist = personfileList;
			personFile.close();
		}
	}
};



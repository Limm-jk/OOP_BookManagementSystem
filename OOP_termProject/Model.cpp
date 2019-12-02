#include<list>
#include"Object.cpp"
#include<string>
#include<fstream>
#include<iostream>
#include <sstream>
#include <cstring>

//�ٲ�
class Model {
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//���ͷ�����
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();

public:

	//�α��� check
	bool loginCheck(std::string id, std::string passwd) {
		//�ش��ϴ� id�� passwd�� ��ġ�ϸ� true����
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id && (*itr).getPasswd() == passwd) {
				return true;
			}
		}

		//id�� passwd �� �� �ϳ��� Ʋ���� false����
		return false;
	}


	//book �߰�
	bool bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		//����ó���� bookNumber�� ���� ���� �ִ��� Ȯ��
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			if ((*itr).getBookNumber() == addbookNumber) {
				return false;
			}
		}

		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
		
		return true;
	}

	//person �߰�
	bool addPerson(std::string& name, std::string& id, std::string& passwd) {
		//����ó���� id�� ���� ���� �ִ��� Ȯ��
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				return false;
			}
		}

		person newPerson(name, id, passwd);
		personlist.push_back(newPerson);

		return true;
	}

	//id�� person��ü ã��
	person idToPerson(std::string id) {
		person* rtps;
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				return *itr;
			}
		}
	}

	//book �˻�
	std::list<Book> bookSearchByNumber(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = booklist.begin(); iterPos != booklist.end(); ++iterPos)
		{
			if ((*iterPos).getBookNumber() == givenBookNumber) {//�־��� �Ͱ� ���� å��ȣ�� ���� ��ü�� ����ų �� �۵�
				Book abook((*iterPos).getBookTitle(), (*iterPos).getAuthor(), (*iterPos).getPublisher(), (*iterPos).getBookNumber());//����Ű�� ��ü�� ����
				abook.setLoan((*iterPos).getLoan());
				aList.push_back(abook);//��ȯ�� ����Ʈ�� �ٿ��ֱ�
			}
		}
		return aList;//����Ʈ ��ȯ
	}

	
	std::list<Book> bookSearchByTitle(std::string title) {
		std::list<Book> alist;

		bklistItr = booklist.begin();//�ʱ�ȭ
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle().find(title) != std::string::npos) {	//find(�˻���) �Լ��� ã�� ���ڿ��� ���� ��� npos��� ����� ��ȯ��.
																				//�� ��� ã�ұ� ������ npos�� �ƴѰ�.
				Book abook((*bklistItr).getBookTitle(), (*bklistItr).getAuthor(), (*bklistItr).getPublisher(), (*bklistItr).getBookNumber());//����Ű�� ��ü�� ����
				abook.setLoan((*bklistItr).getLoan());
				alist.push_back(abook);										//ã������ ����� ��ü�� ����Ʈ �ڿ� Ǫ��.
			}
			bklistItr++;
		}
		bklistItr = booklist.begin();	//�� �������� �ݺ��� �ʱ�ȭ
		return alist;					//�˻���� ����Ʈ ����
	}

	std::list<person> personSearch(std::string id) {
		std::list<person> alist;

		std::list<person>::iterator pslistItr = personlist.begin();
		while (pslistItr != personlist.end()) {
			if ((*pslistItr).getId().find(id) != std::string::npos) {	//find(�˻���) �Լ��� ã�� ���ڿ��� ���� ��� npos��� ����� ��ȯ��.
																				//�� ��� ã�ұ� ������ npos�� �ƴѰ�.
				person aperson((*pslistItr).getName(), (*pslistItr).getId(), (*pslistItr).getPasswd());//����Ű�� ��ü�� ����
				aperson.setLoanNumber((*pslistItr).getLoanNumber());
				aperson.setLoanBook1((*pslistItr).getLoanBook1());
				aperson.setLoanBook2((*pslistItr).getLoanBook2());
				aperson.setLoanBook3((*pslistItr).getLoanBook3());

				alist.push_back(aperson);										//ã������ ����� ��ü�� ����Ʈ �ڿ� Ǫ��.
			}
			pslistItr++;
		}

		return alist;					//�˻���� ����Ʈ ����
	}
	
	//���� ����
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
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 
		while (bklistItr != booklist.end()) { 
			if ((*bklistItr).getBookNumber() == bookNumber) { // å�� �ִ��� Ȯ��
				while (pslistItr != personlist.end()) { 
					if ((*pslistItr).getId() == id) { // id ���� ��� ã�� 
						int num = (*pslistItr).getLoanNumber();
						std::string settitle = std::to_string(bookNumber);
						// �Ǽ��� 1,2�϶��� loanbook�� ���°���� �𸥴�.
						if (num == 0) { // å�� ������ �ʾ��� ��
							(*bklistItr).setLoan(true);
							(*pslistItr).setLoanNumber(1);
							(*pslistItr).setLoanBook1(settitle);
							return true;
						}
						else if (num == 1) { // �ѱ� ������ �� 
							// ���� ���ȴ��� Ȯ�� 
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
						else if (num == 2) { // �α� ������ ��
							// ���� �Ⱥ��ȴ��� Ȯ�� 
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

	// �ݳ�
	bool bookReturn(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 

		while (bklistItr != booklist.end())
		{
			if ((*bklistItr).getBookNumber() == bookNumber) { 
				if ((*bklistItr).getLoan() == true) { // å�� ���� �������� Ȯ�� 
					std::string gettitle = std::to_string(bookNumber);
					while (pslistItr != personlist.end())
					{
						if ((*pslistItr).getId() == id) { // ���̵� Ȯ�� 
							int num = (*pslistItr).getLoanNumber(); // ���� �Ǽ� Ȯ�� 
							if (num == 1) {
								if ((*pslistItr).getLoanBook1() == gettitle) { // �ݳ��� å�� ������ å�� ��ġ�ϴ��� Ȯ�� 
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

	//person ����
	bool personDelete(std::string id) {
		
		//id �˻�
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			if ((*itr).getId() == id) {
				personlist.erase(itr);
				return true;
			}
		}

		//ã�� id�� ������ false����
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
		
		
		//book���� �о����
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


		//person���� �о����
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



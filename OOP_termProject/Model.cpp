#include<list>
#include"Object.cpp"
#include<string>
#include<fstream>
#include<iostream>
#include <sstream>
//�ٲ�
class Model {
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//���ͷ�����
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();



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

		pslistItr = personlist.begin();
		while (pslistItr != personlist.end()) {
			if ((*pslistItr).getId().find(id) != std::string::npos) {	//find(�˻���) �Լ��� ã�� ���ڿ��� ���� ��� npos��� ����� ��ȯ��.
																				//�� ��� ã�ұ� ������ npos�� �ƴѰ�.
				person aperson((*pslistItr).getName(), (*pslistItr).getId(), (*pslistItr).getPasswd());//����Ű�� ��ü�� ����
				aperson.setLoanNumber((*pslistItr).getLoanNumber);
				aperson.setLoanBook1((*pslistItr).getLoanBook1);
				aperson.setLoanBook2((*pslistItr).getLoanBook2);
				aperson.setLoanBook3((*pslistItr).getLoanBook3s);

				alist.push_back(aperson);										//ã������ ����� ��ü�� ����Ʈ �ڿ� Ǫ��.
			}
			pslistItr++;
		}
		pslistItr = booklist.begin();	//�� �������� �ݺ��� �ʱ�ȭ
		return alist;					//�˻���� ����Ʈ ����
	}
	

	bool bookDelete(int bookNumber) {
		if (bookSearchNum(bookNumber)) {
			booklist.erase(bklistItr);
			return true;
		}
		return false;
	}
	
	bool bookLoan(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 
		while (bklistItr != booklist.end()) { 
			if ((*bklistItr).getBookNumber() == bookNumber) { // å�� �ִ��� Ȯ��
				while (pslistItr != personlist.end()) { 
					if ((*pslistItr).getId == id) { // id ���� ��� ã�� 
						int num = (*pslistItr).getLoanNumber;
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
							if ((*pslistItr).getLoanBook1 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3 != "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(2);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
						}
						else if (num == 2) { // �α� ������ ��
							// ���� �Ⱥ��ȴ��� Ȯ�� 
							if ((*pslistItr).getLoanBook1 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook1(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook2 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook2(settitle);
								return true;
							}
							else if ((*pslistItr).getLoanBook3 == "") {
								(*bklistItr).setLoan(true);
								(*pslistItr).setLoanNumber(3);
								(*pslistItr).setLoanBook3(settitle);
								return true;
							}
						}
					}
				}
			}
		}
		return false;
	}

	// �ݳ�
	bool bookReturn(std::string id, int bookNumber) {
		bklistItr = booklist.begin(); // �ʱ�ȭ 
		pslistItr = personlist.begin(); // �ʱ�ȭ 

		while (bklistItr != booklist.end())
		{
			if ((*bklistItr).getBookNumber == bookNumber) { 
				if ((*bklistItr).getLoan == true) { // å�� ���� �������� Ȯ�� 
					std::string gettitle = std::to_string(bookNumber);
					while (pslistItr != personlist.end())
					{
						if ((*pslistItr).getId == id) { // ���̵� Ȯ�� 
							int num = (*pslistItr).getLoanNumber(); // ���� �Ǽ� Ȯ�� 
							if (num == 1) {
								if ((*pslistItr).getLoanBook1 == gettitle) { // �ݳ��� å�� ������ å�� ��ġ�ϴ��� Ȯ�� 
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 0;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
							else if (num == 2) {
								if ((*pslistItr).getLoanBook1 == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 1;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook2 == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber = 1;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
							else if (num == 3) {
								if ((*pslistItr).getLoanBook1 == gettitle) {
									(*pslistItr).setLoanBook1(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook2 == gettitle) {
									(*pslistItr).setLoanBook2(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
								else if ((*pslistItr).getLoanBook3 == gettitle) {
									(*pslistItr).setLoanBook3(NULL);
									(*pslistItr).setLoanNumber = 2;
									(*bklistItr).setLoan = false;
									return true;
								}
							}
						}
					}
				
				}
			}
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

	std::string file_to_string(std::string filePath) {
		std::ifstream in(filePath);
		std::string s;

		if (in.is_open()) {
			// ��ġ �����ڸ� ���� ������ �ű��.
			in.seekg(0, std::ios::end);

			// �׸��� �� ��ġ�� �д´�. (������ ũ��)
			int size = in.tellg();

			// �� ũ���� ���ڿ��� �Ҵ��Ѵ�.
			s.resize(size);

			// ��ġ �����ڸ� �ٽ� ���� �� ������ �ű��.
			in.seekg(0, std::ios::beg);

			// ���� ��ü ������ �о ���ڿ��� �����Ѵ�.
			in.read(&s[0], size);

			in.close();//���� ����
			return s;
		}
	}
public:
	void makeBookList(std::string givenString) {			//��뿹��: makeBookList(file_to_string("book.txt"));
		std::string line;
		std::istringstream input;
		input.str(givenString);
		while (1)
		{
			std::string title;
			std::string author;
			std::string publisher;
			int bookNumber;
			int beforIntToBool;

			if (std::getline(input, line, "\n")== ""){
				break;
			}
			
			std::istream ss(line);
			std::string buffer, value;
			
			std::getline(ss, buffer, '|');
			value = buffer;
			title = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			author = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			publisher = value;

			std::getline(ss, buffer, '|');
			value = std::stoi(buffer);//������ ��ȯ
			bookNumber = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			beforIntToBool = value;

			Book book(title, author, publisher, bookNumber);
			if (beforIntToBool == "1") {								//���� ����ȯ
				book.setLoan(true);
			}
			else {
				book.setLoan(false);
			}

			booklist.push_back(book);
		}
	}

public:
	void makePersonList(std::string givenString) {
		std::string line;
		std::istringstream input;
		input.str(givenString);
		while (1)//���� �о ��ü ����� ����Ʈ�� Ǫ��. ���ڿ� ������. \\\\ �Ű����� ���� �ʿ�?
		{
			std::string name;
			std::string id;
			std::string passwd;
			int loanNumber;
			std::string loanBook1;
			std::string loanBook2;
			std::string loanBook3;
			if (std::getline(input, line, \n) == "") {
				break;
			}
			istream ss(line);
			string buffer, value;

			std::getline(ss, buffer, '|');
			value = buffer;
			name = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			id = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			passwd = value;

			std::getline(ss, buffer, '|');
			value = stoi(buffer);//������ ��ȯ
			loanNumber = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			loanBook1 = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			loanBook2 = value;

			std::getline(ss, buffer, '|');
			value = buffer;
			loanBook3 = value;

			person person(name, id, passwd);
			person.setLoanNumber(loanNumber);
			person.setLoanBook1(loanBook1);
			person.setLoanBook2(loanBook2);
			person.setLoanBook3(loanBook3);


			personlist.push_back(person));
		}
	}
		/*
	public:
		void dataInit() {
			//������������� booklist�� ������ å�����͸� Ǫ��(�ʱ����� 1���� ����)
			//������������� personlist�� ������ ��������͸� Ǫ��(�ʱ����� 1���� ����)
		}
		*/														//���̻� ������ ����. file_to_string �� ����Ұ�.

public:
	std::string booklist_to_string() {
		std::string result;
		for (std::list<Book>::iterator itr = booklist.begin(); itr != booklist.end(); itr++) {
			std::string title = (*itr).getBookTitle();
			std::string author = (*itr).getAuthor();
			std::string publisher = (*itr).getPublisher();
			std::string  bookNumber = std::to_string((*itr).getBookNumber());
			bool beforBoolToInt = (*itr).getLoan;
			std::string loan;

			if (beforBoolToInt == true) {
				loan = "1";
			}
			else {
				loan = "0";
			}
			
			result = result + title + "|" + author + "|" + publisher + "|" + bookNumber + "|" + loan + "\n";

		}
	}
public:
	std::string personlist_to_string() {
		std::string result = "";
		for (std::list<person>::iterator itr = personlist.begin(); itr != personlist.end(); itr++) {
			std::string name = (*itr).getName();
			std::string id = (*itr).getId;
			std::string passwd = (*itr).getPasswd;
			std::string loanNumber = std::to_string((*itr).getLoanNumber;
			std::string loanBook1 = (*itr).getLoanBook1;
			std::string loanBook2 = (*itr).getLoanBook2;
			std::string loanBook3 = (*itr).getLoanBook3;

			result = result + name + "|" + id + "|" + passwd + "|" + loanNumber + "|" + loanBook1 + "|" + loanBook2 + "|" + loanBook3 + "\n";

		}
		return result;
	}
	void string_to_file(std::string bookString, std::string personString) {//���� ������Ʈ. ���α׷� ���� �� �ݵ�� �����Ұ�. ��): string_to_file(booklist_to_string(), personlist_to_string());
		std::fstream out;
		out.open("booklist.txt", std::ios_base::out | std::ios_base::trunc);	//���� �ʱ�ȭ�ϰ� ������� ����

		if (out.is_open()) {
			out << bookString+"\n";											//���Ͽ� �� ���� ����, �� �������� �ٹٲ޹��� �־ �������̶�� �� ǥ��. 
			out.close();													//�������� ǥ���� ������ ���� ���� �� ����ϱ� ����.
		}

		out.open("personlist.txt", std::ios_base::out | std::ios_base::trunc);

		if (out.is_open()) {
			out << personString+"\n";
			out.close();
		}
	}
	

};

#include<list>
#include<string>
#include<fstream>
#include<iostream>
#include"Object.cpp"
//�ٲ�
using namespace std;

class Model {
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;

	//���ͷ�����
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();
public:
	string file_to_string(string filePath) {
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

			return s;
	}

public:
	void makeBookList(string givenString) {			//��뿹��: makeBookList(file_to_string("book.txt"));
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
			value = atoi(buffer.c_str());//������ ��ȯ
			bookNumber = value;

			getline(ss, buffer, '|');
			value = atoi(buffer.c_str());//�ϴ� ������ ��ȯ
			beforIntToBool = value;

			Book book(title, author, publisher, bookNumber);
			if (beforIntToBool == 1) {								//���� ����ȯ
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
		while (givenString)//���� �о ��ü ����� ����Ʈ�� Ǫ��. ���ڿ� ������. \\\\ �Ű����� ���� �ʿ�?
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
			value = atoi(buffer.c_str());//������ ��ȯ
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
		//������������� booklist�� ������ å�����͸� Ǫ��(�ʱ����� 1���� ����)
		//������������� personlist�� ������ ��������͸� Ǫ��(�ʱ����� 1���� ����)


	}

	//book ����, �˻�, ����
	void bookInsert(std::string& addbookTitle, std::string& addauthor, std::string& addpublisher, int& addbookNumber) {
		Book newbook(addbookTitle, addauthor, addpublisher, addbookNumber);
		booklist.push_back(newbook);
	}

	std::list<Book> bookSearch(int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = bookList.begin(); iterPos != bookList.end(); ++iterPos)
		{
			if ((*iterPos).getBookNumber() == givenBookNumber) {//�־��� �Ͱ� ���� å��ȣ�� ���� ��ü�� ����ų �� �۵�
				Book abook((*iterPos).getBookTitle, (*iterPos).getAuthor, (*iterPos).getPublisher, (*iterPos).getBookNumber);//����Ű�� ��ü�� ����
				abook.setLoan((*iterPos).getLoan);
				aList.push_back(abook);//��ȯ�� ����Ʈ�� �ٿ��ֱ�
			}
		}
		return aList;//����Ʈ ��ȯ
		

	}
	/*
	std::list<Book> bookSearch(std::string title  ) {

		bklistItr = booklist.begin();//�ʱ�ȭ
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle() == title) {
				return true;
			}
			++bklistItr;
		}
		bklistItr = booklist.begin();//ã�µ� ���� �ÿ� �ʱ�ȭ �� ����
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

	//person ����, �˻�, ����



	//���� ������Ʈ
};

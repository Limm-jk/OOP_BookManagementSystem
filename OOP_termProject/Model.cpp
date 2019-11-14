#include<list>
#include"Object.cpp"

class Model {
	//book list����(��ũ�帮��Ʈ - STL���)
	std::list<Book> booklist;
	//person list����(��ũ�帮��Ʈ - STL���)
	std::list<person> personlist;
	
	//���ͷ�����
	std::list<Book>::iterator bklistItr = booklist.begin();
	std::list<person>::iterator pslistItr = personlist.begin();


public:
	void dataInit() {
		//������������� booklist�� ������ å�����͸� Ǫ��(�ʱ����� 1���� ����)
		//������������� personlist�� ������ ��������͸� Ǫ��(�ʱ����� 1���� ����)
	}




	//book ����, �˻�, ����
	bool bookInsert(std::string title, std::string author, std::string date, int bookNumber) {
		Book newbook(title, author, date, bookNumber);
		booklist.push_back(newbook);
	}

	std::list<Book> bookSearch(std::list<Book> givenList, int givenBookNumber) {
		std::list<Book> aList;
		for (std::list<Book>::iterator iterPos = givenList.begin(); iterPos != givenList.end; ++iterPos)
		{
			if((*iterPos).getBookNumber() == givenBookNumber) {//�־��� �Ͱ� ���� å��ȣ�� ���� ��ü�� ����ų �� �۵�
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

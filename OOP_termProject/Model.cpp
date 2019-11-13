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
	bool bookInsert(std::string title, std::string author, std::string date, int ISBN) {
		Book newbook(title, author, date, ISBN);
		booklist.push_back(newbook);
	}

	bool bookSearch(std::string title) {
		bklistItr = booklist.begin();//�ʱ�ȭ
		while (bklistItr != booklist.end()) {
			if ((*bklistItr).getBookTitle == title) {
				return true;
			}
			++bklistItr;
		}
		bklistItr = booklist.begin();//ã�µ� ���� �ÿ� �ʱ�ȭ �� ����
		return false;
	}

	bool bookDelete(std::string title) {
		if (bookSearch(title)) {
			booklist.erase(bklistItr);
			return true;
		}
		return false;
	}

	//person ����, �˻�, ����

	//���� ������Ʈ
	//
};

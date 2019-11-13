#pragma once
class Objects
{
	virtual void add() = 0;		//리스트에 객체 추가. person은 ID가 중복되는지 체크하고 예외처리 or 자동으로 ID 부여(정렬해두면 검색에서 속도이득)
	virtual void modify() = 0;	//객체정보수정
	virtual void del() = 0;		//리스트에서 객체 빼고 링크 이어붙이기
	virtual void search() = 0;	//person은 ID로(이름중복시 구별 불가)
								//도서검색은 해당 단어가 중간에 한번만 들어가 있어도 검색에 걸려야함
								//둘다 list 띄우니까 apppView에서 필요한 클래서 구현해서 같이 쓰면됨

	protected:
		Objects() {}//생성자
		~Objects() {}//소멸자
};


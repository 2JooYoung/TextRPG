#include <iostream>
using namespace std;

enum PlayerType
{
	PT_None = 0,
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,

};

enum MonsterType
{
	MT_None = 0,
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,

};

struct StatInfo
{
	int hp;
	int attack;
	int defence;

};


struct MonsterStatInfo
{
	int monsterHp;
	int monsterAttack;
	int monsterDefence;
};

PlayerType playerType;
StatInfo playerStat;

MonsterType monsterType;
MonsterStatInfo monsterStat;



void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();


int main()
{
	srand(time(0));
	EnterLobby();


}



void EnterLobby()
{
	while (true)
	{
		cout << "-----------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "-----------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();


		cout << "-----------------------" << endl;
		cout << "(1) 필드 입장  (2) 게임 종료" << endl;
		cout << "-----------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
		
	}

	  
}



void SelectPlayer()
{
	while (true)
	{

		cout << "-----------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사  (2) 궁수  (3) 마법사" << endl;
		cout << "> " << endl;

		int choice;
		cin >> choice;

		if (choice == PT_Knight)
		{
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			playerType = PT_Knight;
			break;
		}

		else if (choice == PT_Archer)
		{
			playerStat.hp = 100;
			playerStat.attack = 15;
			playerStat.defence = 3;
			playerType = PT_Archer;
			break;
		}
		else if (choice == PT_Mage)
		{
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			playerType = PT_Mage;
			break;
		}

	}
} 


void EnterField()
{
	while (true)
	{
		cout << "-----------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "-----------------------" << endl;

		cout << "[PLAYER] HP : " << playerStat.hp << " / ATT : " << playerStat.attack << " / DEF" << playerStat.defence << endl;

		//몬스터 스폰
		CreateRandomMonster();

		cout << "-----------------------" << endl;
		cout << "(1) 전투  (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterBattle();
			if (playerStat.hp == 0)
				return;
		}
		else
		{
			return;
		}

	}
	
}

void CreateRandomMonster()
{
	// random : 0~32767 값 랜덤 추출
	// 3으로 나눈다면 항상 0,1,2 숫자가 도출
	int randomChoice = 1 + (rand() % 3);

	switch (randomChoice)
	{
	case MT_Slime:
		cout << "슬라임 생성중....!" << endl << "[SLIME] HP : 30 / ATT : 2 / DEF : 0" << endl;
		monsterStat.monsterHp = 30;
		monsterStat.monsterAttack = 2;
		monsterStat.monsterDefence = 0;
		monsterType = MT_Slime;
		break;

	case MT_Orc:
		cout << "오크 생성중....!"  << endl << "[ORC] HP : 40 / ATT : 10 / DEF : 3" << endl;
		monsterStat.monsterHp = 40;
		monsterStat.monsterAttack = 10;
		monsterStat.monsterDefence = 3;
		monsterType = MT_Orc;
		break;

	case MT_Skeleton:
		cout << "해골 생성중....!" << endl << "[SKELETON] HP:80 / ATT:15 / DEF:5" << endl;
		monsterStat.monsterHp = 80;
		monsterStat.monsterAttack = 15;
		monsterStat.monsterDefence = 5;
		monsterType = MT_Skeleton;
		break;

	}




}


void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.monsterDefence;
		if (damage < 0)
			damage = 0;

		//공격
		monsterStat.monsterHp -= damage;
		if (monsterStat.monsterHp < 0)
			monsterStat.monsterHp = 0;

		cout << "몬스터의 남은 체력 : " << monsterStat.monsterHp << endl;

		if (monsterStat.monsterHp == 0)
		{
			cout << "몬스터를 처치했습니다!" << endl;
			WaitForNextKey();
			return;
		}


		//반격
		damage = monsterStat.monsterAttack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;

		cout << "플레이어의 남은 체력 : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << "당신은 사망했습니다...........GAME OVER" << endl;
			WaitForNextKey();
			return;
		}

	}
}


void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << "> ";

	int input;
	cin >> input;

	system("cls");
}
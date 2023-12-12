#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
 
 
 
//武器类
class Weapon{
protected:
	int Price;			//武器价格
	int ATK;			//武器攻击力
	string Name;		//武器名称
	string Rank;		//武器等级
public:
	Weapon(int price=0,int atk=0,string name="",string rank=""){Price=price;ATK=atk;Name=name;Rank=rank;}
	int GetPrice(){return Price;}
	int GetATK(){return ATK;}
	string GetName(){return Name;}
	string GetRank(){return Rank;}
	virtual ~Weapon(){}
};
 
//战士武器类
class WarriorWeapon:public Weapon{
public:
	WarriorWeapon(int price=0,int atk=0,string name="",string rank=""):Weapon(price,atk,name,rank){}
	~WarriorWeapon(){}
};
 
class WarriorWeapon1:public WarriorWeapon{
public:
	WarriorWeapon1(int price=500,int atk=70,string name="巨剑",string rank="白银"):WarriorWeapon(price,atk,name,rank){}
	~WarriorWeapon1(){}
};
 
class WarriorWeapon2:public WarriorWeapon{
public:
	WarriorWeapon2(int price=1000,int atk=130,string name="巨剑",string rank="黄金"):WarriorWeapon(price,atk,name,rank){}
	~WarriorWeapon2(){}
};
 
class WarriorWeapon3:public WarriorWeapon{
public:
	WarriorWeapon3(int price=1800,int atk=220,string name="巨剑",string rank="白金"):WarriorWeapon(price,atk,name,rank){}
	~WarriorWeapon3(){}
};
 
class WarriorWeapon4:public WarriorWeapon{
public:
	WarriorWeapon4(int price=3000,int atk=350,string name="巨剑",string rank="钻石"):WarriorWeapon(price,atk,name,rank){}
	~WarriorWeapon4(){}
};
 
//法师武器类
class WizardWeapon:public Weapon{
public:
	WizardWeapon(int price=0,int atk=0,string name="",string rank=""):Weapon(price,atk,name,rank){}
	~WizardWeapon(){}
};
 
class WizardWeapon1:public WizardWeapon{
public:
	WizardWeapon1(int price=400,int atk=50,string name="法杖",string rank="白银"):WizardWeapon(price,atk,name,rank){}
	~WizardWeapon1(){}
};
 
class WizardWeapon2:public WizardWeapon{
public:
	WizardWeapon2(int price=800,int atk=100,string name="法杖",string rank="黄金"):WizardWeapon(price,atk,name,rank){}
	~WizardWeapon2(){}
};
 
class WizardWeapon3:public WizardWeapon{
public:
	WizardWeapon3(int price=1500,int atk=180,string name="法杖",string rank="白金"):WizardWeapon(price,atk,name,rank){}
	~WizardWeapon3(){}
};
 
class WizardWeapon4:public WizardWeapon{
public:
	WizardWeapon4(int price=2500,int atk=300,string name="法杖",string rank="钻石"):WizardWeapon(price,atk,name,rank){}
	~WizardWeapon4(){}
};
 
//妖怪武器类
class MonsterWeapon:public Weapon{
public:
	MonsterWeapon(int price=0,int atk=0,string name="",string rank=""):Weapon(price,atk,name,rank){}
	~MonsterWeapon(){}
};
 
class MonsterWeapon1:public MonsterWeapon{
public:
	MonsterWeapon1(int price=450,int atk=60,string name="灵刃",string rank="白银"):MonsterWeapon(price,atk,name,rank){}
	~MonsterWeapon1(){}
};
 
class MonsterWeapon2:public MonsterWeapon{
public:
	MonsterWeapon2(int price=900,int atk=120,string name="灵刃",string rank="黄金"):MonsterWeapon(price,atk,name,rank){}
	~MonsterWeapon2(){}
};
 
class MonsterWeapon3:public MonsterWeapon{
public:
	MonsterWeapon3(int price=1650,int atk=200,string name="灵刃",string rank="白金"):MonsterWeapon(price,atk,name,rank){}
	~MonsterWeapon3(){}
};
 
class MonsterWeapon4:public MonsterWeapon{
public:
	MonsterWeapon4(int price=2750,int atk=320,string name="灵刃",string rank="钻石"):MonsterWeapon(price,atk,name,rank){}
	~MonsterWeapon4(){}
};
 
 
//盔甲类
class Armor{
protected:
	int Price;			//盔甲价格
	int DEF;			//盔甲防御力
	string Name;		//盔甲名称
	string Rank;		//盔甲等级
public:
	Armor(int price=0,int def=0,string name="",string rank=""){Price=price;DEF=def;Name=name;Rank=rank;}
	int GetPrice(){return Price;}
	int GetDEF(){return DEF;}
	string GetName(){return Name;}
	string GetRank(){return Rank;}
	//虚析构函数
	~Armor(){}
};
 
 
//战士盔甲类
class WarriorArmor:public Armor{
public:
	WarriorArmor(int price=0,int def=0,string name="",string rank=""):Armor(price,def,name,rank){}
	~WarriorArmor(){}
};
 
class WarriorArmor1:public WarriorArmor{
public:
	WarriorArmor1(int price=300,int def=30,string name="铠甲",string rank="白银"):WarriorArmor(price,def,name,rank){}
	~WarriorArmor1(){}
};
 
class WarriorArmor2:public WarriorArmor{
public:
	WarriorArmor2(int price=600,int def=60,string name="铠甲",string rank="黄金"):WarriorArmor(price,def,name,rank){}
	~WarriorArmor2(){}
};
 
class WarriorArmor3:public WarriorArmor{
public:
	WarriorArmor3(int price=1200,int def=100,string name="铠甲",string rank="白金"):WarriorArmor(price,def,name,rank){}
	~WarriorArmor3(){}
};
 
class WarriorArmor4:public WarriorArmor{
public:
	WarriorArmor4(int price=2000,int def=200,string name="铠甲",string rank="钻石"):WarriorArmor(price,def,name,rank){}
	~WarriorArmor4(){}
};
 
 
//法师盔甲类
class WizardArmor:public Armor{
public:
	WizardArmor(int price=0,int def=0,string name="",string rank=""):Armor(price,def,name,rank){}
	~WizardArmor(){}
};
 
class WizardArmor1:public WarriorArmor{
public:
	WizardArmor1(int price=400,int def=40,string name="面纱",string rank="白银"):WarriorArmor(price,def,name,rank){}
	~WizardArmor1(){}
};
 
class WizardArmor2:public WarriorArmor{
public:
	WizardArmor2(int price=800,int def=80,string name="面纱",string rank="黄金"):WarriorArmor(price,def,name,rank){}
	~WizardArmor2(){}
};
 
class WizardArmor3:public WarriorArmor{
public:
	WizardArmor3(int price=1500,int def=160,string name="面纱",string rank="白金"):WarriorArmor(price,def,name,rank){}
	~WizardArmor3(){}
};
 
class WizardArmor4:public WarriorArmor{
public:
	WizardArmor4(int price=2500,int def=250,string name="面纱",string rank="钻石"):WarriorArmor(price,def,name,rank){}
	~WizardArmor4(){}
};
 
 
//妖怪盔甲类
class MonsterArmor:public Armor{
public:
	MonsterArmor(int price=0,int def=0,string name="",string rank=""):Armor(price,def,name,rank){}
	~MonsterArmor(){}
};
 
class MonsterArmor1:public MonsterArmor{
public:
	MonsterArmor1(int price=350,int def=35,string name="鳞甲",string rank="白银"):MonsterArmor(price,def,name,rank){}
	~MonsterArmor1(){}
};
 
class MonsterArmor2:public MonsterArmor{
public:
	MonsterArmor2(int price=700,int def=70,string name="鳞甲",string rank="黄金"):MonsterArmor(price,def,name,rank){}
	~MonsterArmor2(){}
};
 
class MonsterArmor3:public MonsterArmor{
public:
	MonsterArmor3(int price=1350,int def=130,string name="鳞甲",string rank="白金"):MonsterArmor(price,def,name,rank){}
	~MonsterArmor3(){}
};
 
class MonsterArmor4:public MonsterArmor{
public:
	MonsterArmor4(int price=2300,int def=220,string name="鳞甲",string rank="钻石"):MonsterArmor(price,def,name,rank){}
	~MonsterArmor4(){}
};
 
 
//角色类
class Character{
protected:
	string Name;	//职业名称
	int Health;		//生命值
	int ATK;		//攻击力
	int DEF;		//防御力
	int Money;
	//武器，盔甲，药（暂用治疗术代替药水）
	Weapon *weapon;
	Armor *armor;
	//Medicine medicine;	
public:
	Character(int health=2000,int atk=0,int def=0,int money=500,string name="")
	{Health=health;ATK=atk;DEF=def;Money=money;Name=name;weapon=new Weapon();armor=new Armor();}
	
	//得到角色的信息
	string GetName(){return Name;}
	int GetHealth(){return Health;}
	int GetATK(){return ATK;}
	int GetDEF(){return DEF;}
	int GetMoney(){return Money;}
	Weapon* GetWeapon(){return weapon;}
	Armor* GetArmor(){return armor;}
 
 
	//获得金钱，武器，装备
	void GetMoney(int money){Money+=money;cout<<"获得了"<<money<<"金币"<<endl;}
	void GetWeapon(Weapon *w)
	{		
		Money-=w->GetPrice()-weapon->GetPrice();		//金币减少
		ATK+=w->GetATK()-weapon->GetATK();				//攻击力上升
		weapon=w;							
	}
	void GetArmor(Armor *a)
	{
		Money-=a->GetPrice()-armor->GetPrice();			//金币减少
		DEF+=a->GetDEF()-armor->GetDEF();				//防御力上升
		armor=a;							
	}
 
	/*void GetMedicine(Medicine m)
	{
		Medicine=m;
		Money-=m.Price;
	}*/
 
	//受到攻击
	void TakeAttack(int atk)
	{
		if(atk>DEF)
			Health=Health-atk+DEF;
		if(Health<0)
			Health=0;
	}
 
	//使用治疗术
	void Treatment()
	{
		if((Health+200)<=2000)
			Health+=200;
		else
			Health=2000;
	}
 
	/*void TakeMedicine()
	{
		if((Health+medicine.value)<=2000)
			Health+=medicine.value;
		else
			Health=2000;
	}*/
 
	//展示角色信息
	void Show()
	{
		cout<<"职业："<<Name<<endl;
		cout<<"生命值："<<Health<<endl;
		cout<<"武器："<<weapon->GetRank()<<weapon->GetName()<<"\t攻击力:"<<ATK<<endl;
		cout<<"盔甲："<<armor->GetRank()<<armor->GetName()<<"\t防御力:"<<DEF<<endl;
		cout<<"金币："<<Money<<endl;
	}
	//虚析构函数
	virtual ~Character()
	{
		if(!weapon)delete weapon;
		if(!armor) delete armor;
	}
};
 
//战士类
class Warrior:public Character{
public:
	Warrior(int health=2000,int atk=70,int def=20,int money=500,string name="战士"):Character(health,
		atk,def,money,name){}	
	~Warrior()
	{		
		if(!weapon)delete weapon;
		if(!armor) delete armor;
	}
};
 
//法师类
class Wizard:public Character{
public:
	Wizard(int health=2000,int atk=50,int def=40,int money=500,string name="法师"):Character(health,
		atk,def,money,name){}
	~Wizard()
	{
		if(!weapon)delete weapon;
		if(!armor) delete armor;
	}
};
 
//妖怪类
class Monster:public Character{
public:
	Monster(int health=2000,int atk=60,int def=30,int money=500,string name="妖怪"):Character(health,
		atk,def,money,name){}
	~Monster()
	{
		if(!weapon)delete weapon;
		if(!armor) delete armor;
	}
};
 
 
class CharacterFactory{
public:
	Character *CreatCharacter(int flag)
	{
		switch(flag)
		{
		case 1:
			return new Warrior();
			break;
		case 2:
			return new Wizard();
			break;
		case 3:
			return new Monster();
			break;
		}
	}
};
 
 
//武器商店类
class WeaponStore{
public:
	virtual void Show()=0;		//武器信息展示
	virtual Weapon *CreatWeapon(int flag)=0;		//创建武器
	//虚析构函数，防止析构一般，泄漏一半
	virtual ~WeaponStore(){}
};
 
 
//战士武器商店类
class WarriorWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.白银巨剑 500金币 +70攻击力"<<endl;
		cout<<"2.黄金巨剑 1000金币 +130攻击力"<<endl;
		cout<<"3.白金巨剑 1800金币 +220攻击力"<<endl;
		cout<<"4.钻石巨剑 3000金币 +350攻击力"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new WarriorWeapon1();break;
		case 2:
			return new WarriorWeapon2();break;
		case 3:
			return new WarriorWeapon3();break;
		case 4:
			return new WarriorWeapon4();break;
		}
	}
	~WarriorWeaponStore(){}
};
 
//法师武器商店类
class WizardWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.白银法杖 400金币 +50攻击力"<<endl;
		cout<<"2.黄金法杖 800金币 +100攻击力"<<endl;
		cout<<"3.白金法杖 1500金币 +180攻击力"<<endl;
		cout<<"4.钻石法杖 2500金币 +300攻击力"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new WizardWeapon1();break;
		case 2:
			return new WizardWeapon2();break;
		case 3:
			return new WizardWeapon3();break;
		case 4:
			return new WizardWeapon4();break;
		}
	}
	~WizardWeaponStore(){}
};
 
//妖怪武器商店类
class MonsterWeaponStore:public WeaponStore{
public:
	void Show()
	{
		cout<<"1.白银灵刃 450金币 +60攻击力"<<endl;
		cout<<"2.黄金灵刃 900金币 +120攻击力"<<endl;
		cout<<"3.白金灵刃 1650金币 +200攻击力"<<endl;
		cout<<"4.钻石灵刃 2750金币 +320攻击力"<<endl;
	}
	Weapon *CreatWeapon(int flag)
	{
		switch(flag)
		{
		case 1:
			return new MonsterWeapon1();break;
		case 2:
			return new MonsterWeapon2();break;
		case 3:
			return new MonsterWeapon3();break;
		case 4:
			return new MonsterWeapon4();break;
		}
	}
	~MonsterWeaponStore(){}
};
 
 
//盔甲商店类
class ArmorStore{
public:
	virtual void Show()=0;		//盔甲信息展示
	virtual Armor* CreatArmor(int flag)=0;		//创建盔甲
	virtual ~ArmorStore(){}
};
 
 
//战士盔甲商店类
class WarriorArmorStore:public ArmorStore{
public:
	void Show()
	{
		cout<<"1.白银铠甲 300金币 +30防御力"<<endl;
		cout<<"2.黄金铠甲 600金币 +60防御力"<<endl;
		cout<<"3.白金铠甲 1200金币 +100防御力"<<endl;
		cout<<"4.钻石铠甲 2000金币 +200防御力"<<endl;
	}
	Armor *CreatArmor(int flag)
	{
		switch(flag)
		{
		case 1:
			return new WarriorArmor1();break;
		case 2:
			return new WarriorArmor2();break;
		case 3:
			return new WarriorArmor3();break;
		case 4:
			return new WarriorArmor4();break;
		}
	}
	~WarriorArmorStore(){}
};
 
//法师盔甲商店类
class WizardArmorStore:public ArmorStore{
public:
	void Show()
	{
		cout<<"1.白银面纱 400金币 +40防御力"<<endl;
		cout<<"2.黄金面纱 800金币 +80防御力"<<endl;
		cout<<"3.白金面纱 1500金币 +160防御力"<<endl;
		cout<<"4.钻石面纱 2500金币 +250防御力"<<endl;
	}
	Armor *CreatArmor(int flag)
	{
		switch(flag)
		{
		case 1:
			return new WizardArmor1();break;
		case 2:
			return new WizardArmor2();break;
		case 3:
			return new WizardArmor3();break;
		case 4:
			return new WizardArmor4();break;
		}
	}
	~WizardArmorStore(){}
};
 
//妖怪盔甲商店类
class MonsterArmorStore:public ArmorStore{
public:
	void Show()
	{
		cout<<"1.白银鳞甲 350金币 +35防御力"<<endl;
		cout<<"2.黄金鳞甲 700金币 +70防御力"<<endl;
		cout<<"3.白金鳞甲 1350金币 +130防御力"<<endl;
		cout<<"4.钻石鳞甲 2300金币 +220防御力"<<endl;
	}
	Armor *CreatArmor(int flag)
	{
		switch(flag)
		{
		case 1:
			return new MonsterArmor1();break;
		case 2:
			return new MonsterArmor2();break;
		case 3:
			return new MonsterArmor3();break;
		case 4:
			return new MonsterArmor4();break;
		}
	}
	~MonsterArmorStore(){}
};
 
//管理商店类
class StoreManager{
public:
	WeaponStore *CreatWeaponStore(string name)
	{
		if(name=="战士")
			return new WarriorWeaponStore();
		if(name=="法师")
			return new WizardWeaponStore();
		if(name=="妖怪")
			return new MonsterWeaponStore();
	}
	ArmorStore *CreatArmorStore(string name)
	{
		if(name=="战士")
			return new WarriorArmorStore();
		if(name=="法师")
			return new WizardArmorStore();
		if(name=="妖怪")
			return new MonsterArmorStore();
	}
};
 
 
int main()
{
	CharacterFactory characterFactory;		//角色产生工厂
	Character *player1=0;						//玩家一角色
	Character *player2=0;						//玩家二角色
 
	StoreManager storeManager;				//商店产生工厂（决定产生哪种职业的武器和盔甲）
	WeaponStore* player1weaponStore=0;		//玩家一武器商店
	ArmorStore* player1armorStore=0;			//玩家一盔甲商店
	WeaponStore* player2weaponStore=0;		//玩家二武器商店
	ArmorStore* player2armorStore=0;			//玩家二盔甲商店
 
	Weapon *player1Weapon=0;					//玩家一武器
	Weapon *player2Weapon=0;					//玩家二武器
	Armor *player1Armor=0;					//玩家一盔甲
	Armor *player2Armor=0;					//玩家二盔甲
 
	int money;								//每回合随机生成金币
	srand((unsigned)time(NULL));
	money=rand()%100+200;					//每回合生成200到300的金币
 
 
	int flag=0,count=0;						//用于switch的flag和记录回合数的count
	const int treatCD=4;					//治疗术的CD，即四个回合
	int player1NextTreat=1,player2NextTreat=1;	//玩家一和玩家二下次可以使用治疗术的回合
 
 
	//游戏开始
	cout<<"游戏开始！"<<endl;
 
	//玩家一创建角色
	cout<<"玩家一请选择职业：\n"<<"1.战士\t2.法师\t3.妖怪"<<endl;
	while(1)
	{
		cin>>flag;
		if(!cin)						//输入类型错误，即int型的flag却输入了字母
		{
			cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
			cin.sync();					//清除之前错误的数据流，以便重新输入
			cout<<"输入错误请重新输入！\n"<<endl;
			continue;
		}
		if(flag!=1&&flag!=2&&flag!=3)
			cout<<"输入错误，请重新输入！\n";
		else
			break;
	}
	player1=characterFactory.CreatCharacter(flag);
	player1weaponStore=storeManager.CreatWeaponStore(player1->GetName());
	player1armorStore=storeManager.CreatArmorStore(player1->GetName());
 
	//玩家二创建角色
	cout<<"玩家二请选择职业：\n"<<"1.战士\t2.法师\t3.妖怪"<<endl;
	while(1)
	{
		cin>>flag;
		if(!cin)						//输入类型错误，即int型的flag却输入了字母
		{
			cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
			cin.sync();					//清除之前错误的数据流，以便重新输入
			cout<<"输入错误请重新输入！\n"<<endl;
			continue;
		}
		if(flag!=1&&flag!=2&&flag!=3)
			cout<<"输入错误，请重新输入！";
		else
			break;
	}
	player2=characterFactory.CreatCharacter(flag);
	player2weaponStore=storeManager.CreatWeaponStore(player2->GetName());
	player2armorStore=storeManager.CreatArmorStore(player2->GetName());
 
 
	//无限循环，直到有一方生命值下降为0
	while(1)
	{
		count++;
		cout<<"\n*************"<<endl;
		cout<<"***第"<<count<<"回合***"<<endl;
		cout<<"*************\n"<<endl;
		
		//玩家一进行游戏
		cout<<"玩家一："<<endl;
		money=rand()%100+200;
		player1->GetMoney(money);
		player1->Show();		
		while(1)			//为了能退到上一级，即选择攻击或买武器等，需要这个循环
		{
			cout<<"请选择操作："<<"\n1.攻击\n2.买武器\n3.买盔甲\n4.治疗术（回复200生命值，冷却时间为四个回合）"<<endl;
			while(1)
			{
				cin>>flag;
				if(!cin)						//输入类型错误，即int型的flag却输入了字母
				{
					cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
					cin.sync();					//清除之前错误的数据流，以便重新输入
					cout<<"输入错误请重新输入！\n"<<endl;
					continue;
				}
				if(flag!=1&&flag!=2&&flag!=3&&flag!=4)
					cout<<"输入错误，请重新输入"<<endl;
				else
					break;
			}
			switch(flag)
			{
			case 1:				//攻击
				player2->TakeAttack(player1->GetATK());break;
			case 2:				//买武器			
				player1weaponStore->Show();
				cout<<"0.返回上一级"<<endl;
				while(1)
				{
					cout<<"请选择操作"<<endl;
					cin>>flag;
					if(!cin)						//输入类型错误，即int型的flag却输入了字母
					{
						cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
						cin.sync();					//清除之前错误的数据流，以便重新输入
						cout<<"输入错误请重新输入！\n"<<endl;
						continue;
					}
					if(flag!=0&&flag!=1&&flag!=2&&flag!=3&&flag!=4)
						cout<<"输入错误，请重新输入"<<endl;
					else if(flag==0)
						break;
					else
					{
						Weapon* tempWeapon=player1weaponStore->CreatWeapon(flag);
						if(player1->GetMoney()<tempWeapon->GetPrice()-player1->GetWeapon()->GetPrice())
						{
							cout<<"你的金币不够，请重新选择或输入0返回上一级"<<endl;
							delete tempWeapon;
						}
						else
						{
							delete tempWeapon;
							break;
						}
					}
				}
				if(flag==0)
					break;
				player1Weapon=player1weaponStore->CreatWeapon(flag);
				player1->GetWeapon(player1Weapon);
				break;
			case 3:				//买盔甲
				player1armorStore->Show();
				cout<<"0.返回上一级"<<endl;
				while(1)
				{
					cout<<"请选择盔甲"<<endl;
					cin>>flag;
					if(!cin)						//输入类型错误，即int型的flag却输入了字母
					{
						cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
						cin.sync();					//清除之前错误的数据流，以便重新输入
						cout<<"输入错误请重新输入！\n"<<endl;
						continue;
					}
					if(flag!=0&&flag!=1&&flag!=2&&flag!=3&&flag!=4)
						cout<<"输入错误，请重新输入"<<endl;
					else if(flag==0)
						break;
					else
					{
						Armor* tempArmor=player1armorStore->CreatArmor(flag);
						if(player1->GetMoney()<tempArmor->GetPrice()-player1->GetArmor()->GetPrice())
						{
							cout<<"你的金币不够,请重新选择或输入0返回上一级"<<endl;
							delete tempArmor;
						}
						else
						{
							delete tempArmor;
							break;
						}
					}
				}
				if(flag==0)
					break;
				player1Armor=player1armorStore->CreatArmor(flag);
				player1->GetArmor(player1Armor);
				break;
			case 4:			//补血
				if(count>=player1NextTreat)
				{
					player1->Treatment();
					player1NextTreat+=treatCD;
				}
				else
				{
					cout<<"治疗术正在冷却中，还剩"<<(player1NextTreat-count)<<"个回合"<<endl;
					while(1)
					{
						cout<<"按0退回上一级"<<endl;
						cin>>flag;
						if(flag==0)
							break;
					}
				}
				break;
			}
			if(flag!=0)
				break;
		}
		//判断输赢
		if(player2->GetHealth()<=0)
		{
			cout<<"玩家二生命值下降为0，玩家一胜利"<<endl;
			break;
		}
		
		
 
		//玩家二进行游戏
		cout<<"玩家二："<<endl;
		money=rand()%100+200;
		player2->GetMoney(money);
		player2->Show();		
		while(1)			//为了能退到上一级，即选择攻击或买武器等，需要这个循环
		{
			cout<<"请选择操作："<<"\n1.攻击\n2.买武器\n3.买盔甲\n4.治疗术（回复200生命值，冷却时间为四个回合）"<<endl;
			while(1)
			{
				cin>>flag;
				if(!cin)						//输入类型错误，即int型的flag却输入了字母
				{
					cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
					cin.sync();					//清除之前错误的数据流，以便重新输入
					cout<<"输入错误请重新输入！\n"<<endl;
					continue;
				}
				if(flag!=1&&flag!=2&&flag!=3&&flag!=4)
					cout<<"输入错误，请重新输入"<<endl;
				else
					break;
			}
			switch(flag)
			{
			case 1:				//攻击
				player1->TakeAttack(player2->GetATK());break;
			case 2:				//买武器			
				player2weaponStore->Show();
				cout<<"0.返回上一级"<<endl;
				while(1)
				{
					cout<<"请选择操作"<<endl;
					cin>>flag;
					if(!cin)						//输入类型错误，即int型的flag却输入了字母
					{
						cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
						cin.sync();					//清除之前错误的数据流，以便重新输入
						cout<<"输入错误请重新输入！\n"<<endl;
						continue;
					}
					if(flag!=0&&flag!=1&&flag!=2&&flag!=3&&flag!=4)
						cout<<"输入错误，请重新输入"<<endl;
					else if(flag==0)
						break;
					else
					{
						Weapon* tempWeapon=player2weaponStore->CreatWeapon(flag);
						if(player2->GetMoney()<tempWeapon->GetPrice()-player2->GetWeapon()->GetPrice())
						{
							cout<<"你的金币不够，请重新选择或输入0返回上一级"<<endl;
							delete tempWeapon;
						}
						else
						{
							delete tempWeapon;
							break;
						}
					}
				}
				if(flag==0)
					break;
				player2Weapon=player2weaponStore->CreatWeapon(flag);
				player2->GetWeapon(player2Weapon);
				break;
			case 3:				//买盔甲
				player2armorStore->Show();
				cout<<"0.返回上一级"<<endl;
				while(1)
				{
					cout<<"请选择盔甲"<<endl;
					cin>>flag;
					if(!cin)						//输入类型错误，即int型的flag却输入了字母
					{
						cin.clear();				//防止输入字母后程序崩溃，将之前的输入错误标识改回为0，即输入无错误
						cin.sync();					//清除之前错误的数据流，以便重新输入
						cout<<"输入错误请重新输入！\n"<<endl;
						continue;
					}
					if(flag!=0&&flag!=1&&flag!=2&&flag!=3&&flag!=4)
						cout<<"输入错误，请重新输入"<<endl;
					else if(flag==0)
						break;
					else
					{
						Armor* tempArmor=player2armorStore->CreatArmor(flag);
						if(player2->GetMoney()<tempArmor->GetPrice()-player2->GetArmor()->GetPrice())
						{
							cout<<"你的金币不够,请重新选择或输入0返回上一级"<<endl;
							delete tempArmor;
						}
						else
						{
							delete tempArmor;
							break;
						}
					}
				}
				if(flag==0)
					break;
				player2Armor=player2armorStore->CreatArmor(flag);
				player2->GetArmor(player2Armor);
				break;
			case 4:			//补血
				if(count>=player2NextTreat)
				{
					player2->Treatment();
					player2NextTreat+=treatCD;
				}
				else
				{
					cout<<"治疗术正在冷却中，还剩"<<(player2NextTreat-count)<<"个回合"<<endl;
					while(1)
					{
						cout<<"按0退回上一级"<<endl;
						cin>>flag;
						if(flag==0)
							break;
					}
				}
				break;
			}
			if(flag!=0)
				break;
		}
		//判断输赢
		if(player1->GetHealth()<=0)
		{
			cout<<"玩家一生命值下降为0，玩家二胜利"<<endl;
			break;
		}	
	}
 
	//销毁申请的空间
	if(!player1)
		delete player1;
	if(!player2)
		delete player2;
	if(!player1weaponStore)
		delete player1weaponStore;
	if(!player1armorStore)
		delete player1armorStore;
	if(!player2weaponStore)
		delete player2weaponStore;
	if(!player2armorStore)
		delete player2armorStore;
	if(!player1Weapon)
		delete player1Weapon;
	if(!player2Weapon)
		delete player2Weapon;
	if(!player1Armor)
		delete player1Armor;
	if(!player2Armor)
		delete player2Armor;
 
	system("pause");
	return 0;
}
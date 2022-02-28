#ifndef DAYS_H
#define DAYS_H
#include<string>
using namespace std;
class{
	string time;
	vector<string>name;
	int tprice ;
	int amount;
public:
	day();
	day(string t) {time=t;tprice=0;amount=0;}
	void gettp(int);
	string getday(){return time;}
	void show();
	
};
void gettp(int x){
	tprice+=x;
}
void show(){
	
}


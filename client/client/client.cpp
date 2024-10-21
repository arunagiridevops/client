#include <iostream>
#include<vector>
#include<string>
#include<map>
#include "./json.hpp"
#include "./httplib.h"
using namespace httplib;
using namespace std;
using json = nlohmann::json;
void train();
void user_add();

int main(){
	train();
	user_add();
	
	
}

void train(){
	Client client("http://13.49.68.7:9091");
	{
        auto res = client.Get("/train_station");
        if (res && res->status == 200) {
            cout << "GET /train_station Response:\n" << res->body << endl;
        } else {
            cout << "GET request failed: " << res.error() << endl;
        }
    }
}


void user_add()
{
	Client client("http://13.49.68.7:9090");
	map<string , string> info;
	cout<<"enter the user name:";
	string name;
	cin>>name;
	info["name"]=name;
	lable:
	cout<<"enter the age:";
	int age;
	cin>>age;
	info["age"]=to_string (age);
	if (age>120 || age<0) goto lable;
	string nationality;
	cout<<"enter the nationality:";
	cin>>nationality;
	info["nationality"]=nationality;
	string user_id;
	cout<<"enter the user_id:";
	cin>>user_id;
	info["user_id"]=user_id;
	
	string pass;
	cout<<"enter the pass:";
	cin>>pass;
	info["pass1"]=pass;
	json jsonData = info;
    	string serialized_data = jsonData.dump(); 
	auto res = client.Post("/sign_up", serialized_data, "application/json");
	if (res) {
        cout << "Response status: " << res->status << endl;
        cout << "Response body: " << res->body << endl;
    } else {
        cout << "Error: " << res.error() << endl;
    }
}

#include<vector>
#include<iostream>
#include<list>
#include<string>
using namespace std;
class MyException:public std::exception{
public:
    MyException(int code):code(code){
        msg = "error";
    };
    string getMsg(){
        return msg;
    }
private:
    string msg;
    int code;
};
class Except{
public:
    Except():a(0){

    }
    ~Except(){};
    void doit(){
        throw MyException(1);
    }
private:
    int a;
};
int main(){
    // vector<int> vec={1,2,3,4,5,6};
    // cout<<vec.capacity()<<endl;
    // vec.push_back(2);
    // cout<<vec.capacity()<<endl; 
    // cout<<vec[vec.size()-2]<<endl; 
    
    // list<int> li={1,2,3,4,5,6};
    // cout<<*(li.begin())<<endl;
    // auto it = li.end();
    // *it=0;
    // --it;
    // // --it;
    // cout<<*(it)<<endl;
    Except ex;
    try{
        ex.doit();
        cout<<"doit"<<endl;
    }catch(MyException &e){
        cout<<e.getMsg()<<endl;
    }
}
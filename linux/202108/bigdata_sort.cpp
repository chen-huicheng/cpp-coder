#include<bits/stdc++.h>
using namespace std;
void gen_ip(int n,string filename){
    ofstream outf(filename,ofstream::app);
    int num;
    string out;
    for (int i = 0; i < n; ++i)
    {
        srand((unsigned)time(NULL)+rand());
        for (int j = 0; j < 4; j++){
            num = rand()%256;
            out+=to_string(num);
            if(j==3)out+="\n";
            else out+=".";
        }
        if(i%10000==0){
            outf<<out;
            out.clear();
        }
        if(i%1000000==0){
            cout<<i/1000000<<endl;
        }
    }
    outf<<out;
}
template<typename T>
class Buffer{
public:
    Buffer(size_t size):size(size){

    }
    void append(T data){
        mtx.lock();
        while(que.size()>size){
            mtx.unlock();
            this_thread::yield();
            mtx.lock();
        }
        que.push(data);
        mtx.unlock();
    }
    T get(){
        mtx.lock();
        while(que.size()==0){
            mtx.unlock();
            this_thread::yield();
            mtx.lock();
        }
        tmp = que.front();
        que.pop();
        mtx.unlock();
        return tmp;
    }
private:
    T tmp;
    size_t size;
    mutex mtx;
    queue<T> que;
};

const size_t MAX_BUF_SIZE=1000000;
Buffer<string> buf(MAX_BUF_SIZE);

int hash_func(const string& data){
    int key=0;
    for(auto d:data){
        key+=d;
    }
    return key;
}
void read(string filename){
    ifstream in(filename,ifstream::in);
    string ip;
    while(in>>ip){
        buf.append(ip);
    }
}
void deal(int n){
    string ip;
    int hash_key;
    vector<ofstream> outs(n);
    for(int i=0;i<100;i++){
        outs[i].open(to_string(i)+".txt",ofstream::out|ofstream::app);
    }
    while(1){
        ip=buf.get();
        hash_key=hash_func(ip);
        outs[hash_key%n]<<ip<<endl;
    }
}
void count(int n){
    unordered_map<string,int> hashtable;
    string ip;
    int cnt;
    for(int i=0;i<n;i++){
        ifstream in(to_string(i)+".txt",ifstream::in);
        while(in>>ip){
            hashtable[ip]++;
        }
        ofstream out(to_string(i)+".txt",ofstream::out);
        for(auto ht:hashtable){
            ip=ht.first;
            cnt=ht.second;
            out<<ip<<" "<<cnt<<endl;
        }
    }
}
void topK(int n,int k){
    typedef pair<string,int> T;
    auto cmp=[](const T &a,const T &b){
        if(a.second==b.second) 
            return a.first<b.first;
        return a.second>b.second;
        };
    priority_queue<T,vector<T>,decltype(cmp)> heap(cmp);
    string ip;
    int cnt;
    for(int i=0;i<n;i++){
        ifstream in(to_string(i)+".txt",ifstream::in);
        while(in>>ip>>cnt){
            if(heap.empty()||cnt>=heap.top().second)
                heap.push(make_pair(ip,cnt));
            if(heap.size()>k)
                heap.pop();
        }
    }

    ofstream out("out.txt",ofstream::out);
    while(!heap.empty()){
        cout<<heap.top().first<<" "<<heap.top().second<<endl;
        heap.pop();
    }
}
int main(){
    string filename="data.txt";
    // gen_ip(100000000,filename);

    // thread read_t(read,filename);
    // thread deal_t(deal,100);
    // read_t.join();
    // deal_t.join();

    // count(100);

    topK(100,10);

}
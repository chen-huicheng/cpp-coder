#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
class threadpoll
{
public:
    typedef function<void()> Func;
    threadpoll(int threadnum, uint32_t maxque);
    ~threadpoll();
    bool append(Func);

private:
    Func thread_run = [this](){
        Func func;
        while(!stop){
            {
                unique_lock<mutex> lock(mutex_);
                cond_.wait(lock);
            }
            while(!stop){
                {
                    unique_lock<mutex> lock(mutex_);
                    if(queue_.size()==0)continue;
                    func=queue_.front();
                    queue_.pop_front();
                }
                func();
            }
        }
    };
    uint32_t maxque_;
    list<Func> queue_;
    mutex mutex_;
    condition_variable cond_;
    bool stop;
};
threadpoll::threadpoll(int threadnum, uint32_t maxque) : maxque_(maxque), stop(false)
{
    pthread_t tid;
    for (int i = 0; i < threadnum; i++)
    {
        thread t(thread_run);
        t.detach();
    }
}
threadpoll::~threadpoll()
{
    queue_.clear();
    stop = true;
    cond_.notify_all();
}
bool threadpoll::append(Func func)
{
    unique_lock<mutex> lock(mutex_);
    if (queue_.size() > maxque_)
    {
        return false;
    }
    queue_.push_back(func);
    cond_.notify_all();
    return true;
}

mutex mut;
static int cnt=0;
void add(){
    lock_guard<mutex> lock(mut);
    ++cnt;
}
void sub(){
    lock_guard<mutex> lock(mut);
    --cnt;
}

int main()
{
    int threadnum=10;
    int request=100000;
    threadpoll poll(8, 100000);
    int count_add=0;
    for(int i=0;i<100;i++){
        poll.append(add);
        count_add++;
    }
    cout<<cnt<<" "<<count_add<<endl;
    while(count_add>0){
        count_add--;
        poll.append(sub);
    }
    sleep(4);
    cout<<cnt<<" "<<count_add<<endl;
}
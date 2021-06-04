#include <iostream>
#include <list>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <memory>
using namespace std;
class locker
{
public:
    locker()
    {
        pthread_mutex_init(&mutex, NULL);
    }
    ~locker()
    {
        pthread_mutex_destroy(&mutex);
    }
    void lock()
    {
        pthread_mutex_lock(&mutex);
    }
    void unlock()
    {
        pthread_mutex_unlock(&mutex);
    }
    pthread_mutex_t *get()
    {
        return &mutex;
    }

private:
    pthread_mutex_t mutex;
};
class cond
{
public:
    cond()
    {
        pthread_cond_init(&con, nullptr);
        pthread_mutex_init(&mutex, NULL);
    }
    ~cond()
    {
        pthread_cond_destroy(&con);
        pthread_mutex_destroy(&mutex);
    }
    void wait()
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&con, &mutex);
        pthread_mutex_unlock(&mutex);
    }
    void signal()
    {
        pthread_cond_broadcast(&con);
    }

private:
    pthread_cond_t con;
    pthread_mutex_t mutex;
};

template <typename T>
class threadpoll
{
public:
    threadpoll(int threadnum, uint32_t maxque);
    ~threadpoll();
    bool append(shared_ptr<T> user);

private:
    static void *work(void *);
    void *run();
    uint32_t maxque_;
    list<shared_ptr<T>> queue_;
    locker mutex_;
    cond cond_;
    bool stop;
};
template <typename T>
threadpoll<T>::threadpoll(int threadnum, uint32_t maxque) : maxque_(maxque), stop(false)
{
    pthread_t tid;
    for (int i = 0; i < threadnum; i++)
    {
        pthread_create(&tid, nullptr, work, this);
        if (tid < 0)
        {
            abort();
        }
        if (pthread_detach(tid) < 0)
        {
            abort();
        }
    }
}
template <typename T>
threadpoll<T>::~threadpoll()
{
    queue_.clear();
    stop = true;
    cond_.signal();
}
template <typename T>
bool threadpoll<T>::append(shared_ptr<T> user)
{
    mutex_.lock();
    if (queue_.size() > maxque_)
    {
        mutex_.unlock();
        return false;
    }
    queue_.push_back(user);
    mutex_.unlock();
    cond_.signal();
    return true;
}
template <typename T>
void *threadpoll<T>::work(void *arg)
{
    threadpoll<T> *thpoll = (threadpoll<T> *)arg;
    thpoll->run();
}
template <typename T>
void *threadpoll<T>::run()
{
    shared_ptr<T> user;
    while (!stop)
    {
        cond_.wait();
        while (!stop)
        {
            mutex_.lock();
            if (queue_.size() <= 0)
            {
                mutex_.unlock();
                break;
            }
            // printf("%d\n",queue_.size());
            user = queue_.front();
            queue_.pop_front();
            mutex_.unlock();
            user->run();
        }
    }
}

class User
{
public:
    static int count;
    User(int val) : value(val) {}
    void run()
    {
        printf("value:%d\n", value);
        mutex.lock();
        count++;
        mutex.unlock();
    }

private:
    static locker mutex;
    int value;
};
int User::count = 0;
locker User::mutex;

void *productor(void *arg){
    threadpoll<User>* poll=(threadpoll<User>*)arg;
    for (int i = 0; i < 10000; i++)
    {
        shared_ptr<User> user = make_shared<User>(i);
        while(!poll->append(user))
            usleep(2);
    }
    sleep(3);
    for (int i = 0; i < 10000; i++)
    {
        shared_ptr<User> user = make_shared<User>(i);
        while(!poll->append(user))
            usleep(2);
    }
}

int main()
{
    int threadnum=10;
    int request=100000;
    threadpoll<User> *thpoll=new threadpoll<User>(8, 100000);
    vector<pthread_t> tids;
    for(int i=0;i<threadnum;i++){
        pthread_t tid;
        pthread_create(&tid,NULL,productor,thpoll);
        if(tid<0){
            abort();
        }
        tids.push_back(tid);
    }
    for(auto tid:tids){
        pthread_join(tid,NULL);
    }
    sleep(3);
    printf("%d\n",User::count);
}
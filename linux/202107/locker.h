#ifndef WEBSERVER_LOCKER_H_
#define WEBSERVER_LOCKER_H_
#include <exception>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
/* 封装信号量的类 */
class Sem 
{
public:
    //初始化一个为0的信号量
    Sem()
    {
        if (sem_init(&m_sem, 0, 0) != 0)
        {
            throw std::exception();
        }
    }
    //初始化一个为value的信号量
    Sem(int value)
    {
        if (sem_init(&m_sem, 0, value) != 0)
        {
            throw std::exception();
        }
    }
    ~Sem()
    {
        sem_destroy(&m_sem);
    }
    bool wait()
    {
        return sem_wait(&m_sem) == 0;
    }
    bool trywait()
    {
        return sem_trywait(&m_sem) == 0;
    }
    bool post()
    {
        return sem_post(&m_sem) == 0;
    }

private:
    sem_t m_sem;
};

/* 封装互斥锁的类 */
class Locker 
{
public:
    Locker()
    {
        if (pthread_mutex_init(&m_mutex, NULL) != 0)
        {
            throw std::exception();
        }
    }
    ~Locker()
    {
        pthread_mutex_destroy(&m_mutex);
    }
    bool lock()
    {
        return pthread_mutex_lock(&m_mutex) == 0;
    }
    //如果目标可以加锁，对目标加锁，不能加锁返回false
    bool trylock()
    {
        return pthread_mutex_trylock(&m_mutex) == 0;
    }
    bool unlock()
    {
        return pthread_mutex_unlock(&m_mutex) == 0;
    }

private:
    pthread_mutex_t m_mutex;
};
/* 封装条件变量的类 */
class Cond
{
public:
    Cond()
    {
        if (pthread_mutex_init(&m_mutex, NULL) != 0)
        {
            throw std::exception();
        }
        if (pthread_cond_init(&m_cond, NULL) != 0)
        {
            pthread_mutex_destroy(&m_mutex);
            throw std::exception();
        }
    }
    ~Cond()
    {
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_cond);
    }
    bool wait()
    {
        int ret = 0;
        pthread_mutex_lock(&m_mutex);
        ret = pthread_cond_wait(&m_cond, &m_mutex);
        pthread_mutex_unlock(&m_mutex);
        return ret == 0;
    }
    bool signal()
    {
        return pthread_cond_signal(&m_cond) == 0;
    }
    bool broadcast()
    {
        return pthread_cond_broadcast(&m_cond) == 0;
    }

private:
    pthread_cond_t m_cond;
    pthread_mutex_t m_mutex;
};

class MutexLockGuard 
{
public:
    explicit MutexLockGuard(Locker &_mutex) : mutex(_mutex) { mutex.lock(); }
    ~MutexLockGuard() { mutex.unlock(); }
private:
    Locker &mutex;
};
#endif //WEBSERVER_LOCKER_H_
#include<pthread.h>

class Foo {
public:
    Foo() {
        pthread_mutex_init(&theMutex, NULL);
        now=0;
    }
    ~Foo() {
    	pthread_mutex_destroy(&theMutex);
	}

    void first(function<void()> printFirst) {
        pthread_mutex_lock(&theMutex);
		// printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        now=1;
        pthread_mutex_unlock(&theMutex);
    }

    void second(function<void()> printSecond) {
        while(1){
	        pthread_mutex_lock(&theMutex);
	        if(now==1)break;
	        pthread_mutex_unlock(&theMutex);
		};
		// printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        now=2;
        pthread_mutex_unlock(&theMutex);
    }

    void third(function<void()> printThird) {
        while(1){
		    pthread_mutex_lock(&theMutex);
		    if(now==2)break;
		    pthread_mutex_unlock(&theMutex);
		};
		// printThird() outputs "third". Do not change or remove this line.
        printThird();
        pthread_mutex_unlock(&theMutex);
    }
    
private:
	pthread_mutex_t theMutex;
	int now;
};

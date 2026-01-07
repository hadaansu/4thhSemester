#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

#define N 5  // number of philosophers

sem_t forks[N]; // one semaphore per fork
    // limits number of philosophers

void* philosopher(void* num) {
    int id = *(int*)num;

    for (int i = 0; i < 3; i++) { // each philosopher eats 3 times
        cout << "Philosopher " << id << " is thinking\n";
        sleep(1);

        // enter room (at most N-1 philosophers can try to eat)

        // pick up forks
        sem_wait(&forks[id]);              // pick left fork
        sem_wait(&forks[(id + 1) % N]);    // pick right fork

        cout << "Philosopher " << id << " is eating\n";
        sleep(2);

        // put down forks
        sem_post(&forks[id]);              
        sem_post(&forks[(id + 1) % N]);

        // leave room


        cout << "Philosopher " << id << " finished eating\n";
    }
    return NULL;
}

int main() {
    pthread_t tid[N];
    int phil_id[N];

    // initialize semaphores
    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

 // allow at most N-1 philosophers

    // create philosopher threads
    for (int i = 0; i < N; i++) {
        phil_id[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil_id[i]);
    }

    // wait for all philosophers to finish
    for (int i = 0; i < N; i++)
        pthread_join(tid[i], NULL);

    // destroy semaphores
    for (int i = 0; i < N; i++)
        sem_destroy(&forks[i]);


    return 0;
}

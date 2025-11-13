#include <stdint.h>
#include <stddef.h>
extern void context_switch(void* oldt, void* newt);
#define MAXTASKS 4
typedef struct { uint64_t rsp; uint64_t rip; int alive; uint8_t stack[4096]; } task_t;
static task_t tasks[MAXTASKS];
static int cur = -1;
void task_func1(void){
    extern void console_write_str(const char*);
    while(1){
        console_write_str("[T1] Hello from task1\n");
        for(volatile int i=0;i<10000000;i++);
    }
}
void task_func2(void){
    extern void console_write_str(const char*);
    while(1){
        console_write_str("[T2] Hello from task2\n");
        for(volatile int i=0;i<10000000;i++);
    }
}
void scheduler_init_and_start(void){
    // init two tasks
    for(int i=0;i<MAXTASKS;i++) tasks[i].alive=0;
    // task 0
    tasks[0].alive=1;
    tasks[0].rip = (uint64_t)task_func1;
    tasks[0].rsp = (uint64_t)&tasks[0].stack[4096-1];
    // task 1
    tasks[1].alive=1;
    tasks[1].rip = (uint64_t)task_func2;
    tasks[1].rsp = (uint64_t)&tasks[1].stack[4096-1];
    cur = 0;
    // create fake old task struct on stack for starting
    static uint64_t oldt[2];
    // jump into first task by doing a context_switch from oldt to tasks[0]
    context_switch(oldt, &tasks[0]);
    // should never return
    while(1) asm volatile("hlt");
}
void scheduler_tick(void){
    int next = (cur+1)%2;
    int prev = cur;
    cur = next;
    context_switch(&tasks[prev], &tasks[next]);
}

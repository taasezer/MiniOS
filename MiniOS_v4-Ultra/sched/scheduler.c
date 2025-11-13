#include <stdint.h>
extern void context_switch(void* oldt, void* newt);
#define MAX_TASKS 4
typedef struct { uint64_t rsp; uint64_t rip; int alive; uint8_t stack[4096]; } task_t;
static task_t tasks[MAX_TASKS];
static int cur = -1;
void task_fn1(void){ extern void console_write_str(const char*); while(1){ console_write_str("[TASK1]\n"); for(volatile int i=0;i<10000000;i++); } }
void task_fn2(void){ extern void console_write_str(const char*); while(1){ console_write_str("[TASK2]\n"); for(volatile int i=0;i<10000000;i++); } }
void scheduler_init(void){
    for(int i=0;i<MAX_TASKS;i++) tasks[i].alive=0;
    tasks[0].alive=1; tasks[0].rip=(uint64_t)task_fn1; tasks[0].rsp=(uint64_t)&tasks[0].stack[4095];
    tasks[1].alive=1; tasks[1].rip=(uint64_t)task_fn2; tasks[1].rsp=(uint64_t)&tasks[1].stack[4095];
    cur = 0;
}
void scheduler_tick(void){
    int next = (cur+1)%2;
    int prev = cur;
    cur = next;
    context_switch(&tasks[prev], &tasks[next]);
}

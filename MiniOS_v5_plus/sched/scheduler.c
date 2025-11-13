#include <stdint.h>
extern void context_switch_fx(void* oldt, void* newt);
#define MAXTASKS 4
typedef struct { uint64_t rsp; uint64_t rip; uint8_t fx[512]; uint8_t stack[4096]; } task_t;
static task_t tasks[MAXTASKS];
static int cur=-1;
void task1(void){ extern void console_write_str(const char*); while(1){ console_write_str("[T1]\n"); for(volatile int i=0;i<5000000;i++); } }
void task2(void){ extern void console_write_str(const char*); while(1){ console_write_str("[T2]\n"); for(volatile int i=0;i<5000000;i++); } }
void scheduler_init(void){
    for(int i=0;i<MAXTASKS;i++) tasks[i].rsp=0;
    tasks[0].rip=(uint64_t)task1; tasks[0].rsp=(uint64_t)&tasks[0].stack[4096-16];
    tasks[1].rip=(uint64_t)task2; tasks[1].rsp=(uint64_t)&tasks[1].stack[4096-16];
    cur = 0;
    static uint64_t oldt[2];
    context_switch_fx(oldt, &tasks[0]);
}
void scheduler_tick(void){
    int next=(cur+1)%2; int prev=cur; cur=next; context_switch_fx(&tasks[prev], &tasks[next]); 
}

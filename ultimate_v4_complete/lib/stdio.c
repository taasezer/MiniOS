#include <stdarg.h>
extern void console_write_str(const char*);
static char buf[32];
static void itoa(long v, char* b){ char t[32]; int i=0; int neg=v<0; if(neg) v=-v; if(v==0) t[i++]='0'; while(v){ t[i++]= '0'+(v%10); v/=10;} if(neg) t[i++]='-'; int j=0; while(i) b[j++]=t[--i]; b[j]=0; }
void printf(const char* fmt, ...){ va_list ap; va_start(ap,fmt); const char* p=fmt; while(*p){ if(*p=='%'){ p++; if(*p=='s'){ char* s = va_arg(ap,char*); console_write_str(s);} else if(*p=='d'){ int d = va_arg(ap,int); itoa(d,buf); console_write_str(buf);} p++; continue;} char c[2]={*p,0}; console_write_str(c); p++; } va_end(ap); }

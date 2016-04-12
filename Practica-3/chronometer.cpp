#include "chronometer.h"

Chronometer::Chronometer(int OS)
{
 this->executing_chrono=false;
 switchOS(&isWindows,OS);
 this->isWindows=true;
}
Chronometer::~Chronometer(){
    delete this;
}
/*
Precondicones para windows:
Library Kernel32.lib
DLL Kernel32.dld
*/
void Chronometer::init(){
     if(isWindows)
        QueryPerformanceCounter(&t_ini);
     else
         gettimeofday(&t_ini_u, NULL);
    executing_chrono=true;
}
double Chronometer::end(){
    if(!executing_chrono) return -1;
    if(isWindows)
        QueryPerformanceCounter(&t_fin);
    else
        gettimeofday(&t_fin_u, NULL);

    executing_chrono=false;

    if(isWindows)
        return performancecounter_diff(&t_ini,&t_fin);
    else
        return timeval_diff(&t_ini_u,&t_fin_u);
}
double Chronometer::performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b){
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(b->QuadPart - a->QuadPart) / (double)freq.QuadPart;
}
double Chronometer::timeval_diff(struct timeval *a, struct timeval *b){
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}
void Chronometer::switchOS(bool * isWindows, int OS){
    if(OS==0)
        *isWindows=true;
    else
        *isWindows=false;
}

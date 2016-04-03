#include "chronometer.h"

Chronometer::Chronometer()
{
 this->executing_chrono=false;
 switchOS(&isWindows);
 this->isWindows=true;
}
Chronometer::~Chronometer(){
    delete this;
}

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
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
double Chronometer::timeval_diff(struct timeval *a, struct timeval *b){
  return
    (double)(a->tv_sec + (double)a->tv_usec/1000000) - (double)(b->tv_sec + (double)b->tv_usec/1000000);
}
void Chronometer::switchOS(bool * isWindows){
    *isWindows=true;
}

#include "../../include/MySimpleComputer.h"

MySimpleComputer* globalPC = nullptr;

void MySimpleComputer::stopHandler(int signal)
{
    if (globalPC) {
        globalPC->newTimer.it_interval.tv_sec = 0;
        globalPC->newTimer.it_interval.tv_usec = 0;
        globalPC->newTimer.it_value.tv_sec = 0;
        globalPC->newTimer.it_value.tv_usec = 0;
        globalPC->sc_regSet(IGNORE_IMPULS, 1);
        globalPC->rk_switchecho();
        setitimer(ITIMER_REAL, &globalPC->newTimer, &globalPC->oldTimer);
    }
    globalPC = nullptr;
}
void MySimpleComputer::runHandler(int signal)
{
    itimerval timerTMP{};
    getitimer(ITIMER_REAL, &timerTMP);
    if (globalPC->instructionCounter != 99) {
        ++globalPC->instructionCounter;
        if (timerTMP.it_interval.tv_sec == 0) {
            MySimpleComputer* pc = globalPC;
            stopHandler(0);
            pc->DrawAll();
        } else
            globalPC->DrawAll();
    } else {
        MySimpleComputer* pc = globalPC;
        stopHandler(0);
        pc->DrawAll();
    }
}
void MySimpleComputer::oneStep()
{
    rk_switchecho();
    globalPC = this;
    sc_regSet(IGNORE_IMPULS, 0);
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 1;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
void MySimpleComputer::runEachMemory()
{
    rk_switchecho();
    globalPC = this;
    sc_regSet(IGNORE_IMPULS, 0);
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 1;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 1;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
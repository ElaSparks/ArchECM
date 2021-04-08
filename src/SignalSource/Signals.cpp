#include "../../include/MySimpleComputer.h"

MySimpleComputer* globalPC = nullptr;

void MySimpleComputer::stopHandler(int signal)
{
    globalPC->newTimer.it_interval.tv_sec = 0;
    globalPC->newTimer.it_interval.tv_usec = 0;
    globalPC->newTimer.it_value.tv_sec = 0;
    globalPC->newTimer.it_value.tv_usec = 0;
    globalPC->sc_regSet(IGNORE_IMPULS, 1);
    globalPC->rk_switchecho();
    setitimer(ITIMER_REAL, &globalPC->newTimer, &globalPC->oldTimer);
}
void MySimpleComputer::runHandler(int signal)
{
    itimerval timerTMP{};
    getitimer(ITIMER_REAL, &timerTMP);
    if (globalPC->instructionCounter != 99) {
        ++globalPC->instructionCounter;
        if (timerTMP.it_interval.tv_sec == 0) {
            stopHandler(0);
        }
        globalPC->DrawAll();
    } else {
        stopHandler(0);
        globalPC->DrawAll();
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
{ //сделать Эхо чтобы во время проги ввседенные символы не сыпались в терминал
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
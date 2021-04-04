#include "../../include/MySimpleComputer.h"

MySimpleComputer* globalPC = nullptr;

void MySimpleComputer::stopHandler(int signal)
{
    globalPC->newTimer.it_interval.tv_sec = 0;
    globalPC->newTimer.it_interval.tv_usec = 0;
    globalPC->newTimer.it_value.tv_sec = 0;
    globalPC->newTimer.it_value.tv_usec = 0;
    globalPC->sc_regSet(IGNORE_IMPULS, 1);
    setitimer(ITIMER_REAL, &globalPC->newTimer, &globalPC->oldTimer);
}
void MySimpleComputer::runHandler(int signal)
{
    if (globalPC->instructionCounter != 99) {
        globalPC->DrawAll();
        ++globalPC->instructionCounter;
    } else {
        globalPC->DrawAll();
        stopHandler(0);
    }
}
void MySimpleComputer::oneStep()
{
    globalPC = this;
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 0;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 1;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
void MySimpleComputer::runEachMemory()
{ //сделать Эхо чтобы во время проги ввседенные символы не сыпались в терминал
    globalPC = this;
    sc_regSet(IGNORE_IMPULS, 0);
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 1;
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 1;
    newTimer.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
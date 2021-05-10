#include "../../include/MySimpleComputer.h"

MySimpleComputer* globalPC = nullptr; // reference of this object

void MySimpleComputer::stopHandler(int signal)
{
    if (globalPC) {
        globalPC->newTimer.it_interval.tv_sec = 0;
        globalPC->newTimer.it_interval.tv_usec = 0;
        globalPC->newTimer.it_value.tv_sec = 0;
        globalPC->newTimer.it_value.tv_usec = 0; // disable timer
        globalPC->registerSet(IGNORE_IMPULSE, 1);
        globalPC->rk_switchecho(); // enable output symbols
        setitimer(ITIMER_REAL, &globalPC->newTimer, &globalPC->oldTimer);
    }
    globalPC = nullptr;
}
void MySimpleComputer::runHandler(int signal)
{
    itimerval timerTMP{};                     // var for check step or run
    globalPC->flagsLO = globalPC->flags;      // remind last state of flags
    globalPC->sc_regInit();                   // clean flags
    getitimer(ITIMER_REAL, &timerTMP);        // get currently used timer
    if (globalPC->instructionCounter != 99) { // isn`t end of mem
        globalPC->controlUnit();              // activate CU
        if (globalPC->flags != 0) {           // if bad command
            MySimpleComputer* pc = globalPC;
            stopHandler(0);
            pc->DrawAll();
            return;
        }
        if (!globalPC->jump) {
            ++globalPC->instructionCounter; // goto next
        } else {
            globalPC->jump = false;
        }
        if (timerTMP.it_interval.tv_usec == 0) { // is step?
            MySimpleComputer* pc = globalPC;
            stopHandler(0);
            pc->DrawAll();
        } else
            globalPC->DrawAll();
    } else { // end of the mem
        MySimpleComputer* pc = globalPC;
        stopHandler(0);
        pc->DrawAll();
    }
}
void MySimpleComputer::oneStep()
{
    rk_switchecho(); // disable output symbol
    globalPC = this;
    registerSet(IGNORE_IMPULSE, 0); // disable switch key body
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 0; // set timer
    newTimer.it_interval.tv_usec = 0;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 15000;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
void MySimpleComputer::runEachMemory()
{
    rk_switchecho(); // disable output symbol
    globalPC = this;
    registerSet(IGNORE_IMPULSE, 0); // disable switch key body
    signal(SIGALRM, runHandler);
    newTimer.it_interval.tv_sec = 0; // set timer
    newTimer.it_interval.tv_usec = 15000;
    newTimer.it_value.tv_sec = 0;
    newTimer.it_value.tv_usec = 15000;
    setitimer(ITIMER_REAL, &newTimer, &oldTimer);
}
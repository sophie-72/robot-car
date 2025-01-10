#ifndef SHAREDTRIGGER_H
#define SHAREDTRIGGER_H

class SharedTrigger {
    int triggerPin;

public:
    explicit SharedTrigger(int triggerPin);

    void triggerSensors() const;
};


#endif //SHAREDTRIGGER_H

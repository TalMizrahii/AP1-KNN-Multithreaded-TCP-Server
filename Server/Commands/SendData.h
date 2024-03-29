
#ifndef EX4_SENDDATA_H
#define EX4_SENDDATA_H

#include "Commander.h"

/**
 * This class responsible to send the data to the client.
 */
class SendData : public Commander {
public:
    // This method send classify data to the client (if the data exist), otherwise an error.
    void execute() override;

    // sending the result data after the classification.
    SendData(string description, AbstractDefaultIO *Dio, RelativeDatabase *database);

};

#endif //EX4_SENDDATA_H

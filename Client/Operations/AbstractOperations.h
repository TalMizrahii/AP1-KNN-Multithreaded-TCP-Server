#ifndef EX4_ABSTRACTOPERATIONS_H
#define EX4_ABSTRACTOPERATIONS_H

#include <IO/AbstractDefaultIO.h>
#include "Client/DataAndCalcs/ClientValidation.h"

class AbstractOperations {
public:
    explicit AbstractOperations(AbstractDefaultIO *defaultIo);

    ~AbstractOperations();

    virtual void executeOp() = 0;

    void setDio(AbstractDefaultIO *defaultIo);

    AbstractDefaultIO *getDio();

    string userInput();

protected:
    AbstractDefaultIO *dio;
    ClientValidations clientValidations;
};

#endif //EX4_ABSTRACTOPERATIONS_H

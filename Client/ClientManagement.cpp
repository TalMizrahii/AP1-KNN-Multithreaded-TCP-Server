#include "ClientManagement.h"

/**
 * A default constructor.
 */
ClientManagement::ClientManagement() = default;

/**
 * A default destructor.
 */
ClientManagement::~ClientManagement() = default;

/**
 * A constructor who receives a default io pointer.
 * @param dio The default io pointer.
 */
ClientManagement::ClientManagement(AbstractDefaultIO *dio) {
    setDefaultIO(dio);
}

/**
 * A getter for the DIO.
 * @return The DIO pointer of type AbstractDefaultIO.
 */
AbstractDefaultIO *ClientManagement::getDefaultIO() {
    return this->defaultIo;
}

/**
 * A setter for the default io.
 * @param dio The dio member of the class.
 */
void ClientManagement::setDefaultIO(AbstractDefaultIO *dio) {
    this->defaultIo = dio;
}

/**
 * Reading the user's input.
 * @return The user's input.
 */
string ClientManagement::userInput() {
    string line;
    getline(cin, line);
    return line;
}

/**
 * This method starts the client's operation with the server.
 */
void ClientManagement::start() {
    while (true) {
        string menu = getDefaultIO()->read();
        if (!menuManagement(menu)) {
            return;
        }
    }
}

/**
 * Printing the menu and managing the menu choice of the client.
 * @return The client's choice from the menu.
 */
bool ClientManagement::menuManagement(string menuStr) {
    // Print the menu.
    cout << menuStr;
    // Get the user's input.
    string line = userInput();
    if (line == "8") {
        getDefaultIO()->write(line);
        return false;
    }
    // Check if the input is a valid integer.
    if (!this->clientValidation.validI(line)) {
        // If it isn't, send it to the server making no operations.
        getDefaultIO()->write(line);
        return true;
    }
    // If the operation decided to be 3, it's just print so return.
    if (line == "3") { return true; }
    // Send to the server the choice -->> !
    AbstractOperations *op = choiceProcess(line);
    op->executeOp();
    return true;
}

/**
 * Processing what choice from the menu the user made, and (hopefully returning the choices operation).
 * @param choice The choice the user made (no manipulations made on it).
 */
AbstractOperations *ClientManagement::choiceProcess(string choice) {
    return nullptr;
}
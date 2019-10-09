#include <string>
#include <vector>

enum Command
{
    UNKNOWN,
    START,
    BEGIN,
    TURN,
    BOARD,
    END
};

class Protocol
{
public:
    std::string getNextCommand();
    Command whichCommand(const std::string &command);
private:
    const std::vector<std::string> &split(const std::string &, char delimiter)
};
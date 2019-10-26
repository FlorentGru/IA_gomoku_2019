#include "Launcher.hpp"
#include <iostream>

int Launcher::launch()
{
	const std::string& command = protocol.getNextCommand();
	Command commandType = protocol.whichCommand(command);

	if (commandType == UNKNOWN) {
//		std::cout << command << std::endl;
		protocol.unknown();
		return (0);
	}
	return (brainLaunch(command, commandType));
}

int Launcher::brainLaunch(const std::string& command, Command commandType)
{
	int size = 0;
	std::pair<int, int> coord = { -1, -1 };
	BoardArg arg = { -1, -1, -1 };

	switch (commandType) {

	case START:
		size = protocol.getStartArg(command);
		protocol.answer(brain.start(size));
		break;
	case BEGIN:
		protocol.answer(brain.begin());
		break;
	case TURN:
		coord = protocol.getTurnArg(command);
		protocol.answer(brain.turn(coord.first, coord.second));
		break;
	case BOARD:
		launchBoard();
		break;
	case END:
		brain.end();
		return (1);
	}

	return 0;
}

int Launcher::launchBoard()
{
    std::string command = protocol.getNextCommand();

    brain.start(BOARD_SIZE);
    while (command != "DONE") {
        BoardArg args = protocol.getBoardArg(command);
        brain.board(args.x, args.y, args.player);
        command = protocol.getNextCommand();
    }
    protocol.answer(brain.boardPlay());
    return (0);
}

# Gomoku AI

Epitech 2019 project: a Gomoku (five in a row) AI in C++ that speaks the [Piskvork](https://plastovicka.github.io/protocl2en.htm) `pbrain` protocol on stdin/stdout, so it can be plugged into the Piskvork manager and play against other bots.

- Protocol commands: `START`, `BEGIN`, `TURN`, `BOARD`, `INFO`, `END`
- Strategy: scores every empty cell near existing stones with a pattern heuristic (lines of 1 to 4, own vs. opponent) and plays the best one, attacking or blocking

## Build & run

```bash
make
./pbrain-gomoku-ai
```

Unit tests are in `unit_tests/` (`make -C unit_tests`).

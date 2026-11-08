# 🏎️ Terminal Racing Engine — C Systems Game Loop

A high-performance, grid-based vehicle routing and state engine written in pure C. Designed with a modular architecture separating matrix coordination, directional vector translation, and wall collision logic from presentation layers.

---

## 🚀 Architectural Overview

- **Engine Core (`race.c`)**: Native C implementation managing a `13x30` track matrix grid.
- **State & Memory Management**: Utilizes custom coordinate structs (`struct car`) for real-time player positioning and heading vector tracking.
- **Collision Grid Mapping**: Precomputes a secondary lookup matrix (`c[13][30]`) for instant barrier detection (`1`) and finish line validation (`2`).
- **Event Loop & Safety**: Clean state evaluation handling wall boundary collisions, win conditions at the finish line (`F`), and real-time terminal rendering via ANSI escape sequences.

---

## 🎮 Game Rules & Controls

- **Map Size**: `13x30` track bordered by walls (`#`).
- **Vehicle (`^`, `>`, `v`, `<`)**: Navigates via directional steering controls to reach the finish line (`F`).
- **Interactive Controls**:
  - `[W]` - Accelerate / move forward in current facing direction
  - `[A]` / `[D]` - Steer and rotate vehicle heading
  - `[Q]` - Terminate execution loop
- **Conditionals**:
  - **Loss**: Striking any wall boundary (`#`), triggering a collision alert and closing the engine loop.
  - **Win**: Successfully navigating to the finish line tile (`F`).

---

## 🛠️ Compilation & Execution

Clone the repository and compile the C source file using any standard C compiler (e.g., GCC):

```bash
# Clone repository
git clone [https://github.com/siddharth9234/](https://github.com/siddharth9234/)[REPOSITORY_NAME].git
cd [REPOSITORY_NAME]

# Compile the C engine
gcc race.c -o car_race

# Run the game engine
./car_race

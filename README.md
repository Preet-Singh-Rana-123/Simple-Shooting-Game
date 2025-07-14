# 🎯 Shooting Game - SFML (C++)

A simple shooting game built using **SFML** in **C++**, where the player must eliminate randomly spawning enemies by shooting them. The player can move using `W`, `A`, `S`, `D` keys and shoot using the **left mouse click**. The game ends when the player loses all 3 health bars.

---

## 🕹️ Gameplay Features

- 👾 **Enemies spawn** at random positions.
- 🔫 **Left click to shoot bullets** toward the mouse direction.
- 🎮 **W/A/S/D keys** to control the player’s movement.
- ❤️ **3 Health Bars** – lose one each time an enemy hits the player.
- 🧠 **Score System** – gain points for hitting enemies.

---

## 📁 Project Structure

```

ShootingGame/
├── Font/                     # Fonts used in the game (e.g., for UI/text)
│   └── \<font\_files.ttf>
│
├── include/
│   └── bullet.hpp            # Bullet class declaration
│
├── src/
│   ├── bullet.cpp            # Bullet class implementation
│   └── main.cpp              # Main game logic
│
├── CMakeLists.txt            # CMake build configuration
└── README.md                 # Project documentation

````

---

## ⚙️ Build Instructions

### ✅ Prerequisites

- **C++17** or later
- **SFML 2.5+**
- **CMake** (for building)

### 🛠️ Build Using CMake

```bash
mkdir build
cd build
cmake ..
make
./ShootingGame
````

> Ensure SFML is installed and linked properly on your system.

---

## 🎮 Controls

| Action     | Key/Mouse        |
| ---------- | ---------------- |
| Move Up    | `W`              |
| Move Down  | `S`              |
| Move Left  | `A`              |
| Move Right | `D`              |
| Shoot      | Left Mouse Click |

---

## 🎯 Game Objective

* Eliminate as many enemies as possible.
* Each enemy hit gives you points.
* Avoid getting hit – you only have **3 health bars**.
* Game ends when health reaches **0**.

---

## 📚 Dependencies

* [SFML (Simple and Fast Multimedia Library)](https://www.sfml-dev.org/)
* Standard C++ Libraries

---

## 📄 License

This project is open-source under the **MIT License**. Feel free to use, modify, and share.

---

Happy Shooting! 🔥

# CubeSystemTreePlugin

**CubeSystemTreePlugin** is a plugin for **CubeGUI** that dynamically extracts and visualizes system tree data from a loaded `.cubex` performance report. It formats this tree into readable JSON and displays it in a scrollable tab inside the GUI, helping users understand the system's structure and hierarchy more clearly.

---

## 🚀 Features

- 🔍 Parses the system tree from the currently opened `.cubex` file
- 📄 Converts system structure to a formatted JSON representation
- 🧩 Embeds the JSON output into a dedicated "System" tab in CubeGUI
- 📜 Read-only scrollable view for inspection or documentation
- ♻️ Automatically adapts to different `.cubex` files with varying structures

---

## 🛠️ Getting Started

### ✅ Prerequisites

- [CubeGUI](https://www.scalasca.org/software/cube-4.x/download.html) with plugin support
- Qt 5 or 6 (`Core`, `Gui`, `Widgets` modules)
- CMake
- C++17 compatible compiler

---

## ⚙️ Build Instructions

```bash
git clone git@github.com:Emin-Mammadov/CubeSystemTreePlugin.git
cd CubeSystemTreePlugin

mkdir build && cd build
cmake ..
make

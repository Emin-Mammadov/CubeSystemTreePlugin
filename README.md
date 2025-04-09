# CubeSystemTreePlugin

**CubeSystemTreePlugin** is a plugin for **CubeGUI** that visualizes system tree data from a JSON file in an interactive tree widget. It provides a hierarchical view of system nodes and their descriptions, enabling a more intuitive understanding of system structure within the Cube performance analysis tool.

---

## 🚀 Features

- 📁 Parses and loads hierarchical system tree data from a JSON file.
- 🌳 Displays the tree using a collapsible `QTreeWidget`.
- 🔁 Supports recursive child nodes for complex trees.
- 🧩 Integrates seamlessly as a new tab in CubeGUI.

---

## 🛠️ Getting Started

### ✅ Prerequisites

- [CubeGUI](https://www.scalasca.org/software/cube-4.x/download.html) with plugin support
- Qt 5 or 6 (for GUI rendering)
- C++17 or higher
- Optional: `CMake` (if you use it to build the plugin)

---

### 🧪 Build Instructions

```bash
# Clone the repository
git clone git@github.com:Emin-Mammadov/CubeSystemTreePlugin.git
cd CubeSystemTreePlugin

# Build and install steps depend on your integration with CubeGUI.
# You can use qmake, cmake, or integrate it directly with Cube's build system.

### Expected JSON Structure

The plugin expects a JSON file named `system_tree.json` with the following structure:

```json
{
  "nodes": [
    {
      "name": "Root Node",
      "description": "This is the root of the system tree.",
      "children": [
        {
          "name": "Child Node 1",
          "description": "First child node",
          "children": []
        },
        {
          "name": "Child Node 2",
          "description": "Second child node",
          "children": [
            {
              "name": "Grandchild Node",
              "description": "A node under Child Node 2"
            }
          ]
        }
      ]
    }
  ]
} 
Each node in the JSON can optionally contain a "children" array to define sub-nodes, allowing for a recursive system tree structure.

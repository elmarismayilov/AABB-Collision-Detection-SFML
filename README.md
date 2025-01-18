# SFML AABB Collision Demo
A simple demonstration of Axis-Aligned Bounding Box (AABB) collision detection implemented using SFML graphics library.

## Overview
This project showcases a basic implementation of AABB collision detection between two rectangles. The white rectangle can be controlled by the player using WASD keys, and it changes the yellow rectangle's color to red upon collision.

## Features
- Smooth player movement with normalized directional vectors
- Frame-rate independent motion using delta time
- Real-time AABB collision detection
- Visual collision feedback through color change

## Controls
- W: Move Up
- A: Move Left
- S: Move Down
- D: Move Right

## Dependencies
- SFML 2.x
- C++ compiler with C++11 support

## Building the Project
1. Install SFML on your system
2. Compile the source code with your preferred C++ compiler
3. Link against SFML libraries (graphics, window, system)

## Implementation Details
The collision detection uses AABB (Axis-Aligned Bounding Box) algorithm, which checks for overlapping rectangles by comparing their minimum and maximum coordinates on both axes. This method is efficient for rectangular hitboxes that don't rotate.

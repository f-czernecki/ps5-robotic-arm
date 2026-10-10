## Project Overview & Motivation

This is my first robotics project, designed to explore the use of high-torque servo mechanisms for multi-axis robotic arm. The core objective was to create a simple 3-DOF robotic arm from scratch—handling everything from mechanical design and 3D printing to firmware development, hardware integration, and wireless control implementation.

### Key Learning Objectives & Scope

* **Complete Project Lifecycle:** Experience building a full project from initial idea to working prototype.
* **Hardware & Electronics:** Design 3D-printed parts, add bearings to handle mechanical loads, and set up safe power and motor control.
* **Wireless Control:** Connect a wireless controller for easy, real-time arm movement.

## Hardware & System Architecture

* **Microcontroller & Driver:** Arduino Uno sending commands over I2C to a PCA9685 PWM driver to handle motor signal generation.
* **Actuators:** High-torque PowerHD servos (LF-20MG & LF-20MG-270) powering the base, shoulder, and elbow joints.
* **Power Supply:** External bench power supply (Korad U203) delivering clean power directly to the motors.
* **Control Interface:** Sony DualSense (PS5) controller for responsive wireless movement.
* **Mechanical Structure:** Custom PLA 3D-printed links assembled using M3/M4 screws and heat-set brass inserts.
* **Load Management:**
  * **Base Joint:** Uses a lazy susan bearing to handle vertical loads and overturning moments.
  * **Shoulder & Elbow Joints:** Uses radial ball bearings to reduce friction and absorb bending forces.

> For a detailed list of all parts and hardware used, check the [Bill of Materials (BOM.md)](./BOM.md).


## What I Learned & Key Challenges

* **Servo Limitations & Torque Constraints:** Realized that standard servos limit continuous rotation and angle range, making it difficult to integrate custom gearing (like planetary gearboxes) to boost torque.
* **3D Printing & Part Splitting:** Learned how to break down complex 3D models into smaller parts so they print cleanly, require less support, and assemble securely.
* **Cable & Fastener Design:** Planned screw placement (using brass threaded inserts) and created internal channels to hide wiring and keep the assembly neat.
* **Mechanical Joint Coupling & Backlash:** Resolving how to securely attach the servo shafts to the shoulder and elbow joints took the most time. Overcame issues with joint play and backlash to ensure the arm remains rigid and stable under load.
## Future Improvements

* **Custom End-Effector:** Design and integrate a functional gripper.
* **Kinematics Implementation:** Currently learning and implementing forward and inverse kinematics to enable precise, mathematical coordinate-based control of the arm.* 
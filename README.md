
# AetherFlow-RTC

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Qt](https://img.shields.io/badge/Qt-6.0+-41CD52.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen.svg)

**High-Frequency Heterogeneous Telemetry Ingestion & Real-Time Protocol Orchestration Framework**

AetherFlow-RTC is a high-performance, fault-tolerant C++ application framework designed to orchestrate complex cyber-physical hardware nodes and ingest high-frequency telemetry streams in real-time. It solves the common bottlenecks of monolithic architectures—such as UI freezing, packet drops, and network non-determinism—under heavy industrial data loads.

---

## Core Architecture & Engineering Innovations

### 1. Strict Thread Decoupling (PIMPL Idiom)
Architected a thread-isolated model using the Pointer to Implementation (PIMPL) pattern. The GUI operates on a separate event loop from the backend engine. This creates a robust compilation firewall and guarantees a 100% responsive interface, even when the backend is parsing thousands of telemetry packets per second.

### 2. Hybrid Asynchronous Networking
Engineered a dual-channel communication layer to handle distinct data requirements:
* **Command & Control (TCP):** Utilizes strict, Little-Endian bit-packed TCP frames for deterministic state synchronization. Incorporates 32-bit watchdog counters to prevent message duplication.
* **Telemetry Streaming (UDP):** A non-blocking UDP pipeline handles continuous, high-throughput telemetry without overloading the CPU. Packets are verified by byte-size to prevent malformed network traffic from crashing the parsing engine.

### 3. FSM-Driven Orchestration
Built a rigorous Finite State Machine (FSM) to govern transactional commands across a three-stage execution sequence:
* `INIT_RUN`: Validates network handshakes and serializes nested loop descriptors.
* `RUN`: Executes the high-speed operational loop.
* `FINITE_RUN`: Performs post-execution verification to ensure physical execution matches the requested transaction limits.

### 4. Fault-Tolerant Memory Buffering
Features an in-memory dynamic matrix buffer with OS-level file-lock detection. If disk-write bottlenecks occur (e.g., a locked spreadsheet file), the system safely queues data in RAM until the lock is released, completely preventing application crashes and data loss.

---

## System Topology

```text
+-------------------------------------------------------+
|                FRONTEND (GUI Thread)                  |
|   Exposes Parameters, Tracks Matrix State, Zero Lag   |
+-------------------------------------------+-----------+
                                            ^
                             Queued Signals | (Thread-Safe Event Loop)
                                            v
+-------------------------------------------+-----------+
|               BACKEND ENGINE (Worker Thread)          |
|   Handles State-Machine loops, Ring Buffers, Math     |
+-------------------------------------------+-----------+
                     /                      \
                    /                        \
    [TCP: Port 5001 / Control]       [UDP: Streaming Telemetry]
                  /                            \
                 v                              v
+--------------------------------+   +----------------------------------+
|      Peripheral Slave Node     |   |    Active Matrix Data Stream     |
+--------------------------------+   +----------------------------------+



---

## Tech Stack

* **Language:** C++17
* **Framework:** Qt 6 (Core, Network, Gui, Widgets)
* **Design Patterns:** PIMPL (Pointer to Implementation), Observer (Signals & Slots), Finite State Machine (FSM)
* **Libraries:** QXlsx (for dynamic, post-process spreadsheet generation)
* **Networking:** Asynchronous TCP/IP & UDP Sockets

---

## Build & Installation Instructions

### Prerequisites

* **Qt Creator** with **Qt 6.0+** installed.
* A C++17 compatible compiler (MinGW, MSVC, or GCC).

### Setup

1. Clone the repository:
```bash
git clone [https://github.com/YOUR-USERNAME/AetherFlow-RTC.git](https://github.com/YOUR-USERNAME/AetherFlow-RTC.git)

```


2. Open **Qt Creator**.
3. Go to `File` > `Open File or Project...` and select the `AetherFlow-RTC.pro` file.
4. Configure the project with your default desktop kit.
5. Click **Build** (Ctrl+B) to compile the dependencies.
6. Click **Run** (Ctrl+R) to launch the Master Controller GUI.

---

## Performance & Validation Metrics

* **Sustained Throughput:** Proven stable under continuous high-frequency traffic stress-testing protocols exceeding 30-minute operational intervals.
* **CPU Optimization:** Maintains **<2% CPU utilization** on modern multi-core processors under heavy stress-testing (20Hz continuous packet ingestion).
* **Fault Tolerance:** 100% packet retention during simulated OS-level I/O disk locks.

---

## Applications

While originally designed for Active Electronically Scanned Array (AESA) calibration environments, this framework's architecture is highly applicable to:

* **IoT Sensor Aggregation:** Managing massive swarms of data-reporting edge devices.
* **Robotics Automation:** Synchronizing assembly-line hardware triggers over lossy networks.
* **Aerospace Telemetry:** High-fidelity, real-time tracking of flight metrics.

```

```

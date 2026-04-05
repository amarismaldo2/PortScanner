# PortScanner

<img width="476" height="260" alt="PortSource" src="https://github.com/user-attachments/assets/3318d491-f1ef-4ea1-9761-8098422eb0b3" />

A lightweight TCP port scanner written in C for Windows.

## Features
- Scans a user-defined range of ports on any target IP
- 500ms connection timeout per port for fast scanning
- Displays open ports in real time

## Usage
1. Compile with GCC (add `-lws2_32` linker flag)
2. Run the executable
3. Enter target IP, start port, and end port
4. Open ports will be displayed as `[OPEN] Port X`

## Example
Enter target IP: 127.0.0.1
Enter start port: 1
Enter end port: 1000

## Disclaimer
For educational purposes only. Only scan systems you own or have permission to scan.

---
Built by Amaris Maldonado © 2026

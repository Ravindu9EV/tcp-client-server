# TCP Client-Server Application

> A complete TCP client-server application implemented in C for Linux environments with socket programming

![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)
![GitHub stars](https://img.shields.io/github/stars/Ravindu9EV/tcp-client-server)
![GitHub forks](https://img.shields.io/github/forks/Ravindu9EV/tcp-client-server)
![Platform](https://img.shields.io/badge/platform-Linux-lightgrey)
![Language](https://img.shields.io/badge/language-C-green)

---

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Requirements](#-requirements)
- [Installation](#-installation)
- [Compilation](#-compilation)
- [Usage](#-usage)
- [Sample Output](#-sample-output)
- [Code Structure](#-code-structure)
- [Error Handling](#-error-handling)
- [Troubleshooting](#-troubleshooting)
- [Configuration](#-configuration)
- [Contributing](#-contributing)
- [License](#-license)
- [Author](#-author)
- [Acknowledgments](#-acknowledgments)

---

## 📖 Overview

This project demonstrates a **TCP Client-Server application** using socket programming in C. It establishes a reliable connection between a client and server, enabling bidirectional message exchange over a network. The application is designed for Linux environments and follows standard network programming practices.

### How It Works

1. **Server** starts and listens on port 8080 for incoming connections
2. **Client** connects to the server at localhost (127.0.0.1)
3. **Client** sends a message: "Hello from client!"
4. **Server** receives the message and displays it
5. **Server** responds with: "Message received by server!"
6. **Client** receives and displays the server's response
7. **Connection** is properly terminated by both parties

---

## ✨ Features

### Core Features
- ✅ **TCP Socket Communication** - Reliable, connection-oriented communication
- ✅ **IPv4 Support** - Uses standard IPv4 addressing
- ✅ **Bidirectional Messaging** - Two-way communication between client and server
- ✅ **Error Handling** - Comprehensive error checking for all system calls
- ✅ **Clean Termination** - Proper socket closure and resource cleanup

### Technical Features
- 🔧 **Configurable Port** - Easy to change port number via `#define`
- 📦 **Buffer Management** - Efficient message handling with 1024-byte buffers
- 🛡️ **Socket Reuse** - Allows immediate restart without "address in use" errors
- 📊 **Console Logging** - Clear output showing all communication steps

---

## 🛠️ Requirements

### System Requirements
| Component | Minimum Version |
|-----------|----------------|
| Operating System | Linux (Ubuntu 20.04+) |
| Compiler | GCC 9.0+ |
| Libraries | Standard C Libraries |
| Memory | 128 MB RAM |
| Disk Space | 10 MB |

### Verify Installation
```bash
# Check GCC version
gcc --version

# Check Linux version
uname -a

# Update package list
sudo apt update

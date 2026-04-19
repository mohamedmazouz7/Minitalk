<div align="center">

# 📡 Minitalk

**A signal-based inter-process communication program — send messages between processes using only UNIX signals.**

![C](https://img.shields.io/badge/language-C-blue?style=for-the-badge&logo=c)
![UNIX](https://img.shields.io/badge/signals-SIGUSR1%2FUSR2-red?style=for-the-badge)
![42](https://img.shields.io/badge/school-42-black?style=for-the-badge)
![Score](https://img.shields.io/badge/score-125%2F100-brightgreen?style=for-the-badge)

</div>

---

## 🎯 About

`Minitalk` is a lightweight inter-process communication (IPC) system using only **UNIX signals**. Learn how processes communicate at the OS level using `SIGUSR1` and `SIGUSR2` to encode and transmit data bit-by-bit.

This project teaches you **signal handling**, **bit manipulation**, **process management**, and **low-level communication protocols**.

---

## 🚀 Quick Start

### Clone & Build

```bash
git clone https://github.com/mohamedmazouz7/Minitalk Minitalk
cd Minitalk
make
```

### Run

**Terminal 1 — Start the server:**

```bash
./server
```

Output:
```
My server PID is: 12345
```

**Terminal 2 — Send a message:**

```bash
./client 12345 "Hello from Minitalk!"
```

**Server output:**
```
Hello from Minitalk!
```

---

## 🔑 How It Works

### Communication Protocol

Messages are sent bit-by-bit using signals:

- **SIGUSR1** = Binary `1`
- **SIGUSR2** = Binary `0`

**Example: Sending character 'A' (ASCII 65 = `01000001`)**

```
Client sends 8 signals to server:
0 → SIGUSR2
1 → SIGUSR1
0 → SIGUSR2
0 → SIGUSR2
0 → SIGUSR2
0 → SIGUSR2
0 → SIGUSR2
1 → SIGUSR1

Server receives bits: 01000001 = 'A' → prints 'A'
```

### Signal Flow

```
┌─────────────┐                    ┌─────────────┐
│   CLIENT    │                    │   SERVER    │
├─────────────┤                    ├─────────────┤
│  PID: 9999  │ ──→ SIGUSR1 ──→   │  PID: 12345 │
│  Message    │ ──→ SIGUSR2 ──→   │  Listens    │
│             │ ──→ SIGUSR1 ──→   │  Decodes    │
│             │ ──→ SIGUSR2 ──→   │  Prints     │
└─────────────┘                    └─────────────┘
```

---

## 💡 Usage Examples

### Basic Message

```bash
# Terminal 1
./server

# Terminal 2
./client 12345 "Hi"
```

Output on server:
```
Hi
```

### Longer Message

```bash
./client 12345 "This is a longer message with spaces!"
```

### Multiple Clients

The server handles multiple clients sequentially:

```bash
# Terminal 2
./client 12345 "Client 1"

# Terminal 3
./client 12345 "Client 2"

# Terminal 4
./client 12345 "Client 3"
```

All messages appear on server without restart.

---

## 🛠️ Build Options

### Standard Build

```bash
make
```

Creates `server` and `client` executables.

### Build with Bonus

```bash
make bonus
```

Creates `server_bonus` and `client_bonus` executables.

### Clean

```bash
make clean       # Remove object files
make fclean      # Remove executables
make re          # Full rebuild
```

---

## 📋 Mandatory Features

✅ **Server** displays PID on startup  
✅ **Client** takes server PID + message as arguments  
✅ **Signal encoding** using only SIGUSR1 and SIGUSR2  
✅ **Bit-by-bit transmission** of each character  
✅ **Fast display** (100 chars < 1 second)  
✅ **Multiple clients** supported (no server restart needed)  
✅ **Error handling** for invalid PID/message  

---

## 🚀 Bonus Features (125/100)

✨ **Server acknowledgment** — Server sends signal back to client when message received  
✨ **Unicode support** — Handle multi-byte UTF-8 characters  

---

## 🏗️ Project Architecture

### Files

| File | Purpose |
|------|---------|
| `server.c` | Listens for signals, decodes, prints messages |
| `client.c` | Sends message as signals |
| `server_bonus.c` | Enhanced server with acknowledgment |
| `client_bonus.c` | Enhanced client with acknowledgment |

### Core Algorithm

**Server:**
```
1. Print PID
2. Register signal handlers (SIGUSR1, SIGUSR2)
3. Wait for signals (infinite loop)
4. Decode bits into characters
5. Print received characters
```

**Client:**
```
1. Validate PID argument
2. Validate message argument
3. For each character:
   a. Convert to binary (8 bits)
   b. Send each bit as SIGUSR1 (1) or SIGUSR2 (0)
   c. Wait for acknowledgment (bonus)
4. Exit
```

---

## 💪 What You'll Learn

✅ **UNIX signals** — Signal handling, signal masks, sigaction()  
✅ **Process communication** — Inter-process messaging  
✅ **Bit manipulation** — Encoding/decoding binary data  
✅ **Signal handlers** — Callback functions for signal events  
✅ **PID management** — Working with process IDs  
✅ **Error handling** — Validating arguments, signal errors  
✅ **Timing & synchronization** — Managing signal delivery  
✅ **Bonus: Signal acknowledgment** — Two-way communication  

---

## ⚙️ Technical Details

### Signal Limitations

**Why only 2 signals?**
- Linux doesn't queue signals of the same type
- Multiple identical signals = lost data
- Solution: Use 2 signals (SIGUSR1 and SIGUSR2) to differentiate

**Buffer consideration:**
- Signals can be lost if server is busy
- Proper timing ensures reliable delivery

### Performance

- **Speed:** Sends at ~10,000 bits/second (typical)
- **100 characters:** < 1 second (requirement)
- **Reliable:** No message loss with proper synchronization

---

## 📝 Implementation Notes

### Server Signal Handler

```c
void ft_bit_handler(int signal)
{
    static int c = 0;        // Current character
    static int bit = 0;      // Bit counter (0-7)
    
    if (signal == SIGUSR1)
        c = (c << 1) + 1;    // Append 1
    else
        c = (c << 1) + 0;    // Append 0
    
    bit++;
    if (bit == 8)            // Got full character
    {
        printf("%c", c);     // Print it
        c = 0;
        bit = 0;
    }
}
```

### Client Bit Sender

```c
void send_binary(int pid, char *str)
{
    int i, j, bit;
    
    while (*str)
    {
        for (bit = 7; bit >= 0; bit--)
        {
            if ((*str >> bit) & 1)
                kill(pid, SIGUSR1);   // Send 1
            else
                kill(pid, SIGUSR2);   // Send 0
            usleep(100);              // Small delay
        }
        str++;
    }
}
```

---

## 🔧 Dependencies

- **UNIX/Linux system** — For signal support
- **Standard C library** — signal.h, stdlib.h, unistd.h
- **Your custom ft_printf** — For output

---

## 🚫 Constraints

- ❌ Only SIGUSR1 and SIGUSR2 allowed (no other signals)
- ❌ No global variables (except static in functions)
- ❌ No buffer beyond message transmission
- ✅ Multiple clients can connect in sequence
- ✅ Server keeps running (no restart needed)

---

## 📊 Complexity Analysis

| Operation | Complexity |
|-----------|-----------|
| Encode character to bits | O(1) — 8 bits constant |
| Send message of n chars | O(8n) = O(n) |
| Signal overhead | ~10 microseconds per signal |
| Max throughput | ~100 chars/sec typical |

---

## 🎓 Real-World Applications

- **IPC mechanisms** — Process coordination
- **Signal handling** — Event notification systems
- **Network protocols** — Bit-level data transmission
- **Embedded systems** — Low-level communication
- **Synchronization** — Coordinating concurrent processes

---

<div align="center">

**Signals speak louder than words.**

*Part of the 42 School Common Core curriculum.*

</div>

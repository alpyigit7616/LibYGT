# LibYGT
A lightweight C library for system utilities — logging, message boxes, and more.

> ⚠️ This project is under active development. APIs may change.

---

## 🚀 Features
- Colored log messages (`INFO`, `WARNING`, `ERROR`)
- Cross-platform message boxes (Windows, Linux, macOS)
- Lightweight — no heavy dependencies
- Easy to integrate into any C project


---

## 📖 Usage
```c
#include "libygt.h"

int main() {
    ly_log_message("Hello, World!");
    ly_log_warn("This is a warning!a");
    ly_log_error("This is an error!");
    ly_msgbox_normal("Hello from LibYGT!");
    return 0;
}
```

---

## 📦 File Structure
```
libygt/
├── include/      ← Header files
├── src/          ← Source files
├── examples/     ← Usage examples
├── tests/        ← Tests
└── docs/         ← Documentation
```

---

## 🤝 Contributing
See [CONTRIBUTING.md](docs/CONTRIBUTING.md)

## 📄 License
MIT License — see [LICENSE](LICENSE)

## 👤 Author
**Yiğit ALP** — 2026
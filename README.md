# Vanish
A minimalist secure-delete utility written in C.

## Why?
Standard `rm` only removes the file pointer. **Vanish** ensures data is unrecoverable by overwriting the physical disk sectors with multiple passes (0x00, 0xFF) and forcing a hardware sync.

## Installation
```bash
git clone https://github.com/cyb3rghazi/vanish.git
make
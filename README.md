# D700

Lightweight macOS system monitor written in C.

Designed for monitoring AMD GPU-based Mac systems such as the 2013 Mac Pro with FirePro D700 GPUs.

FEATURES
- GPU information detection
- GPU activity monitoring
- CPU usage monitoring
- Memory statistics
- Live terminal refresh updates

REQUIREMENTS
- macOS
- Clang compiler
- Administrator privileges for GPU power monitoring

COMPILE

clang D700.c -o D700

RUN

sudo ./D700

NOTES
- GPU monitoring uses macOS powermetrics
- sudo is required for GPU activity access
- Older Intel Mac systems may expose limited GPU telemetry
- Press CTRL + C to stop the monitor

# M5 Offline Voice Assistant

An offline voice assistant running directly on the M5CoreS3. No cloud, API key, or server is required.

```text
Microphone -> ESP-SR WakeNet -> "Hi ESP" -> ESP-SR MultiNet -> Command -> Display
```

## Upload

1. Open `offline_voice_assistant/offline_voice_assistant.ino` in Arduino IDE.
2. Select the `M5CoreS3` board.
3. Select partition scheme `ESP SR 16M (3MB APP/6MB SPIFFS/3.9MB MODEL)`.
4. Upload.

Say `Hi ESP`, then try `Start`, `Stop`, `Show status`, or `Clear screen`.

## What this demonstrates

- ESP-SR WakeNet wake-word detection
- ESP-SR MultiNet command recognition
- 16 kHz I2S microphone capture
- FreeRTOS speech-event queue and health task
- Persistent command and timeout counters
- Reset-reason, heap, uptime, and latency diagnostics
- Watchdog protection for the main firmware loop

The assistant accepts multiple commands after one wake word and returns to wake-word mode after the command timeout.

## Project scope

Firmware upload is intentionally USB-only in this project. OTA device management is reserved for a separate future project.

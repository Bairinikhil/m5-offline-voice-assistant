# M5 Offline Voice Assistant

An offline voice assistant running directly on the M5CoreS3.

```text
Microphone -> ESP-SR WakeNet -> "Hi ESP" -> ESP-SR MultiNet -> Command -> Display
```

## Upload

1. Open `offline_voice_assistant/offline_voice_assistant.ino` in Arduino IDE.
2. Select the `M5CoreS3` board.
3. Select partition scheme `ESP SR 16M (3MB APP/6MB SPIFFS/3.9MB MODEL)`.
4. Upload.

Say `Hi ESP`, then try `Start`, `Stop`, `Show status`, or `Clear screen`.

No Wi-Fi, API key, server, or cloud service is required.

## Optional OTA

The assistant is offline by default. To enable wireless firmware updates, set `ENABLE_NETWORK_FEATURES` to `1`, enter your Wi-Fi details locally, and upload once by USB. OTA then uses Wi-Fi only for firmware updates; speech recognition remains on-device.

#include <M5CoreS3.h>

#define SAMPLE_RATE 16000
int16_t samples[256];
uint32_t lastPrint = 0;

void setup() {
    Serial.begin(115200);
    CoreS3.begin();
    auto config = CoreS3.Mic.config();
    config.sample_rate = SAMPLE_RATE;
    CoreS3.Mic.config(config);
    CoreS3.Mic.begin();
    Serial.println("MIC DIAGNOSTIC READY");
    Serial.println("Speak near the microphone and watch the level.");
}

void loop() {
    CoreS3.update();
    if (CoreS3.Mic.record(samples, 256, SAMPLE_RATE)) {
        uint64_t total = 0;
        for (size_t i = 0; i < 256; i++) total += abs((int32_t)samples[i]);
        uint32_t level = total / 256;
        if (millis() - lastPrint >= 500) {
            Serial.printf("mic level: %lu\n", (unsigned long)level);
            lastPrint = millis();
        }
    }
}

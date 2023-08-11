#include "main.h"
#include "esp_log.h"

// Define the logging level and tag.
#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#define LOG_TAG "MAIN"

// Create a static instance of the Main class.
static Main main_app;

extern "C" void app_main(void) {
  ESP_ERROR_CHECK(main_app.setup()); // Initialize the Main object.
  while (true) {
    main_app.loop();
  }
}

esp_err_t Main::setup(void) {
  esp_err_t status {ESP_OK};
  status |= led.init();

  return status;
}

void Main::loop(void) {
  ESP_LOGI("LED STATUS", "ON");
  led.setState(true);
  vTaskDelay(pdSecond);

  ESP_LOGI("LED STATUS", "OFF");
  led.setState(true);
  vTaskDelay(pdSecond);
}
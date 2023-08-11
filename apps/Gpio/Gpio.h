#pragma once

#include "driver/gpio.h"

namespace Gpio {
  class GpioBase {
  protected:
    const gpio_num_t _pin;               // The `_pin` member variable stores the GPIO pin number.          
    const bool _inverted_logic = false;  // The `_inverted_logic` member variable indicates whether the GPIO logic is inverted.
    const gpio_config_t _config;         // The `_config` member variable stores the GPIO configuration.

  public:
    // this will be called from GpioOutput Class
    constexpr GpioBase(
      const gpio_num_t pin,
      const gpio_config_t& config,
      const bool _invert_logic = false
    ) :
      _pin(pin),
      _inverted_logic{ _invert_logic },
      _config{ config } {}

    [[nodiscard]] esp_err_t init(void);               // Initialize the GPIO pin.
    virtual bool getState(void) = 0;                  // Get the current state of the GPIO pin.
    virtual esp_err_t setState(const bool state) = 0; // Set the state of the GPIO pin.
  };

  class GpioOutput : public GpioBase {
    bool _state = false; // The current state of the GPIO pin.

  public:
    constexpr GpioOutput(
      const gpio_num_t pin,
      const bool invert = false
    ) : GpioBase{ pin, gpio_config_t{
      .pin_bit_mask = static_cast<uint64_t>(1) << pin,
      .mode = GPIO_MODE_OUTPUT,
      .pull_up_en = GPIO_PULLUP_DISABLE,
      .pull_down_en = GPIO_PULLDOWN_ENABLE,
      .intr_type = GPIO_INTR_DISABLE
    }, invert } {}

    [[nodiscard]] esp_err_t init(void);  // Initialize the GPIO pin.

    esp_err_t setState(const bool state);
    // esp_err_t toggleState(void);
    bool getState(void) { return _state; }
  };

  class GpioInput {
    // The `_pin` member variable stores the GPIO pin number.
    gpio_num_t _pin;

    // The `_inverted_logic` member variable indicates whether the GPIO logic is inverted.
    // For example, if `_inverted_logic` is true, then a logical 1 on the GPIO pin will be interpreted as a logical 0.
    const bool _inverted_logic = false;

  public:
    // GPIO Input Constructor
    // The `pin` parameter specifies the GPIO pin number.
    GpioInput(const gpio_num_t pin) :
      _pin(pin) {}

    // Initialize the GPIO pin.
    esp_err_t init(void);

    // Get the current state of the GPIO pin.
    bool getState(void);
  };
}

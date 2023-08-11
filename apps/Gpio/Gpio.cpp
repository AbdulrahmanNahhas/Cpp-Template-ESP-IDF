#include "Gpio.h"

namespace Gpio {
  // * BASE Initialize * //
  [[nodiscard]] esp_err_t GpioBase::init(void) {
    esp_err_t status{ ESP_OK };

    //? status = status | ....
    status |= gpio_config(&_config);

    return status;
  }

  // * OUTPUT Initialize * //
  [[nodiscard]] esp_err_t GpioOutput::init(void) {
    esp_err_t status{ GpioBase::init() };

    if (ESP_OK == status) {
      //? status = status | ....
      status |= setState(_inverted_logic);
    }

    return status;
  }

  // * OUTPUT Set State Function * //
  esp_err_t GpioOutput::setState(const bool state) {
    _state = state;

    return gpio_set_level(
      _pin,
      _inverted_logic ? !state : state
    );
  }
}
